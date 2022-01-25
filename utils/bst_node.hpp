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
	private:
		value_type		*_value;
		allocate_type	_alloc;
		bst_node		*_parent;
		bst_node		*_left;
		bst_node		*_right;

	public:
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

		bst_node(const bst_node *other) : _parent(NULL), _left(NULL), _right(NULL), _alloc(allocate_type())
		{
			if (other != NULL)
			{
				this->_value = _alloc.allocate(1);
				_alloc.construct(this->_value, other.get_value());
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

		value_type	&get_value() const
		{
			return (this->_value);
		}

		bool	is_root() const
		{
			if (this->_parent == NULL)
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