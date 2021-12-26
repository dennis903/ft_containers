#ifndef UTILS_HPP
# define UTILS_HPP
namespace ft
{
template <class T>
struct less
{
	bool operator()(const T &lhs, const T &rhs) const
	{
		return (lhs < rhs);
	}
};
}
#endif