#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP
# include <memory>
# include <iostream>
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
		typedef T														value_type;
		typedef Compare													value_compare;
		typedef NodeType												node_type;
		typedef NodeAlloc												node_alloc_type;
		typedef size_t													size_type;
		typedef ft::binary_search_tree_iterator<T, T*, T&>				iterator;
		typedef ft::binary_search_tree_iterator<T, const T*, const T&>	const_iterator;
	private:
		node_type*					_root;
		node_type*					_none;
		value_compare				_comp;
		node_alloc_type				_node_alloc;
		size_type					_size;

	public:
		binary_search_tree(const node_alloc_type& init_node_alloc = node_alloc_type())
		:
			_comp(value_compare()), _node_alloc(init_node_alloc), _size(0)
		{
			this->_none = _node_alloc.allocate(1);
			this->_node_alloc.construct(this->_none, node_type(_none, _none, _none));
			this->_root = this->_none;
		}

		binary_search_tree(const binary_search_tree<value_type> &other, const node_alloc_type& init_node_alloc = node_alloc_type())
		:
			_comp(value_compare()), _node_alloc(node_alloc_type(init_node_alloc)), _size(0)
		{
			this->_none = _node_alloc.allocate(1);
			this->_node_alloc.construct(this->_none, node_type(_none, _none, _none));
			this->_root = this->_none;
			this->copy(other);
		}
		~binary_search_tree()
		{
			delete_all();
			delete_node(this->_none);
		}

		node_type*				get_root() const
		{
			return (this->_root);
		}

		node_type*				get_none() const
		{
			return (this->_none);
		}

		size_type				get_size() const
		{
			return (this->_size);
		}

		void					copy(const binary_search_tree<T> &other)
		{
			this->delete_all();
			copy(other._root);
		}

		void					copy(const node_type *node)
		{
			if (copy(node->_value) == false)
				return ;
			copy(node->_left);
			copy(node->_right);
		}

		bool					copy(const value_type *value)
		{
			if (value == NULL)
				return (false);
			else
			{
				insert_pair(*value);
				return (true);
			}
		}

		bool					is_empty() const
		{
			if (this->_root == this->_none)
				return (true);
			else
				return (false);
		}

		node_type				*get_lowest() const
		{
			node_type			*cur;
			node_type			*parent;

			if (is_empty())
				return (this->_none);
			cur = this->_root;
			while (cur != this->_none)
			{
				parent = cur;
				cur = cur->_left;
			}
			return (parent);
		}

		void					erase(iterator position)
		{
			erase_case(position->get_ptr());
		}

		pair<node_type*, bool>	insert_pair(const value_type &value)
		{
			node_type	*node;
			node_type	*parent;
			node_type	*cur;

			node = construct_node(value);

			if (this->is_empty())
			{
				this->_root = node;
				this->_root->_parent = this->_none;
				this->_root->_left = this->_none;
				this->_root->_right = this->_none;
				this->_none->_parent = find_maximum(_root);
				this->_size += 1;
				return (pair<node_type*, bool>(this->_root, true));
			}
			cur = this->_root;
			parent = this->_none;
			while (cur != this->_none)
			{
				parent = cur;
				if (cur->get_value().first == value.first)
				{
					delete_node(node);
					return (pair<node_type *, bool>(cur, false));
				}
				else if (_comp(value, *(cur->_value)))
					cur = cur->_left;
				else if (_comp(*(cur->_value), value))
					cur = cur->_right;
			}
			// 루프가 끝나면 none노드에 도착한다.
			cur = node;
			cur->_left = this->_none;
			cur->_right = this->_none;
			if (this->_comp(*(parent->_value), *(cur->_value)))
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent;
			this->_none->_parent = find_maximum(this->_root);
			this->_size++;
			return (pair<node_type *, bool>(cur, true));
		}

		void					delete_all()
		{
			delete_all(this->_root);
		}

		void					delete_all(node_type *node)
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
				node->_parent->_right = this->_none;	
			delete_node(node);
		}

		iterator				search_by_key(const value_type &value) const
		{
			iterator	it;

			it = iterator(get_lowest());
			while (it != iterator(this->get_none()))
			{
				if (it->first == value.first)
					return (it);
				it++;
			}
			return (it);
		}

		void					delete_root()
		{
			node_type	*tmpNode;

			if (this->_root->_left == this->_none && this->_root->_right != this->_none) //왼쪽에 노드가 있고 오른쪽엔 노드가 없는 경우
			{
				tmpNode = this->_root->_left;
				tmpNode->_parent = this->_none;
				tmpNode->_right = this->_root->_right;
				delete_node(this->_root);
				this->_root = tmpNode;
			}
			else if (this->_root->_right == this->_none && this->_root->_left != this->_none) //오른쪽에 노드가 있고 왼쪽엔 노드가 없는 경우
			{
				tmpNode = this->_root->_right;
				tmpNode->_parent = this->_none;
				tmpNode->_left = this->_root->_left;
				delete_node(this->_root);
				this->_root = tmpNode;
			}
			else if (this->_root->_right != this->_none && this->_root->_left != this->_none) // 양쪽에 노드가 있을 경우
			{
				// node_type	*tmpRoot;

				// tmpRoot = this->_root;
				// tmpNode = find_minimum(this->_root->_right);
				// this->_root = tmpNode;
				// this->_root->_left = tmpRoot->_left;
				// this->_root->_right = tmpRoot->_right;
				// this->_root->_parent = this->_none;
				// delete_node(tmpRoot);
			}
			else	//root node만 있을 경우
			{
				tmpNode = this->_none;
				delete_node(this->_root);
				this->_root = this->_none;
			}
		}

		node_type				*find_minimum(node_type *node)
		{
			while (node->_left != this->_none)
				node = node->_left;
			return (node);
		}

		node_type				*find_maximum(node_type *node)
		{
			while (node->_right != this->_none)
				node = node->_right;
			return (node);
		}

		void					delete_node(node_type *node)
		{
			this->_node_alloc.destroy(node);
			this->_node_alloc.deallocate(node, 1);
			this->_size--;
		}

		node_type				*construct_node(const value_type &value)
		{
			node_type			*node;

			node = _node_alloc.allocate(1);
			this->_node_alloc.construct(node, node_type(value));
			node->_parent = this->_none;
			node->_left = this->_none;
			node->_right = this->_none;
			return (node);
		}

	private:
		void					erase_case(node_type *node)
		{
			if (node->is_root())
				delete_root();
			else if (node->_left == this->_none && node->_right == this->_none)
				erase_case1(node);
			else if (node->_left != this->_none && node->_right == this->_none)
				erase_case2(node);
			else if (node->_left == this->_none && node->_right != this->_none)
				erase_case3(node);
			else if (node->_left != this->_none && node->_right != this->_none)
				erase_case4(node);
		}

		void					erase_case1(node_type *node)
		{
			if (node->is_left())
				node->_parent->_left = this->_none;
			else if (node->is_right())
				node->_parent->_right = this->_none;
			delete_node(node);
		}

		void					erase_case2(node_type *node)
		{
			node_type	*tmpNode;

			node->_parent->_left = node->_left;
			node->_left->_parent = node->_parent;
			delete_node(node);
		}

		void					erase_case3(node_type *node)
		{
			node->_parent->_right = node->_right;
			node->_right->_parent = node->_parent;
			delete_node(node);
		}

		void					erase_case4(node_type *node)
		{
		}
};
}
#endif