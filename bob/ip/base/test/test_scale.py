#!/usr/bin/env python
# vim: set fileencoding=utf-8 :
# Laurent El Shafey <Laurent.El-Shafey@idiap.ch>
# Tue Aug 27 12:40:18 CEST 2013
#
# Copyright (C) 2011-2014 Idiap Research Institute, Martigny, Switzerland

"""Test the Scaling function
"""

import numpy
from .. import scale, get_scaled_output_shape

src = numpy.array([[  0,   2,   4,   6],
                   [  2,   4,   8,  12],
                   [  4,   8,  16,  24],
                   [  8,  16,  32,  48]], dtype=numpy.uint8)

# Reference values
dst_ref_2by2 = numpy.array([[0, 6], [8, 48]], dtype=numpy.float64)
dst_ref_8by8 = numpy.array([[  0.        ,  0.85714286,  1.71428571,  2.57142857,  3.42857143,  4.28571429,  5.14285714,  6.        ],
                            [  0.85714286,  1.71428571,  2.57142857,  3.67346939,  4.89795918,  6.12244898,  7.34693878,  8.57142857],
                            [  1.71428571,  2.57142857,  3.42857143,  4.7755102 ,  6.36734694,  7.95918367,  9.55102041, 11.14285714],
                            [  2.57142857,  3.67346939,  4.7755102 ,  6.6122449 ,  8.81632653, 11.02040816, 13.2244898 , 15.42857143],
                            [  3.42857143,  4.89795918,  6.36734694,  8.81632653, 11.75510204, 14.69387755, 17.63265306, 20.57142857],
                            [  4.57142857,  6.53061224,  8.48979592, 11.75510204, 15.67346939, 19.59183673, 23.51020408, 27.42857143],
                            [  6.28571429,  8.97959184, 11.67346939, 16.16326531, 21.55102041, 26.93877551, 32.32653061, 37.71428571],
                            [  8.        , 11.42857143, 14.85714286, 20.57142857, 27.42857143, 34.28571429, 41.14285714, 48.        ]], dtype=numpy.float64)

# Precision when checking correctness
eps = 1e-7

def test_scale_regular():

  # Use scaling where both output and input are arguments
  dst_2by2 = numpy.zeros(shape=(2,2), dtype=numpy.float)
  scale(src, dst_2by2)
  assert numpy.allclose(dst_2by2, dst_ref_2by2, atol=eps)

  dst_8by8 = numpy.zeros(shape=(8,8), dtype=numpy.float)
  scale(src, dst_8by8)
  assert numpy.allclose(dst_8by8, dst_ref_8by8, atol=eps)

def test_scale_factor():

  # Use scaling where the output size is provided as a scaling factor
  dst_2by2 = numpy.zeros(shape=(2,2), dtype=numpy.float)
  dst_2by2 = scale(src, 0.5)
  assert numpy.allclose(dst_2by2, dst_ref_2by2, atol=eps)

  dst_8by8 = numpy.zeros(shape=(8,8), dtype=numpy.float)
  dst_8by8 = scale(src, 2.)
  assert numpy.allclose(dst_8by8, dst_ref_8by8, atol=eps)

def test_get_scaled_output_shape():

  shape_2by2 = get_scaled_output_shape(src, 0.5)
  assert shape_2by2 == (2,2)
  shape_8by8 = get_scaled_output_shape(src, 2.)
  assert shape_8by8 == (8,8)
