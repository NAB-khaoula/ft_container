#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "vector.hpp"

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
	//******************base struct iterator***************************
	
	//******************iterator_traits that convert normal pointer***************************
	template<typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
	//******************iterator_traits that convert normal pointer/ const pointer***************************

	//******************customized iterator struct***************************
	template <class Iterator>
	class customizedIterator : public iterator<std::random_access_iterator_tag, typename iterator_traits<Iterator>::value_type >
	{
		public:

			//****************** customizedIterator member types ***************************
			typedef Iterator													iterator_type;
    		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
    		typedef typename iterator_traits<iterator_type>::value_type			value_type;
    		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
    		typedef typename iterator_traits<iterator_type>::pointer			pointer;
    		typedef typename iterator_traits<iterator_type>::reference			reference;
			//****************** customizedIterator member types ***************************

			//****************** constructors ***************************
			customizedIterator(): _iter(nullptr){
			}

			customizedIterator(iterator_type iter): _iter(iter){	
			}

			customizedIterator(const customizedIterator& iter): _iter(iter._iter){
			}

			//****************** constructors ***************************

			//****************** operators overload ***************************
			iterator_type base() const{
				return(this->_iter);
			}

			reference operator*() const{
				return(*_iter);
			}

			customizedIterator& operator++(){
				this->_iter++;
				return (*this);
			}

			customizedIterator  operator++(int){
				customizedIterator post_increment = *this;
				this->_iter++;
				return (post_increment);
			}

			customizedIterator operator+(difference_type n) const{
				return (this->_iter + n);
			}

			customizedIterator &operator+=(difference_type n){
				this->_iter = this->_iter + n;
				return(*this);
			}

			customizedIterator operator-(difference_type n) const{
				return (this->_iter - n);
			}

			customizedIterator& operator--(){
				this->_iter--;
				return (*this);
			}

			customizedIterator  operator--(int){
				customizedIterator post_increment = *this;
				this->_iter--;
				return (post_increment);
			}

			customizedIterator &operator-=(difference_type n){
				this->_iter = this->_iter - n;
				return(*this);
			}

			pointer operator->() const {
  				return &(operator*());
			}

			reference operator[] (difference_type n) const{
				return (*(this->_iter + n));
			}

			//****************** operators overload non member function ***************************
			friend typename customizedIterator<Iterator>::difference_type operator+ (const customizedIterator<Iterator>& n, const customizedIterator<Iterator>& it){
				return (it._iter + n._iter);
			}

			friend typename customizedIterator<Iterator>::difference_type operator- (const customizedIterator<Iterator>& n, const customizedIterator<Iterator>& it){
				return (n._iter - it._iter);
			}
			friend bool operator== (const customizedIterator<Iterator>& lhs, const customizedIterator<Iterator>& rhs){
				return (lhs._iter == rhs._iter);
			}
			friend bool operator!= (const customizedIterator<Iterator>& lhs, const customizedIterator<Iterator>& rhs){
				return (lhs._iter != rhs._iter);
			}
			friend bool operator< (const customizedIterator<Iterator>& lhs, const customizedIterator<Iterator>& rhs){
				return (lhs._iter < rhs._iter);
			}
			friend bool operator<= (const customizedIterator<Iterator>& lhs, const customizedIterator<Iterator>& rhs){
				return (lhs._iter <= rhs._iter);
			}
			friend bool operator> (const customizedIterator<Iterator>& lhs, const customizedIterator<Iterator>& rhs){
				return (lhs._iter > rhs._iter);
			}
			friend bool operator>= (const customizedIterator<Iterator>& lhs, const customizedIterator<Iterator>& rhs){
				return (lhs._iter >= rhs._iter);
			}
			//****************** operators overload non member function ***************************
			//****************** operators overload ***************************

		protected:
			iterator_type _iter;
	};
	//****************** customizedIterator struct***************************

#endif