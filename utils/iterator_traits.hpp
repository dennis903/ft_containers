#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
template<typename Iter>
struct iterator_traits
{
	typedef typename Iter::iterator_category	iterator_category;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::pointer 				pointer;
	typedef typename Iter::reference	 		reference;
	typedef typename Iter::difference_type		difference_type;
};

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<class T>
struct iterator_traits<T*>
{
	typedef T								value_type;
	typedef	T*								pointer;
	typedef T&								reference;
	typedef random_access_iterator_tag		iterator_category;
	typedef ptrdiff_t						difference_type;
};
}
#endif