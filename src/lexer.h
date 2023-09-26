#ifndef __lexer_h__
#define __lexer_h__

#include <string>

namespace potato {

enum Token : int {
  // syntax
  semicolon = ';',
  open_bracket = '(',
  close_bracket = ')',
  open_curly = '{',
  close_curly = '}',
  open_sqbracket = '[',
  close_sqbracket = ']',

  // end of file
  eof = -1,

  // definitions
  var = -2,
  def = -3,
  ret = -4,
};

class Lexer {
public:
  Lexer(const std::string &file_name);
}

}; // namespace potato

#endif