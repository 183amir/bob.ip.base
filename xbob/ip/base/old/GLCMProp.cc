/**
 * @author Ivana Chingovska <ivana.chingovska@idiap.ch>
 * @date Thu Jan 31 17:52:40 CET 2013
 *
 * @brief Binds the GLCMProp class to python
 *
 * Copyright (C) 2011-2014 Idiap Research Institute, Martigny, Switzerland
 */

#include "ndarray.h"
#include <bob/ip/GLCMProp.h>

using namespace boost::python;

static const char* glcmprop_doc = "Objects of this class, after configuration, can compute a number of texture properties on a Grey-Level Co-occurence Matrix (GLCM). \n List of references: \n [1] R. M. Haralick, K. Shanmugam, I. Dinstein; \"Textural Features for Image calssification\", in IEEE Transactions on Systems, Man and Cybernetics, vol.SMC-3, No. 6, p. 610-621. \n [2] L. Soh and C. Tsatsoulis; Texture Analysis of SAR Sea Ice Imagery Using Gray Level Co-Occurrence Matrices, IEEE Transactions on Geoscience and Remote Sensing, vol. 37, no. 2, March 1999. \n [3] D A. Clausi, An analysis of co-occurrence texture statistics as a function of grey level quantization, Can. J. Remote Sensing, vol. 28, no.1, pp. 45-62, 2002 \n [4] http://murphylab.web.cmu.edu/publications/boland/boland_node26.html \n [5] http://www.mathworks.com/matlabcentral/fileexchange/22354-glcmfeatures4-m-vectorized-version-of-glcmfeatures1-m-with-code-changes \n [6] http://www.mathworks.ch/ch/help/images/ref/graycoprops.html\n\n";


static void call_angular_second_moment_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.angular_second_moment(input.bz<double,3>(), output_);
}

static object call_angular_second_moment_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.angular_second_moment(input.bz<double,3>(), output_);
  return output.self();
}


static void call_energy_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.energy(input.bz<double,3>(), output_);
}

static object call_energy_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.energy(input.bz<double,3>(), output_);
  return output.self();
}


static void call_variance_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.variance(input.bz<double,3>(), output_);
}

static object call_variance_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.variance(input.bz<double,3>(), output_);
  return output.self();
}


static void call_contrast_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.contrast(input.bz<double,3>(), output_);
}

static object call_contrast_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.contrast(input.bz<double,3>(), output_);
  return output.self();
}


static void call_auto_correlation_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.auto_correlation(input.bz<double,3>(), output_);
}

static object call_auto_correlation_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.auto_correlation(input.bz<double,3>(), output_);
  return output.self();
}


static void call_correlation_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.correlation(input.bz<double,3>(), output_);
}

static object call_correlation_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.correlation(input.bz<double,3>(), output_);
  return output.self();
}

static void call_correlation_m_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.correlation_m(input.bz<double,3>(), output_);
}

static object call_correlation_m_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.correlation_m(input.bz<double,3>(), output_);
  return output.self();
}

static void call_inv_diff_mom_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.inv_diff_mom(input.bz<double,3>(), output_);
}

static object call_inv_diff_mom_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.inv_diff_mom(input.bz<double,3>(), output_);
  return output.self();
}

static void call_sum_avg_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.sum_avg(input.bz<double,3>(), output_);
}

static object call_sum_avg_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.sum_avg(input.bz<double,3>(), output_);
  return output.self();
}

static void call_sum_var_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.sum_var(input.bz<double,3>(), output_);
}

static object call_sum_var_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.sum_var(input.bz<double,3>(), output_);
  return output.self();
}

static void call_sum_entropy_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.sum_entropy(input.bz<double,3>(), output_);
}

static object call_sum_entropy_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.sum_entropy(input.bz<double,3>(), output_);
  return output.self();
}


static void call_entropy_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.entropy(input.bz<double,3>(), output_);
}

static object call_entropy_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.entropy(input.bz<double,3>(), output_);
  return output.self();
}

static void call_diff_var_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.diff_var(input.bz<double,3>(), output_);
}

static object call_diff_var_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.diff_var(input.bz<double,3>(), output_);
  return output.self();
}

static void call_diff_entropy_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.diff_entropy(input.bz<double,3>(), output_);
}

static object call_diff_entropy_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.diff_entropy(input.bz<double,3>(), output_);
  return output.self();
}


static void call_dissimilarity_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.dissimilarity(input.bz<double,3>(), output_);
}

static object call_dissimilarity_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.dissimilarity(input.bz<double,3>(), output_);
  return output.self();
}


static void call_homogeneity_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.homogeneity(input.bz<double,3>(), output_);
}

static object call_homogeneity_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.homogeneity(input.bz<double,3>(), output_);
  return output.self();
}

static void call_cluster_prom_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.cluster_prom(input.bz<double,3>(), output_);
}

static object call_cluster_prom_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.cluster_prom(input.bz<double,3>(), output_);
  return output.self();
}

static void call_cluster_shade_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.cluster_shade(input.bz<double,3>(), output_);
}

static object call_cluster_shade_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.cluster_shade(input.bz<double,3>(), output_);
  return output.self();
}

static void call_max_prob_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.max_prob(input.bz<double,3>(), output_);
}

static object call_max_prob_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.max_prob(input.bz<double,3>(), output_);
  return output.self();
}

static void call_inf_meas_corr1_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.inf_meas_corr1(input.bz<double,3>(), output_);
}

static object call_inf_meas_corr1_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.inf_meas_corr1(input.bz<double,3>(), output_);
  return output.self();
}

static void call_inf_meas_corr2_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.inf_meas_corr2(input.bz<double,3>(), output_);
}

static object call_inf_meas_corr2_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.inf_meas_corr2(input.bz<double,3>(), output_);
  return output.self();
}


static void call_inv_diff_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.inv_diff(input.bz<double,3>(), output_);
}

static object call_inv_diff_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.inv_diff(input.bz<double,3>(), output_);
  return output.self();
}


static void call_inv_diff_norm_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.inv_diff_norm(input.bz<double,3>(), output_);
}

static object call_inv_diff_norm_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.inv_diff_norm(input.bz<double,3>(), output_);
  return output.self();
}

static void call_inv_diff_mom_norm_c(const bob::ip::GLCMProp& op, bob::python::const_ndarray input, bob::python::ndarray output)
{
  blitz::Array<double,1> output_ = output.bz<double,1>();
  return op.inv_diff_mom_norm(input.bz<double,3>(), output_);
}

static object call_inv_diff_mom_norm_p(const bob::ip::GLCMProp& op, bob::python::const_ndarray input)
{
  const blitz::TinyVector<int,1> sh = op.get_prop_shape(input.bz<double,3>());
  bob::python::ndarray output(bob::core::array::t_float64, sh(0));
  blitz::Array<double,1> output_ = output.bz<double,1>();
  op.inv_diff_mom_norm(input.bz<double,3>(), output_);
  return output.self();
}


void bind_ip_glcmprop()
{
  class_<bob::ip::GLCMProp, boost::shared_ptr<bob::ip::GLCMProp>, boost::noncopyable>("GLCMProp", glcmprop_doc, no_init)
    .def(init<>((arg("self")), "Constructor"))
    .def(init<const bob::ip::GLCMProp&>((arg("self"), arg("other")), "Copy constructs a GLCMProp operator"))

    .def("get_glcmprop_shape", &bob::ip::GLCMProp::get_prop_shape, (arg("self"), arg("input")), "Get the shape of the GLCM properties vector given the input GLCM. For each offset of the GLCM, one field of the output vector is filled.")
    .def("angular_second_moment", &call_angular_second_moment_c, (arg("self"),arg("input"), arg("output")), "Extract Angular Second Moment property of the input GLCM (see ref [1])")
    .def("angular_second_moment", &call_angular_second_moment_p, (arg("self"),arg("input")), "Extract Angular Second Moment property of the input GLCM (see ref [1])")
    .def("energy", &call_energy_c, (arg("self"),arg("input"), arg("output")), "Extract Energy property of the input GLCM (see ref [4])")
    .def("energy", &call_energy_p, (arg("self"),arg("input")), "Extract Energy property of the input GLCM (see ref [4])")
    .def("variance", &call_variance_c, (arg("self"),arg("input"), arg("output")), "Extract Variance property of the input GLCM (see ref [1])")
    .def("variance", &call_variance_p, (arg("self"),arg("input")), "Extract Variance property of the input GLCM (see ref [1])")
    .def("contrast", &call_contrast_c, (arg("self"),arg("input"), arg("output")), "Extract Contrast property of the input GLCM (see ref [1])")
    .def("contrast", &call_contrast_p, (arg("self"),arg("input")), "Extract Contrast property of the input GLCM (see ref [1])")
    .def("auto_correlation", &call_auto_correlation_c, (arg("self"),arg("input"), arg("output")), "Extract Auto-Correlation property of the input GLCM (see ref [2])")
    .def("auto_correlation", &call_auto_correlation_p, (arg("self"),arg("input")), "Extract Auto-Correlation property of the input GLCM (see ref [2])")
    .def("correlation", &call_correlation_c, (arg("self"),arg("input"), arg("output")), "Extract Correlation property of the input GLCM (see ref [1])")
    .def("correlation", &call_correlation_p, (arg("self"),arg("input")), "Extract Correlation property of the input GLCM (see ref [1])")
    .def("correlation_m", &call_correlation_m_c, (arg("self"),arg("input"), arg("output")), "Extract Correlation property of the input GLCM as in MATLAB Image Processing Toolbox method graycoprops() (see ref [6])")
    .def("correlation_m", &call_correlation_m_p, (arg("self"),arg("input")), "Extract Correlation property of the input GLCM as in MATLAB Image Processing Toolbox method graycoprops() (see ref [6])")
    .def("inv_diff_mom", &call_inv_diff_mom_c, (arg("self"),arg("input"), arg("output")), "Extract Inverse Difference moment property of the input GLCM (see ref [1])")
    .def("inv_diff_mom", &call_inv_diff_mom_p, (arg("self"),arg("input")), "Extract Inverse Difference moment property of the input GLCM (see ref [1])")
    .def("sum_avg", &call_sum_avg_c, (arg("self"),arg("input"), arg("output")), "Extract Sum Average property of the input GLCM (see ref [1])")
    .def("sum_avg", &call_sum_avg_p, (arg("self"),arg("input")), "Extract Sum Average property of the input GLCM (see ref [1])")
    .def("sum_var", &call_sum_var_c, (arg("self"),arg("input"), arg("output")), "Extract Sum Variance property of the input GLCM (see ref [1])")
    .def("sum_var", &call_sum_var_p, (arg("self"),arg("input")), "Extract Sum Variance property of the input GLCM (see ref [1])")
    .def("sum_entropy", &call_sum_entropy_c, (arg("self"),arg("input"), arg("output")), "Extract Sum Entropy property of the input GLCM (see ref [1])")
    .def("sum_entropy", &call_sum_entropy_p, (arg("self"),arg("input")), "Extract Sum Entropy property of the input GLCM (see ref [1])")
    .def("entropy", &call_entropy_c, (arg("self"),arg("input"), arg("output")), "Extract Entropy property of the input GLCM (see ref [1])")
    .def("entropy", &call_entropy_p, (arg("self"),arg("input")), "Extract Entropy property of the input GLCM (see ref [1])")
    .def("diff_var", &call_diff_var_c, (arg("self"),arg("input"), arg("output")), "Extract Difference Variance property of the input GLCM (see ref [4])")
    .def("diff_var", &call_diff_var_p, (arg("self"),arg("input")), "Extract Difference Variance property of the input GLCM (see ref [4])")
    .def("diff_entropy", &call_diff_entropy_c, (arg("self"),arg("input"), arg("output")), "Extract Difference Entropy property of the input GLCM (see ref [1])")
    .def("diff_entropy", &call_diff_entropy_p, (arg("self"),arg("input")), "Extract Difference Entropy property of the input GLCM (see ref [1])")
    .def("dissimilarity", &call_dissimilarity_c, (arg("self"),arg("input"), arg("output")), "Extract Dissimilarity property of the input GLCM (see ref [4])")
    .def("dissimilarity", &call_dissimilarity_p, (arg("self"),arg("input")), "Extract Dissimilarity property of the input GLCM (see ref [4])")
    .def("homogeneity", &call_homogeneity_c, (arg("self"),arg("input"), arg("output")), "Extract Homogeneity property of the input GLCM (see ref [6])")
    .def("homogeneity", &call_homogeneity_p, (arg("self"),arg("input")), "Extract Homogeneity property of the input GLCM (see ref [6])")
    .def("cluster_prom", &call_cluster_prom_c, (arg("self"),arg("input"), arg("output")), "Extract Cluster Prominance property of the input GLCM (see ref [2])")
    .def("cluster_prom", &call_cluster_prom_p, (arg("self"),arg("input")), "Extract Cluster Prominance of the input GLCM (see ref [2])")
    .def("cluster_shade", &call_cluster_shade_c, (arg("self"),arg("input"), arg("output")), "Extract Cluster Shade property of the input GLCM (see ref [2])")
    .def("cluster_shade", &call_cluster_shade_p, (arg("self"),arg("input")), "Extract Cluster Shade property of the input GLCM (see ref [2])")
    .def("max_prob", &call_max_prob_c, (arg("self"),arg("input"), arg("output")), "Extract Maximum Probability property of the input GLCM (see ref [2])")
    .def("max_prob", &call_max_prob_p, (arg("self"),arg("input")), "Extract Maximum Probability property of the input GLCM (see ref [2])")
    .def("inf_meas_corr1", &call_inf_meas_corr1_c, (arg("self"),arg("input"), arg("output")), "Extract Information Measure of Correlation 1 property of the input GLCM (see ref [1])")
    .def("inf_meas_corr1", &call_inf_meas_corr1_p, (arg("self"),arg("input")), "Extract Information Measure of Correlation 1 property of the input GLCM (see ref [1])")
    .def("inf_meas_corr2", &call_inf_meas_corr2_c, (arg("self"),arg("input"), arg("output")), "Extract Information Measure of Correlation 2 property of the input GLCM (see ref [1])")
    .def("inf_meas_corr2", &call_inf_meas_corr2_p, (arg("self"),arg("input")), "Extract Information Measure of Correlation 2 property of the input GLCM (see ref [1])")
    .def("inv_diff", &call_inv_diff_c, (arg("self"),arg("input"), arg("output")), "Extract Inverse Difference property of the input GLCM (see ref [3]) - same as the Homogeneity property")
    .def("inv_diff", &call_inv_diff_p, (arg("self"),arg("input")), "Extract Inverse Difference property of the input GLCM (see ref [3]) - same as the Homogeneity property")
    .def("inv_diff_norm", &call_inv_diff_norm_c, (arg("self"),arg("input"), arg("output")), "Extract Inverse Difference Normalized property of the input GLCM (see ref [3]) - same as the Homogeneity property")
    .def("inv_diff_norm", &call_inv_diff_norm_p, (arg("self"),arg("input")), "Extract Inverse Difference Normalized property of the input GLCM (see ref [3]) - same as the Homogeneity property")
    .def("inv_diff_mom_norm", &call_inv_diff_mom_norm_c, (arg("self"),arg("input"), arg("output")), "Extract Inverse Difference Moment Normalized property of the input GLCM (see ref [3]) - same as the Homogeneity property")
    .def("inv_diff_mom_norm", &call_inv_diff_mom_norm_p, (arg("self"),arg("input")), "Extract Inverse Difference Moment Normalized property of the input GLCM (see ref [3]) - same as the Homogeneity property")
    ;
}
