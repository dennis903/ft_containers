#include "utils/binary_search_tree.hpp"
#include "utils/bst_node.hpp"
#include "utils/print_tree.hpp"
#include "utils/pair.hpp"
#include <string>

int			main()
{
	ft::pair<std::string, int> p;
	ft::binary_search_tree<ft::pair<std::string, int> > bst;
	p = ft::make_pair<std::string, int>("alice", 1);
	bst.insert_pair(p);
	// print_tree(bst.get_root());
	return (0);
}