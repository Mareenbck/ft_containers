/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:38:55 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/21 17:12:20 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>
# include "../iterators/treeIterator.hpp"
# include "../iterators/reverseIterator.hpp"

namespace ft {

	typedef enum s_color {
		RED,
		BLACK
	}	t_color;

	template <typename T>
	struct node
	{
		T	value;
		T*	left;
		T*	right;
		T*	parent;
		t_color color;

		node() : value(),left(NULL), right(NULL), parent(NULL), color(BLACK) {
		}
		node(const T& value) : value(value), left(NULL), right(NULL), parent(NULL), color(RED) {
		}
		node(const node& src)
		{
			*this = src;
		}
		~node();

		node& operator=(const node& rhs)
		{
			value = rhs.value;
			left = rhs.left;
			right = rhs.right;
			parent = rhs.parent;
			color = RED;
			return *this;
		}

	};

	template <class T, class Compare, class Alloc = std::allocator<node<T>>>
	class rb_tree
	{
		public:
			typedef node<T>							value_type;
			typedef	std::allocator<value_type>		allocator;
			typedef value_type 						&reference;
			typedef const value_type				&const_reference;
			typedef node<T>							*pointer_node;
			typedef node<T>							*const_pointer_node;
			typedef	iteratorTree<pointer_node>		iterator;
			typedef	iteratorTree<const_pointer_node> const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::size_t								size_type;

		private:
			allocator		_alloc;
			Compare			_comp;
			pointer_node	_root;
			pointer_node	_head;
			size_type 		_size;

		public:
			explicit rb_tree(void)
			{
				_alloc.construct(_head, value_type());
				_head = _alloc.allocate(1);
				_head->parent = _root;
				_head->left = _head;
				_head->right = _head;
				_head->color = RED;
				_size = 0;
			}

			~rb_tree(void)
			{
				// clear()
				_alloc.deallocate(_head, 1);
			}

			rb_tree	&operator=(const rb_tree &rhs)
			{
				_comp = rhs._comp;
				_root = rhs._root;
				_head = rhs._head;
				_size = rhs._size;
				return *this;
			}

			iterator begin(void)
			{
				return iterator(_root);
			}
			const_iterator begin(void) const
			{
				return const_iterator(_root);
			}
			iterator end(void)
			{
				return iterator(_head);
			}
			const_iterator end(void)
			{
				return const_iterator(_head);
			}
			pointer_node get_grand_parent(pointer_node n)
			{
				pointer_node p = n->parent;
				if (p == NULL)
					return NULL; // Un noeud sans parent n'a pas de grand-parent
				return p->parent;
			}
			pointer_node get_bro(pointer_node n)
			{
				pointer_node p = n->parent;
				if (p == NULL)
					return NULL; // Un noeud sans parent n'a pas de frere
				if (n == p->left)
					return p->right;
				else
					return p->left;
			}
			pointer_node get_uncle(pointer_node n)
			{
				pointer_node p = n->parent;
				pointer_node g =  get_grand_parent(n)
				if (g == NULL)
					return NULL; // Pas de grand parent, donc pas d'oncle
				return frere(p);
			}

			void	left_rotate(pointer_node x)
			{
				pointer_node tmp = x->right;
				//le fils droit de x devient le fils gauche de tmp
				x->right = tmp->left;
				if (tmp->left != NULL)
					tmp->left->parent = x;
				tmp->parent = x->parent;

				//si x est root, tmp devient root, sinon remplace x par tmp
				if (x->parent == NULL)
					x = tmp;
				else if (x == x->parent->left)
					x->parent->left = tmp;
				else
					x->parent->right = tmp;

				//on attache x a gauche de tmp
				tmp->left = x;
				x->parent = tmp;
			}
			void	right_rotate(pointer_node x)
			{
				pointer_node tmp = x->left;
				x->left = tmp->right;
				if (tmp->right != NULL)
					tmp->right->parent = x;
				tmp->parent = x->parent;
				if (x->parent == NULL)
					x = tmp;
				else if (x == x->parent->right)
					x->parent->right = tmp;
				else
					x->parent->left = tmp;
				tmp->right = x;
				x->parent = tmp;
			}

			pointer_node insertion(pointer_node n)
			{
				// Insertion d'un nouveau nœud dans l'arbre
				insertion_recursif(_root, n);

				// Réparation de l'arbre au cas où les propriétés rouge-noir seraient violées
				insertion_repare_arbre(n);

				// Recherche de la nouvelle racine à renvoyer
				_root = n;

				while (_root->parent != NULL)
					_root = _root->parent;

				return _root;
			}
			void insertion_recursif(pointer_node n)
			{
				// Descente récursive dans l'arbre jusqu'à atteindre une feuille
				if (_root != NULL && n->value < _root->value)
				{
    				if (_root->left != NULL)
					{
						insertion_recursif(_root->left, n);
						return;
					}
					else
						_root->left = n;
  				}
				else if (_root != NULL)
				{
					if (_root->right != NULL)
					{
						insertion_recursif(_root->right, n);
						return;
					}
					else
						_root->right = n;
  				}
  				// Insertion du nouveau noeud n
				n->parent = _root;
				n->left = NULL;
				n->right = NULL;
				n->color = RED;
			}
			void insertion_repare_arbre(pointer_node n)
			{
				if (n->parent == NULL)
					n->color = BLACK;
				else if (n->parent->color == BLACK)
					return ;
				else if (get_uncle(n) != NULL && get_uncle(n)->color == RED)
				{
					n->parent->color = BLACK;
					get_uncle(n)->color = BLACK;
					pointer_node g = get_grand_parent(n);
					g->color = RED;
					insertion_repare_arbre(g);
				}
				else
				{
					pointer_node p = n->parent;
					pointer_node g = get_grand_parent(n);
					if (n == g->left->right)
					{
						left_rotate(p);
						n = n->left;
					}
					else if (n == g->right->left)
					{
						right_rotate(p)
						n = n->right;
					}
					pointer_node p = n->parent;
					pointer_node g = get_grand_parent(n);
					if (n == p->left)
						right_rotate(g);
					else
						left_rotate(g);
					p->color = BLACK;
					g->color = RED;
				}
 			}

}

#endif
