#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "algorithm.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include "__tree.hpp"
#include "_tree_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft{

	template < class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<pair<const Key,T> > >
	class map{
		public:
		typedef Key																key_type;
		typedef T																mapped_type;
		typedef pair<const key_type, mapped_type> 								value_type;
		typedef Compare															key_compare;
		typedef Alloc															allocator_type;
		typedef value_type&						 								reference;
		typedef const value_type&												const_reference;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
				friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c){}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				result_type operator() (const first_argument_type& x, const second_argument_type& y) const
				{
				  return comp(x.first, y.first);
				}
		};
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef _tree_iterator<value_type, binaryTreeNode<value_type> >			iterator;
		typedef _tree_iterator<const value_type, binaryTreeNode<value_type> >	const_iterator;
		typedef reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef reverse_iterator<iterator>										reverse_iterator;
		typedef typename allocator_type::size_type								size_type;
		typedef typename allocator_type::difference_type						difference_type;
		typedef binarySearchTree<value_type, key_compare>						binarySearchTree;
		// NOTE constructors
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(), _size(0){}
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			while(first != last)
			{
				_tree.insert(*first);
				_size++;
				first++;
			}
		}
		
		map (const map& x){
			(*this) = x;
		}

		map& operator=(const map& x)
		{
			_tree = x._tree;
			_size = x._size;
			return (*this);
		}
		//FIXME need to destroy the object in my destructor;
		~map(){}

		//NOTE iterator function
		iterator begin(){
			return (iterator (_tree.get_min()));
		}

		const_iterator begin() const{
			return (const_iterator (_tree.get_min()));
		}

		iterator end(){
			iterator it(_tree.get_max());
			it++;
			return (it);
		}

		const_iterator end() const{
			const_iterator it(_tree.get_max());
			it++;
			return (it);
		}

		reverse_iterator rbegin(){
			return (reverse_iterator (end()));
		}

		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator (end()));
		}

		reverse_iterator rend(){
			return (reverse_iterator (begin()));
		}

		const_reverse_iterator rend() const{
			return (const_reverse_iterator (begin()));
		}

		// NOTE **************** insert *******************

		pair<iterator,bool> insert (const value_type& val){
			binaryTreeNode<value_type> *foundNode = _tree.search(val);
			if (!foundNode)
			{
				_tree.insert(val);
				_size++;
				return (make_pair<iterator, bool>(_tree.search(val), true));
			}
			else
				return (make_pair<iterator, bool>(foundNode, false));
		}

		// FIXME need to review the algorithm;
		iterator insert (iterator position, const value_type& val){
			_tree.insert(val);
			_size++;
			return (_tree.search(val));
		}

		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last){
			while(first != last)
			{
				_tree.insert(*first);
				_size++;
				first++;
			}
		}

		void clear(){
			while(_size--)
				_tree.delete_node(_tree.get_min()->_data);
		}

		size_type erase (const key_type& k){
			_tree.delete_node(make_pair(k, mapped_type()));
			return (1);
		}

		void erase (iterator position){
			_tree.delete_node(*position);
			_size--;
		}

		void erase (iterator first, iterator last){
			while (first != last)
			{
				_tree.delete_node(*first);
				first++;
				_size--;
			}
		}

		void swap (map& x){
			map temp = x;
			x = (*this);
			(*this) = temp;
		}

		// NOTE **************** capacity *******************
		bool empty() const{
			return (_tree.isempty());
		}

		size_type size() const{
			return (_size);
		}

		size_type max_size() const{
			return (std::min(std::numeric_limits<difference_type>::max(), _allocator.max_size()));
		}

		// NOTE **************** Element access *******************
		mapped_type& operator[] (const key_type& k){
			return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
		}

		// NOTE **************** Operations: *******************

		void Treeprint()
		{
			_tree.printTree();
		}

		protected:
			binarySearchTree	_tree;
			size_type			_size;
			allocator_type		_allocator;
	};
		
}
#endif