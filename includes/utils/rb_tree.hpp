/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:38:55 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/25 16:15:14 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>
// # include "../iterators/iteratorTraits.hpp"
// # include "../iterators/treeIterator.hpp"
// # include "../iterators/constTreeIterator.hpp"
# include "../iterators/reverseIterator.hpp"
# include "../utils/pair.hpp"

namespace ft {

	typedef enum s_color {
		RED,
		BLACK
	}	t_color;

	template <class T>
	class Node
	{
		public:
			typedef T 					value_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;
			typedef Node<value_type>*	pointer_node;

			Node(void) : left(NULL), right(NULL), parent(NULL), color(BLACK), value() {}
			Node(const T& value) : left(NULL), right(NULL), parent(NULL), color(RED),  value(value) {}
			// Node(const Node& src)
			// {
			// 	*this = src;
			// }
			~Node(void) {}

			// Node& operator=(const Node& rhs)
			// {
			// 	left = rhs.left;
			// 	right = rhs.right;
			// 	parent = rhs.parent;
			// 	color = rhs.color;
			// 	value = rhs.value;
			// 	return *this;
			// }
			pointer_node	left;
			pointer_node	right;
			pointer_node	parent;
			t_color			color;
			value_type		value;

	};

	template<typename T>
	class iteratorTree
	{
		public:
			template <class, class, class>
			friend struct rb_tree;
			typedef T							value_type;
			typedef value_type*					pointer;
			typedef value_type&					reference;
			typedef std::ptrdiff_t				difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
			// typedef typename ft::Node< value_type >::pointer_node pointer_node;
			// pointer_node 						root;
			// pointer_node 						NIL;

		private:
			typedef ft::Node<T>* pointer_node;
			pointer_node 						_node;

		public:
			iteratorTree(void) : _node(NULL) {}
			iteratorTree(pointer_node n) : _node(n) {}
			iteratorTree(const iteratorTree& src)
			{
				*this = src;
			}
			~iteratorTree(void) {}

			iteratorTree& operator=(const iteratorTree& rhs)
			{
				_node = rhs._node;
				return *this;
			}
			pointer_node base() const { return (_node); }

			reference operator*() const
			{
				return _node->value;
			}

			pointer operator->() const
			{
				return &_node->value;
				// return (&this->operator*());
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
					pointer_node tmp = _node->parent;
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
					pointer_node tmp = _node->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
					_node = tmp;
				}
				else
				{
					pointer_node tmp = _node->parent;
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

			bool operator==(const iteratorTree& rhs) const	{ return (rhs._node == _node); }
			bool operator!=(const iteratorTree& rhs) const	{ return !(rhs._node == _node); }
	};

	template<typename T>
	class constIterTree
	{
		public:
			template <class, class, class>
			friend struct rb_tree;
			typedef const T 						value_type;
			// typedef value_type*					pointer_node;
			// typedef typename T::value_type 		data_type;
			// typedef value_type*					pointer;
			// typedef value_type&					reference;
			typedef const value_type&			reference;
			typedef const value_type*			pointer;
			typedef std::ptrdiff_t				difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

		private:
			typedef ft::Node<T> *		pointer_node;
			// typedef typename ft::Node<value_type>::pointer_node	pointer_node;
			pointer_node 				_node;

		public:
			constIterTree(void) : _node(NULL) {}
			constIterTree(pointer_node n) : _node(n) {}
			// constIterTree(const pointer_node& src)
			// {
			// 	*this = src;
			// }
			// constIterTree(const iteratorTree<T>& rhs) : _node(rhs.base()) {}
			constIterTree(const iteratorTree<T>& rhs)  { *this = rhs; }
			constIterTree(const constIterTree& rhs) { *this = rhs; }
			~constIterTree(void) {}

			constIterTree	&operator=(const iteratorTree<T> &rhs)
			{
				_node = rhs.base();
				return *this;
			}
			constIterTree& operator=(const constIterTree& rhs)
			{
				_node = rhs._node;
				return *this;
			}
			pointer_node base() const { return (_node); }
			bool operator==(const constIterTree& rhs) const	{ return (rhs._node == _node); }
			bool operator!=(const constIterTree& rhs) const	{ return !(rhs._node == _node); }

			reference operator*() const
			{
				return _node->value;
			}

			pointer operator->() const
			{
				return &_node->value;
			}

			constIterTree &operator++(void)
			{
				if (_node->right != NULL)
				{
					_node = _node->right;
					while(_node->left != NULL)
						_node = _node->left;
				}
				else
				{
					pointer_node tmp = _node->parent;
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
			constIterTree operator++(int)
			{
				constIterTree tmp(*this);
				++(*this);
				return tmp;
			}

			constIterTree &operator--(void)
			{
				// if (_node->color == RED && _node->parent->parent == _node)
					// _node = _node->right;
				if (_node->left != NULL)
				{
					pointer_node tmp = _node->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
					_node = tmp;
				}
				else
				{
					pointer_node tmp = _node->parent;
					while (tmp != NULL && _node == tmp->left)
					{
						_node = tmp;
						tmp = tmp->parent;
					}
					_node = tmp;
				}
				return *this;
			}
			constIterTree operator--(int)
			{
				constIterTree tmp(*this);
				--(*this);
				return tmp;
			}
	};

	// template<typename T>
	// bool operator==(const iteratorTree<T>& x, const constIterTree<T>& y) { return x.base() == y.base(); }

	// template<typename T>
	// bool operator!=(const iteratorTree<T>& x, const constIterTree<T>& y) { return x.base() != y.base(); }

	template <class T, class Compare, class Allocator = std::allocator<Node<T> > >
	class rb_tree
	{
		public:
			typedef T										value_type; //pair
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef Compare 								value_compare;
			// typedef Compare 								key_compare;
			typedef typename Allocator::template rebind<Node<value_type> >::other allocator_type;
			typedef std::size_t								size_type;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef typename ft::Node<value_type> 				node;
			typedef node*									pointer_node;

			// typedef Node<T>									value_type;
			// typedef Allocator 								allocator_type;

			//for iterators
			typedef std::ptrdiff_t 							difference_type;
			typedef iteratorTree<T>							iterator;
			typedef constIterTree<T> 						const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			// typedef node<T> 								node;
			// typedef node* const								const_pointer_node;
			// typedef typename allocator_type::const_pointer 	const_pointer;


			pointer_node	_end;
		private:
			allocator_type	_alloc;
			size_type 		_size;
			// key_compare		_comp;
			value_compare	_comp;
			pointer_node	_root;

/***************************************CONSTRUCTORS****************************************/
		public:
			rb_tree(void)
			{
				_alloc = Allocator();
				_size = 0;
				_comp = Compare();
				_root = NULL;
				_end = create_node();
			}
			rb_tree(rb_tree const &rhs)
			{
				*this = rhs;
			}
			~rb_tree(void)
			{
				clear();
			}

		private:
			rb_tree	&operator=(const rb_tree &rhs)
			{
				// _comp = rhs._comp;
				// _root = rhs._root;
				// _end = rhs._end;
				// _size = rhs._size;
				// return *this;
				(void)rhs;
				return (*this);
			}

		public:
			void clear()
			{
				_branch_clear(_root);
				_root = NULL;
				_size = 0;
			}

			void _branch_clear(pointer_node x)
			{
				if (x != NULL)
				{
					_branch_clear(x->left);
					_branch_clear(x->right);
					_alloc.destroy(x);
					_alloc.deallocate(x, 1);
				}
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
			void delete_node(pointer_node n)
			{
				std::cout << " delete " << std::endl;
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
			}

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
				pointer_node g =  get_grand_parent(n);
				if (g == NULL)
					return NULL; // Pas de grand parent, donc pas d'oncle
				return get_bro(p);
			}

			void	left_rotate(pointer_node x)
			{
				pointer_node tmp = x->right;
				if (x->parent == NULL)
					_root = tmp;
				else
				{
					if (x == x->parent->left)
						x->parent->left = tmp;
					else
						x->parent->right = tmp;
				}
				if (tmp != NULL)
					tmp->parent = x->parent;

				x->right = tmp->left;
				if (tmp->left != NULL)
					tmp->left->parent = x;


				//on attache x a gauche de tmp
				tmp->left = x;
				x->parent = tmp;
			}
			void	right_rotate(pointer_node x)
			{
				pointer_node tmp = x->left;
				if (x->parent == NULL)
					_root = tmp;
				else
				{
					if (x == x->parent->left)
						x->parent->left = tmp;
					else
						x->parent->right = tmp;
				}
				if (tmp != NULL)
					tmp->parent = x->parent;
				x->left = tmp->right;
				if (tmp->right != NULL)
					tmp->right->parent = x;
				tmp->right = x;
				x->parent = tmp;
			}

			// iterator insert(const_reference val)
			// {
			// 	pointer_node n = create_node(node(val));
			// 	// Insertion d'un nouveau nœud dans l'arbre
			// 	ft::pair<pointer_node, bool> pair;
			// 	pair = insertion_recursif(_root, n);

			// 	// Réparation de l'arbre au cas où les propriétés rouge-noir seraient violées
			// 	insertion_repare_arbre(n);

			// 	// Recherche de la nouvelle racine à renvoyer
			// 	_root = n;

			// 	while (_root->parent != NULL)
			// 		_root = _root->parent;

			// 	return n;
			// }
			void insert(const_reference value)
			{
				pointer_node n = search(value);
				if (n != NULL)
					return;
				if (this->_size)
					this->_end->parent->right = NULL; // supprime end
				else
					this->_root = NULL;
				++this->_size;
			/* Cree un noeud rouge */
				pointer_node inserted_node = create_node(node(value));
				inserted_node->color = RED;
			/* Arbre vide on insert le noeud a la racine */
				if (this->_root == NULL)
					this->_root = inserted_node;
				else
				{
					pointer_node n = this->_root;
					while (true)
					{
					/* Tant que plus petit on se deplace a gauche jusqua trouver une place*/
						if (this->_comp(value, n->value) == true)
						{
							if (n->left == NULL && n->left != this->_end)
							{
								n->left = inserted_node;
								break;
							}
							else
								n = n->left;
						}
					/* Tant que plus grand on se deplace a droit jusqua trouver une place*/
						else
						{
							if (n->right == NULL && n->right != this->_end)
							{
								n->right = inserted_node;
								break;
							}
							else
								n = n->right;
						}
					}
				/* On le relie au reste de l'arbre.*/
					inserted_node->parent = n;
				}
			/* On verifie que les regle de larbre sont ok */
			// insert_case1(inserted_node);
			insertion_repare_arbre(inserted_node);
			/* Replace end a la fin de l'arbre */
			update_end();
		}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					insert(*first);
			}

			// ft::pair<pointer_node, bool> insertion_recursif(pointer_node root, pointer_node n)
			// {
			// 	// Descente récursive dans l'arbre jusqu'à atteindre une feuille
			// 	if (_root != NULL && _comp(n->value, root->value))
			// 	{
    		// 		if (_root->left != NULL)
			// 			return insertion_recursif(_root->left, n);
			// 		else
			// 			_root->left = n;
  			// 	}
			// 	else if (_root != NULL && _comp(_root->value, n->value))
			// 	{
			// 		if (_root->right != NULL)
			// 			return insertion_recursif(_root->right, n);
			// 		else
			// 			_root->right = n;
  			// 	}
			// 	else if (_root != NULL)
			// 		return ft::make_pair(_root, false);
  			// 	// Insertion du nouveau noeud n
			// 	n->parent = _root;
			// 	n->left = NULL;
			// 	n->right = NULL;
			// 	n->color = RED;
			// 	return ft::make_pair(n, true);
			// }
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
					if (n == n->parent->right && n->parent == g->left)
					{
						left_rotate(p);
						n = n->left;
					}
					else if (n == n->parent->left && n->parent == g->right)
					{
						right_rotate(p);
						n = n->right;
					}
					n->parent->color = BLACK;
					get_grand_parent(n)->color = RED;
					if (n == n->parent->left && n->parent == get_grand_parent(n)->left)
						right_rotate(get_grand_parent(n));
					else
						left_rotate(get_grand_parent(n));
				}
 			}

		void update_end(void)
		{

			if (_size == 0)
			{
				if (_end == NULL)
					_end = create_node();
				_root = _end;
				return;
			}
			pointer_node max = get_max(_root);
			max->right = _end;
			this->_end->parent = max;
		}

			void clear(pointer_node root)
			{
				std::cout << "clear " << std::endl;
				if (_root == NULL || _root == _end)
				{
					this->_size = 0;
					this->update_end();
					return;
				}
				clear(root->left);
				clear(root->right);
				delete_node(root);
			}

		/* Renvoie le pointeur vers l'element passe en param ou null */
		pointer_node search(const_reference val)
		{
			pointer_node n = this->_root;
			while (n != NULL)
			{
				/* Element trouve */
				if (this->_comp(val, n->value) == false && this->_comp(n->value, val) == false && n != this->_end)
					return (n);
				/* plus petit va a gauche */
				else if (this->_comp(val, n->value) == true)
					n = n->left;
				/* Plus grand va a droite */
				else
					n = n->right;
			}
			return (n);
		}
		pointer_node search(const_reference val) const
		{
			pointer_node n = this->_root;
			while (n != NULL)
			{
				if (this->_comp(val, n->value) == false && this->_comp(n->value, val) == false)
					return (n);
				else if (this->_comp(val, n->value) == true)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}

/***************************************ITERATORS****************************************/
			iterator begin(void)
			{
				//renvoi le minimum
				iterator it = get_min(_root);
				return it;
			}
			const_iterator begin(void) const
			{
				const_iterator it = get_min(_root);
				return it;
			}
			iterator end(void)
			{
				return iterator(get_end());
			}
			const_iterator end(void) const
			{
				return const_iterator(get_end());
			}
			reverse_iterator rbegin(void)
			{
				iterator it = end();
				return reverse_iterator(it);
			}
			const_reverse_iterator rbegin(void) const
			{
				const_iterator it = end();
				return const_reverse_iterator(it);
			}
			reverse_iterator rend(void)
			{
				iterator it = begin();
				return reverse_iterator(it);
			}
			const_reverse_iterator rend(void) const
			{
				const_iterator it = begin();
				return const_reverse_iterator(it);
			}

/***************************************UTILS****************************************/

			pointer_node get_min(pointer_node n)
			{
				if (_size == 0)
					return (_end);
				while (n->left != NULL)
					n = n->left;
				return (n);
			}

			pointer_node get_max(pointer_node n)
			{
				while (n->right != NULL && n->right != _end)
					n = n->right;
				return (n);
			}

	};
}

#endif
