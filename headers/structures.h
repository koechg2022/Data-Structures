

#include "../libraries/useful_functions.h"







namespace data_structures {

    namespace {

        template <typename data_> class node {

            protected:
                data_ data;

            public:
                node(data_ new_data = NULL) : data(new_data) {

                }

                void set_data(data_ new_data) {
                    this->data = new_data;
                }

                data_ get_data() const {
                    return this->data;
                }

        };

        template <typename data_> class linear_node : public node<data_>{

            protected:
                linear_node<data_>* previous, *next;

            public:
                linear_node(data_ new_data = NULL) : data(new_data), previous(NULL), next(NULL) {

                }

                void set_previous(linear_node<data_>* prev) {
                    this->previous = prev;
                }

                linear_node<data_>* get_previous() const {
                    return this->previous;
                }

                void set_next(linear_node<data_>* nxt) {
                    this->next = nxt;
                }

                linear_node<data_>* get_next() const {
                    return this->next;
                }

        };

    }

    template <typename data_> class linked_list {

        private:
            unsigned long size, frame_index;
            linear_node<data_>* front, *rear, *frame;

            void shift_frame(signed long by) {
                while ((this->frame != NULL) && (by != 0)) {
                    this->frame = (by < 0) ? this->frame->get_previous() : this->frame->get_next();
                    this->frame_index = (by < 0) ? this->frame_index - 1 : this->frame_index + 1;
                }

            }
        

        public:

            linked_list(data_ new_data = NULL) {
                if (new_data != NULL) {
                    this->front = new linear_node<data_>(new_data);
                    this->rear = this->front;
                    this->frame = this->front;
                    this->size = 1;
                }
                else {
                    this->front = this->rear = this->frame = NULL;
                }
                this->ref_index = 0;
            }


            ~linked_list() {
                this->frame = this->front;
                while (this->frame != NULL) {
                    this->front = this->ref;
                    this->frame = this->ref->get_next();
                    delete this->front;
                }
            }


            /**
             * @brief   Get the length of the linked list.
             * @returns The length of the linked list as an unsigned int.
            */
            unsigned long length() const {
                return this->size;
            }

            /**
             * @brief   Check if the {@code linked_list} is empty or not.
             * @returns A bool specifying whether or not the linked_list is empty or not.
            */
            bool empty() const {
                return (this->size == 0);
            }

            /**
             * @brief   Push new data onto the linked list at the specified index.
             * @param new_data  The new data to push onto the linked list.
             * @param trg The index where the data is to be added. If negative, the index is determiend
             * by subtracting trg from the size + 1 of the linked list.
            */
            void push(data_ new_data, signed long trg = -1) {
                
                unsigned long target = (trg < 0) ? this->size - useful_functions::absolute(trg) + 1 : useful_functions::absolute(trg);
                linear_node<data_>* new_node = new linear_node<data_>(new_data);
                if (this->size == 0) {
                    this->front = this->rear = this->ref;
                    this->frame_index = 0;
                }
                else {
                    if (target == 0) {
                        this->front->set_previous(new_node);
                        new_node->set_next(this->front);
                        this->front = this->front->get_previous();
                        this->frame = this->front;
                        this->frame_index = 0;
                    }
                    else if (target == this->size) {
                        this->rear->set_next(new_node);
                        this->rear->get_next()->set_previous(this->rear);
                        this->frame = this->rear;
                        this->frame_index = this->size;
                    }
                    else {
                        signed long shift = (target < this->frame_index) ? useful_functions::get_negative(useful_functions::get_difference(this->frame_index, target)) : (signed long) useful_functions::get_difference(this->frame_index, target);
                        this->shift_frame(shift);
                        new_node->set_previous(this->frame->get_previous());
                        this->frame->get_previous()->set_next(new_node);
                        new_node->set_previous(this->frame->get_previous());
                        new_node->set_next(this->frame);
                        this->frame->set_previous(new_node);
                    }
                }
                this->size = this->size + 1;
            }


            data_ peek(signed long index = 0) {
                unsigned long indx = (index < 0) ? this->size - useful_functions::absolute(index) : useful_functions::absolute(index);
                if (indx == 0) {
                    this->frame = this->front;
                }
                else if (indx == this->size - 1) {
                    this->frame = this->rear;
                }
                else {
                    signed long shift (indx < this->frame_index) ? useful_functions::get_negative(useful_functions::get_difference(this->frame_index, indx)) : (signed long) useful_functions::get_difference(this->frame_index, indx);
                    this->shift_frame(shift);
                }
                return this->frame->get_data();
            }

    };


}