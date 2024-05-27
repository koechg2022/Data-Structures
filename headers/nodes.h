










#define _DATA_STRUCTURES_



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

        template <typename data_> class Node {

            protected:
                data_ node_data;

            public:

                Node() {
                    
                }

                Node(data_ new_data) {
                    this->node_data = new_data;
                }

                // Look into making virtual
                void update_data(data_ new_data) {
                    this->node_data = new_data;
                }

                // Look into making virtual
                const data_ get_data() const {
                    return this->node_data;
                }

                // Look into making virtual
                data_& peek_data() {
                    return this->node_data;
                }

        };

        template <typename data_> class single_linear_node : public Node <data_> {
            
            protected:
                single_linear_node<data_>* next;

            
            public:

                single_linear_node() : Node<data_>() {
                    this->next = nullptr;
                }

                single_linear_node(data_ new_data) : Node<data_>(new_data) {
                    this->next = nullptr;
                }

                void set_next(single_linear_node<data_>* next_node) {
                    this->next = next_node;
                }

                single_linear_node<data_>* get_next_node() const {
                    return this->next;
                }

                single_linear_node<data_>& peek_next_node() {
                    return *this->next;
                }

        };

        template <typename data_> class double_linear_node : public Node<data_> {

            protected:
                double_linear_node<data_>* next, *previous;

            public:

                double_linear_node() : Node<data_>() {
                    this->next = this->previous = nullptr;
                }

                double_linear_node(data_ new_data) : Node<data_>(new_data) {
                    this->next = this->previous = nullptr;
                }

                double_linear_node(double_linear_node<data_>* previous, double_linear_node<data_>* next) {
                    this->previous = previous;
                    this->next = next;
                }

                void update_previous_node(double_linear_node<data_>* new_previous) {
                    this->previous = new_previous;
                }

                double_linear_node<data_>* get_previous_node() const {
                    return this->previous;
                }

                double_linear_node<data_>& peek_previous_node() {
                    return *this->previous;
                }

                void update_next_node(double_linear_node<data_>* new_next) {
                    this->next = new_next;
                }

                double_linear_node<data_>* get_next_node() const {
                    return this->next;
                }

                double_linear_node<data_>& peek_next_node() {
                    return *this->next;
                }

        };

        template <typename key_, typename data_> class double_point_node : public Node<data_> {

            protected:
                key_ node_key;
                double_point_node<key_, data_>* left_node, *right_node;

            public:

                double_point_node() : Node<data_>() {
                    this->left_node = this->right_node;
                }


                double_point_node(key_ new_key, data_ new_data, double_point_node<key_, data_>* left = nullptr, double_point_node<key_, data_>* right = nullptr) : Node<data_>(new_data) {
                    this->node_key = new_key;
                    this->left_node = left;
                    this->right_node = right;
                }

                
                void update_key(const key_ new_key) {
                    this->node_key = new_key;
                }

                const key_ get_key() const {
                    return this->node_key;
                }

                key_& peek_key() {
                    return this->node_key;
                }

                void update_left_node(double_point_node<key_, data_>* left) {
                    this->left_node = left;
                }

                double_point_node<key_, data_>* get_left_node() const {
                    return this->left_node;
                }

                double_point_node<key_, data_>& peek_left_node() {
                    return this->left_node;
                }

                void update_right_node(double_point_node<key_, data_>* right) {
                    this->right_node = right;
                }

                double_point_node<key_, data_>* get_right_node() const {
                    return this->right_node;
                }

                double_point_node<key_, data_>& peek_right_node() {
                    return this->right_node;
                }

            

        };

    }



    /**
     * @brief The Data structure that stores data in nodes that hold the data and point to the next node.
     * 
     * @tparam data_ The data type that the Linked_list will hold.
     */
    template <typename data_> class Linked_list;



    /**
     * @brief A Queue. Pretty much the same as a Linked_list. An Abstraction built over the Linked_list actually.
     * Has all the functionality of the Linked_list, but it's built using no nodes, just an internal Linked_list.
     * 
     * @tparam data_ The data type that the Queue will hold.
     */
    template <typename data_> class Queue;



    /**
     * @brief A Stack. Pretty much the same as a Queue and Linked_list in that each node holds data and points to the next node,
     * but also different in that the order is revered as compared to a linked list or a Queue.
     * Very powerful.
     * 
     * @tparam data_ The data type that the Stack will hold.
     */
    template <typename data_> class Stack;



    /**
     * @brief A Binary Search Tree. Basic as fudge though. Only holds data, and no key.
     * 
     * @tparam data_ The data type that the Binary Seach Tree will hold.
     * @note To use this tree, ideally have a data type (data_) that has comparables defined for it
     * if not, you can pass in a function to be used for the comparisons.
     */
    template <typename data_> class Binary_search_tree;



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
    template <typename data_> class List_iterator;



    /**
     * @brief An iterator to use for iterating throught the Dictionary.
     * 
     * @tparam key_ The data type of the key
     * @tparam data_ The data type of the data held at each key.
     */
    template <typename key_, typename data_> class Dict_iterator;



}