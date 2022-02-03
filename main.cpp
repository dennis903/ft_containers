#include "utils/binary_search_tree.hpp"
#include "utils/bst_node.hpp"
#include "utils/print_tree.hpp"
#include "utils/pair.hpp"
#include "includes/map.hpp"
#include <string>
#include <map>

int			main()
{
	ft::map<char,int> mymap;

  // first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	std::cout << ret.second << std::endl;
	  if (ret.second==false) {
	    std::cout << "element 'z' already existed";
	    std::cout << " with a value of " << ret.first->second << '\n';
  }

	printTree(mymap._tree.get_root(), NULL, false);

	// ft::pair<std::string, int> p;
	// ft::binary_search_tree<ft::pair<std::string, int> > bst;
	// p = ft::make_pair<std::string, int>("d", 1);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("a", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("b", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("c", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("e", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("f", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("g", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("y", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("m", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("p", 2);
	// bst.insert_pair(p);
	// p = ft::make_pair<std::string, int>("z", 2);
	// bst.insert_pair(p);
	// printTree<ft::pair<std::string, int> >(bst.get_root(), NULL, false);
	return (0);
}