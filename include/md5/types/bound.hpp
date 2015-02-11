#ifndef _MD5_BOUND_HPP
#define _MD5_BOUND_HPP

#include <boost/fusion/include/adapt_struct.hpp>

namespace md5 { 
  template <typename vec3 >
    struct bound {
      vec3 bound_min;
      vec3 bound_max;
    };
} /* namespace md5 */

  BOOST_FUSION_ADAPT_TPL_STRUCT
  (
   (vec3),
   (md5::bound)(vec3),
   (vec3)(bound_min)
   (vec3)(bound_max)
  )




#endif /* end of include guard: _MD5_BOUND_HPP */
