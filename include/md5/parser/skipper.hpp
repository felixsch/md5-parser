#ifndef _MD5_SKIPPER_HPP
#define _MD5_SKIPPER_HPP

#include <boost/spirit/include/qi.hpp>


namespace md5 {
  namespace parser {
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

  template< typename iterator >
    struct md5_skipper : public qi::grammar< iterator > {

      md5_skipper() : md5_skipper::base_type( skip, "skip" ) {
        using qi::lit;
      
      skip = ascii::space | ("//" >> *(ascii::char_ - qi::eol) >> qi::eol ) | qi::eol;
    }
     qi::rule< iterator > skip;
    }; 
  } /* namespace parser */
  
} /* namespace md5 */



#endif /* end of include guard: _MD5_SKIPPER_HPP */
