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
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  std::cout << itlow->first << " => " << itlow->second << "\n";
  std::cout << itup->first << " => " << itup->second << "\n";

  // mymap.erase(itlow,itup);        // erases [itlow,itup)

  // // print content:
  // for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  return 0;
}