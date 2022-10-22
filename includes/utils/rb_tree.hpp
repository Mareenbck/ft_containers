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
		typedef T 					value_type;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		typedef value_type*			pointer;
		typedef const value_type*	const_pointer;
		typedef node<value_type>*	node_pointer;

		node(void) : value(),left(NULL), right(NULL), parent(NULL), color(BLACK) {}
		node(const T& value) : value(value), left(NULL), right(NULL), parent(NULL), color(RED) {}
		node(const node& src)
		{
			*this = src;
		}
		~node(void) {}

		node& operator=(const node& rhs)
		{
			value = rhs.value;
			left = rhs.left;
			right = rhs.right;
			parent = rhs.parent;
			color = rhs.color;
			return *this;
		}
		node_pointer left;
		node_pointer right;
		node_pointer parent;
		t_color color;
		value_type value;
	};

	template <class T, class Compare, class Alloc = std::allocator<node<T> > >
	class rb_tree
	{
		public:
			typedef T										value_type; //pair
			// typedef node<T>								value_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef Compare 								value_compare
			typedef typename Allocator::template rebind<node<value_type>>::other allocator_type;
			typedef std::size_t								size_type;
			typedef typename allocator_type::pointer 		pointer;
			typedef typename allocator_type::const_pointer 	const_pointer;
			typedef node<T> 								node;
			typedef node*									pointer_node;
			// typedef	iteratorTree<pointer_node>		iterator;
			// typedef	iteratorTree<const_pointer_node> const_iterator;
			// typedef ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			allocator_type	_alloc;
			size_type 		_size;
			value_compare	_comp;
			pointer_node	_root;
			pointer_node	_end;

		public:
			explicit rb_tree(void)
			{
				_alloc = Alloc();
				_size = 0;
				_comp = Compare();
				_root = NULL;
				_end = create_node();
			}
			rb_tree(rb_tree const &rhs) { *this = rhs; }
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

			pointer_node create_node(void)
			{
				pointer_node n = _alloc.allocate(1);
				_alloc.construct(n, node());
				return (n);
			}
			pointer_node create_node(node p)
			{
				pointer_node n = _alloc.allocate(1);
				_alloc.construct(n, p);
				return (n);
			}

			// iterator begin(void)
			// {
			// 	return iterator(_root);
			// }
			// const_iterator begin(void) const
			// {
			// 	return const_iterator(_root);
			// }
			// iterator end(void)
			// {
			// 	return iterator(_end);
			// }
			// const_iterator end(void)
			// {
			// 	return const_iterator(_end);
			// }
			allocator_type get_allocator(void) const { return (_alloc); }
			size_type get_size(void) const { return (_size); }
			pointer_node get_root(void) const { return (_root); }
			pointer_node get_end(void) const { return (_end); }

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
				return get_bro(p);
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
	};
}

#endif
