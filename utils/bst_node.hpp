#ifndef BST_NODE_HPP
# define BST_NODE_HPP
# include <memory>
namespace ft
{
template < class T, class Allocate = std::allocator<T> >
class bst_node
{
	public:
		typedef T			value_type;
		typedef Allocate	allocate_type;

		value_type		*_value;
		allocate_type	_alloc;
		bst_node		*_parent;
		bst_node		*_left;
		bst_node		*_right;

		bst_node() : _value(NULL), _parent(NULL), _left(NULL), _right(NULL), _alloc(allocate_type())
		{}

		bst_node(const value_type &value) : _parent(NULL), _left(NULL), _right(NULL), _alloc(allocate_type())
		{
			if (value != NULL)
			{
				this->_value = _alloc.allocate(1);
				_alloc.construct(this->_value, value);
			}
		}

		bst_node(const bst_node<T> *other) : _parent(NULL), _left(NULL), _right(NULL), _alloc(allocate_type())
		{
			if (other != NULL)
			{
				this->_value = _alloc.allocate(1);
				_alloc.construct(this->_value, other->_value);
			}
		}

		~bst_node()
		{
			if (this->_value != NULL)
			{
				this->_alloc.destroy(this->_value);
				this->_alloc.deallocate(this->_value, 1);
			}
		}

		bst_node &operator=(const bst_node<T> &other)
		{
			this->_value = other._value;
			this->_parent = other._parent;
			this->_left = other._left;
			this->_right = other._right;
		}

		bool	is_empty() const
		{
			if (this->_value == NULL)
				return (true);
			else
				return (false);
		}

		bool	is_root() const
		{
			if (this->_parent->_value == NULL)
				return (true);
			else
				return (false);
		}

		bool	is_left() const
		{
			if (this->_parent->_left == this)
				return (true);
			else
				return (false);
		}

		bool	is_right() const
		{
			if (this->_parent->_right == this)
				return (true);
			else
				return (false);
		}
};
}
#endif