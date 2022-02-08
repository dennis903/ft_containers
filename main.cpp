#include "utils/binary_search_tree.hpp"
#include "utils/bst_node.hpp"
#include "utils/print_tree.hpp"
#include "utils/pair.hpp"
#include "includes/map.hpp"
#include <string>
#include <map>

int main ()
{
  ft::map<char,int> mymap;

  mymap['e'] = 100;
  mymap['a'] = 200;
  mymap['b'] = 200;
  mymap['c'] = 200;
  mymap['d'] = 200;
  mymap['f'] = 200;
  mymap['g'] = 200;
  mymap['h'] = 200;
  mymap['i'] = 300;

  printTree(mymap._tree.get_root(), NULL, false);
  ft::map<char, int>::iterator it = mymap.begin();
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  std::cout << it->first << " " << it->second << "\n";
  it++;
  if (it == mymap.end())
	std::cout << "end" << std::endl;
  // show content:
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

  return 0;
}