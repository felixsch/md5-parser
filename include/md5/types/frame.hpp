#ifndef _MD5_FRAME_HPP
#define _MD5_FRAME_HPP

#include <boost/fusion/include/adapt_struct.hpp>

#include <vector>

namespace md5 {
  struct frame {
    int index;
    std::vector< float > data;
  };
} /* namespace md5 */

BOOST_FUSION_ADAPT_STRUCT
(
 md5::frame,
 (int, index)
 (std::vector< float >, data)
 )

#endif /* end of include guard: _MD5_FRAME_HPP */
