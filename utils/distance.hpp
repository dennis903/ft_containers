#ifndef DISTANCE_HPP
# define DISTANCE_HPP
namespace ft
{
template < class InputIterator>
size_t	distance(InputIterator first, InputIterator	last)
{
	size_t	gap = 0;
	while (first != last)
	{
		first++;
		gap++;
	}
	return (gap);
}
}
#endif