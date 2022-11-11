/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:38:55 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/11 15:43:11 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>
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
			~Node(void) {}

			Node& operator=(const Node& rhs)
			{
				if (this == &rhs)
					return (*this);
				this->left = rhs.left;
				this->right = rhs.right;
				this->parent = rhs.parent;
				this->color = rhs.color;
				this->value = rhs.value;
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
			typedef T							value_type;
			typedef value_type*					pointer;
			typedef value_type&					reference;
			typedef std::ptrdiff_t				difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

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
			}
			iteratorTree &operator++(void)
			{
				if (!_node)
					return (*this);
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
			typedef const T 						value_type;
			typedef const value_type&			reference;
			typedef const value_type*			pointer;
			typedef std::ptrdiff_t				difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

		private:
			typedef ft::Node<T> *		pointer_node;
			pointer_node 				_node;

		public:
			constIterTree(void) : _node(NULL) {}
			constIterTree(pointer_node n) : _node(n) {}
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

	template <class T, class Compare, class Allocator = std::allocator<Node<T> > >
	class rb_tree
	{
		public:
			typedef T										value_type; //pair
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef Compare 								value_compare;
			typedef typename Allocator::template rebind<Node<value_type> >::other allocator_type;
			typedef std::size_t								size_type;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef ft::Node<value_type> 			node;
			typedef node*									pointer_node;

			//for iterators
			typedef std::ptrdiff_t 							difference_type;
			typedef iteratorTree<T>							iterator;
			typedef constIterTree<T> 						const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			allocator_type	_alloc;
			size_type 		_size;
			pointer_node	_end;
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
				delete_node(_end);
			}
			rb_tree	&operator=(const rb_tree &rhs)
			{
				(void)rhs;
				return (*this);
			}

/***************************************MODIFIERS****************************************/

		void clear(pointer_node root)
		{
			if (root == NULL || root == _end)
			{
				_size = 0;
				return;
			}
			clear(root->left);
			clear(root->right);
			delete_node(root);
			_root = NULL;
			_size = 0;
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
				if (search(val) != NULL)
					return;
				if (_size)
					_end->parent->right = NULL;
				else
					_root = NULL;
				pointer_node n = create_node(node(val));
				if (_root == NULL)
					_root = n;
				else
					n = insertion_recursif(_root, n);
				_size++;
				insertion_repare_arbre(n);
				update_end();
			}

			pointer_node insertion_recursif(pointer_node root, pointer_node n)
			{
				if (_comp(n->value, root->value))
				{
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
				_root = _end;
				return;
			}
			pointer_node max = get_max(_root);
			max->right = _end;
			_end->parent = max;
		}

		pointer_node search(const_reference val)
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

		void transplant(pointer_node old_node, pointer_node new_node)
		{
			if (old_node->parent == NULL)
				_root = new_node;
			else if (old_node == old_node->parent->left)
				old_node->parent->left = new_node;
			else
				old_node->parent->right = new_node;
			if (new_node != NULL)
				new_node->parent = old_node->parent;
		}



		void	erase(pointer_node node)
		{
			pointer_node x = NULL;
			if (!node)
				return ;
			if (node->left != NULL && node->right != NULL)
			{
				pointer_node previous = get_max(node->left);
				node->value = previous->value;
				node = previous;
			}
			if (node->left == NULL)
				x = node->right;
			else if (node->right == NULL)
				x = node->left;
			if (node->color == BLACK)
				delete_fix(node);
			transplant(node, x);
			_size--;
			delete_node(node);
			update_end();
		}

		t_color get_color(pointer_node n)
		{
			return (n == NULL ? BLACK : n->color);
		}

		void delete_fix(pointer_node x)
		{
			pointer_node sibling;
			while (x != _root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					sibling = x->parent->right;
					if (get_color(sibling) == RED)
					{
						sibling->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						sibling = x->parent->right;
					}
					if (get_color(sibling->left) == BLACK && get_color(sibling->right) == BLACK)
					{
						sibling->color = RED;
						x = x->parent;
					}
					else
					{
						if (get_color(sibling->right) == BLACK)
						{
							sibling->left->color = BLACK;
							sibling->color = RED;
							right_rotate(sibling);
							sibling = x->parent->right;
						}
						sibling->color = x->parent->color;
						x->parent->color = BLACK;
						sibling->right->color = BLACK;
						left_rotate(x->parent);
						x = _root;
					}
				}
				else
				{
					sibling = x->parent->left;
					if (get_color(sibling) == RED)
					{
						sibling->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						sibling = x->parent->left;
					}
					if (get_color(sibling->right) == BLACK && get_color(sibling->left) == BLACK)
					{
						sibling->color = RED;
						x = x->parent;
					}
					else
					{
						if (get_color(sibling->left) == BLACK)
						{
							sibling->right->color = BLACK;
							sibling->color = RED;
							left_rotate(sibling);
							sibling = x->parent->left;
						}
						sibling->color = x->parent->color;
						x->parent->color = BLACK;
						sibling->left->color = BLACK;
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
					return NULL;
				return p->parent;
			}
			pointer_node get_bro(pointer_node n)
			{
				pointer_node p = n->parent;
				if (p == NULL)
					return NULL;
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
					return NULL;
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
				while (n && n->right != NULL && n->right != _end)
					n = n->right;
				return (n);
			}

			pointer_node get_max(pointer_node n) const
			{
				while (n->right != NULL && n->right != _end)
					n = n->right;
				return (n);
			}

//************************************************************************************************************
			// void printTree(pointer_node node, int i = 0)
			// {
			// 	if (!node && i == 0 && _root)
			// 		printTree(_root);
			// 	else if (node != NULL)
			// 	{
			// 		std::cout << "Depth: " << i << " Key: " << node->value.first << " value: " << node->value.second << std::endl;
			// 		if (node->left)
			// 			printTree(node->left, i + 1);
			// 		if (node->right)
			// 			printTree(node->right, i + 1);
			// 	}
			// }
	};
}

#endif
