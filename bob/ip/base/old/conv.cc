/**
 * @author Laurent El Shafey <Laurent.El-Shafey@idiap.ch>
 * @date Mon Aug 27 18:00:00 2012 +0200
 *
 * @brief Binds convolution options
 *
 * Copyright (C) 2011-2014 Idiap Research Institute, Martigny, Switzerland
 */

#include <boost/python.hpp>
#include <bob/sp/conv.h>

using namespace boost::python;

void bind_sp_convolution()
{
  enum_<bob::sp::Conv::SizeOption>("SizeOption")
    .value("Full", bob::sp::Conv::Full)
    .value("Same", bob::sp::Conv::Same)
    .value("Valid", bob::sp::Conv::Valid)
    ;
}
