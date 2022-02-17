#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/less.hpp"
# include "../utils/bst_node.hpp"
# include "../utils/binary_function.hpp"
# include "../utils/binary_search_tree.hpp"
# include "../utils/lexicographical_compare.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include "iterators/binary_search_tree_iterator.hpp"
# include "iterators/reverse_iterator.hpp"

namespace ft
{
template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair< const Key, T > > >
class	map
{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef ft::pair<const Key, T>				value_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef value_type&							reference;
		typedef size_t								size_type;
		typedef ptrdiff_t							difference_type;
		typedef const value_type&					const_reference;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef ft::bst_node<value_type>			node_type;
		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
			friend class map<key_type, mapped_type, key_compare, allocator_type>;
			protected:
				key_compare		comp;

			public:
				bool operator() (const value_type& lhs, const value_type& rhs) const
				{
					return (comp(lhs.first, rhs.first));
				}
		};
		typedef ft::binary_search_tree<value_type, value_compare>	tree_type;
		typedef binary_search_tree_iterator<value_type, value_type*, value_type&>				iterator;
		typedef binary_search_tree_iterator<value_type, const value_type*, const value_type&>	const_iterator;
		typedef reverse_iterator<const_iterator>												const_reverse_iterator;
		typedef reverse_iterator<iterator>														reverse_iterator;
		//constructor

	private:
		key_compare								_comp;
		allocator_type							_alloc;
	public:
		//constructor
		tree_type								_tree;
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:   _comp(comp), _alloc(alloc), _tree()
		{}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree()
		{
			insert(first, last);
		}

		map(const map& x)
		{
			*this = x;
		}
		//destructor
		~map() {}

		//operator =
		map&	operator=(const map& x)
		{
			this->_alloc = x._alloc;
			this->_comp = x._comp;
			this->_tree.copy(x._tree);
			return (*this);
		}

		mapped_type&			operator[](const key_type& k)
		{
			return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
		}

		iterator				begin()
		{
			return (iterator(this->_tree.get_lowest()));
		}

		const_iterator			begin() const
		{
			return (const_iterator(this->_tree.get_lowest()));
		}

		iterator				end()
		{
			return (iterator(this->_tree.get_none()));
		}

		const_iterator			end() const
		{
			return (const_iterator(this->_tree.get_none()));
		}

		reverse_iterator		rbegin()
		{
			return (reverse_iterator(this->end()));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator		rend()
		{
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}

		void					clear()
		{
			this->_tree.delete_all();
		}

		size_type				count(const key_type& k) const
		{
			iterator			check_key;

			check_key = _tree.search_by_key(value_type(k, mapped_type()));
			if (check_key == iterator(this->_tree.get_none()))
				return (0);
			else
				return (1);
		}

		bool					empty() const
		{
			if (this->_tree.get_size() == 0)
				return (1);
			else
				return (0);
		}

		pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
		{
			return (make_pair(lower_bound(k), upper_bound(k)));
		}

		pair<iterator, iterator> 				equal_range(const key_type& k)
		{
			return (make_pair(lower_bound(k), upper_bound(k)));
		}

		void					erase(iterator position)
		{
			this->_tree.erase(position.get_ptr());
		}

		size_type				erase(const key_type& k)
		{
			iterator			it;

			it = this->find(k);
			if (it == this->end())
				return (0);
			else
			{
				erase(it);
				return (1);
			}
		}

		void					erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		}

		iterator				lower_bound(const key_type &k)
		{
			iterator	it;

			it = begin();
			while (it != end())
			{
				if (it->first >= k)
					return (it);
				it++;
			}
			return (it);
		}

		const_iterator			lower_bound(const key_type &k) const
		{
			iterator	it;

			it = begin();
			while (it != end())
			{
				if (it->first >= k)
					return (it);
				it++;
			}
			return (it);
		}

		iterator				upper_bound(const key_type& k)
		{
			iterator	it;

			it = begin();
			while (it != end())
			{
				if (it->first > k)
					return (it);
				it++;
			}
			return (it);

		}

		const_iterator			upper_bound(const key_type& k) const
		{
			iterator	it;

			it = begin();
			while (it != end())
			{
				if (it->first > k)
					return (it);
				it++;
			}
			return (it);
		}

		pair<iterator, bool>	insert(const value_type& val)
		{
			pair<node_type *, bool> ret = this->_tree.insert_pair(val);
			return (ft::make_pair(iterator(ret.first), ret.second));
		}

		iterator				insert(iterator position, const value_type &val)
		{
			(void)position;
			return (_tree.insert_pair(val).first);
		}

		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		iterator				find(const key_type& k)
		{
			iterator	it;

			it = this->begin();
			while (it != this->end())
			{
				if (it->first == k)
					break ;
				it++;
			}
			return (it);
		}

		const_iterator			find(const key_type& k) const
		{
			iterator	it;

			it = this->begin();
			while (it != this->end())
			{
				if (it->first == k)
					break ;
				it++;
			}
			return (it);
		}

		allocator_type			get_allocator() const
		{
			return (this->_alloc);
		}

		key_compare				key_comp() const
		{
			return (this->_comp);
		}

		size_type				max_size() const
		{
			allocator_type		alloc;
			return (alloc.max_size());
		}

		size_type				size() const
		{
			return (this->_tree.get_size());
		}

		void					swap(map& x)
		{
			map		tmp;

			tmp = *this;
			*this = x;
			x = tmp;
		}

		value_compare			value_comp() const
		{
			return (value_compare());
		}
};
template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename ft::map<Key, T, Compare, Alloc>::const_iterator liter = lhs.begin();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator riter = rhs.begin();
	while (liter != lhs.end())
	{
		if (liter->first != riter->first || liter->second != riter->second)
			return (false);
		liter++;
		riter++;
	}
	return (true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc>&lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc>&lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc>&lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
{
	x.swap(y);
}
}
#endif