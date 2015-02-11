#ifndef _MD5_JOIN_HPP
#define _MD5_JOIN_HPP

#include <boost/fusion/include/adapt_struct.hpp>

#include <string>

namespace md5 {
  template< typename vec3 > struct joint {
    
    std::string name;
    int parent_id;

    vec3 position;
    vec3 orientation;
  };
}

BOOST_FUSION_ADAPT_TPL_STRUCT
  (
    (vec3),
    (md5::joint)(vec3),
    (std::string, name)
    (int, parent_id)
    (vec3, position)
    (vec3, orientation)
  )










#endif /* end of include guard: _MD5_JOIN_HPP */
