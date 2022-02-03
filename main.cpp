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

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  printTree(mymap._tree.get_root(), NULL, false);
  // show content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}