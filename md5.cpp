
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>

#include <boost/fusion/include/adapt_struct.hpp>

#include <iostream>
#include <fstream>
#include <vector>

#include <md5/meshfile.hpp>
#include <md5/animfile.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

typedef sf::Vector2f vec2f;
typedef sf::Vector3f vec3f;


BOOST_FUSION_ADAPT_STRUCT
(
 sf::Vector2f,
 (float, x)
 (float, y)
)

BOOST_FUSION_ADAPT_STRUCT
(
 sf::Vector3f,
 (float, x)
 (float, y)
 (float, z)
)




/*
 * md5::meshfile< vec2i, vec3f > m("test.md5mesh");
 * md5::animfile< vec2i, vec3f > a("text.md5mesh");
 *
 * m.load() ? "geladen" : "failed";
 * m.parse() ? "geparsed" : "nicht geparsed";
 * md5::check_files(m,a);
 * md5::model model(m,a);
 *
 * model.valid() ? "jupp" : "nopp";
 *
 * 
 *
 *
 *
 */

int main(int argc, const char *argv[])
{
 
  md5::meshfile< vec2f, vec3f > mesh("boblampclean.md5mesh");
  md5::animfile< vec3f > anim("boblampclean.md5anim");

  std::cout << "[*] Meshfile" << std::endl;
  if (! mesh.load() ) {
      std::cout << "Could not load meshfile" << std::endl;
      return 1;
 }
  
 if (mesh.parse()) std::cout << "  => Parse succeded.." << std::endl;
 else              std::cout << "  => Parse failed.." << std::endl;


  std::cout << "[*] Animfile" << std::endl;
  if (! anim.load() ) {
      std::cout << "Could not load animfile" << std::endl;
      return 1;
 }
  
 if (anim.parse()) std::cout << "  => Parse succeded.." << std::endl;
 else              std::cout << "  => Parse failed.." << std::endl;





  std::cout << "testing my own md5 loader implementation :)" << std::endl;
  return 0;
}
