#include "included.h"





#if not defined(_LIBCPP_IOSTREAM)
    #include <iostream>
#endif





#define _DATA_STRUCTURES_



// for debugging. Comment out in real time.

// #if not defined(_LIBCPP_IOSTREAM)
//     #include <iostream>
// #endif




/**
Known Bugs:
    * Cannot handle nested data structures of the same type.
*/



/**
 * @brief Namespace of the exceptions used for the data structures.
 * @a Data_Structure_Exceptions
 * @attention Contains the following data structures:
 *      *   MemoryError
 *      *   IllegalIndex
 *      *   Empty_Data_Structure
 *      *   Not_Yet_Implemented
 *      *   UnsupportedOperator
 * 
 */
namespace Data_Structure_Exceptions {

    class MemoryError {

        private:
            char* msg;

        public:

            MemoryError(char* msg = (char*) "Memory management error") {
                this->msg = msg;
            }

            ~MemoryError() throw() {
                // std::free(this->msg);
                return;
            }

            char* what() {
                return this->msg;
            }

    };
    
    class IllegalIndex {

        private:
            char* msg;

        public:

            IllegalIndex(char* msg = (char*) "Illegal index referenced") {
                this->msg = msg;
            }

            ~IllegalIndex() throw() {
                // std::free(this->msg);
                return;
            }

            char* what() {
                return this->msg;
            }

    };

    class Empty_Data_Structure {

        private:
            char* msg;

        public:

            Empty_Data_Structure(char* msg = (char*) "Empty Data Structure") {
                this->msg = msg;
            }

            ~Empty_Data_Structure() throw() {
                // std::free(this->msg);
                return;
            }

            char* what() {
                return this->msg;
            }

    };

    class Not_Yet_Implemented {

        private:
            char* msg;

        public:

            Not_Yet_Implemented(char* msg = (char*) "Data Structure is not implemented yet.") {
                this->msg = msg;
            }

            ~Not_Yet_Implemented() throw() {
                // std::free(this->msg);
                return;
            }

            char* what() {
                return this->msg;
            }

    };

    class UnsupportedOperator {

        private:
            char* msg;

        public:

            UnsupportedOperator(char* msg = (char*) "Data Structure Doesn't support this operator.") {
                this->msg = msg;
            }

            ~UnsupportedOperator() throw() {
                // std::free(this->msg);
                return;
            }

            char* what() {
                return this->msg;
            }

    };

}








namespace Data_Structures {


    namespace {

        template <typename data_> class base_node {

            private:
                data_ node_data;

            public:
                base_node() {}

                base_node(data_ data) {
                    this->node_data = data;
                }

                void set_data(data_ data) {
                    this->node_data = data;
                }

                data_ get_data() const {
                    return this->node_data;
                }

                data_& peek_data() {
                    return this->node_data;
                }

        };


        template <typename data_> class single_linear_node : public base_node<data_> {

            private:
                single_linear_node<data_>* next;

            public:

                single_linear_node() : base_node<data_>() {
                    this->next = nullptr;
                }

                single_linear_node(data_ data) : base_node<data_>(data) {
                    this->next = nullptr;
                }

                single_linear_node(const single_linear_node<data_>& other) {
                    this->set_data(other.get_data());
                    this->next = other.get_next();
                }

                void update_next(single_linear_node<data_>* new_next) {
                    this->next = new_next;
                }

                single_linear_node<data_>* get_next() const {
                    return this->next;
                }

                single_linear_node<data_>& operator=(const single_linear_node<data_>& other) {
                    if (this != &other) {
                        this->set_data(other.get_data());
                        this->next = other.get_next();
                    }
                    // std::printf("In single_linear_node<data_>& operator=() method\n");
                    return *this;
                }

        };

    }

    /**
     * @brief The Data structure that stores data in nodes that hold the data and point to the next node.
     * 
     * @tparam data_ The data type that the Linked_list will hold.
     */
    template <typename data_> class linked_list;

    /**
     * @brief A Queue. Pretty much the same as a Linked_list. An Abstraction built over the Linked_list actually.
     * Has all the functionality of the Linked_list, but it's built using no nodes, just an internal Linked_list.
     * 
     * @tparam data_ The data type that the Queue will hold.
     */
    template <typename data_> class queue;

    /**
     * @brief A Stack. Pretty much the same as a Queue and Linked_list in that each node holds data and points to the next node,
     * but also different in that the order is revered as compared to a linked list or a Queue.
     * Very powerful.
     * 
     * @tparam data_ The data type that the Stack will hold.
     */
    template <typename data_> class stack;

    /**
     * @brief A Binary Search Tree. Basic as fudge though. Only holds data, and no key.
     * 
     * @tparam data_ The data type that the Binary Seach Tree will hold.
     * @note To use this tree, ideally have a data type (data_) that has comparables defined for it
     * if not, you can pass in a function to be used for the comparisons.
     */
    template <typename data_> class binary_search_tree;

    /**
     * @brief An Iterator that works on Linked_list<data_>, Queue<data_>, and Stack<data_> data types.
     * 
     * @note Use it like so:
     *
     *      for (Data_Structures::List_iterator<data_> iter = data_struct; iter; iter++) {
     *
     *          iter.index() : holds the current index.
     *          iter.dat()   : holds the current data.
     *     }
     *
     *   or like so:
     *
     *      Data_Structures::List_iterator<data_> iter = data_struct;
     *
     *      while (iter) {
     *
     *          iter.index() : holds the current index.
     *
     *          iter.data()  : holds the current data.
     *
     *          iter++
     *
     *      }
     *  where data_struct is a data structure of type Stack<data_>, Queue<data_>, or Linked_list<data_>
     * 
     * @tparam data_ The data type of the data to be held in the List_iterator.
     */
    template <typename data_> class list_iterator;

    /**
     * @brief An iterator to use for iterating throught the Dictionary.
     * 
     * @tparam key_ The data type of the key
     * @tparam data_ The data type of the data held at each key.
     */
    template <typename key_, typename data_> class dict_iterator;


    template <typename data_> class linked_list {

        private:
            single_linear_node<data_>* head, *tail;
            unsigned long size;
            bool throw_and_destruct;
            bool (*compare_func) (data_ first, data_ second);

            friend class list_iterator<data_>;

            bool default_compare(data_ first, data_ second) {
                return first == second;
            }

        public:

            linked_list() {
                this->head = this->tail = nullptr;
                this->size = 0;
                this->throw_and_destruct = true;
                this->compare_func = nullptr;
            }

            linked_list(data_ new_data, bool throw_and_free = true, bool (*comp) (data_ first, data_ second) = nullptr) {
                this->head = new single_linear_node<data_>(new_data);
                this->tail = this->head;
                this->size = 1;
                this->throw_and_destruct = throw_and_free;
                this->compare_func = comp;
            }

            linked_list(linked_list<data_>& list) {
                if ((this != &list) && (list.size > 0)) {
                    single_linear_node<data_> *list_node, *new_node = new single_linear_node<data_>();
                    for (list_node = list.head, this->size = 0; list_node != nullptr && this->size < list.size; list_node = list_node->get_next(), this->size = this->size + 1) {
                        new_node->set_data(list_node->get_data());
                        if (this->size == 0) {
                            this->head = new_node;
                        }
                        if (list_node->get_next() != nullptr) {
                            single_linear_node<data_>* new_next = new single_linear_node<data_>();
                            new_node->update_next(new_next);
                            new_node = new_node->get_next();
                        }
                        else {
                            this->tail = new_node;
                        }
                    }
                    this->compare_func = list.compare_func;
                    this->throw_and_destruct = list.throw_and_destruct;
                }
                else if ((this != &list) && (list.size == 0)) {
                    this->head = this->tail = nullptr;
                    this->throw_and_destruct = true;
                    this->size = 0;
                    this->compare_func = nullptr;
                    this->throw_and_destruct = list.throw_and_destruct;
                }
            }

            ~linked_list() {
                this->tail = this->head;
                while (this->tail != nullptr && this->size > 0) {
                    this->head = this->tail->get_next();
                    delete this->tail;
                    this->tail = this->head;
                    // this->size = this->size - 1;
                }
                this->size = 0;
                this->throw_and_destruct = true;
                this->compare_func = nullptr;
            }

            linked_list<data_>& operator=(linked_list<data_>& list) {
                if ((this != &list) && (list.size > 0)) {
                    this->reset();
                    single_linear_node<data_> *list_node, *new_node = new single_linear_node<data_>();
                    for (list_node = list.head, this->size = 0; list_node != nullptr && this->size < list.size; list_node = list_node->get_next(), this->size = this->size + 1) {
                        new_node->set_data(list_node->get_data());
                        if (this->size == 0) {
                            this->head = new_node;
                        }
                        if (list_node->get_next() != nullptr) {
                            single_linear_node<data_>* new_next = new single_linear_node<data_>();
                            new_node->update_next(new_next);
                            new_node = new_node->get_next();
                        }
                        else {
                            this->tail = new_node;
                        }
                    }
                    this->compare_func = list.compare_func;
                    this->throw_and_destruct = list.throw_and_destruct;
                }
                else if ((this != &list) && (list.size == 0)) {
                    this->reset();
                    this->head = this->tail = nullptr;
                    this->throw_and_destruct = true;
                    this->size = 0;
                    this->compare_func = nullptr;
                    this->throw_and_destruct = list.throw_and_destruct;
                }
                return *this;
            }

            void reset() {
                // this->~linked_list();
                this->tail = this->head;
                while (this->tail != nullptr && this->size > 0) {
                    // std::printf("In loop with a size of %lu\n", this->size);
                    this->head = this->tail->get_next();
                    delete this->tail;
                    this->tail = this->head;
                }
                this->size = 0;
                this->throw_and_destruct = true;
                this->compare_func = nullptr;
            }

            bool empty() const {
                return this->size == 0;
            }

            bool throws_and_distructs() const {
                return this->throw_and_destruct;
            }

            void throws_and_distructs(bool will_throw) {
                this->throw_and_destruct = will_throw;
            }

            operator bool() const {
                return this->size > 0;
            }

            unsigned long length() const {
                return this->size;
            }

            void update_compare_function(bool (*comp) (data_ first, data_ second) = nullptr) {
                this->compare_func = comp;
            }

            bool push(data_ new_data, signed long index = -1) {
                unsigned long push_index = (index < 0) ? this->size + 1 - ((unsigned long) (index * -1)) : (unsigned long) index;
                if (push_index > this->size) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Push index passed in is not reachable given the current size of the linked list.");
                }
                single_linear_node<data_>* new_node = new single_linear_node<data_>(new_data);
                if (!new_node) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::MemoryError((char *) "Could not get the memory necessary to push data to the linked list\n");
                }
                new_node->set_data(new_data);
                unsigned long old_len = this->size;
                if (this->size == push_index) {
                    if (this->size == 0) {
                        this->head = new_node;
                        this->tail = this->head;
                    }
                    else {
                        this->tail->update_next(new_node);
                        this->tail = this->tail->get_next();
                    }
                    if (this->compare_func == nullptr) {
                        this->size = (this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size;
                    }
                    else {
                        this->size = ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size);
                    }
                    // this->size = (this->compare_func == nullptr) ? ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size) : ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size);
                }

                else if (push_index == 0) {
                    if (this->size == 0) {
                        this->head = new_node;
                        this->tail = this->head;
                        
                    }
                    else {
                        new_node->update_next(this->head);
                        this->head = new_node;
                        // this->size = this->size + 1;
                    }
                    this->size = (this->compare_func == nullptr) ? ((this->default_compare(this->head->get_data(), new_data) && this->head->get_next() != nullptr) ? this->size + 1 : this->size) : ((this->compare_func(this->head->get_data(), new_data) && this->head->get_next() != nullptr) ? this->size + 1 : this->size);
                    
                }

                else {
                    unsigned long this_index;
                    single_linear_node<data_>* this_node;                                                           // this_node = this_node->get_next()
                    for (this_node = this->head, this_index = 0; this_index < push_index - 1 && this_node != nullptr; this_node = this_node->get_next(), this_index = this_index + 1);

                    if (this_index + 1 != push_index) {
                        if (this->throw_and_destruct) {
                            this->~linked_list();
                        }
                        throw Data_Structure_Exceptions::IllegalIndex((char *) "Shifted to the wrong index.");
                    }
                    new_node->update_next(this_node->get_next());
                    this_node->update_next(new_node);
                    this->size = ((this_node->get_next() == new_node) && (this_node->get_next()->get_next() == new_node->get_next())) ? this->size + 1 : this->size;
                    
                }
                
                return (old_len + 1) == this->size;
            }

            bool push_positive(data_ new_data, unsigned long index) {
                unsigned long push_index = index;
                if (push_index > this->size) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Push index passed in is not reachable given the current size of the linked list.");
                }
                single_linear_node<data_>* new_node = new single_linear_node<data_>(new_data);
                if (!new_node) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::MemoryError((char *) "Could not get the memory necessary to push data to the linked list\n");
                }
                new_node->set_data(new_data);
                unsigned long old_len = this->size;
                if (this->size == push_index) {
                    if (this->size == 0) {
                        this->head = new_node;
                        this->tail = this->head;
                    }
                    else {
                        this->tail->update_next(new_node);
                        this->tail = this->tail->get_next();
                    }
                    if (this->compare_func == nullptr) {
                        this->size = (this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size;
                    }
                    else {
                        this->size = ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size);
                    }
                    // this->size = (this->compare_func == nullptr) ? ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size) : ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size);
                }

                else if (push_index == 0) {
                    if (this->size == 0) {
                        this->head = new_node;
                        this->tail = this->head;
                        
                    }
                    else {
                        new_node->update_next(this->head);
                        this->head = new_node;
                        // this->size = this->size + 1;
                    }
                    this->size = (this->compare_func == nullptr) ? ((this->default_compare(this->head->get_data(), new_data) && this->head->get_next() != nullptr) ? this->size + 1 : this->size) : ((this->compare_func(this->head->get_data(), new_data) && this->head->get_next() != nullptr) ? this->size + 1 : this->size);
                    
                }

                else {
                    unsigned long this_index;
                    single_linear_node<data_>* this_node;
                    for (this_node = this->head, this_index = 0; this_index < push_index - 1 && this_node != nullptr; this_node = this_node->get_next(), this_index = this_index + 1);

                    if (this_index + 1 != push_index) {
                        if (this->throw_and_destruct) {
                            this->~linked_list();
                        }
                        throw Data_Structure_Exceptions::IllegalIndex((char *) "Shifted to the wrong index.");
                    }
                    new_node->update_next(this_node->get_next());
                    this_node->update_next(new_node);
                    this->size = ((this_node->get_next() == new_node) && (this_node->get_next()->get_next() == new_node->get_next())) ? this->size + 1 : this->size;
                    
                }
                
                return (old_len + 1) == this->size;
            }

            data_& operator[](signed long index) {
                if (this->size == 0) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::Empty_Data_Structure((char *) "Illegal indexing. Linked list is empty");
                }
                unsigned long this_index, peek_index = (index < 0) ? ((this->size) - ((unsigned long) (index * -1))) : ((unsigned long) index);
                if (peek_index >= this->size) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Illegal index. Cannot peek an index greater than the size of the linked list");
                }
                single_linear_node<data_>* the_answer;
                for (the_answer = this->head, this_index = 0; (this_index < this->size) && (the_answer != nullptr) && (this_index < peek_index); the_answer = the_answer->get_next(), this_index = this_index + 1);
                
                return the_answer->peek_data();
            }

            data_ pop(signed long index = 0) {
                if (this->size == 0) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::Empty_Data_Structure((char *) "Illegal indexing. Linked list is empty");
                }
                unsigned long this_index, pop_index = (index < 0) ? ((this->size) - ((unsigned long) (index * -1))) : ((unsigned long) index);
                if (pop_index >= this->size) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Illegal index. Cannot peek an index greater than the size of the linked list");
                }
                
                single_linear_node<data_>* this_node = this->head;

                if (pop_index == 0) {
                    // removing from the front
                    // have to reset the head pointer
                    if (this->size > 1) {
                        this->head = this->head->get_next();
                        // std::printf("shifting head\n");
                    }
                    else {
                        // std::printf("Not shifting head\n");
                    }
                }
                else {
                    single_linear_node<data_>* before = this_node;
                    for (this_index = 0; (before != nullptr) && (before != this->tail) && (this_index < pop_index - 1); this_index = this_index + 1, before = before->get_next());

                    if ((before == nullptr) || (before == this->tail) || (this_index >= pop_index)) {
                        if (this->throw_and_destruct) {
                            this->~linked_list();
                        }
                        throw Data_Structure_Exceptions::MemoryError((char *) "Shifted too far and lost the proper memory location");
                    }

                    // to get here, remove is at the node right before the node to be removed
                    this_node = before->get_next();
                    if (this_node == this->tail) {
                        this->tail = before;
                    }
                    else {
                        before->update_next(this_node->get_next());
                    }

                }

                data_ the_answer = this_node->get_data();
                delete this_node;
                this->size = this->size - 1;
                return the_answer;
            }


    };

    template <typename data_> class list_iterator {

        private:
            single_linear_node<data_>* this_node;
            unsigned long this_index;

        public:

            list_iterator() {
                this_node = nullptr;
                this->this_index = 0;
            }

            list_iterator(const linked_list<data_>& list) {
                this->this_node = list.head;
                this->this_index = 0;
            }

            list_iterator<data_>& operator=(const linked_list<data_>& list) {
                this->this_node = list.head;
                this->this_index = 0;
                return *this;
            }

            list_iterator(const stack<data_>& the_stack) {
                this->this_node = the_stack.head;
                this->this_index = 0;
                // return *this;
            }

            list_iterator<data_>& operator=(const stack<data_>& the_stack) {
                this->this_node = the_stack.head;
                this->this_index = 0;
            }

            operator bool() const {
                return this->this_node != nullptr;
            }

            list_iterator<data_>& operator++() {
                this->this_node = this->this_node->get_next();
                this->this_index = this->this_index + 1;
                return *this;
            }


            list_iterator<data_>& operator++(int) {
                list_iterator<data_>* this_iter = this;
                ++(*this);
                return this_iter;
            }

    };

}