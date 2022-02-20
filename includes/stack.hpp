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
	private:
		container_type		_container;
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
			: _container(ctnr)
		{
		}

		~stack()
		{
		}

		bool				empty() const
		{
			return (_container.empty());
		}

		void				pop()
		{
			_container.pop_back();
		}

		void				push(const value_type& val)
		{
			_container.push_back(val);
		}

		size_type			size() const
		{
			return (_container.size());
		}

		value_type&			top()
		{
			return (_container.back());
		}

		const value_type&	top() const
		{
			return (_container.back());
		}
};
	template <class T1, class TC>
	bool	operator== (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs._container == rhs._container);
	}
	template <class T1, class TC>
	bool	operator!= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs._container != rhs._container);
	}
	template <class T1, class TC>
	bool	operator< (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs._container < rhs._container);
	}
	template <class T1, class TC>
	bool	operator<= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs._container <= rhs._container);
	}
	template <class T1, class TC>
	bool	operator> (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs._container > rhs._container);
	}
	template <class T1, class TC>
	bool	operator>= (const stack<T1, TC>& lhs, const stack<T1, TC>& rhs)
	{
		return (lhs._container >= rhs._container);
	}

}
#endif