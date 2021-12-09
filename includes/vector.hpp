#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include "./iterators/RandomAccessIter.hpp"
# include "./iterators/ReverseIter.hpp"
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
		pointer _arr;
		_Alloc  _alloc;
	public:
		explicit vector (const allocate_type& alloc = allocate_type())
		: _arr(0), _alloc(alloc)
		{
			_arr = this->_alloc.allocate(0);
		}
		explicit vector (size_type length, value_type val = 0, const allocate_type &alloc = allocate_type())
		: _arr(0), _alloc(alloc)
		{
			_arr = this->_alloc.allocate(length);
			if (length == 0)
				_arr[0] = val;
			else
			{
				for (size_type i = 0; i < length; i++)
					_arr[i] = val;
			}
		}
};
}
#endif