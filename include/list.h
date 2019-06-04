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
            std::size_t CAPACITY;       //!<
            Node *m_head;               //!< Head node of the list
            Node *m_tail; 

        public:



        using size_type = unsigned long;
        ///Classe precia de ajustes, não esta completa;
        class const_iterator{

            public:
                ///Iterator Constructor
                const_iterator( Node * curr):
                    {}
                {/*empty*/}

                const Object & operator*( void ) const
                {

                }

                const_iterator & operator++( void )
                {
                    return this-> current->next;
                }

                const_iterator operator++( int )
                {
                    Node * iterator temp( current );
                    current = current-> next;

                    return temp;
                }

                const_iterator & operator--( void )
                {
                    return this-> current->prev;
                }

                const_iterator operator--( int )
                {
                    Node * iterator temp( current );
                    current = current->prev;

                    return temp;
                }

                ///Comparsion ==
                bool operator==( const const_iterator & rhs ) const
                {return this-> current == it.current;}

                ///Comparsion !=
                bool operator!=( const const_iterator & rhs ) const
                {return this-> current != it.current;}

            private:
                Node *current;
                const_iterator(Node *p) : current( p );
                friend class List<Object>;
        };


        };

        /*
        class const_iterator{

        };*/

        ///Special Members

        ///Default Constructor
        list():               
                SIZE { 0 },
                CAPACITY{ 0 },              
                m_head { new Node() },
                m_tail { new Node() }
                
        {/* Initialize the vector with null values */
                this->m_head->prev = nullptr;
                this->m_tail->next = nullptr;
                this->m_head->next = m_tail;
                this->m_tail->prev = m_head;
                std::cout << "Construiu 1\n";
                
                if(this->m_head->next == m_tail){
                    std::cout<< "deu certo\n";
                }
        }

        ///Destructor
        ~list()
        {
            Node *aux = this->m_head->next;
            while( aux != this->m_tail ){//vai percorrer os nodes e deletar um por um
                aux = aux->next;

            }
            
            delete this->m_head;//vai deletar o nodes finais de head e tail
            delete this->m_tail;
            std::cout << "Destruiu\n";
        }

        /// Construct the list with count default-inserted instances of T
        explicit list( size_type count ):
                SIZE{ 0 },
                CAPACITY{ count },
                m_head { new Node() },
                m_tail { new Node() }

        {   
            this->m_head->prev = nullptr;
            this->m_tail->next = nullptr;
            this->m_head->next = m_tail;
            this->m_tail->prev = m_head;
            Node * ant = m_head;

            for(size_t i = 0; i < count; i++){
                Node * new_T = new Node();
                ant->next = new_T;
                new_T->prev = ant;
                new_T->next = m_tail;
                this->m_tail->prev = new_T;

                ant = ant->next;
                
            }
            
            std::cout << "Construiu 2\n";
        }

        template < typename InputIt >
        list( InputIt first, InputIt last ):
            SIZE{ (size_type)(last - first)},
            CAPACITY{ (size_type)(last - first)},
            m_head { new Node() },
            m_tail { new Node() }
        {
            this->m_head->prev = nullptr;
            this->m_tail->next = nullptr;
            this->m_head->next = m_tail;
            this->m_tail->prev = m_head;

            Node * aux = m_head;

            for( size_type i = 0; i < CAPACITY; i++){

                Node * new_n = new Node();
                aux->next = new_n;
                new_n->prev = aux;
                new_n->next = m_tail;
                this->m_tail->prev = new_n;

                new_n->data = *first;

                first++;
                std::cout << new_n->data;
            }

            std::cout << "Construiu 3\n";
        }

        
        list( const list& other )
            SIZE{ other.SIZE },
            CAPACITY{ other.CAPACITY },
            m_head { new Node() },
            m_tail { new Node() }
        {

            this->m_head->prev = nullptr;
            this->m_tail->next = nullptr;
            this->m_head->next = m_tail;
            this->m_tail->prev = m_head;

            Node * aux = m_head;

            for(size_type i = 0; i < CAPACITY; i++ ){

                Node *new_n = new Node();
                aux->next = new_n;
                new_n->prev = aux;
                new_n->next = m_tail;
                this->m_tail->prev = new_n;

                new_n->data = 
            }

            std::cout << "Construiu 4\n";

        }
        /*
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