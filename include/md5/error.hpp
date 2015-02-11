#ifndef _MD5_ERROR_HPP
#define _MD5_ERROR_HPP

#include <stdexcept>

namespace md5 {

namespace error {

  class file_error : public std::runtime_error {};

  class parse_error : public std::runtime_error {};
  
  




 } /* namespace error */
} /* namespace md5 */



#endif /* end of include guard: _MD5_ERROR_HPP */
