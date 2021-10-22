#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "vector.hpp"
#include "iterator.hpp"

	//****************** reverse_iterator struct***************************

template <class Iterator>
	class reverse_iterator : public iterator<std::random_access_iterator_tag, typename iterator_traits<Iterator>::value_type >
	{
		public:

			//****************** reverse_iterator member types ***************************
			typedef Iterator													iterator_type;
    		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
    		typedef typename iterator_traits<iterator_type>::value_type			value_type;
    		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
    		typedef typename iterator_traits<iterator_type>::pointer			pointer;
    		typedef typename iterator_traits<iterator_type>::reference			reference;
			//****************** reverse_iterator member types ***************************

			//****************** constructors ***************************
			reverse_iterator() : _iter(nullptr){
			}

			explicit reverse_iterator (iterator_type it){
				_iter = it;
			}

			reverse_iterator(const reverse_iterator& iter) : _iter(iter._iter){
			}

			//****************** constructors ***************************

			//****************** operators overload ***************************
			iterator_type base() const{
				return(this->_iter);
			}

			reverse_iterator& operator--(){
				this->_iter++;
				return (*this);
			}

			reverse_iterator  operator--(int){
				reverse_iterator post_increment = *this;
				this->_iter++;
				return (post_increment);
			}

			reverse_iterator& operator++(){
				this->_iter--;
				return (*this);
			}

			reverse_iterator  operator++(int){
				reverse_iterator post_increment = *this;
				this->_iter--;
				return (post_increment);
			}

			reference operator*() const{
				return(*(_iter - 1));
			}

			reverse_iterator operator+(difference_type n) const{				
				reverse_iterator newReverseIterator(this->_iter);
				newReverseIterator += n;
				return (newReverseIterator);
			}

			reverse_iterator &operator+=(difference_type n){
				this->_iter = this->_iter - n;
				return(*this);
			}

			reverse_iterator operator-(difference_type n) const{
				reverse_iterator newReverseIterator(this->_iter);
				newReverseIterator -= n;
				return (newReverseIterator);
			}


			reverse_iterator &operator-=(difference_type n){
				this->_iter = this->_iter + n;
				return(*this);
			}

			pointer operator->() const {
  				return &(operator*());
			}

			reference operator[] (difference_type n) const{
				return (*(this->_iter - n - 1));
			}

			//****************** operators overload non member function ***************************
			friend typename reverse_iterator<Iterator>::difference_type operator+ (const reverse_iterator<Iterator>& n, const reverse_iterator<Iterator>& it){
				return (it._iter + n._iter);
			}

			friend typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& n, const reverse_iterator<Iterator>& it){
				return (it._iter - n._iter);
			}

			friend bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs._iter == rhs._iter);
			}
			friend bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs._iter != rhs._iter);
			}
			friend bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs._iter > rhs._iter);
			}
			friend bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs._iter >= rhs._iter);
			}
			friend bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs._iter < rhs._iter);
			}
			friend bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
				return (lhs._iter <= rhs._iter);
			}
			//****************** operators overload non member function ***************************
			//****************** operators overload ***************************

		protected:
			iterator_type _iter;
	};
		//****************** reverse_iterator struct***************************


#endif