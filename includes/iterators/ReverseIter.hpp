#ifndef REVERSEITER_HPP
# define REVERSEITER_HPP
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
};
}
#endif