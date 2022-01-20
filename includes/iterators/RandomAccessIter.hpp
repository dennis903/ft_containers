#ifndef RANDOMACCESSITER_HPP
# define RANDOMACCESSITER_HPP
# include "../../utils/iterator_traits.hpp"

namespace ft
{
template<typename T, typename Pointer = T*, typename Reference = T&, typename Category = ft::random_access_iterator_tag>
class	RandomAccessIter
{
	public:
		typedef T								value_type;
		typedef Pointer							pointer;
		typedef Reference						reference;
		typedef RandomAccessIter<T, Pointer, Reference>	current;
		typedef size_t							size_type;
		typedef RandomAccessIter<T, T*, T&>		iterator;
		typedef Category						iterator_category;
		typedef RandomAccessIter<T, const T*, const T&> const_iterator;
		typedef ptrdiff_t						difference_type;
	private:
		pointer	_arr;
	public:
		RandomAccessIter() : _arr(NULL) {}
		explicit RandomAccessIter(const pointer arr) : _arr(arr) {}
		RandomAccessIter(const RandomAccessIter &_Iter) : _arr(_Iter._arr) { *this = _Iter; }
		~RandomAccessIter() {}
		//대입 연산자(=)
		current	&operator=(const RandomAccessIter &_Iter)
		{
			if (this == &_Iter)
				return (*this);
			this->_arr = _Iter._arr;
			return (*this);
		}
		//증가 연산자(후위, 전위, *a++)
		current &operator++(void)
		{
			this->_arr += 1;
			return (*this);
		}
		current operator++(int)
		{
			current temp(this->_arr);
			this->_arr += 1;
			return (temp);
		}
		// *a++ 나중에 테스트 해보기
		//감소 연산자(후위, 전위, *a--)
		current &operator--(void)
		{
			this->_arr -= 1;
			return (*this);
			
		}
		current operator--(int)
		{
			current temp(*this);
			this->_arr--;
			return (temp);
		}
		//첨자 연산자([])
		value_type &operator[] (const int index)
		{
			return (this->_arr[index]);
		}

		const value_type &operator[] (const int index) const
		{
			return (this->_arr[index]);
		}
		//참조 연산자(*, ->)
		reference operator* () const
		{
			return (*this->_arr);
		}
		pointer operator-> () const
		{
			return (this->_arr);
		}
		//+, - += -=
		current operator+(size_type n)
		{
			//iterator의 주소를 찍었을 때 다른 주소를 가짐.
			current temp(*this);
			temp._arr += n;
			return (temp);
		}

		template < class T1, class T2, class T3, class T4 >
		difference_type	operator-(const RandomAccessIter<T1, T2, T3, T4> &other) const
		{
			return (this->_arr - other._arr);
		}
		current operator+=(size_type n)
		{
			this->_arr += n;
			return (this);
		}
		current operator-=(size_type n)
		{
			this->_arr -= n;
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