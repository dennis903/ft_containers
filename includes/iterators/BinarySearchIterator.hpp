#ifndef BINARYSEARCHITERATOR
namespace ft
{
template<typename T, typename Pointer = T*, typename Reference = T&>
class BinarySearchTreeIter
{
	public:
		typedef T											value_type;
		typedef Pointer										pointer;
		typedef Reference									reference;
		typedef BinarySearchTreeIter<T, Pointer, Reference> current;
		typedef size_t										size_type;
		typedef BinarySearchTreeIter<T, T*, T&>				iterator;
		typedef BinarySearchTreeIter<T, const T*, const T&> const_iterator;
};
}
# define BINARYSEARCHITERATOR
#endif