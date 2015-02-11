#ifndef _MD5_BASEFRAME_HPP
#define _MD5_BASEFRAME_HPP

#include <boost/fusion/include/adapt_struct.hpp>


namespace md5 {

  template< typename fvec3 >
    struct baseframe_pair {
      fvec3 position;
      fvec3 orientation;
    };

} /* namespace md5 */

  BOOST_FUSION_ADAPT_TPL_STRUCT
  (
   (fvec3),
   (md5::baseframe_pair)(fvec3),
   (fvec3, position)
   (fvec3, orientation)
  )

#endif /* end of include guard: _MD5_BASEFRAME_HPP */
