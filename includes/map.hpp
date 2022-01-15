#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/less.hpp"
# include "../utils/BinaryFunction.hpp"

namespace ft
{
template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair< const Key, T > > >
class	map
{
	public:
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef ft::pair<const Key, T>			value_type;
		typedef size_t							size_type;
		typedef ptrdiff_t						difference_type;
		typedef Compare							key_compare;
		typedef Allocator						allocator_type;
		typedef value_type&						reference;
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
		//iterator만들기
};
}
#endif