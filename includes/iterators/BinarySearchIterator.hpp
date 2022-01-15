#ifndef BINARYSEARCHITERATOR
# define BINARYSEARCHITERATOR
# include "../../utils/iterator_traits.hpp"
# include "../../utils/bst_node.hpp"
# include "../../utils/BinarySearchTree.hpp"
namespace ft
{
template<typename T, typename Pointer = T*, typename Reference = T&, typename Category = ft::bidirectional_iterator_tag>
class BinarySearchTreeIter
{
	public:
		typedef T											value_type;
		typedef ft::bst_node								node;
		typedef typename node*								node_ptr;
		typedef Pointer										pointer;
		typedef Reference									reference;
		typedef BinarySearchTreeIter<T, Pointer, Reference> current;
		typedef size_t										size_type;
		typedef Category									iterator_category;
		typedef ptrdiff_t									difference_type;
		typedef BinarySearchTreeIter<T, T*, T&>				iterator;
		typedef BinarySearchTreeIter<T, const T*, const T&> const_iterator;
	private:
		node_ptr	ptr;
	public:
		BinarySearchTreeIter() :
			ptr()
		{}

		BinarySearchTreeIter(const node_ptr &other) :
			ptr(x)
		{}

		BinarySearchTreeIter(const iterator &other) :
			ptr(other.ptr)
		{}

		~BinarySearchTreeIter() {}
};
}
#endif