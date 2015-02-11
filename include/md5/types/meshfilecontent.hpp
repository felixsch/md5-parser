#ifndef _MD5_MESHFILETCONTENT_HPP
#define _MD5_MESHFILETCONTENT_HPP

#include <boost/fusion/include/adapt_struct.hpp>

#include <md5/types/mesh.hpp>
#include <md5/types/joint.hpp>

#include <vector>
#include <string>


namespace md5 {
 
  template< typename fvec2, typename fvec3 > 
    struct meshfilecontent {

    typedef mesh< fvec2, fvec3 >        mesh_type;
    typedef joint< fvec3 >             joint_type;

    typedef std::vector< mesh_type >  meshes_type;
    typedef std::vector< joint_type > joints_type;

    int version;
    std::string commandline;

    int num_joints;
    int num_meshes;

    joints_type joints;
    meshes_type meshes;

    };
  
} /* namespace md5 */

#include <md5/types/meshfilecontent_fusion.inl>
#endif /* end of include guard: _MD5_MESHFILETYPE_HPP */



