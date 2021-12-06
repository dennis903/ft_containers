#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <./iterators/RandomAccessIter.hpp>
# include <./iterators/ReverseIter.hpp>
namespace ft
{
template<typename T, typename _Alloc = std::allocator<T> >
class	vector
{
	typedef T								value_type;
	typedef _Alloc							allocate_type;
	typedef size_t							size_type;
	typedef ptrdiff_t						difference_type; //두 포인터를 뺀 결과
	typedef value_type&						reference;
	typedef const value_type&				const_reference;
	typedef value_type*						pointer;
	typedef const value_type*				const_pointer;
	typedef RandomAccessIter<pointer>		iterator;
	typedef RandomAccessIter<const pointer>	const_iterator;
	typedef ReverseIter<iterator>			reverse_iterator;
	typedef ReverseIter<const iterator>		const_reverse_iterator;

	private:
		allocate_type<value_type>	alloc;
	public:
		vector() : _alloc(NULL) {};
};
}
#endif