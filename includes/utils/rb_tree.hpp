/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:38:55 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/07 13:29:28 by mbascuna         ###   ########.fr       */
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

	// #define NULL NULL

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

			Node& operator=(const Node& rhs)
			{
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				color = rhs.color;
				value = rhs.value;
				return *this;
			}
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
			// template <class, class, class>
			// friend struct rb_tree;
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
			// template <class, class, class>
			// friend struct rb_tree;
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
				clear(_root);
				// if (_size == 0)
				delete_node(_end);
				// clear();
			}
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

/***************************************MODIFIERS****************************************/

			// void clear()
			// {
			// 	_branch_clear(_root);
			// 	_root = NULL;
			// 	_size = 0;
			// }


		void clear(pointer_node root)
		{
			if (root == NULL || root == _end)
			{
				_size = 0;
				return;
			}
			clear(root->left);// rappelle recursivement
			clear(root->right);
			delete_node(root);
			_root = NULL;
			_size = 0;
		}

			// void _branch_clear(pointer_node x)
			// {
			// 	if (x != NULL)
			// 	{
			// 		_branch_clear(x->left);
			// 		_branch_clear(x->right);
			// 		_alloc.destroy(x);
			// 		_alloc.deallocate(x, 1);
			// 	}
			// }
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
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
			}

			void swap(rb_tree &tree)
			{
				allocator_type tmp_alloc = tree._alloc;
				size_type tmp_size = tree._size;
				value_compare tmp_comp = tree._comp;
				pointer_node tmp_root = tree._root;
				pointer_node tmp_end = tree._end;

				tree._alloc = this->_alloc;
				tree._size = this->_size;
				tree._comp = this->_comp;
				tree._root = this->_root;
				tree._end = this->_end;

				this->_alloc = tmp_alloc;
				this->_size = tmp_size;
				this->_comp = tmp_comp;
				this->_root = tmp_root;
				this->_end = tmp_end;
			}

/***************************************OPERATIONS****************************************/

			void	left_rotate(pointer_node x)
			{
				pointer_node y = x->right;

				x->right = y->left;
				if (y->left != NULL)
					y->left->parent = x;
				if (y != NULL)
					y->parent = x->parent;
				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;

			}

			void	right_rotate(pointer_node x)
			{
				pointer_node y = x->left;

				x->left = y->right;
				if (y->right != NULL)
					y->right->parent = x;
				if (y != NULL)
					y->parent = x->parent;
				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			void insert(const_reference val)
			{
				// pointer_node x = search(val);
				if (search(val) != NULL)
					return;
				if (_size)
					_end->parent->right = NULL; // supprime end
				else
					_root = NULL;
				pointer_node n = create_node(node(val));
				n->color = RED;
				if (_root == NULL)
					_root = n;
				else
					n = insertion_recursif(_root, n);
				_size++;
				insertion_repare_arbre(n);
				// update_end();
				pointer_node max = get_max(_root);
				max->right = _end;
				_end->parent = max;
			}

			pointer_node insertion_recursif(pointer_node root, pointer_node n)
			{
				//Compare newKey with rootKey.
				if (_comp(n->value, root->value))
				{
					//If newKey is greater than rootKey, traverse through the left subtree
					if (root->left != NULL)
						return insertion_recursif(root->left, n);
					else
						root->left = n;
				}
				else if (root != NULL && _comp(root->value, n->value))
				{
					if (root->right != NULL)
						return insertion_recursif(root->right, n);
					else
						root->right = n;
				}
				n->parent = root;
				n->left = NULL;
				n->right = NULL;
				n->color = RED;
				return n;
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					insert(*first);
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

		void assign_end()
		{
			pointer_node maxNode = get_max(_root);
			maxNode->right = _end;
			_end->parent = maxNode;
			_end->right = NULL;
			_end->left = NULL;
			_end->color = BLACK;
		}
		// pointer_node search(const_reference val)
		// {
		// 	// value_type data_key(k, this->_comp);
		// 	pointer_node ptr = search_recursif(this->_root, val);
		// 	if (ptr == NULL)
		// 		return NULL;
		// 	return (ptr);
		// }
		// pointer_node search_recursif(pointer_node node, const_reference val)
		// {
		// 	if (node == NULL )
		// 		return NULL;
		// 	if (_comp(val, node->value))
		// 		return search_recursif(node->left, val);
		// 	else
		// 		return search_recursif(node->right, val);
		// }

		pointer_node search(const_reference val)
		{
			pointer_node current = _root;
			while (current != NULL)
			{
				if (_comp(val, current->value) == false && _comp(current->value, val) == false && current != this->_end)
					return current;
				else if (_comp(val, current->value) == true)
					current = current->left;
				else if (_comp(current->value, val))
					current = current->right;
			}
			return NULL;
		}

		pointer_node search(const_reference val) const
		{
			pointer_node current = _root;
			while (current != NULL)
			{
				if (_comp(val, current->value))
					current = current->left;
				else if (_comp(current->value, val))
					current = current->right;
				else
					return current;
			}
			return NULL;
		}

		void transplant(pointer_node child, pointer_node parent)
		{
			if (parent == _root)
			{
				_root = child;
				child->parent = NULL;
				return ;
			}
			child->parent = parent->parent;
			if (parent == child->parent->left)
				child->parent->left = child;
			else
				child->parent->right = child;
		}

		void printTree(pointer_node node, int i = 0)
		{
			if (!node && i == 0 && _root)
				printTree(_root);
			else if (node != NULL)
			{
				std::cout << "Depth: " << i << " Key: " << node->value.first << " value: " << node->value.second << std::endl;
				if (node->left)
					printTree(node->left, i + 1);
				if (node->right)
					printTree(node->right, i + 1);
			}
		}

		void	erase(pointer_node node)
		{
			// printTree(_root);
			t_color origrinalColor = node->color;
			pointer_node x;
			pointer_node y = node;
			if (!node->left && !node->right)
			{
				if (node == _root)
					_root = NULL;
				else
				{
					if (node == node->parent->left)
						node->parent->left = NULL;
					else
						node->parent->right = NULL;
				}
				delete_node(node);
				_size--;
				assign_end();
				return;
			}
			else if (!node->left || !node->right)
			{
				if (!node->left)
					transplant(node->right, node);
				else
					transplant(node->left, node);
				delete_node(node);
				_size--;
				assign_end();
			}
			else
			{
				y = get_min(node->right);
				origrinalColor = y->color;
				x = y->right;
				if (node == y->parent)
					x->parent = y;
				else
				{
					transplant(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				// transplant(node, y);
				// y->left = node->left;
				// y->left->parent = y;
				// y->color = node->color;
				y->color = origrinalColor;
				delete_node(node);
				_size--;
				assign_end();
			}
			if (origrinalColor == BLACK)
				delete_fix(x);
		}

		void delete_fix (pointer_node x)
		{
			pointer_node s;
			while (x != _root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->right->color == BLACK)
						{
							s->left->color = BLACK;
							s->color = RED;
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						left_rotate(x->parent);
						x = _root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if (s->right->color == BLACK && s->left->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == BLACK)
						{
							s->right->color = BLACK;
							s->color = RED;
							left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						right_rotate(x->parent);
						x = _root;
					}
				}
			}
			x->color = BLACK;
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

/***************************************ELEMENT ACCESS****************************************/

			allocator_type get_allocator(void) const { return (_alloc); }
			size_type get_size(void) const { return (_size); }
			pointer_node get_root(void) const { return (_root); }
			pointer_node get_end(void) const { return (_end); }
			size_type max_size() const {return _alloc.max_size();}

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

			pointer_node get_min(pointer_node n)
			{
				if (_size == 0)
					return (_end);
				while (n->left != NULL)
					n = n->left;
				return (n);
			}

			pointer_node get_min(pointer_node n) const
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

			pointer_node get_max(pointer_node n) const
			{
				while (n->right != NULL && n->right != _end)
					n = n->right;
				return (n);
			}


	};
}

#endif
