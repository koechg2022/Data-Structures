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

                single_linear_node(const single_linear_node<data_>* other) {
                    if (this != &other) {
                        this = &other;
                    }
                }

                void update_next(single_linear_node<data_>* new_next) {
                    this->next = new_next;
                }

                single_linear_node<data_>* get_next() const {
                    return this->next;
                }

                single_linear_node<data_>* operator=(single_linear_node<data_>* other) {
                    if (this != other) {
                        this = other;
                    }
                    return this;
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


            bool default_compare(data_ first, data_ second) {
                return first == second;
            }

        public:

            linked_list() {
                this->head = this->tail = nullptr;
                this->size = 0;
                this->throw_and_destruct = true;
            }

            linked_list(data_ new_data, bool throw_and_free = true, bool (*comp) (data_ first, data_ second) = nullptr) {
                this->head = new single_linear_node<data_>(new_data);
                this->tail = this->head;
                this->size = 1;
                this->throw_and_destruct = throw_and_free;
                this->compare_func = comp;
            }

            ~linked_list() {
                this->tail = this->head;
                while (this->tail != nullptr) {
                    this->head = this->tail->get_next();
                    delete this->head;
                    this->tail = this->head;
                    this->size = this->size - 1;
                }
                this->throw_and_destruct = true;
                this->compare_func = nullptr;
            }

            bool empty() const {
                return this->size == 0;
            }

            bool throws_and_distructs() {
                return this->throw_and_destruct;
            }

            void throws_and_distructs(bool will_throw) {
                this->throw_and_destruct = will_throw;
            }

            operator bool() const {
                return this->size != 0;
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

                unsigned long old_len = this->size;
                if (this->size == push_index) {
                    if (this->size == 0) {
                        this->head = new_node;
                        this->tail = this->head;
                        // this->size = ((this->compare_func == nullptr) ? ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size) : ((this-compare_func(this->tail->get_data(), new_data)) ? this->size + 1 : this->size));
                        // if (this->compare_func == nullptr) {
                        //     this->size = (this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size;
                        // }
                        // else {
                        //     this->size = (this-compare_func(this->tail->get_data(), new_data)) ? this->size + 1 : this->size;
                        // }
                    }
                    else {
                        this->tail->update_next(new_node);
                        // if (this->compare_func == nullptr) {
                        //     this->size = (this->default_compare(this->tail->get_next()->get_data(), new_data)) ? this->size + 1 : this->size;
                        // }
                        // else {
                        //     this->size = (this->compare_func(this->tail->get_next()->get_data(), new_data)) ? this->size + 1 : this->size;
                        // }
                        // this->size = ((this->tail->get_next() == new_node ) && (new_node->get_data() == new_data)) ? this->size + 1 : this->size;
                        this->tail = this->tail->get_next();
                    }
                    this->size = ((this->compare_func == nullptr) ? ((this->default_compare(this->tail->get_data(), new_data)) ? this->size + 1 : this->size) : ((this-compare_func(this->tail->get_data(), new_data)) ? this->size + 1 : this->size));
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
                    // if (this->compare_func == nullptr) {
                    //     this->size = (this->default_compare(this->head->get_data(), new_data) && this->head->get_next() != nullptr) ? this->size + 1 : this->size;
                    // }
                    // else {
                    //     this->size = (this->compare_func(this->head->get_data(), new_data) && this->head->get_next() != nullptr) ? this->size + 1 : this->size;
                    // }

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
                    // this->size = this->size + 1;
                }
                
                return (old_len + 1) == this->size;
            }

            


    };




}