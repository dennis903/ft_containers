#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft
{
template <class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
	protected:
		container_type		c;
		template <class T1, class TC>
		friend bool	operator== (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs);
		template <class T1, class TC>
		friend bool	operator!= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs);
		template <class T1, class TC>
		friend bool	operator< (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs);
		template <class T1, class TC>
		friend bool	operator<= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs);
		template <class T1, class TC>
		friend bool	operator> (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs);
		template <class T1, class TC>
		friend bool	operator>= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs);
	public:
		explicit	stack (const container_type& ctnr = container_type())
			: c(ctnr)
		{
		}

		~stack()
		{
		}

		bool				empty() const
		{
			return (c.empty());
		}

		void				pop()
		{
			c.pop_back();
		}

		void				push(const value_type& val)
		{
			c.push_back(val);
		}

		size_type			size() const
		{
			return (c.size());
		}

		value_type&			top()
		{
			return (c.back());
		}

		const value_type&	top() const
		{
			return (c.back());
		}
};
	template <class T1, class TC>
	bool	operator== (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class T1, class TC>
	bool	operator!= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs.c != rhs.c);
	}
	template <class T1, class TC>
	bool	operator< (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class T1, class TC>
	bool	operator<= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs.c <= rhs.c);
	}
	template <class T1, class TC>
	bool	operator> (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <class T1, class TC>
	bool	operator>= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs.c >= rhs.c);
	}

}
#endif