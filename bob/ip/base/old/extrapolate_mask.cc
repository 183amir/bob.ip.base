/**
 * @author Laurent El Shafey <Laurent.El-Shafey@idiap.ch>
 * @date Sun Jun 26 18:59:21 2011 +0200
 *
 * @brief Binds the extrapolateMask operation into python
 *
 * Copyright (C) 2011-2013 Idiap Research Institute, Martigny, Switzerland
 */

#include "ndarray.h"
#include <bob/ip/extrapolateMask.h>

using namespace boost::python;

template <typename T>
static void inner_extrapolateMask(bob::python::const_ndarray src,
  bob::python::ndarray img)
{
  blitz::Array<T,2> img_ = img.bz<T,2>();
  bob::ip::extrapolateMask<T>(src.bz<bool,2>(), img_);
}

static void extrapolate_mask(bob::python::const_ndarray src,
  bob::python::const_ndarray img)
{
  const bob::core::array::typeinfo& info = img.type();
  switch (info.dtype) {
    case bob::core::array::t_uint8: return inner_extrapolateMask<uint8_t>(src, img);
    case bob::core::array::t_uint16: return inner_extrapolateMask<uint16_t>(src, img);
    case bob::core::array::t_float64: return inner_extrapolateMask<double>(src, img);
    default: PYTHON_ERROR(TypeError, "mask extrapolation does not support type '%s'", info.str().c_str());
  }

}

void bind_ip_extrapolate_mask() {
  def("extrapolate_mask", &extrapolate_mask, (arg("src_mask"), arg("img")),
    "Extrapolate a 2D array/image, taking a boolean mask into account. The img argument is used both as an input and an output. Only values where the mask is set to false are extrapolated.");
}

