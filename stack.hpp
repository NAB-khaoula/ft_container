#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"
#include <stack>
#include <iostream>

namespace ft
{
    template <class T, class Container = vector<T> > 
    class stack{
        public:
	    //******************member type******************
            typedef	T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;
	    //******************member type******************
            stack(const container_type& ctnr = container_type()): c(ctnr){}
            bool empty() const{
                return (c.empty());
            }

            size_type size() const{
                return (c.size());
            }

            value_type& top(){
                return(c.back());
            }

            const value_type& top() const{
                return(c.back());
            }

            void push (const value_type& val){
                c.push_back(val);
            }

            void pop(){
                c.pop_back();
            }

            template <class T_shadow, class Container_shadow>
            friend bool operator== (const stack<T_shadow,Container_shadow>& lhs, const stack<T_shadow,Container_shadow>& rhs){
                return (lhs.c == rhs.c);
            }

            template <class T_shadow, class Container_shadow>
            friend bool operator!= (const stack<T_shadow,Container_shadow>& lhs, const stack<T_shadow,Container_shadow>& rhs){
                return (lhs.c != rhs.c);
            }

            template <class T_shadow, class Container_shadow>
            friend bool operator<= (const stack<T_shadow,Container_shadow>& lhs, const stack<T_shadow,Container_shadow>& rhs){
                return (lhs.c <= rhs.c);
            }

            template <class T_shadow, class Container_shadow>
            friend bool operator< (const stack<T_shadow,Container_shadow>& lhs, const stack<T_shadow,Container_shadow>& rhs){
                return (lhs.c < rhs.c);
            }

            template <class T_shadow, class Container_shadow>
            friend bool operator>= (const stack<T_shadow,Container_shadow>& lhs, const stack<T_shadow,Container_shadow>& rhs){
                return (lhs.c >= rhs.c);
            }

            template <class T_shadow, class Container_shadow>
            friend bool operator> (const stack<T_shadow,Container_shadow>& lhs, const stack<T_shadow,Container_shadow>& rhs){
                return (lhs.c > rhs.c);
            }

        protected:
            container_type c;
    };
}
#endif