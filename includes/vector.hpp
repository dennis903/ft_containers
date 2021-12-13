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
	public:
		typedef T								value_type;
		typedef _Alloc							allocate_type;
		typedef size_t							size_type;
		typedef ptrdiff_t						difference_type; //두 포인터를 뺀 결과
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		typedef RandomAccessIter<T, T*, T&>		iterator;
		typedef RandomAccessIter<const T, const T*, const T&>	const_iterator;
		typedef ReverseIter<iterator>			reverse_iterator;
		typedef ReverseIter<const iterator>		const_reverse_iterator;

	private:
		pointer _arr;
		size_type _size;
		size_type _capacity;
		_Alloc  _alloc;
	public:
		//constructor
		explicit vector (const allocate_type& alloc = allocate_type())
		: _arr(0), _size(0), _capacity(0), _alloc(alloc)
		{
			this->_arr = this->_alloc.allocate(0);
		}

		explicit vector( size_type count, const value_type& value = value_type(), const allocate_type& alloc = allocate_type())
		: _arr(0), _size(0), _capacity(0), _alloc(alloc)
		{
			this->_size = count;
			this->_capacity = count;
			this->_arr = this->_alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
			{
				this->_arr[i] = value;
			}
		}
		//begin이랑 end함수 만든 뒤에 해보는걸로
		vector( iterator first, iterator last, const allocate_type& alloc = allocate_type())
		: _arr(0), _size(0), _capacity(0), _alloc(alloc)
		{
			size_type iter_size = 0;

			for (iterator iter = first; iter != last; iter++)
				iter_size++;
			this->_size = iter_size;
			this->_capacity = iter_size;
			_arr = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
			{
				_arr[i] = value_type(*first);
				first++;
			}
		}

		vector(const vector& other)
		: _arr(0), _size(0), _capacity(0), _alloc(allocate_type())
		{
			this->_size = other.size();
			this->_capacity = other.capacity();
			_arr = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < other.size(); i++)
				_arr[i] = other[i];
		}

		//destructor

		virtual ~vector()
		{
			if (_arr != nullptr)
			{
				this->_alloc.deallocate(_arr, _size);
				this->_arr = nullptr;
			}
		}
		//operator =
		vector& operator=(const vector& other)
		{
			this->_size = other._size;
			this->_capacity = other._capacity;
			this->_alloc = allocate_type();
			this->_arr = _alloc.allocate(_capacity);
		}
		//Member function
		void assign(size_type count, const T& value)
		{
			if (_arr != nullptr)
			{
				_alloc.deallocate(this->_arr, this->_capacity);
				this->_arr = nullptr;
			}
			this->_size = count;
			this->_capacity = count;
			this->_alloc = allocate_type();
			this->_arr = _alloc.allocate(_capacity);
			for (size_type i = 0; i < count; i++)
				this->_arr[i] = value;
		}

		void assign(iterator first, iterator last)
		{
			size_type iter_size = 0;

			if (_arr != nullptr)
			{
				_alloc.deallocate(this->_arr, this->_capacity);
				_arr = nullptr;
			}
			for (iterator iter = first; iter != last; iter++)
				iter_size++;
			this->_size = iter_size;
			this->_capacity = iter_size;
			_alloc = allocate_type();
			_arr = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
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
			return (this->_arr[pos]);
		}

		reference front()
		{
			return (this->_arr[0]);
		}

		const_reference front() const
		{
			return (this->_arr[0]);
		}

		reference back()
		{
			return (this->_arr[_size - 1]);
		}

		const_reference back() const
		{
			return (this->_arr[_size - 1]);
		}

		pointer data()
		{
			return (this->_arr);
		}

		const_pointer data() const
		{
			return (this->_arr);
		}
		//iterators
		//iterator은 modify가 완성되면 실험해보기
		iterator begin()
		{
			return (iterator(this->_arr));
		}

		const_iterator begin() const
		{
			return (iterator(this->_arr));
		}

		iterator end()
		{
			return (iterator(this->_arr + this->_size));
		}

		const_iterator end() const
		{
			return (const_iterator(this->_arr + this->_size));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->_arr + this->_size - 1));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->_arr + this->_size - 1));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->_arr - 1));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->_arr - 1));
		}

		//capacity
		bool empty() const
		{
			return (this->_size == 0 ? true : false);
		}

		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (_alloc.max_size());
		}

		void reserve (size_type new_cap)
		{
			if (new_cap > this->_capacity && new_cap != 0)
			{
				ft::vector<value_type> cp(ft::vector<value_type>(*this));
				this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_capacity = new_cap;
				this->_arr = _alloc.allocate(_capacity);
				if (this->_size != 0)
					for (size_type i = 0; i < this->_size; i++)
						this->_arr[i] = cp[i];
			}
		}

		size_type capacity() const
		{
			return (this->_capacity);
		}

		// modify

		void clear()
		{
			this->_size = 0;
		}

		iterator insert( iterator pos, const T& value ) // 나중에 좀 더 보기
		{
			if (this->_size > 0)
			{
				for (size_type i = 0; i < this->_size; i++)
				{
					if (pos == iterator(this->_arr + i))
					{
						ft::vector<value_type> copy(*this);
						if (this->_size == this->_capacity)
						{
							this->_alloc.deallocate(this->_arr, this->_capacity);
						}
						this->_size += 1;
						this->_capacity *= 2;
						if (this->_capacity == 0)
							this->_capacity = 1;
						this->_arr = this->_alloc.allocate(_capacity);
						bool seat = false;
						for (size_type j = 0; j < this->_size; j++)
						{
							if (j == i)
							{
								seat = true;
								this->_arr[j] = value;
							}
							else
								this->_arr[j] = copy[j - seat];
						}
						return (iterator(&this->_arr[i]));
					}
				}
			}
			else
			{
				this->_size += 1;
				this->_capacity += 1;
				this->_arr = this->_alloc.allocate(this->_capacity);
				this->_arr[0] = value;
				return (iterator(this->_arr));
			}
			return (iterator(0));
		}

		iterator insert (iterator pos, size_type count, T& value)
		{
			size_type
		}
};
}
#endif