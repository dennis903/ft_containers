#ifndef BST_NODE_HPP
# define BST_NODE_HPP
# include "less.hpp"
# include "pair.hpp"
namespace ft
{
template< class T1, class T2, class Compare = ft::less<T1> >
class bst_node
{
	private:
		bst_node* parent;
		bst_node* left;
		bst_node* right;

	public:
		pair<T1, T2> current;

		bst_node() :
			parent(NULL),
			left(NULL),
			right(NULL)
		{}

		bst_node(T1 first, T2 second = T2()) :
			parent(NULL),
			left(NULL),
			right(NULL),
			current(first, second)
		{}

		bst_node(const pair<T1, T2> &pair) :
			parent(NULL),
			left(NULL),
			right(NULL),
			current(pair)
		{}

		bst_node(const bst_node &other, const bst_node other_parent = NULL) :
			parent(other_parent)
		{
			if (other.left != NULL)
				this->left = new bst_node<T1, T2, Compare>(*other.left, NULL);
			if (other.right != NULL)
				this->right = new bst_node<T1, T2, Compare>(*other.right, NULL);
		}

		~bst_node() {}
};
}
#endif