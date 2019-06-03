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

    class list{

        private:

            /** Contains nodes previous/next adresses, and it's data. */
            struct Node {
                T data;
                Node *prev;
                Node *next;
                Node( const T & d = T(), Node *p = nullptr, Node *n = nullptr ):
                    data(d), prev(p), next(n){}
            };

            std::size_t SIZE;           //!< Total size of the list
            Node *m_head;               //!< Head node of the list
            Node *m_tail; 

        public:



        using size_type = unsigned long;

        /*class iterator{

        };


        class const_iterator{

        };*/

        ///Special Members

        list():               
                SIZE { 0 },              
                m_head { new Node() },
                m_tail { new Node() }
                
        {/* Initialize the vector with null values */
                this->m_head->prev = m_tail;
                this->m_tail->next = m_head;
                std::cout << "contruiu 1\n";
        }

        ~list()//não ta funcionando
        {
            Node *aux = this->m_head;
            while( aux != this->m_tail ){//vai percorrer os nodes e deletar um por um
                aux = aux->next;

                std::cout << "lo\n";

                if( aux->prev != this->m_head ){//procedimento para impedir de deletar o head nesse momento
                    delete aux->prev;
                }

            }
            std::cout << "2lo\n";
            delete this->m_head;//vai deletar o nodes finais de head e tail
            delete this->m_tail;
            std::cout << "3lo\n";
        }

        /*
        explicit list();

        template < typename InputIt >
        list( InputIt first, InputIt last );

        list(const list& other);

        list ( std::initializer_list<T> ilist);

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

        */



    };
}

#endif