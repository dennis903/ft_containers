#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include "./iterators/random_access_iterator.hpp"
# include "./iterators/reverse_iterator.hpp"
# include "../utils/lexicographical_compare.hpp"
# include "../utils/iterator_traits.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include "../utils/distance.hpp"
# include <exception>

#include <iostream>
namespace ft
{
template<typename T, typename _Alloc = std::allocator<T>, typename Category = ft::random_access_iterator_tag>
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
		typedef random_access_iterator<T, T*, T&>		iterator;
		typedef random_access_iterator<T, const T*, const T&>	const_iterator;
		typedef reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef reverse_iterator<iterator>				reverse_iterator; //cost_reverse_iterator과 reverse_iterator랑 순서 바꾸면 컴파일이 안됌.
		typedef Category								iterator_category;

	private:
		pointer _arr;
		size_type _size;
		size_type _capacity;
		_Alloc  _alloc;

		class OutOfRangeException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Index out of range";
			}
		};
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

		template <class InputIterator>
		vector( InputIterator first, InputIterator last, const allocate_type& alloc = allocate_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) //deep copy
		: _arr(0), _size(0), _capacity(0), _alloc(alloc)
		{
			difference_type		gap = ft::distance(first, last);

			this->_size = gap;
			this->_capacity = gap;
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
				_arr[i] = other._arr[i];
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
			for (size_type i = 0; i < other.size(); i++)
				_arr[i] = other._arr[i];
			return (*this);
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

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type gap = ft::distance(first, last);
			if (_arr != nullptr)
			{
				_alloc.deallocate(this->_arr, this->_capacity);
				_arr = nullptr;
			}
			this->_size = gap;
			this->_capacity = gap;
			_alloc = allocate_type();
			_arr = _alloc.allocate(_capacity);
			// size_type iter_size = 0;
			// for (iterator iter = first; iter != last; iter++)
			// 	iter_size++;
			for (size_type i = 0; i < _size; i++)
			{
				this->_arr[i] = value_type(*first);
				*first++;
			}
		}

		allocate_type get_allocator() const
		{
			return (this->_alloc);
		}
		//element access
		reference at( size_type pos )
		{
			if (pos < this->_size)
				return (this->_arr[pos]);
			throw std::out_of_range("out of range");
		}

		const_reference at( size_type pos ) const
		{
			if (pos < this->_size)
				return (this->_arr[pos]);
			throw std::out_of_range("out of range");
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
			return (const_iterator(this->_arr));
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
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
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

		void	resize(size_type count, T value = T())
		{
			if (count > capacity())
			{
				if (count >= this->_capacity * 2)
					reserve(count);
				else
					reserve(this->_capacity * 2);
			}
			if (count < size())
				for (size_type i = count; i < size(); i++)
					this->_alloc.destroy(&_arr[i]);
			else
				for (size_type i = size(); i < count; i++)
					this->_arr[i] = value;
			this->_size = count;
		}

		void insert(iterator pos, size_type count, const T& value)
		{
			size_type back_count = 0;
			size_type back = size() + count - 1;
			size_type index = 0;

			for (iterator it = end(); it != pos; it--)
				back_count++;
			for (iterator it = begin(); it != pos; it++)
				index++;
			resize(size() + count);
			for (size_type i = 0; i < back_count; i++)
				this->_arr[back - i] = this->_arr[back - count - i];
			for (size_type i = index; i < index + count; i++)
				this->_arr[i] = value;
		}
		
		iterator insert( iterator pos, const T& value ) // 나중에 좀 더 보기
		{
			size_type back_count = 0;
			size_type back = size();
			size_type index = 0;

			for (iterator it = end(); it != pos; it--)
				back_count++;
			for (iterator it = begin(); it != pos; it++)
				index++;
			resize(size() + 1);
			for (size_type i = 0; i < back_count; i++)
				this->_arr[back - i] = this->_arr[back - 1 - i];
			this->_arr[index] = value;
			return (iterator(&this->_arr[index]));
		}

		template< class InputIterator >
		void insert( iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_type back_count = 0;
			difference_type count = ft::distance(first, last);
			size_type back;
			size_type index = 0;

			for (iterator it = end(); it != pos; it--)
				back_count++;
			for (iterator it = begin(); it != pos; it++)
				index++;
			back = size() + count - 1;
			resize(size() + count);
			for (size_type i = 0; i < back_count; i++)
				this->_arr[back - i] = this->_arr[back - count - i];
			for (size_type i = index; i < index + count; i++)
			{
				this->_arr[i] = *(first++);
			}
		}

		void push_back( const T& value )
		{
			resize(size() + 1);
			this->_arr[size() - 1] = value;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator	temp = first;
			size_type	count = 0;
			size_type	index = 0;

			for (iterator it = begin(); it != first; it++)
				index++;
			while (temp != last)
			{
				this->_alloc.destroy(&this->_arr[index]);
				index++;
				count++;
				temp++;
			}
			for (size_type i = index; i < size(); i++)
				this->_arr[i - count] = this->_arr[i];
			resize(size() - count);
			return (first);
		}

		iterator erase(iterator pos)
		{
			erase(pos, pos + 1);
			return (pos);
		}

		void pop_back()
		{
			erase(end() - 1);
		}

		void swap(vector &other)
		{
			pointer temp_arr;
			size_type temp_size;
			size_type temp_capacity;

			temp_arr = other._arr;
			temp_size = other._size;
			temp_capacity = other._capacity;
			other._arr = this->_arr;
			other._size = this->_size;
			other._capacity = this->_capacity;
			this->_arr = temp_arr;
			this->_size = temp_size;
			this->_capacity = temp_capacity;
		}
	};

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (rhs <= lhs );
	}

	template<class T, class Alloc>
	void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif