#ifndef BINARYSEARCHTREEITER
# define BINARYSEARCHTREEITER
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

		reference operator*() const
		{
			return (this->ptr->value);
		}

		pointer operator->() const
		{
			return (&this->ptr->value);
		}

		iterator& operator++()
		{
			++ptr;
			return (*this);
		}

		iterator operator++(int)
		{
			node_ptr temp(*this);
			++(*this);
			return (temp);
		}

		iterator& operator--()
		{
			--ptr;
			return (*this);
		}

		iterator operator--(int)
		{
			iterator temp(*this);
			--(*this);
			return (temp);
		}

		template<class T2, class A, class B, class C>
		bool operator==(const BinarySearchTreeIter<T2, A, B, C>& x)
		{
			return (this->ptr == x.ptr);
		}

		template<class T2, class A, class B, class C>
		bool operator!=(const BinarySearchTreeIter<T2, A, B, C>& x)
		{
			return (this->ptr != x.ptr);
		}
};
}
#endif