#ifndef BST_NODE_HPP
# define BST_NODE_HPP
namespace ft
{
template <typename T>
struct bst_node
{
	public:
		typedef T			value_type;
		value_type			value;
		bst_node			*parent;
		bst_node			*left;
		bst_node			*right;

		bst_node() :
			value(0),
			parent(NULL),
			left(NULL),
			right(NULL)
		{}

		bst_node(bst_node *parent = NULL, bst_node *left = NULL, bst_node *right = NULL) :
			value(),
			parent(parent),
			left(left),
			right(right)
		{}

		bst_node(value_type value, bst_node *parent = NULL, bst_node *left = NULL, bst_node *right = NULL) :
			value(value),
			parent(parent),
			left(left),
			right(right)
		{}

		bst_node(const bst_node &node) :
			value(node.value),
			parent(node.parent),
			left(node.left),
			right(node.right)
		{}

		~bst_node() {}

		bst_node &operator=(const bst_node &node)
		{
			if (this == node)
				return (*this);

			this->value = node.value;
			this->parent = node.parent;
			this->left = node.left;
			this->right = node.right;
			return (*this);
		}

		bool operator == (const bst_node &node)
		{
			if (this->value == node.value)
				return (true);
			return (false);
		}

		bool operator >= (const bst_node &node)
		{
			if (this->value >= node.value)
				return (true);
			return (false);
		}

		bool operator <= (const bst_node &node)
		{
			if (this->value <= node.value)
				return (true);
			return (false);
		}

		bool operator > (const bst_node &node)
		{
			if (this->value > node.value)
				return (true);
			return (false);
		}

		bool operator < (const bst_node &node)
		{
			if (this->value < node.value)
				return (true);
			return (false);
		}
};
}
#endif