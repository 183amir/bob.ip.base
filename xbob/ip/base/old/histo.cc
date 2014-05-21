/**
 * @author Francois Moulin <Francois.Moulin@idiap.ch>
 * @date Mon Apr 18 16:08:34 2011 +0200
 *
 * @brief Binds histogram to python
 *
 * Copyright (C) 2011-2014 Idiap Research Institute, Martigny, Switzerland
 */

#include "ndarray.h"
#include <bob/ip/histo.h>

using namespace boost::python;

template <typename T>
static object inner_histo1 (bob::python::const_ndarray input) {
  int size = bob::ip::detail::getHistoSize<T>();
  bob::python::ndarray out(bob::core::array::t_uint64, size);
  blitz::Array<uint64_t,1> out_ = out.bz<uint64_t,1>();
  bob::ip::histogram(input.bz<T,2>(), out_, false);
  return out.self();
}

static object histo1 (bob::python::const_ndarray input) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_uint8: return inner_histo1<uint8_t>(input);
    case bob::core::array::t_uint16: return inner_histo1<uint16_t>(input);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

template <typename T>
static void inner_histo2 (bob::python::const_ndarray input, bob::python::ndarray output,
    bool accumulate) {
  blitz::Array<uint64_t,1> out_ = output.bz<uint64_t,1>();
  bob::ip::histogram(input.bz<T,2>(), out_, accumulate);
}

static void histo2 (bob::python::const_ndarray input, bob::python::ndarray output,
    bool accumulate=false) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_uint8: return inner_histo2<uint8_t>(input, output, accumulate);
    case bob::core::array::t_uint16: return inner_histo2<uint16_t>(input, output, accumulate);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

BOOST_PYTHON_FUNCTION_OVERLOADS(histo2_overloads, histo2, 2, 3)

template <typename T>
static void inner_histo3 (bob::python::const_ndarray input, bob::python::ndarray output,
    object max, bool accumulate) {
  blitz::Array<uint64_t,1> out_ = output.bz<uint64_t,1>();
  T tmax = extract<T>(max);
  bob::ip::histogram(input.bz<T,2>(), out_, (T)0, tmax, (uint32_t)(tmax+1), accumulate);
}

static void histo3 (bob::python::const_ndarray input, bob::python::ndarray output, object max,
    bool accumulate=false) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_int8:
      return inner_histo3<int8_t>(input, output, max, accumulate);
    case bob::core::array::t_int16:
      return inner_histo3<int16_t>(input, output, max, accumulate);
    case bob::core::array::t_int32:
      return inner_histo3<int32_t>(input, output, max, accumulate);
    case bob::core::array::t_int64:
      return inner_histo3<int64_t>(input, output, max, accumulate);
    case bob::core::array::t_uint8:
      return inner_histo3<uint8_t>(input, output, max, accumulate);
    case bob::core::array::t_uint16:
      return inner_histo3<uint16_t>(input, output, max, accumulate);
    case bob::core::array::t_uint32:
      return inner_histo3<uint32_t>(input, output, max, accumulate);
    case bob::core::array::t_uint64:
      return inner_histo3<uint64_t>(input, output, max, accumulate);
    case bob::core::array::t_float32:
      return inner_histo3<float>(input, output, max, accumulate);
    case bob::core::array::t_float64:
      return inner_histo3<double>(input, output, max, accumulate);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

BOOST_PYTHON_FUNCTION_OVERLOADS(histo3_overloads, histo3, 3, 4)

template <typename T>
static void inner_histo4 (bob::python::const_ndarray input, bob::python::ndarray output,
    object min, object max, bool accumulate) {
  blitz::Array<uint64_t,1> out_ = output.bz<uint64_t,1>();
  T tmin = extract<T>(min);
  T tmax = extract<T>(max);
  bob::ip::histogram(input.bz<T,2>(), out_, tmin, tmax, (uint32_t)(tmax-tmin+1), accumulate);
}

static void histo4 (bob::python::const_ndarray input, bob::python::ndarray output,
    object min, object max, bool accumulate=false) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_int8:
      return inner_histo4<int8_t>(input, output, min, max, accumulate);
    case bob::core::array::t_int16:
      return inner_histo4<int16_t>(input, output, min, max, accumulate);
    case bob::core::array::t_int32:
      return inner_histo4<int32_t>(input, output, min, max, accumulate);
    case bob::core::array::t_int64:
      return inner_histo4<int64_t>(input, output, min, max, accumulate);
    case bob::core::array::t_uint8:
      return inner_histo4<uint8_t>(input, output, min, max, accumulate);
    case bob::core::array::t_uint16:
      return inner_histo4<uint16_t>(input, output, min, max, accumulate);
    case bob::core::array::t_uint32:
      return inner_histo4<uint32_t>(input, output, min, max, accumulate);
    case bob::core::array::t_uint64:
      return inner_histo4<uint64_t>(input, output, min, max, accumulate);
    case bob::core::array::t_float32:
      return inner_histo4<float>(input, output, min, max, accumulate);
    case bob::core::array::t_float64:
      return inner_histo4<double>(input, output, min, max, accumulate);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

BOOST_PYTHON_FUNCTION_OVERLOADS(histo4_overloads, histo4, 4, 5)

template <typename T>
static void inner_histo5 (bob::python::const_ndarray input, bob::python::ndarray output,
    object min, object max, uint32_t nbins, bool accumulate) {
  blitz::Array<uint64_t,1> out_ = output.bz<uint64_t,1>();
  T tmin = extract<T>(min);
  T tmax = extract<T>(max);
  bob::ip::histogram(input.bz<T,2>(), out_, tmin, tmax, nbins, accumulate);
}

static void histo5 (bob::python::const_ndarray input, bob::python::ndarray output,
    object min, object max, uint32_t nbins, bool accumulate=false) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_int8:
      return inner_histo5<int8_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_int16:
      return inner_histo5<int16_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_int32:
      return inner_histo5<int32_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_int64:
      return inner_histo5<int64_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_uint8:
      return inner_histo5<uint8_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_uint16:
      return inner_histo5<uint16_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_uint32:
      return inner_histo5<uint32_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_uint64:
      return inner_histo5<uint64_t>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_float32:
      return inner_histo5<float>(input, output, min, max, nbins, accumulate);
    case bob::core::array::t_float64:
      return inner_histo5<double>(input, output, min, max, nbins, accumulate);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

BOOST_PYTHON_FUNCTION_OVERLOADS(histo5_overloads, histo5, 5, 6)

template <typename T>
static object inner_histo3a (bob::python::const_ndarray input, object max) {
  T tmax = extract<T>(max);
  uint32_t size = (uint32_t)(tmax + 1);
  bob::python::ndarray out(bob::core::array::t_uint64, size);
  blitz::Array<uint64_t,1> out_ = out.bz<uint64_t,1>();
  bob::ip::histogram(input.bz<T,2>(), out_, (T)0, tmax, size, false);
  return out.self();
}

static object histo3a (bob::python::const_ndarray input, object max) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_int8: return inner_histo3a<int8_t>(input, max);
    case bob::core::array::t_int16: return inner_histo3a<int16_t>(input, max);
    case bob::core::array::t_int32: return inner_histo3a<int32_t>(input, max);
    case bob::core::array::t_int64: return inner_histo3a<int64_t>(input, max);
    case bob::core::array::t_uint8: return inner_histo3a<uint8_t>(input, max);
    case bob::core::array::t_uint16: return inner_histo3a<uint16_t>(input, max);
    case bob::core::array::t_uint32: return inner_histo3a<uint32_t>(input, max);
    case bob::core::array::t_uint64: return inner_histo3a<uint64_t>(input, max);
    case bob::core::array::t_float32: return inner_histo3a<float>(input, max);
    case bob::core::array::t_float64: return inner_histo3a<double>(input, max);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

template <typename T>
static object inner_histo4a (bob::python::const_ndarray input, object min, object max) {
  T tmin = extract<T>(min);
  T tmax = extract<T>(max);
  int64_t size = (int64_t)(tmax - tmin + 1);
  bob::python::ndarray out(bob::core::array::t_uint64, size);
  blitz::Array<uint64_t,1> out_ = out.bz<uint64_t,1>();
  bob::ip::histogram(input.bz<T,2>(), out_, tmin, tmax, size, false);
  return out.self();
}

static object histo4a (bob::python::const_ndarray input, object min, object max) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_int8:
      return inner_histo4a<int8_t>(input, min, max);
    case bob::core::array::t_int16:
      return inner_histo4a<int16_t>(input, min, max);
    case bob::core::array::t_int32:
      return inner_histo4a<int32_t>(input, min, max);
    case bob::core::array::t_int64:
      return inner_histo4a<int64_t>(input, min, max);
    case bob::core::array::t_uint8:
      return inner_histo4a<uint8_t>(input, min, max);
    case bob::core::array::t_uint16:
      return inner_histo4a<uint16_t>(input, min, max);
    case bob::core::array::t_uint32:
      return inner_histo4a<uint32_t>(input, min, max);
    case bob::core::array::t_uint64:
      return inner_histo4a<uint64_t>(input, min, max);
    case bob::core::array::t_float32:
      return inner_histo4a<float>(input, min, max);
    case bob::core::array::t_float64:
      return inner_histo4a<double>(input, min, max);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

template <typename T>
static object inner_histo5a (bob::python::const_ndarray input, object min, object max,
    uint32_t nbins) {
  T tmin = extract<T>(min);
  T tmax = extract<T>(max);
  bob::python::ndarray out(bob::core::array::t_uint64, nbins);
  blitz::Array<uint64_t,1> out_ = out.bz<uint64_t,1>();
  bob::ip::histogram(input.bz<T,2>(), out_, tmin, tmax, nbins, false);
  return out.self();
}

static object histo5a (bob::python::const_ndarray input,
    object min, object max, uint32_t nbins) {
  const bob::core::array::typeinfo& info = input.type();
  switch (info.dtype) {
    case bob::core::array::t_int8:
      return inner_histo5a<int8_t>(input, min, max, nbins);
    case bob::core::array::t_int16:
      return inner_histo5a<int16_t>(input, min, max, nbins);
    case bob::core::array::t_int32:
      return inner_histo5a<int32_t>(input, min, max, nbins);
    case bob::core::array::t_int64:
      return inner_histo5a<int64_t>(input, min, max, nbins);
    case bob::core::array::t_uint8:
      return inner_histo5a<uint8_t>(input, min, max, nbins);
    case bob::core::array::t_uint16:
      return inner_histo5a<uint16_t>(input, min, max, nbins);
    case bob::core::array::t_uint32:
      return inner_histo5a<uint32_t>(input, min, max, nbins);
    case bob::core::array::t_uint64:
      return inner_histo5a<uint64_t>(input, min, max, nbins);
    case bob::core::array::t_float32:
      return inner_histo5a<float>(input, min, max, nbins);
    case bob::core::array::t_float64:
      return inner_histo5a<double>(input, min, max, nbins);
    default:
      PYTHON_ERROR(TypeError, "unsupported histogram operation for type '%s'", info.str().c_str());
  }
}

template <typename T1, typename T2>
static void inner_histogram_equalization2(bob::python::const_ndarray src, bob::python::ndarray dst){
  const blitz::Array<T1,2> src_array = src.bz<T1,2>();
  blitz::Array<T2,2> dst_array = dst.bz<T2,2>();
  bob::ip::histogram_equalize<T1,T2>(src_array, dst_array);
}

template <typename T>
static void inner_histogram_equalization(bob::python::const_ndarray src, bob::python::ndarray dst){
  switch (dst.type().dtype){
    case bob::core::array::t_int8:
      return inner_histogram_equalization2<T,int8_t>(src, dst);
    case bob::core::array::t_int16:
      return inner_histogram_equalization2<T,int16_t>(src, dst);
    case bob::core::array::t_int32:
      return inner_histogram_equalization2<T,int32_t>(src, dst);
    case bob::core::array::t_int64:
      return inner_histogram_equalization2<T,int64_t>(src, dst);
    case bob::core::array::t_uint8:
      return inner_histogram_equalization2<T,uint8_t>(src, dst);
    case bob::core::array::t_uint16:
      return inner_histogram_equalization2<T,uint16_t>(src, dst);
    case bob::core::array::t_uint32:
      return inner_histogram_equalization2<T,uint32_t>(src, dst);
    case bob::core::array::t_uint64:
      return inner_histogram_equalization2<T,uint64_t>(src, dst);
    case bob::core::array::t_float32:
      return inner_histogram_equalization2<T,float>(src, dst);
    case bob::core::array::t_float64:
      return inner_histogram_equalization2<T,double>(src, dst);
    case bob::core::array::t_float128:
      return inner_histogram_equalization2<T,long double>(src, dst);
    default:
      PYTHON_ERROR(TypeError, "Histogram equalization is not supported for destination type '%s'", src.type().str().c_str());
  }
}

static void histogram_equalization(bob::python::const_ndarray src, bob::python::ndarray dst){
  switch (src.type().dtype){
    case bob::core::array::t_int8:
      return inner_histogram_equalization<int8_t>(src, dst);
    case bob::core::array::t_int16:
      return inner_histogram_equalization<int16_t>(src, dst);
    case bob::core::array::t_int32:
      return inner_histogram_equalization<int32_t>(src, dst);
    case bob::core::array::t_uint8:
      return inner_histogram_equalization<uint8_t>(src, dst);
    case bob::core::array::t_uint16:
      return inner_histogram_equalization<uint16_t>(src, dst);
    case bob::core::array::t_uint32:
      return inner_histogram_equalization<uint32_t>(src, dst);
    default:
      PYTHON_ERROR(TypeError, "Histogram equalization is only supported for integral source types <= 32 bit, but not for type '%s'", src.type().str().c_str());
  }
}

static bob::python::ndarray histogram_equalization_single(bob::python::const_ndarray src){
  bob::python::ndarray dst(src.type());
  histogram_equalization(src, dst);
  return dst;
}

void bind_ip_histogram() {
  def("histogram_", &histo2, histo2_overloads((arg("src"), arg("histo"), arg("accumulate")=false), "Compute an histogram of a 2D array. The histogram must have a size of 2^N-1 elements, where N is the number of bits in input. If the accumulate flag is set (defaults to False), then I accumulate instead of resetting the histogram."));

  def("histogram_", &histo3, histo3_overloads((arg("src"), arg("histo"), arg("max"), arg("accumulate")=false), "Compute an histogram of a 2D array.\nsrc elements are in range [0, max] (max >= 0)\nhisto must have a size of max elements"));

  def("histogram_", &histo4, histo4_overloads((arg("src"), arg("histo"), arg("min"), arg("max"), arg("accumulate")=false), "Compute an histogram of a 2D array.\nsrc elements are in range [min, max] (max >= min)\nhisto must have a size of max-min elements"));

  def("histogram_", &histo5, histo5_overloads((arg("src"), arg("histo"), arg("min"), arg("max"), arg("nb_bins"), arg("accumulate")=false), "Compute an histogram of a 2D array.\nsrc elements are in range [min, max] (max >= min)\nhisto must have a size of nb_bins elements"));

  def("histogram", &histo1, (args("src")), "Compute an histogram of a 2D array");
  def("histogram", &histo3a, (arg("src"), arg("max")), "Return an histogram of a 2D array.\nsrc elements are in range [0, max] (max >= 0)\n");

  def("histogram", &histo4a, (arg("src"), arg("min"), arg("max")), "Return an histogram of a 2D array.\nsrc elements are in range [min, max] (max >= min)\n");

  def("histogram", &histo5a, (arg("src"), arg("min"), arg("max"), arg("nb_bins")), "Return an histogram of a 2D array.\nsrc elements are in range [min, max] (max >= min)\n");

  def("histogram_equalization", &histogram_equalization, (args("src", "dst")), "Computes the histogram equalization of the given src image and fills the dst image. The types of the images wmight differ, but the resolution must be idenitcal");
  def("histogram_equalization", &histogram_equalization_single, (args("src")), "Computes the histogram equalization of the given src image returns the equalized image with the same size and data type.");
}
