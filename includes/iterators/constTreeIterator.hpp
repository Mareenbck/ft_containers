// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   constTreeIterator.hpp                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/24 13:25:32 by mbascuna          #+#    #+#             */
// /*   Updated: 2022/10/24 17:12:38 by mbascuna         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef CONSTTREEITERATOR_HPP
// # define CONSTTREEITERATOR_HPP

// # include "iteratorTraits.hpp"
// # include "treeIterator.hpp"
// # include "../utils/rb_tree.hpp"


// namespace ft {

// 	template<typename T>
// 	class constIterTree
// 	{
// 		public:
// 			typedef T const						value_type;
// 			// typedef value_type*					pointer_node;
// 			// typedef typename T::value_type 		data_type;
// 			// typedef value_type*					pointer;
// 			// typedef value_type&					reference;
// 			typedef const value_type&			reference;
// 			typedef const value_type*			pointer;
// 			typedef std::ptrdiff_t				difference_type;
// 			typedef std::bidirectional_iterator_tag	iterator_category;

// 		private:
// 			typedef typename ft::Node<value_type>::pointer_node	pointer_node;
// 			pointer_node 						_node;

// 		public:
// 			constIterTree(void) : _node(NULL) {}
// 			constIterTree(pointer_node n) : _node(n) {}
// 			// constIterTree(const pointer_node& src)
// 			// {
// 			// 	*this = src;
// 			// }
// 			// constIterTree(const iteratorTree<T>& rhs) : _node(rhs.base()) {}
// 			constIterTree(const constIterTree& rhs) { *this = rhs; }
// 			~constIterTree() {}

// 			constIterTree& operator=(const constIterTree& rhs)
// 			{
// 				_node = rhs._node;
// 				return *this;
// 			}
// 			pointer_node base() const { return (_node); }
// 			bool operator==(const constIterTree& rhs) const	{ return (rhs._node == _node); }
// 			bool operator!=(const constIterTree& rhs) const	{ return !(rhs._node == _node); }

// 			reference operator*() const
// 			{
// 				return _node->value;
// 			}

// 			pointer operator->() const
// 			{
// 				return &_node->value;
// 			}
// 			constIterTree &operator++(void)
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
// 			constIterTree operator++(int)
// 			{
// 				constIterTree tmp(*this);
// 				++(*this);
// 				return tmp;
// 			}

// 			constIterTree &operator--(void)
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
// 			constIterTree operator--(int)
// 			{
// 				constIterTree tmp(*this);
// 				--(*this);
// 				return tmp;
// 			}
// 	};
// }

// #endif
