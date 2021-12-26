#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/utils.hpp"

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
		//iterator만들기
};
}
#endif