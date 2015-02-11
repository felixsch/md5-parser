#ifndef _MD5_BOUND_HPP
#define _MD5_BOUND_HPP

#include <boost/fusion/include/adapt_struct.hpp>

namespace md5 { 
  template <typename fvec3 >
    struct bound {
      fvec3 bound_min;
      fvec3 bound_max;
    };
} /* namespace md5 */

  BOOST_FUSION_ADAPT_TPL_STRUCT
  (
   (fvec3),
   (md5::bound)(fvec3),
   (fvec3, bound_min)
   (fvec3, bound_max)
  )




#endif /* end of include guard: _MD5_BOUND_HPP */
