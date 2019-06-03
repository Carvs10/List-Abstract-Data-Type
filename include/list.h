#ifndef LIST_H
#define LIST_H

#include <iostream> //cout, endl
#include <cstdlib> // size_t
#include <string>
#include <initializer_list> //ilist
#include <exception>
#include <algorithm> //std::copy

namespace ls{

    template < typename T >
    class List{

        public:

        class iterator{

        };


        class const_iterator{

        };

        using size_type = unsigned long;

        ///Special Members

        list();

        explicit list();

        template < typename InputIt >
        list( InputIt first, InputIt last );

        list(const list& other);

        list ( std::initializer_list<T> ilist);

        ~list();

        list& operator=( const list& other );

        list& operator=( std::initializer_list<T> ilist);

        ///Operators

        size_type size() const;

        void clear();

        bool empty();

        void push_front( const T & value);

        void push_back( const T & value );

        void pop_back();

        void pop_front();

        const T & back() const ;

        const T & front() const ;

        void assign( const T & value );


        ///Operator overloading

        bool operator==( const Vector& lhs, const Vector& rhs );

        bool operator!=( const Vector& lhs, const Vector& rhs );

        /// Methods with Iterator

        iterator insert( iterator pos, const T & value);

        template< typename InItr >
        iterator insert( iterator pos, InItr first, InItr last );

        



    };
}

#endif