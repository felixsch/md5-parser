#ifndef _MD5_MESH_HPP
#define _MD5_MESH_HPP

#include <boost/fusion/include/adapt_struct.hpp>

#include <md5/types/vertex.hpp>
#include <md5/types/weight.hpp>
#include <md5/types/triangle.hpp>

#include <string>
#include <vector>

namespace md5 {
  
  template< typename fvec2, typename fvec3 >
    struct mesh {

      typedef vertex< fvec2 > vertex_type;
      typedef weight< fvec3 > weight_type;

      typedef std::vector< vertex_type > verticies_type;
      typedef std::vector< weight_type > weights_type;
      typedef std::vector< triangle >       triangles_type;

      std::string shader_name;
      int num_verts;
      verticies_type verticies;
      int num_tris;
      triangles_type triangles;
      int num_weights;
      weights_type   weights;
    };
} /* namespace md5 */


BOOST_FUSION_ADAPT_TPL_STRUCT
  (
   (fvec2)(fvec3),
   (md5::mesh)(fvec2)(fvec3),
   (std::string, shader_name)
   (int, num_verts)
   (std::vector< md5::vertex< fvec2 > >, verticies)
   (int, num_tris)
   (std::vector< md5::triangle >, triangles)
   (int, num_weights)
   (std::vector< md5::weight< fvec3 > >, weights)
  )

#endif /* end of include guard: _MD5_MESH_HPP */
