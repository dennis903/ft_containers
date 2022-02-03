#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/less.hpp"
# include "../utils/bst_node.hpp"
# include "../utils/binary_function.hpp"
# include "../utils/binary_search_tree.hpp"
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
		typedef ft::binary_search_tree<value_type>	tree_type;
		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
			protected:
				Compare	comp;
				value_compare( Compare c ) : comp(c) {}

			public:
				bool operator() (const value_type& lhs, const value_type& rhs) const
				{
					return (comp(lhs, rhs));
				}
		};
		typedef binary_search_tree_iterator<value_type, value_type*, value_type&>				iterator;
		typedef binary_search_tree_iterator<value_type, const value_type*, const value_type&>	const_iterator;
		typedef reverse_iterator<const_iterator>												const_reverse_iterator;
		typedef reverse_iterator<iterator>														reverse_iterator;
		//constructor

	private:
		key_compare								_comp;
		allocator_type							_alloc;
	public:
		tree_type								_tree;
		//constructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:  _comp(comp), _alloc(alloc), _tree()
		{}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(), _comp(comp), _alloc(alloc) //insert를 만든 이후에 만들기
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

		mapped_type&			operator[] (const key_type& k)
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

		void					clear()
		{
			this->_tree.delete_all();
		}

		pair<iterator, bool>	insert(const value_type& val)
		{
			pair<node_type *, bool> ret = this->_tree.insert_pair(val);
			return (ft::make_pair(iterator(ret.first), ret.second));
		}

		iterator				insert (iterator position, const value_type &val)
		{
			(void)position;
			return (_tree.insert_pair(val).first);
		}

		template <class InputIterator>
		void					insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}
};
}
#endif