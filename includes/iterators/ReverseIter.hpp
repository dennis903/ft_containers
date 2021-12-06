#ifndef REVERSEITER_HPP
# define REVERSEITER_HPP
# include <iterator_traits.hpp>

namespace ft
{
template<typename T, typename Pointer, typename Reference>
class	ReverseIter
{
	public:
		typedef T						value_type;
		typedef Pointer					pointer;
		typedef Reference				reference;
		typedef ReverseIter<T, Pointer, Reference> current;
		typedef size_t				size_type;
		typedef ReverseIter<T, T*, T&>	iterator;
		typedef ReverseIter<T, const *T, const &T> const_reverse_iterator;
	private:
		pointer	_arr;
	public:
		ReverseIter() : _arr(NULL) {}
		ReverseIter(const pointer arr) { this->arr = arr; }
		ReverseIter(const ReverseIter &_Iter) { *this= _Iter; }
		~ReverseIter() {}

		current &operator=(const ReverseIter &_Iter)
		{
			if (this == &_Iter)
				return (*iter);
			this->_arr = _Iter._arr;
			return (*this);
		}
		current &operator++(void)
		{
			this->_arr -= 1;
			return (*this);
		}
		current &operator++(int)
		{
			current temp(this->_arr);
			this->_arr -= 1;
			return (temp);
		}
		current &operator--(void)
		{
			this->_arr += 1;
			return (*this);
		}
		current &operator--(int)
		{
			current temp(this->_arr);
			this->_arr += 1;
			return (temp);
		}
		value_type &operator[] (const int index)
		{
			return (this->_arr[index]);
		}
		const value_type &operator[] (const int index) const
		{
			return (this->_arr[index]);
		}

		reference operator* () const
		{
			return (this->_arr);
		}
		pointer operator-> () const
		{
			return (this->_arr);
		}
		current operator+(size_type n)
		{
			current temp(*this);
			temp._arr -= n;
			return (temp);
		}
		current operator-(size_type n)
		{
			current temp(*this);
			temp._arr += n;
			return (temp);
		}
		current operator+=(size_type n)
		{
			this->_arr -= n;
			return (this);
		}
		current operator-=(size_type n)
		{
			this->_arr += n;
			return (this);
		}
		bool operator==(const current &temp) const
		{
			return (this->_arr == temp._arr);
		}

		bool operator!=(const current &temp) const
		{
			return (this->_arr != temp._arr);
		}

		bool operator>(const current &temp) const
		{
			return (this->_arr > temp._arr);
		}

		bool operator<(const current &temp) const
		{
			return (this->_arr < temp._arr);
		}

		bool operator<=(const current &temp) const
		{
			return (this->_arr <= temp._arr);
		}

		bool operator>=(const current &temp) const
		{
			return (this->_arr >= temp._arr);
		}
};
}
#endif