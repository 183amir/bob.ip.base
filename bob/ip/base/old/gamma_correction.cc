/**
 * @author Laurent El Shafey <Laurent.El-Shafey@idiap.ch>
 * @date Sun Jun 26 18:59:21 2011 +0200
 *
 * @brief Binds gamma correction into python
 *
 * Copyright (C) 2011-2014 Idiap Research Institute, Martigny, Switzerland
 */


#include "ndarray.h"
#include <bob/ip/gammaCorrection.h>

using namespace boost::python;

template <typename T, int N>
static void inner_gammaCorrection_c(bob::python::const_ndarray src,
  bob::python::ndarray dst, const double g)
{
  blitz::Array<double,N> dst_ = dst.bz<double,N>();
  bob::ip::gammaCorrection<T>(src.bz<T,N>(), dst_, g);
}

static void py_gamma_correction_c(bob::python::const_ndarray src,
  bob::python::ndarray dst, const double g)
{
  const bob::core::array::typeinfo& info = src.type();

  switch (info.dtype) {
    case bob::core::array::t_uint8:
      return inner_gammaCorrection_c<uint8_t,2>(src, dst, g);
    case bob::core::array::t_uint16:
      return inner_gammaCorrection_c<uint16_t,2>(src, dst, g);
    case bob::core::array::t_float64:
      return inner_gammaCorrection_c<double,2>(src, dst, g);
    default:
      PYTHON_ERROR(TypeError,
        "bob.ip.gamma_correction() does not support input array of type '%s'.",
        info.str().c_str());
  }
}

template <typename T, int N>
static object inner_gammaCorrection_p(bob::python::const_ndarray src,
  const double g)
{
  const bob::core::array::typeinfo& info = src.type();
  bob::python::ndarray dst(bob::core::array::t_float64, info.shape[0],
    info.shape[1]);
  blitz::Array<double,N> dst_ = dst.bz<double,N>();
  bob::ip::gammaCorrection<T>(src.bz<T,N>(), dst_, g);
  return dst.self();
}

static object py_gamma_correction_p(bob::python::const_ndarray src,
  const double g)
{
  const bob::core::array::typeinfo& info = src.type();

  switch (info.dtype) {
    case bob::core::array::t_uint8:
      return inner_gammaCorrection_p<uint8_t,2>(src, g);
    case bob::core::array::t_uint16:
      return inner_gammaCorrection_p<uint16_t,2>(src, g);
    case bob::core::array::t_float64:
      return inner_gammaCorrection_p<double,2>(src, g);
    default:
      PYTHON_ERROR(TypeError,
        "bob.ip.gamma_correction() does not support input array of type '%s'.",
        info.str().c_str());
  }
}
void bind_ip_gamma_correction()
{
  def("gamma_correction",
    &py_gamma_correction_c, (arg("src"), arg("dst"), arg("gamma")),
    "Performs a power-law gamma correction on a 2D blitz array/image.");
  def("gamma_correction",
    &py_gamma_correction_p, (arg("src"), arg("gamma")),
    "Performs a power-law gamma correction on a 2D blitz array/image. The output is allocated and returned.");
}
