#ifndef TCP_PARSER
#define TCP_PARSER


#include <vector>
#include <map>
#include <bind>


class CParser
{
public:
  // estructuras y variables
  std::map<string,bind> 
  // metodos
  CParser(){};
  
  typedef std::vector<string>* string_splited;
  string_splited split_string(string _to_split);
  
  int parse_string(string _s);
  
private:


};

extern CParser::string_split string_split;


#endif
