#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>

namespace ft
{
template<typename T, typename _Alloc = std::allocator<T> >
class	vector
{
	typedef T						value_type;
	typedef _Alloc					allocate_type;
	typedef size_t					size_type;
	typedef ptrdiff_t				difference_type; //두 포인터를 뺀 결과
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef value_type*				pointer;
	typedef const value_type*		const_pointer;
	
};
}
#endif