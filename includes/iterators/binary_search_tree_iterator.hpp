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

			if (!ret->_right->is_empty()) //현재 노드에 오른쪽 노드가 존재할 시 오른쪽 노드의 가장 왼쪽 노드가 다음 iter가 된다.
			{
				if (test)
					std::cout << "1" << std::endl;
				ret = ret->_right;
				while (!ret->_left->is_empty())
					ret = ret->_left;
			}
			else if (ret->_parent->is_empty()) //부모 노드가 empty라는 이야기는 노드가 root노드 라는 것
				ret = this->ptr->_parent;
			else if (ret->is_empty())
				ret = ret->_right;
			else
			{
				while (!ret->_parent->is_empty()) //오른쪽에 노드가 없을 경우 부모노드가 left노드 일 때 까지 타고 올라간다. 그 이후 left노드의 부모 노드가 다음 iter가 된다.
				{
					if (ret->is_left())
					{
						ret = ret->_parent;
						break ;
					}
					ret = ret->_parent;
				}
			}
			this->ptr = ret;
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
			}
			else if (ret->_parent->is_empty())
				ret = this->ptr->_parent;
			else if (ret->is_empty())
				ret = ret->_left;
			else
			{
				while (!ret->_parent->is_empty())
				{
					if (ret->is_right())
					{
						ret = ret->_parent;
						break ;
					}
					ret = ret->_parent;
				}
			}
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