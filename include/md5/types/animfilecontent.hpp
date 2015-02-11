#ifndef __MD5_ANIMFILECONTENT_HPP
#define __MD5_ANIMFILECONTENT_HPP 1

#include <boost/fusion/include/adapt_struct.hpp>

#include <md5/types/bounds.hpp>
#include <md5/types/baseframe_pair.hpp>
#include <md5/types/hierarchy_section.hpp>
#include <md5/types/frame.hpp>

#include <vector>
#include <string>


namespace md5 {
 
  template< typename fvec3 > 
    struct animfilecontent {

    typedef bound< fvec3 > bound_type;
    typedef std::vector< bound_type > bounds_type;

    
    typedef baseframe_pair< fvec3 > baseframe_pair_type;
    typedef std::vector< baseframe_pair_type > baseframe_type;

    typedef frame frame_type;
    typedef std::vector< frame_type > frames_type;

    typedef hierarchy_section hierarchy_section_type;
    typedef std::vector< hierarchy_section_type > hierarchy_type;

    int version;
    std::string commandline;

    int num_frames;
    int num_joints;

    int framerate;

    int animated_components;

    hierarchy_type hierarchy;

    bounds_type    bounds;

    baseframe_type baseframe;

    frames_type    frames;
    };

}

BOOST_FUSION_ADAPT_TPL_STRUCT
  (
   (fvec3),
   (md5::animfilecontent)(fvec3),
   (int, version)
   (std::string, commandline)
   (int, num_frames)
   (int, num_joints)
   (int, framerate)
   (int, animated_components)
   (typename md5::animfilecontent< fvec3 >::hierarchy_type, hierarchy)
   (typename md5::animfilecontent< fvec3 >::bounds_type, bounds)
   (typename md5::animfilecontent< fvec3 >::baseframe_type, baseframe)
   (typename md5::animfilecontent< fvec3 >::frames_type, frames)
  )
   



    

#endif
