#ifndef RANDOMACCESSITER_HPP
# define RANDOMACCESSITER_HPP
template<typename T, typename Pointer, typename Reference>
class	RandomAccessIter
{
	public:
		typedef T								value_type;
		typedef Pointer							pointer;
		typedef Reference						reference;
		typedef RandomAccessIter<T, Pointer, Reference>	current;
		typedef size_t							size_type;
		typedef RandomAccessIter<T, *T, &T>		iterator;
	private:
		pointer	_arr;
	public:
		RandomAccessIter() : _arr(NULL) {}
		RamdomAccessIter(const pointer arr) { this->_arr = arr; }
		RandomAccessIter(const RandomAccessIter &_Iter) { *this = _Iter; }
		~RandomAccessIter() {}

		//대입 연산자(=)
		//증가 연산자(후위, 전위, *a++)
		//감소 연산자(후위, 전위, *a--)
		//첨자 연산자([])
		//비교 연산자(==, !=, >, <, <=, >=)
		//참조 연산자(*, ->)
		//+, - += -=
};
#endif