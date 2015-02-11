#ifndef __MD5_ANIMFILE_HPP 
#define __MD5_ANIMFILE_HPP 1

#include <md5/error.hpp>

#include <md5/types/animfilecontent.hpp>
#include <md5/parser/skipper.hpp>
#include <md5/parser/anim.hpp>


#include <vector>
#include <fstream>


namespace md5 {
  template < typename fvec3 >
    class animfile {

      typedef animfilecontent< fvec3 > content_type;

      public: 
      animfile( const std::string& file ): m_loaded(false), m_parsed(false), m_filename(file) {}

      bool load() {
        std::ifstream stream( m_filename.c_str(), std::ios_base::in);

        if( !stream )
          throw std::runtime_error("Could not open file: "+ m_filename);

        stream.unsetf( std::ios_base::skipws );

        std::copy(
            std::istream_iterator< char >( stream ),
            std::istream_iterator< char >( ),
            std::back_inserter( m_raw_content )
            );
        m_loaded = true;
        return true;
      }

      bool parse() {
        using boost::spirit::ascii::space;
        typedef md5::parser::md5_skipper< std::string::const_iterator > skipper_type;
        typedef md5::parser::anim::animfilecontent_grammar< std::string::const_iterator, skipper_type, fvec3 > grammar_type;


        skipper_type skipper;
        grammar_type grammar;
        // TODO: error handling here :)lo
        std::string::const_iterator begin = m_raw_content.begin();
        std::string::const_iterator end = m_raw_content.end();
        return phrase_parse( begin, end, grammar, skipper, m_content); 
      }

      const content_type& get_content() {
        return m_content;
      }

      const content_type& operator()() {
        return m_content;
      }

      protected:

      bool m_loaded;
      bool m_parsed;

      std::string m_filename;
      std::string m_raw_content;

      content_type m_content;
    };
}



#endif
