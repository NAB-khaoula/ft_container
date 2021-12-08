#ifndef MAP_HPP
#define MAP_HPP
// #include <memory>
// #include <iostream>
// #include <math.h>
// #include <cstddef>
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
		typedef typename allocator_type::pointer									pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		typedef _tree_iterator<value_type, binaryTreeNode<value_type> >				iterator;
		typedef _tree_iterator<const value_type, binaryTreeNode<value_type> >		const_iterator;
		typedef reverse_iterator<const_iterator>									const_reverse_iterator;
		typedef reverse_iterator<iterator>											reverse_iterator;
		typedef typename allocator_type::size_type									size_type;
		typedef typename allocator_type::difference_type							difference_type;
		typedef binarySearchTree<value_type, key_compare>							binarySearchTree;

		// NOTE **************************constructors**********************************
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(), _size(0), _allocator(alloc), _cmp(comp){}
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(), _size(0), _allocator(alloc), _cmp(comp){
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
			if (_size)
				this->clear();
			this->insert(x.begin(), x.end());
			_size = x.size();
			return (*this);
		}

		~map(){}
		// NOTE **************************constructors**********************************

		// NOTE **************************iterator function**********************************
		iterator begin(){
			return (iterator (_tree.get_min()));
		}

		const_iterator begin() const{
			return (const_iterator (_tree.get_min()));
		}

		iterator end(){
			iterator it(_tree.get_max());
			if (!(_tree.isempty()))
				++it;
			return (it);
		}

		const_iterator end() const{
			iterator it(_tree.get_max());
			if (!(_tree.isempty()))
				++it;
			return (const_iterator (it));
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
		// NOTE **************************iterator function**********************************

		// NOTE **************** capacity *******************
		bool empty() const{
			return (_tree.isempty());
		}

		size_type size() const{
			return (_size);
		}

		size_type max_size() const{
			return (_tree.max_size());
		}
		// NOTE **************** capacity *******************

		// NOTE **************** Element access *******************
		mapped_type& operator[] (const key_type& k){
			return ((*((this->insert(pair<key_type, mapped_type>(k,mapped_type()))).first)).second);
		}
		// NOTE **************** Element access *******************

		// NOTE **************** Modifiers *******************
		// NOTE ************insert**********
		pair<iterator,bool> insert (const value_type& val){
			binaryTreeNode<value_type> *foundNode = _tree.search(val);

			if (!foundNode)
			{
				_tree.insert(val);
				_size++;
				return (pair<iterator, bool>(_tree.search(val), true));
			}
			else
				return (pair<iterator, bool>(foundNode, false));
		}

		iterator insert (iterator position, const value_type& val){
			static_cast<void>(position);
			return ((this->insert(pair<key_type, mapped_type>(val.first,val.second))).first);
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
			if (_tree.search(pair<key_type, mapped_type>(k, mapped_type())))
			{
				_tree.delete_node(make_pair(k, mapped_type()));
				_size--;
				return (1);
			}
			return (0);
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
		// NOTE **************** Modifiers *******************

		// NOTE **************** Operations: *******************
		
		iterator find (const key_type& k){
			return (_tree.search(make_pair<key_type, mapped_type>(k, mapped_type())));
		}

		const_iterator find (const key_type& k) const{
			return (_tree.search(make_pair<key_type, mapped_type>(k, mapped_type())));
		}

		size_type count (const key_type& k) const{
			if (_tree.search(make_pair<key_type, mapped_type>(k, mapped_type())))
				return 1;
			return 0;
		}

		iterator lower_bound (const key_type& k){
			iterator it = this->begin();
			key_compare comparing;
			while(it != this->end())
			{
				if (!(comparing(it->first,k)))
					return (it); 
				it++;
			}
			return it;
		}

		const_iterator lower_bound (const key_type& k) const{
			iterator it = this->begin();
			key_compare comparing;
			while(it != this->end())
			{
				if (!(comparing(it->first,k)))
					return (it); 
				it++;
			}
			return (const_iterator (it));
		}

		iterator upper_bound (const key_type& k){
			iterator it = this->begin();
			key_compare comparing;
			while(it != this->end())
			{
				if (it->first == k)
					return (++it);
				if (!(comparing(it->first,k)))
					return (it); 
				it++;
			}
			return it;
		}

		const_iterator upper_bound (const key_type& k) const{
			iterator it = this->begin();
			key_compare comparing;
			while(it != this->end())
			{
				if (it->first == k)
					return (++it);
				if (!(comparing(it->first,k)))
					return (it); 
				it++;
			}
			return (const_iterator (it));
		}

		pair<iterator,iterator>	equal_range (const key_type& k){
			return(make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return(make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

		// NOTE **************** Observers: *******************
		key_compare key_comp() const{
			return (key_compare());
		}

		value_compare value_comp() const{
			return (value_compare(key_compare()));
		}

		// NOTE **************** Observers: *******************
		
		// NOTE **************** Allocator: *******************
		allocator_type get_allocator() const{
			return (allocator_type());
		}
		// NOTE **************** Allocator: *******************

		void Treeprint()
		{
			_tree.printTree();
		}

		protected:
			binarySearchTree	_tree;
			size_type			_size;
			allocator_type		_allocator;
			key_compare			_cmp;
	};
		
}
#endif