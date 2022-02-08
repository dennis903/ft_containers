#include "utils/binary_search_tree.hpp"
#include "utils/bst_node.hpp"
#include "utils/print_tree.hpp"
#include "utils/pair.hpp"
#include "includes/map.hpp"
#include <iostream>
#include <map>

int main ()
{
  ft::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  mymap.clear();
  mymap['a']=1101;
//   mymap['b']=2202;

//   std::cout << "mymap contains:\n";
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

  return 0;
}