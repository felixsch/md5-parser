#ifndef _MD5_TRIANGLE_HPP
#define _MD5_TRIANGLE_HPP

#include <boost/fusion/include/adapt_struct.hpp>

namespace md5 {

  struct triangle {
    int index;
    int vert_index_0;
    int vert_index_1;
    int vert_index_2;
  };
}

BOOST_FUSION_ADAPT_STRUCT
  (
   md5::triangle,
   (int, index)
   (int, vert_index_0)
   (int, vert_index_1)
   (int, vert_index_2)
  )
   



#endif /* end of include guard: _MD5_TRIANGLE_HPP */
