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
		size_type size;
		size_type capacity;
		_Alloc  _alloc;
	public:
		//constructor
		explicit vector (const allocate_type& alloc = allocate_type())
		: _arr(0), _alloc(alloc), size(0), capacity(0)
		{
			this->_arr = this->_alloc.allocate(0);
		}

		explicit vector( size_type count, const value_type& value = value_type(), const allocate_type& alloc = allocate_type())
		: _arr(0), size(0), capacity(0), _alloc(alloc)
		{
			this->size = count;
			this->capacity = count;
			this->_arr = this->_alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
			{
				this->_arr[i] = value;
			}
		}
		//begin이랑 end함수 만든 뒤에 해보는걸로
		vector( iterator first, iterator last, const allocate_type& alloc = allocate_type())
		: _arr(0), size(0), capacity(0), _alloc(alloc)
		{
			size_type iter_size = 0;

			for (iterator iter = first; iter != last; iter++)
				iter_size++;
			size = iter_size;
			capacity = iter_size;
			_arr = _alloc.allocate(capacity);
			for (size_type i = 0; i < size; i++)
			{
				_arr[i] = value_type(*first);
				first++;
			}
		}

		vector(const vector& other)
		: _arr(0), _alloc(allocate_type()), size(0), capacity(0)
		{
			this->size = other.size;
			this->capacity = other.capacity;
			_arr = this->_alloc.allocator(capacity);
			for (int i = 0; i < other.size; i++)
				_arr[i] = other[i];
		}

		//destructor

		virtual ~vector()
		{
			if (_arr != nullptr)
			{
				this->_alloc.deallocate(_arr, size);
				this->_arr = nullptr;
			}
		}
		//operator =
		vector& operator=(const vector& other)
		{
			this->size = other.size;
			this->capacity = other.capacity;
			this->_alloc = allocate_type();
			this->_arr = _alloc.allocate(capacity);
		}
		//Member function
		void assign(size_type count, const T& value)
		{
			if (_arr != nullptr)
			{
				_alloc.deallocate(this->_arr, this->capacity);
				this->_arr = nullptr;
			}
			this->size = count;
			this->capacity = count;
			this->_alloc = allocate_type();
			this->_arr = _alloc.allocate(capacity);
			for (size_type i = 0; i < count; i++)
				this->_arr[i] = value;
		}

		void assign(iterator first, iterator last)
		{
			size_type iter_size = 0;

			if (_arr != nullptr)
			{
				_alloc.deallocate(this->_arr, this->capacity);
				_arr = nullptr;
			}
			for (iterator iter = first; iter != last; iter++)
				iter_size++;
			this->size = iter_size;
			this->capacity = iter_size;
			_alloc = allocate_type();
			_arr = _alloc.allocate(capacity);
			for (size_type i = 0; i < size; i++)
				this->_arr[i] = value_type(*first);
		}

		allocate_type get_allocator() const
		{
			return (this->_alloc);
		}
		//element access
		reference at( size_type pos )
		{
			return (this->_arr[pos]);
		}

		const_reference at( size_type pos ) const
		{
			return (this->_arr[pos]);
		}

		reference operator[](size_type pos)
		{
			return (this->_arr[pos]);
		}

		const_reference operator[]( size_type pos ) const
		{
			return (this->_arr[pos])
		}
};
}
#endif