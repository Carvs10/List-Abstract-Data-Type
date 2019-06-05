#ifndef LIST_H
#define LIST_H

#include <iostream> //cout, endl
#include <cstdlib> // size_t
#include <string>
#include <initializer_list> //ilist
#include <exception>
#include <algorithm> //std::copy

namespace sc{

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
                const_iterator( const Node * it = nullptr)
                {/*empty*/}


                const_iterator & operator*( void ) const
                {
                    return *it;
                }

                const_iterator & operator++( void )
                {   
                    it= it->next;
                    return this-> it->next;
                }

                const_iterator operator++( int )
                {
                    const_iterator temp( it );
                    it = it-> next;

                    return temp;
                }

                const_iterator & operator--( void )
                {
                    it = it->prev;
                    return this-> it->prev;
                }

                const_iterator operator--( int )
                {
                    const_iterator temp( it );
                    it = it->next;

                    return temp;
                }

                ///Comparsion ==
                const bool operator==( const const_iterator & rhs ) const
                {return this-> it == rhs.itit;}

                ///Comparsion !=
                const bool operator!=( const const_iterator & rhs ) const
                {return this-> it != rhs.it;}

            private:
                const Node *it;
                
        };


        

        
        class iterator{

            public:
                ///Iterator Constructor
                iterator( Node * it = nullptr)
                {/*empty*/}


                iterator & operator*( void ) const
                {
                    return *it;
                }

                iterator & operator++( void )
                {   
                    it= it->next;
                    return this-> it->next;
                }

                iterator operator++( int )
                {
                    iterator temp( it );
                    it = it-> next;

                    return temp;
                }

                iterator & operator--( void )
                {
                    it = it->prev;
                    return this-> it->prev;
                }

                iterator operator--( int )
                {
                    iterator temp( it );
                    it = it->next;

                    return temp;
                }

                ///Comparsion ==
                bool operator==( const iterator & rhs ) const
                {return this-> it == rhs.it;}

                ///Comparsion !=
                bool operator!=( const iterator & rhs ) const
                {return this-> it != rhs.it;}

            private:
                Node *it;

        };

        //iterator op
        //template <class T>
        iterator begin()
        {
            return iterator(this->m_head->next);
        }

        ///Special Members

        ///Default Constructor
        list():               
                SIZE { 0 },              
                m_head { new Node() },
                m_tail { new Node() }
                
        {/* Initialize the vector with null values */
                this->m_head->prev = nullptr;
                this->m_tail->next = nullptr;
                this->m_head->next = m_tail;
                this->m_tail->prev = m_head;
                std::cout << "Construiu 1\n";
                
                if(this->m_head->next == m_tail){
                    //std::cout<< "deu certo\n";
                }
        }

        ///Destructor
        ~list()
        {
            Node *aux = this->m_head->next;
            while( aux != this->m_tail ){//vai percorrer os nodes e deletar um por um
                aux = aux->next;
                delete aux->prev;

            }
            
            delete this->m_head;//vai deletar o nodes finais de head e tail
            delete this->m_tail;
            std::cout << "Destruiu\n";
        }

        /// Construct the list with count default-inserted instances of T
        explicit list( size_type count ):
                SIZE{ count },
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

                new_T->data = 0;

                ant = ant->next;
                
            }
            
            std::cout << "Construiu 2\n";
        }

        template < typename InputIt >
        list( InputIt first, InputIt last ):
            SIZE{ (size_type)(last - first)},
            m_head { new Node() },
            m_tail { new Node() }
        {
            this->m_head->prev = nullptr;
            this->m_tail->next = nullptr;
            this->m_head->next = m_tail;
            this->m_tail->prev = m_head;

            Node * aux = this->m_head;


            for( size_type i = 0; i < SIZE; i++){

                Node * new_n = new Node();

                new_n->data = *first;

                aux->next = new_n;
                new_n->prev = aux;
                new_n->next = this->m_tail;
                this->m_tail->prev = new_n;
                aux = aux->next;

                

                first++;
                //std::cout << new_n->data <<std::endl;
               // std::cout << new_n->prev->data <<std::endl;
            }
            Node * aux2 = this->m_head;
            for( size_type i = 0; i < SIZE; i++){

                aux2 = aux2->next;
                //std::cout  <<std::endl;
                //std::cout << aux2->prev->data <<std::endl;
            }

            std::cout << "Construiu 3\n";
            //std::cout << this->m_head;
        }



        
        list( const list& other ):
            SIZE{ other.SIZE },
            m_head { new Node() },
            m_tail { new Node() }
        {

            this->m_head->prev = nullptr;
            this->m_tail->next = nullptr;
            this->m_head->next = m_tail;
            this->m_tail->prev = m_head;

            Node * aux = this->m_head;
            Node * aux2 = other.m_head;

            //std::cout << aux2->data <<"\n\n";
            //aux2 = aux2->next;
            //std::cout << aux2->data <<"\n\n";

            //std::cout << "\n"<<m_head->next<<"\n";
            for(size_type i = 0; i < SIZE; i++ ){

                //std::cout << aux2->data <<"\n\n";

                Node *new_n = new Node();
                //std::cout << "Construiu 42\n";
                aux2 = aux2->next;//ponteiro percorrendo
                //std::cout << aux2->data <<"\n\n";
                aux->next = new_n;
                new_n->prev = aux;
                new_n->next = m_tail;
                this->m_tail->prev = new_n;
                //std::cout << "Construiu 41\n";
                new_n->data = aux2->data;//atribuindo os valores
                aux = aux->next;//avançando para o proximo nó
            }

            std::cout << "Construiu 4\n";

        }
        
        list ( std::initializer_list<T> ilist):
            SIZE{ ilist.size() },
            m_head { new Node() },
            m_tail { new Node() } 
        {
            this->m_head->prev = nullptr;
            this->m_tail->next = nullptr;
            this->m_head->next = m_tail;
            this->m_tail->prev = m_head;

            Node * aux = m_head;

            for( auto i(0u); i < ilist.size(); i++){

                Node * new_n = new Node();

                aux->next = new_n;
                new_n->prev = aux;
                new_n->next = m_tail;
                this->m_tail->prev = new_n;

                aux = aux->next;

                new_n->data = (*ilist.begin() + i); 
            }

            std::cout <<"Construiu 5\n";

        }
        /*
        list& operator=( const list& other ):
            SIZE{ other.SIZE },
            CAPACITY{ other.CAPACITY }
        {
            
        }

        
        list& operator=( std::initializer_list<T> ilist);
        */

        ///Operators

        size_type size() const
        {
            return SIZE;
        }

        void clear(){
            
            //Lista Vazia;
            if( m_head->next == m_tail) return;

            else{
                Node *aux = this->m_head->next;
                while( aux != this->m_tail ){//vai percorrer os nodes e deletar um por um
                    aux = aux->next;
                    delete aux->prev;
                }
            }
        };

        
        bool empty(){
            
            if( m_head->next == m_tail ){
                return true;
            }
            else{
                return false;
            } 
        }
        
        void push_front( const T & value )
        {
            SIZE = SIZE + 1;
            //Lista vazia;

            Node * val = new Node();
            if(m_head->next == m_tail){
                
                val->prev = m_head;
                m_head->next = val;
                val->next = m_tail;
                m_tail->prev = val;

            }
            else{
                Node * aux = m_head->next;
                

                val->prev = m_head;
                val->next = aux;
                aux->prev = val;
                m_head->next = val;
            
                
            }

            val->data =  value;

        }

        
        void push_back( const T & value )
        {   
            SIZE = SIZE + 1;
            //Lista vazia;
            Node * val = new Node();
            if( m_tail->prev == m_head ){
                //Node * val = new Node();
                val->prev = m_head;
                m_head->next = val;
                val->next = m_tail;
                m_tail->prev = val;

            }
            else{
                Node * aux = m_tail->prev;
                //Node * val = new Node();

                val->prev = aux;
                aux->next = val;
                val->next = m_tail;
                m_tail->prev = val;

                
            }

            val->data = value;
        }
        
        void pop_back()
        {
            SIZE = SIZE - 1;

            if(m_tail->prev == m_head) return;

            else{
                Node * aux = this->m_tail->prev;

                aux = aux->prev;
                aux->next = this->m_tail;
                this->m_tail->prev = aux;

            }

        }
        
        void pop_front()
        {
            SIZE = SIZE - 1;
            if(m_head->next == m_tail) return;

            else{
                Node * aux = this->m_head->next;

                aux = aux->next;
                aux->prev = this->m_head;
                this->m_head->next = aux;
            }

        }
        
        const T & back() const 
        {
            Node * aux = this->m_tail->prev;
            return aux->data;

        }

        const T & front() const 
        {
            Node * aux = this->m_head->next;
            return aux->data;

        }

        /*
        void assign( const T & value );


        ///Operator overloading

        bool operator==( const Vector& lhs, const Vector& rhs );

        bool operator!=( const Vector& lhs, const Vector& rhs );
        */

        /// Methods with Iterator

        iterator insert( iterator pos, const T & value){
            iterator returner = pos;

            returner--;

            Node * val = new Node();
            val->data = value;
            val->next = pos.it;

            pos.it->prev->next = val;
            val->prev = pos.it->prev;
            pos.it->prev = val;

            SIZE += 1;

            return returner;
        }

        template< typename InItr >
        //iterator insert( iterator pos, InItr first, InItr last );

        iterator erase( iterator pos ){

            iterator returner = pos.it->next;

            (pos.it->next)->prev = pos.it->prev;
            (pos.it->prev)->next = pos.it->next;

            delete pos.it;

            SIZE-= 1;

            return returner;
        }



    };
}

#endif