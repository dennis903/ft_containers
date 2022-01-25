#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/less.hpp"
# include "../utils/bst_node.hpp"
# include "../utils/BinaryFunction.hpp"
# include "iterators/binary_search_tree_iterator.hpp"
# include "iterators/reverse_iterator.hpp"

namespace ft
{
template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair< const Key, T > > >
class	map
{
	public:
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef ft::pair<const Key, T>			value_type;
		typedef Compare							key_compare;
		typedef Allocator						allocator_type;
		typedef value_type&						reference;
		typedef size_t							size_type;
		typedef ptrdiff_t						difference_type;
		typedef const value_type&				const_reference;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
			protected:
				Compare	comp;
				value_compare( Compare c ) : comp(c) {}

			public:
				bool operator() (const value_type& lhs, const value_type& rhs) const
				{
					return (comp(lhs, rhs))
				}
		};
		typedef binary_search_tree_iterator<value_type, value_type*, value_type&>	iterator;
		typedef binary_search_tree_iterator<value_type, const value_type*, const value_type&>	const_iterator;
		typedef reverse_iterator<iterator>			reverse_iterator;
		typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		//constructor

	private:
		bst_node<Key, T, Compare>				*root;
		key_compare								_comp;
		allocator_type							_alloc;
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: root(), _comp(comp), _alloc(alloc)
		{}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: 
};
}
#endif