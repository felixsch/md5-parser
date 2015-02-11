# A basic md5 mesh file parser

> This snippet is just a test and bleeding alpha. Use with care!

A header only md5 (.md5mesh / .md5anim) parser using _boost::spirit_
The md5 format was invented by Id Tech. The format supports triangular meshes and skeletal animations.

##Requirements

> boost (libboost-dev / boost-devel) — [http://boost.org](www.boost.org)

`This snippet uses the spirit, fusion and filesystem module of boost`

##Usage

Copy into your project and include it.

`gcc project.cpp -o project -I<include/to/md5/include>`

The parser parses into two data structures `md5meshfile` and `md5animfile`.
```c++
template <typename fvec3> class md5animefile;
template <typename ivec2, typename fvec3> class md5meshfile;
```
The template parameters must be `boost::fusion` compatible. See [Boost Fusion Adapted functionality](http://www.boost.org/doc/libs/1_57_0/libs/fusion/doc/html/fusion/adapted.html) for more informations.

- __fvec3__ — A 3-dimensional vector supporting floats
- __ivec2__ — A 2-dimensional vector supporting integers

#Example

```c++
// Using SMFL Vector classes

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


int main(int argc, const char *argv[])
{

  md5::meshfile< vec2f, vec3f > mesh("example.md5mesh");
  md5::animfile< vec3f > anim("example.md5anim");
  
  if( !mesh.load() || !anim.load() ) {
    std::cout << "Loading mesh and/or anim file" << std::endl;
    return 1;
  }

  if( !mesh.parse() || !anim.parse() ) {
    std::cout << "Parsing mesh and/or anim file" << std::endl;
    return 1;
  }

  // ... make something usefull ..

  return 0;
}
```




