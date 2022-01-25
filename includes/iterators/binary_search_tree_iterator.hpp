#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP
# include "../../utils/iterator_traits.hpp"
# include "../../utils/bst_node.hpp"
namespace ft
{
template<typename T, typename Pointer = T*, typename Reference = T&, typename Category = ft::bidirectional_iterator_tag>
class bst_iterator
{
	public:
		typedef T													value_type;
		typedef ft::bst_node										node;
		typedef typename node*										node_ptr;
		typedef Pointer												pointer;
		typedef Reference											reference;
		typedef size_t												size_type;
		typedef Category											iterator_category;
		typedef ptrdiff_t											difference_type;
		typedef bst_iterator<T, T*, T&>				iterator;
		typedef bst_iterator<T, const T*, const T&>	const_iterator;
	private:
		node_ptr	ptr;
	public:
		bst_iterator() :
			ptr()
		{}

		bst_iterator(const node_ptr &other) :
			ptr(x)
		{}

		bst_iterator(const iterator &other) :
			ptr(other.ptr)
		{}

		~bst_iterator() {}

		reference operator*() const
		{
			return (this->ptr->get_value());
		}

		pointer operator->() const
		{
			return (&this->ptr->get_value());
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
		bool operator==(const bst_iterator<T2, A, B, C>& x)
		{
			return (this->ptr == x.ptr);
		}

		template<class T2, class A, class B, class C>
		bool operator!=(const bst_iterator<T2, A, B, C>& x)
		{
			return (this->ptr != x.ptr);
		}
};
}
#endif