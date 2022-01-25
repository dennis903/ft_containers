#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "../../utils/iterator_traits.hpp"

namespace ft
{
template<typename Iterator>
class	reverse_iterator
{
	public:
		typedef Iterator											iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
		typedef typename ft::iterator_traits<Iterator>::reference				reference;
	private:
		iterator_type	_Iter;
	public:
		reverse_iterator() : _Iter(NULL) {}

		explicit reverse_iterator(iterator_type x) : _Iter(x) {}

		template< class U >
		reverse_iterator( const reverse_iterator<U>& other) : _Iter(other.base()) {}

		~reverse_iterator() {};

		template< class U >
		reverse_iterator &operator=(const reverse_iterator<U> &_other)
		{
			_Iter = _other.base();
			return (*this);
		}

		iterator_type base() const
		{
			return (this->_Iter);
		}

		reverse_iterator &operator++(void)
		{
			this->_Iter -= 1;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return (temp);
		}

		reverse_iterator &operator--(void)
		{
			this->_Iter += 1;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return (temp);
		}

		reference &operator[] (difference_type n) const
		{
			return (base()[-n-1]);
		}

		reference operator* () const
		{
			iterator_type tmp = this->_Iter;
			return (*--tmp);
		}

		pointer operator->() const
		{
			return &(this->operator*());
		}

		reverse_iterator operator+(difference_type n) const
		{
			reverse_iterator temp(this->_Iter - n);
			return (temp);
		}
		reverse_iterator operator-(difference_type n) const
		{
			reverse_iterator temp(this->_Iter + n);
			return (temp);
		}
		reverse_iterator& operator+=(difference_type n)
		{
			this->_Iter -= n;
			return (*this);
		}
		reverse_iterator& operator-=(difference_type n)
		{
			this->_Iter += n;
			return (*this);
		}
};
template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template< class Iter >
reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
{
	return (reverse_iterator<Iter>(it.base() - n));
}

template< class Iterator1, class Iterator2 >
typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return (rhs.base() - lhs.base());
}
}
#endif