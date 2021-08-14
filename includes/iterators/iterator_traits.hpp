#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
template<typename Iter>
struct iterator_traits
{
	typedef typename Iter::iterator_category	iterator_category;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::pointer 				pointer;
	typedef typename Iter::reference	 		reference;
};
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
}
#endif