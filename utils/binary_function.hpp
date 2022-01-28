#ifndef BINARY_FUNCTION_HPP
# define BINARY_FUNCTION_HPP
namespace ft
{
template<class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef first_argument_type					Arg1;
	typedef second_argument_type				Arg2;
	typedef result_type							Result;
};
}
#endif