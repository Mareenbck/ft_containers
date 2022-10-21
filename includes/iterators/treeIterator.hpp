/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:11:22 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/21 13:55:09 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "iteratorTraits.hpp"
# include "../utils/rb_tree.hpp"

namespace ft {

	template<class T>
	class iteratorTree
	{
		private:
			typedef ft::node<T>*		node;
			node 						_node;

		public:
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef value_type *				pointer;
			typedef value_type &				reference;
			typedef bidirectional_iterator_tag	iterator_category;

			iteratorTree(void) : _node() {}
			iteratorTree(node n) : _node(n) {}
			iteratorTree(const node& src)
			{
				*this = src;
			}
			~iteratorTree(void) {}

			iteratorTree& operator=(const iteratorTree& rhs)
			{
				_node = rhs._node;
				return *this;
			}

			bool operator==(const iteratorTree& rhs) const	{ return (rhs._node == _node); }
			bool operator!=(const iteratorTree& rhs) const	{ return !(rhs._node == _node); }

			reference operator*() const
			{
				return _node->value;
			}

			pointer operator->() const
			{
				return &_node->value;
			}
			iteratorTree &operator++(void)
			{
				if (_node->right != NULL)
				{
					_node = _node->right;
					while(_node->left != NULL)
						_node = _node->left;
				}
				else
				{
					node tmp = _node->parent;
					while(tmp != NULL && _node == tmp->right)
					{
						_node = tmp;
						tmp = tmp->parent;
					}
					// if (_node->right != tmp)
					_node = tmp;
				}
				return *this;
			}
			iteratorTree operator++(int)
			{
				iteratorTree tmp(*this);
				++(*this);
				return tmp;
			}

			iteratorTree &operator--(void)
			{
				// if (_node->color == RED && _node->parent->parent == _node)
					// _node = _node->right;
				if (_node->left != NULL)
				{
					node tmp = _node->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
					_node = tmp;
				}
				else
				{
					node tmp = _node->parent;
					while (tmp != NULL && _node == tmp->left)
					{
						_node = tmp;
						tmp = tmp->parent;
					}
					_node = tmp;
				}
				return *this;
			}
			iteratorTree operator--(int)
			{
				iteratorTree tmp(*this);
				--(*this);
				return tmp;
			}

			iteratorTree	base(void) const
			{
				return _node;
			}
	};
}

#endif
