#include "included.h"










#define _DATA_STRUCTURES_



// for debugging. Comment out in real time.

// #if not defined(_LIBCPP_IOSTREAM)
//     #include <iostream>
// #endif




/**
Known Bugs:
    * 
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

        // void* null_data = 0;
        // void** null_ptr = &null_data;

        template <typename data_> class basic_node {
            protected:
                data_ node_data;

            public:

                basic_node() {}

                basic_node(data_ new_data) {
                    this->node_data = new_data;
                }

                basic_node(basic_node<data_>& other_node) {
                    if (this != &other_node) {
                        this->node_data = other_node.node_data;
                    }
                }

                basic_node(basic_node<data_>* other_node) {
                    if (this != other_node) {
                        this->node_data = other_node->node_data;
                    }
                }

                basic_node<data_>& operator=(basic_node<data_>& other) {
                    if (this != &other) {
                        this->node_data = other.node_data;
                    }
                    return *this;
                }

                void update_data(const data_ new_data) {
                    this->node_data = new_data;
                }

                data_ get_data() const {
                    return this->node_data;
                }

                data_& peek_data() {
                    return this->node_data;
                }

        };


        template <typename data_> class single_linear_node : public basic_node<data_> {

            protected:
                single_linear_node<data_>* next;

            public:

                single_linear_node() : basic_node<data_>() {
                    this->next = nullptr;
                }

                single_linear_node(data_ data) : basic_node<data_>(data) {
                    this->next = nullptr;
                }

                void update_next(const single_linear_node<data_>* next_node) {
                    this->next = next_node;
                }

                single_linear_node<data_>* get_next() const {
                    return this->next;
                }

                single_linear_node<data_>& peek_next() {
                    return this->next;
                }

                single_linear_node<data_>& operator++() {
                    this = this->next;
                    return *this;
                }

                single_linear_node<data_>& operator++(int) {
                    single_linear_node<data_>& the_answer = *this;
                    ++(this);
                    return the_answer;
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
            bool (*compare_equal) (const data_& first, const data_& second);

            friend class list_iterator<data_>;

        public:

            linked_list() {
                this->head = tail = nullptr;
                this->size = 0;
                this->compare_equal = nullptr;
                throw_and_destruct = true;
            }

            linked_list(const data_ data, bool (*equal) (const data_&, const data_&) = nullptr, bool throw_and_free = true) {
                this->head = new single_linear_node<data_>(data);
                this->tail = this->head;
                this->size = 1;
                this->compare_equal = equal;
                throw_and_destruct = throw_and_free;
            }

            linked_list(const linked_list<data_>& other_list) {
                if (other_list.size > 0 && &other_list != this) {
                    single_linear_node<data_>* this_node, *other_node = other_list.head;
                    this->head = new single_linear_node<data_>(other_node);
                    this->size = 1;
                    this_node = this->head;
                    while (other_node->get_next() != nullptr) {
                        this_node->update_next(new single_linear_node<data_>(other_node->get_data()));
                        other_node = other_node->get_next();
                        this->size = this->size + 1;
                    }
                    this->tail = this_node;
                    this->compare_equal = other_list.compare_equal;
                    this->throw_and_destruct = other_list.throw_and_destruct;
                }
            }

            ~linked_list() {
                single_linear_node<data_>* this_node = this->head;
                while (this_node) {
                    this->head = this_node->get_next();
                    delete this_node;
                    this_node = this->head;
                    this->size = this->size - 1;
                }
                this->throw_and_destruct = true;
                this->compare_equal = nullptr;
            }

            void destruct_and_throw(const bool free_and_throw) {
                this->throw_and_destruct = free_and_throw;
            }

            bool destruct_and_throw() const {
                return this->throw_and_destruct;
            }

            bool empty() const {
                return this->size == 0;
            }

            unsigned long length() const {
                return this->size;
            }

            operator bool() const {
                return this->size > 0;
            }

            data_& operator[](signed long index_) {
                if ((index_ > 0 && (this->size < ((unsigned long) index_))) || (index_ < 0 && (this->size < ((unsigned long) (index_ * -1))))) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Ya... you just passed in an index that is larger than the linked list");
                }
                unsigned long peek_index = (index_ < 0) ? this->size - ((unsigned long) (index_ * -1)) : (unsigned long) index_;
                // single_linear_node<data_>* remove_me;
                data_ the_answer;
                if (peek_index == 0) {
                    the_answer = this->head->get_data();
                }
                else {
                    the_answer = this->tail->get_data();
                    unsigned long this_index;
                    single_linear_node<data_>* this_node;
                    for (this_index = 0, this_node = this->head; this_index < peek_index - 1 && this_node != nullptr; this_index++, this_node++);

                    if (this_index == peek_index - 1) {
                        the_answer = this_node->get_next()->get_data();
                    }
                    else {
                        if (this->throw_and_destruct) {
                            this->~linked_list();
                        }
                        throw Data_Structure_Exceptions::IllegalIndex((char *) "Did not get to the proper location while trying to pop data");
                    }
                }
                this->size = this->size - 1;
                return the_answer;
            }

            bool push(const data_ new_data, signed long index_ = -1) {
                if ((index_ > 0 && (this->size < ((unsigned long) index_))) || (index_ < 0 && (this->size + 1 < ((unsigned long) (index_ * -1))))) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Ya... you just passed in an index that is too large for this list to understand");
                }
                unsigned long push_index = (index_ < 0) ? this->size + 1 - ((unsigned long) (index_ * -1)) : (unsigned long) index_;
                unsigned long old_len = this->size;
                single_linear_node<data_>* new_node = new single_linear_node<data_>(new_data);
                if (this->size == 0) {
                    this->head = new_node;
                    this->tail = this->head;
                }
                else {
                    if (push_index == 0) {
                        new_node->update_next(this->head);
                        this->size = this->size + 1;
                    }
                    else if (push_index == this->size) {
                        this->tail->update_next(new_node);
                        this->tail = this->tail->get_next();
                        this->size = this->size + 1;
                    }
                    else {
                        unsigned long this_index;
                        single_linear_node<data_>* this_node;
                        
                        // need the this_index < push_index - 1 to ensure that
                        // when loop terminates, this_node is at the node before peek_index.
                        for (this_index = 0, this_node = this->head; this_index < push_index - 1 && this_node != nullptr; this_index++, this_node++);
                        
                        if (this_index == push_index - 1) {
                            // at proper location
                            new_node->update_next(this_node->get_next());
                            this_node->update_next(new_node);
                            this->size = this->size + 1;
                        }
                        else {
                            if (throw_and_destruct) {
                                this->~linked_list();
                            }
                            throw Data_Structure_Exceptions::IllegalIndex((char *) "Something went wrong with trying to find the right location in the linked list for the data.");
                        }
                    }
                }
                return this->size == (old_len + 1);
            }

            data_ pop(signed long index_ = 0) {
                if ((index_ > 0 && (this->size < ((unsigned long) index_))) || (index_ < 0 && (this->size < ((unsigned long) (index_ * -1))))) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Ya... you just passed in an index that is larger than the linked list");
                }
                unsigned long peek_index = (index_ < 0) ? this->size - ((unsigned long) (index_ * -1)) : (unsigned long) index_;
                single_linear_node<data_>* remove_me;
                data_ the_answer;
                if (peek_index == 0) {
                    the_answer = this->head->get_data();
                    remove_me = this->head;
                    this->head = this->head->get_next();
                    // delete remove_me;
                }
                else {
                    the_answer = this->tail->get_data();
                    unsigned long this_index;
                    single_linear_node<data_>* this_node;
                    for (this_index = 0, this_node = this->head; this_index < peek_index - 1 && this_node != nullptr; this_index++, this_node++);

                    if (this_index == peek_index - 1) {
                        // at proper location
                        the_answer = this_node->get_next()->get_data();
                        if (this_index + 1 == this->size - 1) {
                            // delete this_node->get_next();
                            remove_me = this_node->get_next();
                        }
                        else {
                            remove_me = this_node->get_next();
                            this_node->update_next(this_node->get_next()->get_next());
                            // delete remove_me;
                        }
                    }
                    else {
                        if (this->throw_and_destruct) {
                            this->~linked_list();
                        }
                        throw Data_Structure_Exceptions::IllegalIndex((char *) "Did not get to the proper location while trying to pop data");
                    }
                }
                delete remove_me;
                this->size = this->size - 1;
                return the_answer;
            }

            data_ peek(signed long index_ = 0) {
                if ((index_ > 0 && (this->size < ((unsigned long) index_))) || (index_ < 0 && (this->size < ((unsigned long) (index_ * -1))))) {
                    if (this->throw_and_destruct) {
                        this->~linked_list();
                    }
                    throw Data_Structure_Exceptions::IllegalIndex((char *) "Ya... you just passed in an index that is larger than the linked list");
                }
                unsigned long peek_index = (index_ < 0) ? this->size - ((unsigned long) (index_ * -1)) : (unsigned long) index_;
                // single_linear_node<data_>* remove_me;
                data_ the_answer;
                if (peek_index == 0) {
                    the_answer = this->head->get_data();
                }
                else {
                    the_answer = this->tail->get_data();
                    unsigned long this_index;
                    single_linear_node<data_>* this_node;
                    for (this_index = 0, this_node = this->head; this_index < peek_index - 1 && this_node != nullptr; this_index++, this_node++);

                    if (this_index == peek_index - 1) {
                        the_answer = this_node->get_next()->get_data();
                    }
                    else {
                        if (this->throw_and_destruct) {
                            this->~linked_list();
                        }
                        throw Data_Structure_Exceptions::IllegalIndex((char *) "Did not get to the proper location while trying to pop data");
                    }
                }
                this->size = this->size - 1;
                return the_answer;
            }

            void reset() {
                single_linear_node<data_>* this_node = this->head;
                while (this_node != nullptr) {
                    this->head = this_node->get_next();
                    delete this_node;
                    this_node = this->head;
                    this->size = this->size - 1;
                }
                this->throw_and_distruct = true;
                this->compare_equal = nullptr;
            }

    };

}