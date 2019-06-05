/*!
 * \ File list.h
 * \ Implemetation of class Abstract Data Type List
 * \ Authors João Victtor and Pedro Henrique
 */

#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include <cstdlib> // size_t
#include <string> //strings
#include <initializer_list> //ilist
#include <exception>
#include <algorithm> //std::copy

namespace sc{

    template < typename T >

    //! Class list
    /*!
       Contains the methods
    */

    class list{

        private:

            //! Struct of a Node
            /*! Contains nodes previous/next adresses, and it's data. */
            struct Node {
                T data;
                Node *prev;
                Node *next;
                Node( const T & d = T(), Node *p = nullptr, Node *n = nullptr ):
                    data(d), prev(p), next(n){}
            };

            std::size_t SIZE;           //!< Total size of the list
            Node *m_head;               //!< Head node of the list
            Node *m_tail;               //!< Tail node of the list

        public:



        using size_type = unsigned long;

        //! Class Const Iterator
        class const_iterator{

            public:

                //! Const Iterator Constructor
                const_iterator( const Node * it = nullptr)
                {/*empty*/}

                //! Const Iterator Destructor
                ~const_iterator()
                {/*empty*/}

                //! Const Iterator oparator
                const_iterator & operator*( void ) const
                {
                    return *it;
                }

                //! Const Iterator oparator
                const_iterator & operator++( void )
                {   
                    it= it->next;
                    return this-> it->next;
                }

                //! Const Iterator oparator
                const_iterator operator++( int )
                {
                    const_iterator temp( it );
                    it = it-> next;

                    return temp;
                }

                //! Const Iterator oparator
                const_iterator & operator--( void )
                {
                    it = it->prev;
                    return this-> it->prev;
                }

                //! Const Iterator oparator
                const_iterator operator--( int )
                {
                    const_iterator temp( it );
                    it = it->next;

                    return temp;
                }

                //! Const Iterator oparator
                T operator*()
                {
                    return it->data;
                }
                //! Comparsion ==
                const bool operator==( const const_iterator & rhs ) const
                {return this-> it == rhs.itit;}

                //! Comparsion !=
                const bool operator!=( const const_iterator & rhs ) const
                {return this-> it != rhs.it;}

            private:
                //! The private pointer
                const Node *it;
                
        };


        

        //! Class Iterator
        class iterator{

            public:

                //! Iterator Constructor
                iterator( Node * it = nullptr)
                {/*empty*/}

                //! Iterator Destructor
                ~iterator()
                {/*empty*/}

                //! Const Iterator oparator
                iterator & operator*( void ) const
                {
                    return *it;
                }

                //! Const Iterator oparator
                iterator & operator++( void )
                {   
                    it= it->next;
                    return this-> it->next;
                }

                //! Const Iterator oparator
                iterator operator++( int )
                {
                    iterator temp( it );
                    it = it-> next;

                    return temp;
                }

                //! Const Iterator oparator
                iterator & operator--( void )
                {
                    it = it->prev;
                    return this-> it->prev;
                }

                //! Const Iterator oparator
                iterator operator--( int )
                {
                    iterator temp( it );
                    it = it->next;

                    return temp;
                }

                //! Const Iterator oparator
                T operator*()
                {
                    return it->data;
                }
                //! Comparsion ==
                bool operator==( const iterator & rhs ) const
                {return this-> it == rhs.it;}

                //! Comparsion !=
                bool operator!=( const iterator & rhs ) const
                {return this-> it != rhs.it;}

            private:
                Node *it;

        };

        //! Iterator method
        iterator begin()
        {
            iterator it(this->m_head->next);
            return it;
        }

        //! Iterator method
        const const_iterator cbegin() const
        {
            iterator it(this->m_head->next);
            return it;
        }

        //! Iterator method
        iterator end()
        {
            iterator it(this->m_tail);
            return it;
        }

        //! Iterator method
        const iterator cend() const
        {
            const_iterator it(this->m_tail);
            return it;
        }

        //! Special Members

        //! Constructor Default
        list():               
                SIZE { 0 },              
                m_head { new Node() },
                m_tail { new Node() }
                
        {/* Initialize the vector with null values */
                this->m_head->prev = nullptr;
                this->m_tail->next = nullptr;
                this->m_head->next = m_tail;
                this->m_tail->prev = m_head;
                //std::cout << "Construiu 1\n";
                
                if(this->m_head->next == m_tail){
                    
                }
        }

        //! Destructor
        ~list()
        {
            Node *aux = this->m_head->next;
            while( aux != this->m_tail ){
                aux = aux->next;
                delete aux->prev;

            }
            
            delete this->m_head;
            delete this->m_tail;
            //std::cout << "Destruiu\n";
        }

        //! Construct the list with count default-inserted instances of T
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
            
            //std::cout << "Construiu 2\n";
        }

        template < typename InputIt >

        //! Contructor that recives a range: first and last
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
                
            }
            Node * aux2 = this->m_head;
            for( size_type i = 0; i < SIZE; i++){

                aux2 = aux2->next;
                
            }

            //std::cout << "Construiu 3\n";
        }

        //! Contructor of a list with another list
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

           
            for(size_type i = 0; i < SIZE; i++ ){

                Node *new_n = new Node();

                aux2 = aux2->next;

                aux->next = new_n;
                new_n->prev = aux;
                new_n->next = m_tail;
                this->m_tail->prev = new_n;
 
                new_n->data = aux2->data;
                aux = aux->next;
            }

            //std::cout << "Construiu 4\n";

        }
        
        //! Constructor with a inicialization list (not tested !)
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

            //std::cout <<"Construiu 5\n";

        }
        //not done!
        /*
        list& operator=( const list& other ):
            SIZE{ other.SIZE },
            CAPACITY{ other.CAPACITY }
        {           
        }
        list& operator=( std::initializer_list<T> ilist);
        */

        //! Operators (class methods)

        //! Size operator
        size_type size() const
        {
            return SIZE;
        }

        //! Clear operator
        void clear(){
            
            if( m_head->next == m_tail) return;

            else{
                Node *aux = this->m_head->next;
                while( aux != this->m_tail ){
                    aux = aux->next;
                    delete aux->prev;
                }
            }
        };

        //! Empty operator
        bool empty(){
            
            if( m_head->next == m_tail ){
                return true;
            }
            else{
                return false;
            } 
        }
        
        //! Push front operator
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

        //! Push back operator
        void push_back( const T & value )
        {   
            SIZE = SIZE + 1;

            Node * val = new Node();
            if( m_tail->prev == m_head ){
 
                val->prev = m_head;
                m_head->next = val;
                val->next = m_tail;
                m_tail->prev = val;

            }
            else{
                Node * aux = m_tail->prev;

                val->prev = aux;
                aux->next = val;
                val->next = m_tail;
                m_tail->prev = val;

                
            }

            val->data = value;
        }
        
        //! Pop back operator
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
        
        //! Pop front operator
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
        
        //! Back operator
        const T & back() const 
        {
            Node * aux = this->m_tail->prev;
            return aux->data;

        }

        //! Front operator
        const T & front() const 
        {
            Node * aux = this->m_head->next;
            return aux->data;

        }

        //not done!
        /*
        void assign( const T & value );

        */

        //! Operator overloading

        //! Equal overloading operator
        friend bool operator==( const list& lhs, const list& rhs ){

            
            if( lhs.size() == rhs.size() ){

                Node * aux = lhs.m_head;
                Node * aux2 = rhs.m_head;

                for(int i =0; i < rhs.size(); i++){

                    aux = aux->next;
                    aux2 = aux2->next;

                    if(aux->data != aux2->data){


                        return false;
                    }
                }
                return true;
            }
            else{
                return false;
            }

        }

        //! Note equal overloading operator
        friend bool operator!=( const list& lhs, const list& rhs ){

            if(lhs.size() == rhs.size() ){

                Node * aux = lhs.m_head;
                Node * aux2 = rhs.m_head;

               for(size_type i = 0; i < rhs.size(); i++){

                    aux = aux->next;
                    aux2 = aux2->next;

                    if(aux->data != aux2->data){
                        return true;
                    }
                }
                
                return false;
            }
            else{
                return true;
            }
        }
        

        //! Methods with Iterator (not tested)

        //! Incert method (not tested)
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

        // not done
        // terator insert( iterator pos, InItr first, InItr last );

        //! Erase method (not tested)
        iterator erase( iterator pos ){

            iterator returner = pos.it->next;

            (pos.it->next)->prev = pos.it->prev;
            (pos.it->prev)->next = pos.it->next;

            delete pos.it;

            SIZE -= 1;

            return returner;
        }
    };
}

#endif