// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   treeIterator.hpp                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/21 12:11:22 by mbascuna          #+#    #+#             */
// /*   Updated: 2022/10/25 10:57:04 by mbascuna         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef TREE_ITERATOR_HPP
// # define TREE_ITERATOR_HPP

// # include "../utils/rb_tree.hpp"
// # include "iteratorTraits.hpp"
// // # include "constTreeIterator.hpp"
// // #include "../iterators/reverseIterator.hpp"
// // #include "../utils/pair.hpp"

// namespace ft {

// 	// template <typename T>
// 	// class constIterTree;

// 	template<typename T>
// 	class iteratorTree
// 	{
// 		public:
// 			typedef T							value_type;
// 			typedef value_type*					pointer;
// 			typedef value_type&					reference;
// 			typedef std::ptrdiff_t				difference_type;
// 			typedef std::bidirectional_iterator_tag	iterator_category;
// 			typedef typename ft::Node< value_type >::pointer_node pointer_node;
// 			// typedef ft::Node<T>* pointer_node;
// 			pointer_node 						_node;
// 			pointer_node 						root;
// 			pointer_node 						NIL;

// 		private:

// 		public:
// 			iteratorTree(void) : _node(NULL) {}
// 			iteratorTree(pointer_node n) : _node(n) {}
// 			iteratorTree(const iteratorTree<T>& src)
// 			{
// 				*this = src;
// 			}
// 			~iteratorTree(void) {}

// 			iteratorTree& operator=(const iteratorTree& rhs)
// 			{
// 				_node = rhs._node;
// 				root = rhs.root;
// 				NIL = rhs.NIL;
// 				return *this;
// 			}
// 			pointer_node base() const { return (_node); }

// 			reference operator*() const
// 			{
// 				return _node->value;
// 			}

// 			pointer operator->() const
// 			{
// 				// return &_node->value;
// 				return (&this->operator*());
// 			}
// 			iteratorTree &operator++(void)
// 			{
// 				if (_node->right != NULL)
// 				{
// 					_node = _node->right;
// 					while(_node->left != NULL)
// 						_node = _node->left;
// 				}
// 				else
// 				{
// 					pointer_node tmp = _node->parent;
// 					while(tmp != NULL && _node == tmp->right)
// 					{
// 						_node = tmp;
// 						tmp = tmp->parent;
// 					}
// 					// if (_node->right != tmp)
// 					_node = tmp;
// 				}
// 				return *this;
// 			}
// 			iteratorTree operator++(int)
// 			{
// 				iteratorTree tmp(*this);
// 				++(*this);
// 				return tmp;
// 			}

// 			iteratorTree &operator--(void)
// 			{
// 				// if (_node->color == RED && _node->parent->parent == _node)
// 					// _node = _node->right;
// 				if (_node->left != NULL)
// 				{
// 					pointer_node tmp = _node->left;
// 					while (tmp->right != NULL)
// 						tmp = tmp->right;
// 					_node = tmp;
// 				}
// 				else
// 				{
// 					pointer_node tmp = _node->parent;
// 					while (tmp != NULL && _node == tmp->left)
// 					{
// 						_node = tmp;
// 						tmp = tmp->parent;
// 					}
// 					_node = tmp;
// 				}
// 				return *this;
// 			}
// 			iteratorTree operator--(int)
// 			{
// 				iteratorTree tmp(*this);
// 				--(*this);
// 				return tmp;
// 			}

// 			bool operator==(const iteratorTree& rhs) const	{ return (rhs._node == _node); }
// 			bool operator!=(const iteratorTree& rhs) const	{ return !(rhs._node == _node); }
// 	};


// }

// #endif
