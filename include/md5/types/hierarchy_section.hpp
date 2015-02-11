#ifndef _MD5_HIERACHY_HPP
#define _MD5_HIERACHY_HPP


#include <boost/fusion/include/adapt_struct.hpp>


namespace md5 {
  
 struct hierarchy_section
  {
    std::string joint_name;
    int parent_index;
    int flags;
    int start_index;
  };
} /* namespace md5 */

BOOST_FUSION_ADAPT_STRUCT
  (
   md5::hierarchy_section,
   (std::string, joint_name)
   (int, parent_index)
   (int, flags)
   (int, start_index)
  )

#endif /* end of include guard: _MD5_HIERACHY_HPP */
