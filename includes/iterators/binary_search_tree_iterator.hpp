#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP
# include "../../utils/iterator_traits.hpp"
# include "../../utils/bst_node.hpp"
namespace ft
{
template<typename T, typename Pointer = T*, typename Reference = T&, typename Category = ft::bidirectional_iterator_tag>
class binary_search_tree_iterator
{
	public:
		typedef T													value_type;
		typedef ft::bst_node<T>										node;
		typedef node*												node_ptr;
		typedef Pointer												pointer;
		typedef Reference											reference;
		typedef size_t												size_type;
		typedef Category											iterator_category;
		typedef ptrdiff_t											difference_type;
		typedef binary_search_tree_iterator<T, T*, T&>				iterator;
		typedef binary_search_tree_iterator<T, const T*, const T&>	const_iterator;
	private:
		node_ptr	ptr;
	public:
		binary_search_tree_iterator() :
			ptr()
		{}

		binary_search_tree_iterator(const node_ptr &other) :
			ptr(other)
		{}

		binary_search_tree_iterator(const iterator &other) :
			ptr(other.ptr)
		{}

		~binary_search_tree_iterator() {}

		iterator& operator=(const iterator& other)
		{
			this->ptr = other.ptr;
			return (*this);
		}

		reference operator*() const
		{
			return (this->ptr->get_value());
		}

		pointer operator->() const
		{
			return (&(this->ptr->get_value()));
		}

		iterator& operator++()
		{
			node_ptr ret = this->ptr;

			if (!ret->_right->is_empty())
			{
				ret = ret->_right;
				while (!ret->_left->is_empty())
					ret = ret->_left;
				this->ptr = ret;
			}
			else if (!this->ptr->_parent->is_empty())
			{
				while (!ret->_parent->is_empty())
				{
					if (ret->is_left())
						break ;
					ret = ret->_parent;
				}
				this->ptr = ret->_parent;
			}
			else
				this->ptr = ret->_parent;
			return (*this);
		}

		iterator operator++(int)
		{
			iterator temp(*this);
			operator++();
			return (temp);
		}

		iterator& operator--()
		{
			node_ptr ret = this->ptr;

			if (!ret->_left->is_empty())
			{
				ret = ret->_left;
				while (!ret->_right->is_empty())
					ret = ret->_right;
				this->ptr = ret;
			}
			else if (!this->ptr->_parent->is_empty())
			{
				while (!ret->_parent->is_empty())
				{
					if (ret->is_right())
						break ;
					ret = ret->_parent;
				}
				this->ptr = ret->_parent;
			}
			else
				this->ptr = ret->_parent;
			return (*this);
		}

		iterator operator--(int)
		{
			iterator temp(*this);
			operator--();
			return (temp);
		}

		bool operator==(const iterator& x)
		{
			return (this->ptr == x.ptr);
		}

		bool operator!=(const iterator& x)
		{
			return (this->ptr != x.ptr);
		}
};
}
#endif