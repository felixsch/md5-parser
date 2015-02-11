#ifndef _MD5_WEIGHT_HPP
#define _MD5_WEIGHT_HPP

#include <boost/fusion/include/adapt_struct.hpp>

namespace md5 {
  template< typename fvec3 > struct weight {
    int index;
    int joint_index;
    float weight_bias;
    fvec3 weight_position;
  };
}

BOOST_FUSION_ADAPT_TPL_STRUCT
  (
   (fvec3),
   (md5::weight) (fvec3),
   (int, index)
   (int, joint_index)
   (float, weight_bias)
   (fvec3, weight_position)
  )

#endif /* end of include guard: _MD5_WEIGHT_HPP */
