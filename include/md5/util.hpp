#ifndef _MD5_UTIL_HPP
#define _MD5_UTIL_HPP

#include <boost/fusion/include/adapt_struct.hpp>


namespace md5 {
  namespace util {

    template< typename vec3_type, typename T >
      struct vec3_wrapper : public vec3_type<T>
    { };

  } /* namespace util */
} /* namespace md5 */

BOOST_FUSION_ADAPT_TPL_STRUCT
(
 (vec_type)(T),
 (md5::util::vec3_wrapper)(vec_type)(T),
 (T)(x)
 (T)(y)
 (T)(z)
 )

#endif /* end of include guard: _MD5_UTIL_HPP */
