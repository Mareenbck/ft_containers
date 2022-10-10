#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft{

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		// typedef implementation-defined iterator;
		// typedef implementation-defined const_iterator;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

	private:
			size_type _size;
			// size_type _capacity;
			value_type *_tab;
			allocator_type _alloc;

	public:
	//CONSTRUCTEURS
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_tab = NULL;
			_size = 0;
		}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_size = 0;
			_tab = new T[n];
			_alloc = alloc;
			for (size_t i = 0; i < n; i++)
				_tab[i] = val;
		}

		template <class InputIterator> vector(InputIterator first, InputIterator last, const Allocator& allocator)
		{

		}

		vector(const vector& x)
		{
			_size = x._size;
			if (_tab != NULL)
				delete [] _tab;
			_tab = new T[x._size];
			for (size_t i = 0; i < x._size; i++)
				_tab[i] = x._tab[i];
			return *this;
		}
};

}
#endif
