#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP
# include <memory>
# include "bst_node.hpp"
# include "less.hpp"
# include "pair.hpp"
# include "../includes/iterators/binary_search_tree_iterator.hpp"

namespace ft
{
template< class T, class Compare = ft::less<T>, class NodeType = ft::bst_node<T>, class NodeAlloc = std::allocator<NodeType> >
class binary_search_tree
{
	public:
		typedef T					value_type;
		typedef Compare				value_compare;
		typedef NodeType			node_type;
		typedef NodeAlloc			node_alloc_type;
		typedef size_t				size_type;

	private:
		node_type*					_root;
		node_type*					_none;
		value_compare				_comp;
		node_alloc_type				_node_alloc;
		size_type					_size;

	public:
		binary_search_tree() : _comp(value_compare()), _size(0), _node_alloc(node_alloc_type())
		{
			this->_none = _node_alloc.allocate(1);
			this->_node_alloc.construct(this->_none, node_alloc_type());
			this->_none->_parent = this->_none;
			this->_none->_left = this->_none;
			this->_none->_right = this->_none;
			this->_root = this->_none;
		}

		binary_search_tree(const binary_search_tree &other) : _comp(value_compare()), _size(0), _node_alloc(node_alloc_type())
		{
			this->_none = _node_alloc.allocate(1);
			this->_node_alloc.construct(this->_none, node_alloc_type());
			this->_root = this->_none;
			this->_none->_parent = this->_none;
			this->_none->_left = this->_none;
			this->_none->_right = this->_none;
			this->_root = this->_none;
			this->bst_copy(other);
		}
		~binary_search_tree()
		{
			delete_all();
		}

		void		copy(const binary_search_tree &other)
		{
			this->delete_all();
			copy(other._root);
		}

		void		copy(const node_type *node)
		{
			if (copy(node->_value) == false)
				return ;
			copy(node->_left);
			copy(node->_right);
		}

		bool		copy(const value_type *value)
		{
			if (value == NULL)
				return (false);
			else
			{
				insert(*value);
				return (true);
			}
		}

		void		insert()

		void		delete_all()
		{
			delete_all(this->_root);
			delete_node(this->_none);
		}

		void		delete_all(node_type *node)
		{
			if (node == this->_none)
				return ;
			delete_all(node->_left);
			delete_all(node->_right);
			if (node->is_root())
			{
				delete_root();
				return ;
			}
			else if (node->is_left())
				node->_parent->_left = this->_none;
			else
				node->_parent-_right = this->_none;
			delete_node(node);
		}

		void		delete_root()
		{
			node_type *tmpNode;

			if (this->_root->_left == this->_none && this->_root->_right != this->_none) //왼쪽에 노드가 있고 오른쪽엔 노드가 없는 경우
			{
				tmpNode = this->_root->_left;
				delete_node(this->_root);
				this->_root = tmpNode;
			}
			else if (this->_root->_right == this->_none && this->_root->_left != this->_none) //오른쪽에 노드가 있고 왼쪽엔 노드가 없는 경우
			{
				tmpNode = this->_root->_right;
				delete_node(this->_root);
				this->_root = tmpNode;
			}
			else if (this->_root->_right != this->_none && this->_root->_left != this->_none) // 양쪽에 노드가 있을 경우
			{
				tmpNode = find_minimum(this->_root->_right);
				this->_root = tmpNode;
				delete_node(tmpNode);
			}
			else	//root node만 있을 경우
			{
				tmpNode = NULL;
				delete_node(this->_root);
			}
		}

		node_type	*find_minimum(node_type *node)
		{
			while (node->_left != this->_none)
				node = node->_left;
			return (node);
		}

		void		delete_node(node_type *node)
		{
			this->_node_alloc.destroy(node);
			this->_node_alloc.deallocate(node, 1);
		}
};
}
#endif