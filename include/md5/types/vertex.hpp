#ifndef _MD5_VERTEXT_HPP
#define _MD5_VERTEXT_HPP

#include <boost/fusion/include/adapt_struct.hpp>

namespace md5 {
 template< typename ivec2 > struct vertex {
    
    int index;
    ivec2 texcoords;
    int start_weight;
    int weight_count;
  };
}

BOOST_FUSION_ADAPT_TPL_STRUCT
  (
    (ivec2),
    (md5::vertex) (ivec2),
    (int, index)
    (ivec2, texcoords)
    (int, start_weight)
    (int, weight_count)
  )




#endif /* end of include guard: _MD5_VERTEXT_HPP */
