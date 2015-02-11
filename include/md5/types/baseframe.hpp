#ifndef _MD5_BASEFRAME_HPP
#define _MD5_BASEFRAME_HPP

#include <boost/fusion/include/adapt_struct.hpp>


namespace md5 {

  template< typename vec3 >
    struct baseframe_item {
      vec3 position;
      vec3 orientation;
    };

} /* namespace md5 */

  BOOST_FUSION_ADAPT_TPL_STRUCT
  (
   (vec3),
   (md5::baseframe_item)(vec3),
   (vec3, position)
   (vec3, orientation)
  )

#endif /* end of include guard: _MD5_BASEFRAME_HPP */
