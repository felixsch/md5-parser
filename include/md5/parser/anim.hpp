#ifndef _MD5_ANIM_PARSER_HPP
#define _MD5_ANIM_PARSER_HPP


#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/phoenix_object.hpp>


#include <md5/parser/skipper.hpp>
#include <md5/types/animfilecontent.hpp>
/* .md4anim skeleton
 *
 *
 *MD5Version <int:version>
 *commandline <string:commandline>
 *
 *numFrames <int:numFrames>
 *numJoints <int:numJoints>
 *frameRate <int:frameRate>
 *numAnimatedComponents <int:numAnimatedComponents>
 *
 *hierarchy {
 *  <string:jointName> <int:parentIndex> <int:flags> <int:startIndex>
 *  ...
 *}
 *
 *bounds {
 *  ( vec3:boundMin ) ( vec3:boundMax )
 *  ...
 *}
 *
 *baseframe {
 *  ( vec3:position ) ( vec3:orientation )
 *  ...
 *}
 *
 *frame <int:frameNum> {
 *  <float:frameData> ...
 *}
 *
 * ...
 */

namespace md5 {
  namespace parser {

    namespace anim {
      namespace fus = boost::fusion;
      namespace pho = boost::phoenix;
      namespace qi  = boost::spirit::qi;
      namespace ascii = boost::spirit::ascii;

      template <typename iterator, typename skipper_type, typename fvec3 >
        struct animfilecontent_grammar
        : qi::grammar< iterator, md5::animfilecontent< fvec3 >(), qi::locals< std::string >, skipper_type >
        {
          typedef animfilecontent< fvec3 >      content_type;

          typedef typename content_type::bound_type bound_type;
          typedef typename content_type::bounds_type bounds_type;

          typedef typename content_type::baseframe_pair_type baseframe_pair_type;
          typedef typename content_type::baseframe_type baseframe_type;

          typedef typename content_type::frame_type   frame_type;
          typedef typename content_type::frames_type  frames_type;

          typedef typename content_type::hierarchy_section_type hierarchy_section_type;
          typedef typename content_type::hierarchy_type hierarchy_type;

          animfilecontent_grammar(): animfilecontent_grammar::base_type( anim, "anim" )
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

            fvector3_ %= '(' >> float_ >> float_ >> float_ >> ')';

            commandline_ %= lit("commandline") >> qstring_;

            version_ %= lit("MD5Version") >> int_;
            numframes_ %= lit("numFrames") >> int_;
            numjoints_ %= lit("numJoints") >> int_;

            framerate_ %= lit("frameRate") >> int_;

            numanimatedcomp_ %= lit("numAnimatedComponents") >> int_;

            hierarchy_section_ %= qstring_ >> int_ >> int_ >> int_;

            hierarchy_ %= lit("hierarchy")
              >> '{'
              >> *hierarchy_section_
              >> '}';

            bound_ = fvector3_ >> fvector3_;

            bounds_ = lit("bounds") 
              >> "{"
              >> *bound_
              >> "}";

            baseframe_pair_ = fvector3_ >> fvector3_;
            baseframe_ = lit("baseframe")
              >> '{'
              >> *baseframe_pair_
              >> '}';

            frame_ = lit("frame")
              >> int_
              >> '{'
              >> *float_
              >> '}';

            anim = version_
              >> commandline_
              >> numframes_
              >> numjoints_
              >> framerate_
              >> numanimatedcomp_
              >> hierarchy_
              >> bounds_
              >> baseframe_
              >> *frame_
              >> qi::eoi;

            qstring_.name("quoted string");
            fvector3_.name("commandline");
            version_.name("version");
            numjoints_.name("numjoints");
            numframes_.name("numframes");
            framerate_.name("framerate");
            numanimatedcomp_.name("numanimatedcomponents");
            hierarchy_section_.name("hierarchy_section");
            hierarchy_.name("hierarchy");
            bound_.name("bound");
            bounds_.name("bounds");
            baseframe_pair_.name("baseframe pair");
            baseframe_.name("baseframe");
            frame_.name("frame");

            // TODO: Add real error handling 
            on_error<fail>
              (
               anim
               , std::cout
               << val("Error! Exception ")
               << _4
               << val(" here: \"")
               << construct< std::string >(_3,_2)
               << val("\"")
               << std::endl
              );

#if HAVE_DEBUG
            debug(qstring_);
            debug(commandline_);
            debug(fvector3_);
            debug(version_);
            debug(numjoints_);
            debug(numframes_);
            debug(framerate_);
            debug(numanimatedcomp_);
            debug(hierarchy_section_);
            debug(hierarchy_);
            debug(bound_);
            debug(bounds_);
            debug(baseframe_pair_);
            debug(baseframe_);
            debug(frame_);
#endif
          }
          qi::rule< iterator, content_type(), qi::locals< std::string >, skipper_type > anim;

          qi::rule< iterator, std::string(), skipper_type > qstring_, commandline_;

          qi::rule< iterator, fvec3(), skipper_type> fvector3_;

          qi::rule< iterator, int(), skipper_type > version_, numjoints_, numframes_, framerate_, numanimatedcomp_;

          qi::rule< iterator, hierarchy_section_type(), skipper_type > hierarchy_section_;
          qi::rule< iterator, hierarchy_type(), skipper_type > hierarchy_;

          qi::rule< iterator, bound_type(), skipper_type > bound_;
          qi::rule< iterator, bounds_type(), skipper_type > bounds_;

          qi::rule< iterator, baseframe_pair_type(), skipper_type > baseframe_pair_;
          qi::rule< iterator, baseframe_type(), skipper_type > baseframe_;

          qi::rule< iterator, frame_type(), skipper_type > frame_;
        };
     }
  }
}


#endif
