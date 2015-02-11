#ifndef _MD5_MESH_PARSER_HPP
#define _MD5_MESH_PARSER_HPP


#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/phoenix_object.hpp>


#include <md5/parser/skipper.hpp>
#include <md5/types/meshfilecontent.hpp>

namespace md5 {

  namespace parser {
    

    namespace mesh {
      namespace fus   = boost::fusion;
      namespace pho   = boost::phoenix;
      namespace qi    = boost::spirit::qi;
      namespace ascii = boost::spirit::ascii;


      template< typename iterator, typename skipper_type, typename fvec2, typename fvec3 >
      struct meshfilecontent_grammar
        : qi::grammar< iterator, md5::meshfilecontent< fvec2, fvec3 >(), qi::locals< std::string >, skipper_type >
      {
        typedef meshfilecontent< fvec2, fvec3 >                content_type;

        typedef typename content_type::joint_type    joint_type;
        typedef typename content_type::joints_type   joints_type;

        typedef typename content_type::mesh_type     mesh_type;
        typedef typename content_type::meshes_type   meshes_type;

        typedef typename mesh_type::vertex_type       vertex_type;
        typedef typename mesh_type::weight_type       weight_type;


        meshfilecontent_grammar(): meshfilecontent_grammar::base_type( md5mesh, "md5mesh" )
        {
          using qi::on_error;
          using qi::fail;
          using qi::lit;
          using qi::lexeme;
          using qi::int_;
          using qi::float_;
          using ascii::char_;
          using ascii::string;
          using namespace qi::labels;

          using pho::construct;
          using pho::val;

          qstring_ %= lexeme['"' >> *(char_ - '"') >> '"'];

          fvector3_ %= float_ >> float_ >> float_;
          fvector2_ %= float_ >> float_;

          version_      %= lit("MD5Version") >> int_;
          commandline_  %= lit("commandline") >> qstring_;
          numjoints_    %= lit("numJoints") >> int_;
          nummeshes_    %= lit("numMeshes") >> int_;

          joints_       %= lit("joints")
                            >> '{'
                            >> *joint_
                            >> '}';

          joint_        %= qstring_
                            >> int_
                            >> '(' >> fvector3_ >> ')'
                            >> '(' >> fvector3_ >> ')';

          shader_       %= lit("shader") >> qstring_;

          numverts_     %= lit("numverts") >> int_;
          vertex_       %= lit("vert") 
                            >> int_ 
                            >> '(' >> fvector2_ >> ')' 
                            >> int_
                            >> int_;

          numtris_     %= lit("numtris") >> int_;

          triangle_     %= lit("tri") >> int_ >> int_ >> int_ >> int_; 

          numweights_   %= lit("numweights") >> int_;

          weight_       %= lit("weight")
                            >> int_
                            >> int_
                            >> float_
                            >> '(' >> fvector3_ >> ')';

          mesh_         %= lit("mesh")
                            >> '{'
                            >> shader_
                            >> numverts_
                            >> *vertex_
                            >> numtris_
                            >> *triangle_
                            >> numweights_
                            >> *weight_
                            >> '}';

          md5mesh       %= version_ 
                            >> commandline_
                            >> numjoints_
                            >> nummeshes_
                            >> joints_
                            >> *mesh_
                            >> qi::eoi;


          qstring_.name("quoted string");
          commandline_.name("commandline");
          shader_.name("shader");

          fvector3_.name("vec3f");
          fvector2_.name("vec2f");

          version_.name("version");
          numjoints_.name("numjoints");
          numtris_.name("numtris");
          nummeshes_.name("nummeshes");
          numverts_.name("numverts");
          numweights_.name("numweights");

          joint_.name("joint");
          joints_.name("joints");

          vertex_.name("vertex");
          weight_.name("weight");

          triangle_.name("triangle");
          
          mesh_.name("mesh");

          on_error<fail>
            (
             md5mesh
            , std::cout 
              << val("Error! Expecting ")
              << _4
              << val(" here: \"")
              << construct< std::string >(_3, _2)
              << val("\"")
              << std::endl
            );

#if HAVE_DEBUG
          debug(md5mesh);
          debug(version_);
          debug(commandline_);
          debug(shader_);
          debug(fvector3_);
          debug(fvector2_);
          debug(numjoints_);
          debug(numweights_);
          debug(nummeshes_);
          debug(numtris_);
          debug(numverts_);
          debug(joint_);
          debug(joints_);
          debug(vertex_);
          debug(weight_);
          debug(triangle_);
          debug(mesh_);
#endif

        } 


          qi::rule< iterator, content_type(), qi::locals< std::string >, skipper_type > md5mesh;

          qi::rule< iterator, std::string(),  skipper_type > qstring_, commandline_, shader_;
          
          qi::rule< iterator, fvec3(),  skipper_type > fvector3_;
          qi::rule< iterator, fvec2(),  skipper_type > fvector2_;

          qi::rule< iterator, int(),          skipper_type > version_, numjoints_, numtris_, nummeshes_, numverts_, numweights_;

          qi::rule< iterator, joint_type(),   skipper_type > joint_;
          qi::rule< iterator, joints_type(),  skipper_type > joints_;

          qi::rule< iterator, vertex_type(), skipper_type > vertex_;
          qi::rule< iterator, weight_type(),  skipper_type > weight_;

          qi::rule< iterator, triangle(),     skipper_type > triangle_;

          qi::rule< iterator, mesh_type(),    skipper_type > mesh_;

          

      };

      
    } /* namespace mesh */
    
  } /* namespace parser */
  
} /* namespace md5 */



#endif /* end of include guard: _MD5_MESH_PARSER_HPP */
