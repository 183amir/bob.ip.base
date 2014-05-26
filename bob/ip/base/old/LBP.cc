/**
 * @author Laurent El Shafey <Laurent.El-Shafey@idiap.ch>
 * @date Tue Apr 26 17:25:41 2011 +0200
 *
 * @brief Binds the LBP class to python
 *
 * Copyright (C) 2011-2014 Idiap Research Institute, Martigny, Switzerland
 */

#include "ndarray.h"

#include <stdint.h>
#include <vector>
#include <bob/ip/LBP.h>
#include <bob/ip/LBPTop.h>
#include <bob/ip/LBPHSFeatures.h>

using namespace boost::python;


template <typename T>
static void inner_call_inout (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bob::python::ndarray output, bool is_integral_image) {
  blitz::Array<uint16_t,2> out_ = output.bz<uint16_t,2>();
  lbp(input.bz<T,2>(), out_, is_integral_image);
}

static void call_inout (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bob::python::ndarray output, bool is_integral_image) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: inner_call_inout<uint8_t>(lbp, input, output, is_integral_image); break;
    case bob::core::array::t_uint16: inner_call_inout<uint16_t>(lbp, input, output, is_integral_image); break;
    case bob::core::array::t_float64: inner_call_inout<double>(lbp, input, output, is_integral_image); break;
    default: PYTHON_ERROR(TypeError, "LBP operator cannot process image of type '%s'", input.type().str().c_str()); break;
  }
}

static uint16_t call_pos (const bob::ip::LBP& lbp, bob::python::const_ndarray input, int y, int x, bool is_integral_image) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: return lbp(input.bz<uint8_t,2>(), y, x, is_integral_image);
    case bob::core::array::t_uint16: return lbp(input.bz<uint16_t,2>(), y, x, is_integral_image);
    case bob::core::array::t_float64: return lbp(input.bz<double,2>(), y, x, is_integral_image);
    default: PYTHON_ERROR(TypeError, "LBP operator cannot process image of type '%s'", input.type().str().c_str()); return 0;
  }
}

template <typename T>
static object inner_call_alloc (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bool is_integral_image) {
  blitz::Array<T,2> i_ = input.bz<T,2>();
  blitz::TinyVector<int,2> shape = lbp.getLBPShape(i_, is_integral_image);
  bob::python::ndarray out(bob::core::array::t_uint16, shape(0), shape(1));
  blitz::Array<uint16_t,2> out_ = out.bz<uint16_t,2>();
  lbp(input.bz<T,2>(), out_, is_integral_image);
  return out.self();
}

static object call_alloc (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bool is_integral_image) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: return inner_call_alloc<uint8_t>(lbp, input, is_integral_image);
    case bob::core::array::t_uint16: return inner_call_alloc<uint16_t>(lbp, input, is_integral_image);
    case bob::core::array::t_float64: return inner_call_alloc<double>(lbp, input, is_integral_image);
    default: PYTHON_ERROR(TypeError, "LBP operator cannot process image of type '%s'", input.type().str().c_str()); return boost::python::api::object();
  }
}


template <typename T>
static void inner_extract_inout (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bob::python::ndarray output, bool is_integral_image) {
  blitz::Array<uint16_t,2> out_ = output.bz<uint16_t,2>();
  lbp.extract_(input.bz<T,2>(), out_, is_integral_image);
}

static void extract_inout (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bob::python::ndarray output, bool is_integral_image) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: inner_extract_inout<uint8_t>(lbp, input, output, is_integral_image); break;
    case bob::core::array::t_uint16: inner_extract_inout<uint16_t>(lbp, input, output, is_integral_image); break;
    case bob::core::array::t_float64: inner_extract_inout<double>(lbp, input, output, is_integral_image); break;
    default: PYTHON_ERROR(TypeError, "LBP operator cannot process image of type '%s'", input.type().str().c_str()); break;
  }
}

static uint16_t extract_pos (const bob::ip::LBP& lbp, bob::python::const_ndarray input, int y, int x, bool is_integral_image) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: return lbp.extract_(input.bz<uint8_t,2>(), y, x, is_integral_image);
    case bob::core::array::t_uint16: return lbp.extract_(input.bz<uint16_t,2>(), y, x, is_integral_image);
    case bob::core::array::t_float64: return lbp.extract_(input.bz<double,2>(), y, x, is_integral_image);
    default: PYTHON_ERROR(TypeError, "LBP operator cannot process image of type '%s'", input.type().str().c_str()); return 0;
  }
}

template <typename T>
static object inner_get_shape (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bool is_integral_image) {
  return object(lbp.getLBPShape(input.bz<T,2>(), is_integral_image));
}

static object get_shape (const bob::ip::LBP& lbp, bob::python::const_ndarray input, bool is_integral_image) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: return inner_get_shape<uint8_t>(lbp, input, is_integral_image);
    case bob::core::array::t_uint16: return inner_get_shape<uint16_t>(lbp, input, is_integral_image);
    case bob::core::array::t_float64: return inner_get_shape<double>(lbp, input, is_integral_image);
    default: PYTHON_ERROR(TypeError, "LBP operator cannot process image of type '%s'", input.type().str().c_str()); return boost::python::api::object();
  }
}

static object get_shape_2 (const bob::ip::LBP& lbp, const blitz::TinyVector<int,2>& shape, bool is_integral_image) {
  return object(lbp.getLBPShape(shape, is_integral_image));
}

template <typename T>
static void inner_call_lbptop (const bob::ip::LBPTop& op, bob::python::const_ndarray input, bob::python::ndarray xy, bob::python::ndarray xt, bob::python::ndarray yt) {
  blitz::Array<uint16_t,3> xy_ = xy.bz<uint16_t,3>();
  blitz::Array<uint16_t,3> xt_ = xt.bz<uint16_t,3>();
  blitz::Array<uint16_t,3> yt_ = yt.bz<uint16_t,3>();
  op(input.bz<T,3>(), xy_, xt_, yt_);
}

static void call_lbptop (const bob::ip::LBPTop& op, bob::python::const_ndarray input, bob::python::ndarray xy, bob::python::ndarray xt, bob::python::ndarray yt) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: return inner_call_lbptop<uint8_t>(op, input, xy, xt, yt);
    case bob::core::array::t_uint16: return inner_call_lbptop<uint16_t>(op, input, xy, xt,yt);
    case bob::core::array::t_float64: return inner_call_lbptop<double>(op, input, xy, xt, yt);
    default: PYTHON_ERROR(TypeError, "LBPTop operator cannot process image of type '%s'", input.type().str().c_str()); return;
  }
}


template <typename T>
static object inner_lbp_apply (bob::ip::LBPHSFeatures& op, bob::python::const_ndarray input) {
  std::vector<blitz::Array<uint64_t,1> > dst;
  op(input.bz<T,2>(), dst);
  list t;
  for(size_t i=0; i<dst.size(); ++i) t.append(dst[i]);
  return t;
}

static object lbp_apply (bob::ip::LBPHSFeatures& op, bob::python::const_ndarray input) {
  switch(input.type().dtype) {
    case bob::core::array::t_uint8: return inner_lbp_apply<uint8_t>(op, input);
    case bob::core::array::t_uint16: return inner_lbp_apply<uint16_t>(op, input);
    case bob::core::array::t_float64: return inner_lbp_apply<double>(op, input);
    default: PYTHON_ERROR(TypeError, "LBPHS operator cannot process image of type '%s'", input.type().str().c_str()); return boost::python::api::object();
  }
}


void bind_ip_lbp() {
  enum_<bob::ip::ELBPType>("ELBPType", "Different types of LBP codes")
    .value("REGULAR", bob::ip::ELBP_REGULAR)
    .value("TRANSITIONAL", bob::ip::ELBP_TRANSITIONAL)
    .value("DIRECTION_CODED", bob::ip::ELBP_DIRECTION_CODED);

  enum_<bob::ip::LBPBorderHandling>("LBPBorderHandling", "How to handle pixels near the border of the image.")
    .value("SHRINK", bob::ip::LBP_BORDER_SHRINK)
    .value("WRAP", bob::ip::LBP_BORDER_WRAP);

  class_<bob::ip::LBP, boost::shared_ptr<bob::ip::LBP> >("LBP", "A class for the LBP operators", no_init)
    .def(init<int, double, double, bool, bool, bool, bool, bool, bob::ip::ELBPType, bob::ip::LBPBorderHandling >((arg("self"), arg("neighbors"), arg("radius_y"), arg("radius_x"), arg("circular")=false, arg("to_average")=false, arg("add_average_bit")=false, arg("uniform")=false, arg("rotation_invariant")=false, arg("elbp_type")=bob::ip::ELBP_REGULAR, arg("border_handling")=bob::ip::LBP_BORDER_SHRINK), "Constructs a new LBP operator with different radii"))
    .def(init<int, double, bool, bool, bool, bool, bool, bob::ip::ELBPType, bob::ip::LBPBorderHandling >((arg("self"), arg("neighbors"), arg("radius")=1., arg("circular")=false, arg("to_average")=false, arg("add_average_bit")=false, arg("uniform")=false, arg("rotation_invariant")=false, arg("elbp_type")=bob::ip::ELBP_REGULAR, arg("border_handling")=bob::ip::LBP_BORDER_SHRINK), "Constructs a new LBP operator"))
    .def(init<int, blitz::TinyVector<int,2>, blitz::TinyVector<int,2>, bool, bool, bool, bool, bob::ip::ELBPType, bob::ip::LBPBorderHandling >((arg("self"), arg("neighbors"), arg("block_size"), arg("block_overlap")=blitz::TinyVector<int,2>(0,0), arg("to_average")=false, arg("add_average_bit")=false, arg("uniform")=false, arg("rotation_invariant")=false, arg("elbp_type")=bob::ip::ELBP_REGULAR, arg("border_handling")=bob::ip::LBP_BORDER_SHRINK), "Constructs a new multi-block LBP operator with possibly overlapping blocks"))
    //.def(init<bob::io::HDF5File>((arg("self"), arg("hdf5file")), "Reads the LBP configuration from the given HDF5File"))
    .def(init<bob::ip::LBP>((arg("self"), arg("other")), "Copy constructor"))

    .def(self == self)
    //.def("load", &bob::ip::LBP::load, "Reads the LBP configuration from the given HDF5File")
    //.def("save", &bob::ip::LBP::save, "Writes the LBP configuration to the given HDF5File")

    .add_property("radius", &bob::ip::LBP::getRadius, &bob::ip::LBP::setRadius, "The radius of the round or square LBP")
    .add_property("radii", &bob::ip::LBP::getRadii, &bob::ip::LBP::setRadii, "The radii (y,x) of the elliptical or rectangular LBP")
    .add_property("block_size", &bob::ip::LBP::getBlockSize, &bob::ip::LBP::setBlockSize, "The size (y,x) of one block of the multi-block LBP")
    .add_property("block_overlap", &bob::ip::LBP::getBlockOverlap, &bob::ip::LBP::setBlockOverlap, "The overlap (y,x) of the blocks in the multi-block LBP")
    .add_property("points", &bob::ip::LBP::getNNeighbours, &bob::ip::LBP::setNNeighbours, "The number of points in the LBP (usually, 4, 8 or 16)")
    .add_property("circular", &bob::ip::LBP::getCircular, &bob::ip::LBP::setCircular, "Extract elliptical (True) or rectangular (false) LBP")
    .add_property("to_average", &bob::ip::LBP::getToAverage, &bob::ip::LBP::setToAverage, "Compare the pixel values to their average (True) or to the central pixel (False)")
    .add_property("add_average_bit", &bob::ip::LBP::getAddAverageBit, &bob::ip::LBP::setAddAverageBit, "When comparing to average, also add the comparison of the central bit with the average?")
    .add_property("uniform", &bob::ip::LBP::getUniform, &bob::ip::LBP::setUniform, "Extract uniform (u2) patterns?")
    .add_property("rotation_invariant", &bob::ip::LBP::getRotationInvariant, &bob::ip::LBP::setRotationInvariant, "Extract rotation-invariant patterns?")
    .add_property("elbp_type", &bob::ip::LBP::get_eLBP, &bob::ip::LBP::set_eLBP, "The type of extended LBP: bob.ip.ELBPType.REGULAR (0), bob.ip.ELBPType.TRANSITIONAL (1), bob.ip.ELBPType.DIRECTION_CODED (2)")
    .add_property("border_handling", &bob::ip::LBP::getBorderHandling, &bob::ip::LBP::setBorderHandling, "The way, how the image is treated at its borders: bob.ip.LBPBpoderHandling.SHRINK: shrinks image, bob.ip.LBPBpoderHandling.WRAP: uses pixels from other border.")
    .add_property("max_label", &bob::ip::LBP::getMaxLabel, "The number of different LBP values that can be extracted.")
    .add_property("look_up_table", &bob::ip::LBP::getLookUpTable, &bob::ip::LBP::setLookUpTable, "How to extract the LBP code from the binary vector (interpreted as int)")
    .add_property("relative_positions", &bob::ip::LBP::getRelativePositions, "The vector of positions (relative), with which the central pixel (0,0) is compared.")
    .add_property("offset", &bob::ip::LBP::getOffset, "The first valid pixel in the __call__ function that takes the position.")
    .add_property("is_multi_block_lbp", &bob::ip::LBP::isMultiBlockLBP, "Is this LBP extractor extracting multi-block LBP?")

    .def("set_block_size_and_overlap", &bob::ip::LBP::setBlockSizeAndOverlap, (arg("self"), arg("block_size"), arg("block_overlap")), "Sets block size and block overlap at the same time.")
    .def("get_lbp_shape", &get_shape, (arg("self"), arg("input"), arg("is_integral_image")=false), "Get a tuple containing the expected size of the output when extracting LBP features.")
    .def("get_lbp_shape", &get_shape_2, (arg("self"), arg("shape"), arg("is_integral_image")=false), "Get a tuple containing the expected size of the output when extracting LBP features.")
    .def("__call__", &call_inout, (arg("self"), arg("input"), arg("output"), arg("is_integral_image")=false), "Call an object of this type to extract LBP features for the whole image.")
    .def("__call__", &call_pos, (arg("self"), arg("input"), arg("y"), arg("x"), arg("is_integral_image")=false), "Call an object of this type to extract LBP features for a given position in the image.")
    .def("__call__", &call_alloc, (arg("self"), arg("input"), arg("is_integral_image")=false), "Call an object of this type to extract LBP features for the whole image.")

    .def("extract", &extract_inout, (arg("self"), arg("input"), arg("output"), arg("is_integral_image")=false), "The same as the according () operator, but for performance reasons without checks.")
    .def("extract", &extract_pos, (arg("self"), arg("input"), arg("y"), arg("x"), arg("is_integral_image")=false), "The same as the according () operator, but for performance reasons without checks.")

    ;

  class_<bob::ip::LBPTop, boost::shared_ptr<bob::ip::LBPTop> >("LBPTop", "Constructs a new LBPTop object starting from the algorithm configuration.",
     init< const bob::ip::LBP &,  const bob::ip::LBP &,  const bob::ip::LBP & >((arg("self"), arg("xy"), arg("xt"), arg("yt")), "Constructs a new LBPTop object"))
    .add_property("xy", &bob::ip::LBPTop::getXY)
    .add_property("xt", &bob::ip::LBPTop::getXT)
    .add_property("yt", &bob::ip::LBPTop::getYT)
    .def("__call__", &call_lbptop, (arg("self"),arg("input"), arg("xy"), arg("xt"), arg("yt")), "Processes a 3D array representing a set of <b>grayscale</b> images and returns (by argument) the three LBP planes calculated. The 3D array has to be arranged in this way:\n\n1st dimension => time\n2nd dimension => frame height\n3rd dimension => frame width\n\nThe central pixel is the point where the LBP planes intersect/have to be calculated from.")
    ;


  class_<bob::ip::LBPHSFeatures, boost::shared_ptr<bob::ip::LBPHSFeatures> >("LBPHSFeatures", "Constructs a new LBPHSFeatures object to extract histogram of LBP over 2D blitz arrays/images.", no_init)
    .def(init<const int, const int, const int, const int, optional<const double, const int, const bool, const bool, const bool, const bool, const bool> >((arg("self"), arg("block_h"), arg("block_w"), arg("overlap_h"), arg("overlap_w"), arg("lbp_radius")=1., arg("lbp_neighbours")=8, arg("circular")=false,arg("to_average")=false,arg("add_average_bit")=false,arg("uniform")=false, arg("rotation_invariant")=false), "Constructs a new LBPHS features extractor creating a new LBP extractor with the given parameters."))
    .def(init<const int, const int, const int, const int, const bob::ip::LBP& >((arg("self"), arg("block_h"), arg("block_w"), arg("overlap_h"), arg("overlap_w"), arg("lbp")), "Constructs a new LBPHS features extractor using the given LBP extractor."))
    .add_property("n_bins", &bob::ip::LBPHSFeatures::getNBins)
    .def("get_n_blocks", (const int (bob::ip::LBPHSFeatures::*)(const blitz::Array<uint8_t,2>& src))&bob::ip::LBPHSFeatures::getNBlocks<uint8_t>, (arg("self"),arg("input")), "Return the number of blocks generated when extracting LBPHS Features on the given input")
    .def("get_n_blocks", (const int (bob::ip::LBPHSFeatures::*)(const blitz::Array<uint16_t,2>& src))&bob::ip::LBPHSFeatures::getNBlocks<uint16_t>, (arg("self"),arg("input")), "Return the number of blocks generated when extracting LBPHS Features on the given input")
    .def("get_n_blocks", (const int (bob::ip::LBPHSFeatures::*)(const blitz::Array<double,2>& src))&bob::ip::LBPHSFeatures::getNBlocks<double>, (arg("self"),arg("input")), "Return the number of blocks generated when extracting LBPHS Features on the given input")
    .def("__call__", &lbp_apply, (arg("self"),arg("input")), "Call an object of this type to extract LBP Histogram features.")
    ;
}
