
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "../headers/constants.h"






namespace useful_functions {

    /**
     * @brief  Get the difference between the two longs passed in
     * @note   Should work with negatives and positives.
     * @param  first: One of the long numbers to get the difference between.
     * @param  second: The other long number to get the difference between.
     * @retval The difference between the first and second long.
     */
    unsigned long get_difference(signed long first, signed long second) {
        return ((unsigned long) max((signed long) first, (signed long) second)) - ((unsigned long) min((signed long) first, (signed long) second));
    }


    unsigned long get_difference(unsigned long first, unsigned long second) {
        return ((unsigned long) max((signed long) first, (unsigned long) second)) - ((unsigned long) min((unsigned long) first, (unsigned long) second));
    }


    signed long get_negative(unsigned long of) {
        return ((of < 0) ? (signed long) of : (signed long)(-1 * ((signed long) of)));
    }


    /**
     * @brief  Delay execution for a given amount of time.
     * @note   1000 milliseconds is equal to 1 second.
     * @param  milli_sec: The amount of milliseconds to delay execution for.
     * @retval None
     */
    void delay(int milli_sec) {
        long pause;
        clock_t past, present;
        pause = milli_sec * (CLOCKS_PER_SEC / 1000);
        past = present = clock();
        while ((present - past) < pause) {
            present = clock();
        }
    }


    /**
     * @brief  Get the absolute value of a value.
     * @note
     * @param  the_number: The value whose absolute value is to be determined.
     * @retval The absolute value of the number passed in.
     */
    unsigned long absolute(signed long the_number) {
        return (the_number < 0) ? the_number * -1 : the_number;
    }


    /**
     * @brief  Get the length of the char* passed in, but as an unsigned long.
     * @note   The length can never be negative.
     * @param  the_string: The char* whose length is to be determined.
     * @retval An unsigned long representing the length of the char* string passed in.
     */
    unsigned long string_length(char* the_string) {
        unsigned long the_answer;
        for (the_answer = 0; the_string[the_answer] != '\0'; the_answer = the_answer + 1);
        return the_answer;
    }


    /**
     * @brief  Convert a std::string into a char*.
     * @note
     * @param  the_string: The std::string to be converted into a char*
     * @retval The recently created char*
     */
    char* string_to_char(std::string the_string) {
        unsigned long index;
        char* the_answer = (char*) malloc(sizeof(char*) * the_string.length());
        for (index = 0; index < the_string.length(); index = index + 1) {
            the_answer[index] = the_string[index];
        }
        the_answer[index] = '\0';
        return the_answer;
    }


        /**
     * @brief  Convert a char into a std::string and return the std::string.
     * @note
     * @param  the_string: The char* to be converted into a std::string.
     * @retval The recently created std::string.
     */
    std::string char_to_string(char* the_string) {
        std::string the_answer;
        unsigned long index, length = string_length(the_string);
        for (index = 0; index < length; index = index + 1) {
            the_answer = the_answer + the_string[index];
        }
        return the_answer;
    }


    /**
     * @brief  Convert a char* to all uppercase.
     * @note   This is still being debugged and doesn't work properly. Instead use this function with a std::string.
     * @param  the_word: The word to be converted to all caps.
     * @retval None
     */
    char* case_caps(char* the_word) {
        unsigned long length = string_length(the_word), index;
        char* the_answer = (char*) malloc(sizeof(char*) * length);
        for (index = 0; index < length; index = index + 1) {
            if (is_letter(the_word[index])) {
                the_answer[index] = (char*) to_caps(the_word[index]);
            }
            else {
                the_answer[index] = the_word[index];
            }
        }
        the_answer[index] = '\0';
        return the_answer;
    }


    /**
     * @brief  Convert a std::string to all uppercase.
     * @note
     * @param  the_word: The word to be converted to all caps.
     * @retval None
     */
    std::string case_caps(std::string the_word) {
        std::string the_answer;
        // unsigned long index;
        char* word = string_to_char(the_word);
        char* upped = case_caps(word);
        the_answer = char_to_string(upped);
        free(word);
        free(upped);
        return the_answer;
    }


    /**
     * @brief  Convert a char* to all lowercase.
     * @note   This is still being debugged and doesn't work properly. Instead use this function with a std::string.
     * @param  the_word: The word to be converted to all caps.
     * @retval None
     */
    char* case_lower(char* the_word) {
        unsigned long length = string_length(the_word), index;
        char* the_answer = (char*) malloc(sizeof(char*) * length);
        for (index = 0; index < length; index = index + 1) {
            if (is_letter(the_word[index])) {
                the_answer[index] = (char*) to_lower(the_word[index]);
            }
            else {
                the_answer[index] = the_word[index];
            }
        }
        the_answer[index] = '\0';
        return the_answer;
    }


    /**
     * @brief  Convert a std::string to all lowercase.
     * @note
     * @param  the_word: The word to be converted to all caps.
     * @retval None
     */
    std::string case_lower(std::string the_word) {
        // unsigned long length = the_word.length(), index;
        std::string the_answer;
        char* word = string_to_char(the_word);
        char* lowered = case_lower(word);
        the_answer = char_to_string(lowered);
        free(word);
        free(lowered);
        return the_answer;
    }



    /**
     * @brief  Checks if two chars are the same.
     * @note   By default ignores the case.
     * @param  first: One of the two chars to be checked.
     * @param  second: The other of the two chars to be checked.
     * @param  ignore_case: A bool to specify whether or not to ignore the cases of the two chars passed in.
     * @retval true if first and second are the same, false otherwise.
     */
    bool same_char(char first, char second, bool ignore_case = true) {
        if (((bool) is_letter(first)) && ((bool) is_letter(second)) && (ignore_case)) {
            if ((((bool) is_caps(first)) && ((bool) is_caps(second))) || ((bool) is_lower(first)) && ((bool) is_lower(second))) {
                return (first == second) ? true : false;
            }
            else if (((bool) is_caps(first)) && ((bool) is_lower(second))) {
                return ((char)(first + ('a' - 'A')) == second) ? true : false;
            }
            else {
                return ((char)(second + ('a' - 'A')) == first) ? true : false;
            }
        }
        return (first == second) ? true : false;
    }


    /**
     * @brief  Checks if the two strings (char*) are the same.
     * @note   There is an option to ignore the cases within the two char* (s) passed in.
     * @param  first: The first string (char*) to be checked.
     * @param  second: The second string (char*) to be checked.
     * @param  ignore_case: A bool specifying whether or not the string's cases should be ignored or not.
     * @retval
     */
    bool same_string(char* first, char* second, bool ignore_case = true) {
        int first_length = string_length(first), second_length = string_length(second), index;

        if (!(first_length == second_length)) {
            return false;
        }

        // to get here first_length and second_length must be the same
        for (index = 0; index < (int) (min((int) first_length, (int) second_length)); index = index + 1) {

            if (!(same_char(first[index], second[index], ignore_case))) {
                return false;
            }

        }

        // to get here, all the characters were determined to be the same.
        return true;
    }


    /**
     * @brief  Checks if the two std::strings are the same or different.
     * @note   There is an option to ignore the cases.
     * @param  first: The first std::string to be checked.
     * @param  second: The second std::string to be checked.
     * @param  ignore_case: A bool specifying whether or not the cases should be ignored or not.
     * @retval
     */
    bool same_string(std::string first, std::string second, bool ignore_case = true) {

        if (first.length() != second.length()) {
            return false;
        }

        bool the_answer = true;
        int index, the_min = (int) min((int) first.length(), (int) second.length());
        
        for (index = 0; index < the_min; index = index + 1) {

            the_answer = same_char((char) first[index], (char) second[index], ignore_case);

            if (!(the_answer)) {
                printf("");
                break;
            }

        }
        return the_answer;
    }


    /**
     * @brief  Convert a std::string into a colored string.
     * @note
     * @param  the_string: The to be formatted.
     * @param  text: The color of the text whose options are [30, 37] inclusive.
     * @param  style: The style of the text whose options are [0, 5], inclusive, except excluding 4.
     * @param  bkg: The background color whose options are [40, 47] inclusive.
     * @retval
     */
    std::string colored_string(std::string the_string, unsigned short int text = black_text, unsigned short int style = no_style, unsigned short int bkg = no_background) {
        // printf("Inside colored_string with std::string\n");
        return ((std::string) ansi_escape) + std::to_string(style) + ";" + std::to_string(text) + ";" + std::to_string(bkg) + "m" + the_string + ((std::string) default_console);
    }


    /**
     * @brief  Convert a std::string into a colored string.
     * @note
     * @param  the_string: The to be formatted.
     * @param  text: The color of the text whose options are [30, 37] inclusive.
     * @param  style: The style of the text whose options are [0, 5], inclusive, except excluding 4.
     * @param  bkg: The background color whose options are [40, 47] inclusive.
     * @retval
     */
    char* colored_string(char* the_string, unsigned short int text = black_text, unsigned short int style = no_style, unsigned short int bkg = no_background) {
        // printf("Inside the colored_string with char*\n");
        std::string to_add = "";
        int index, length = string_length(the_string);
        for (index = 0; index < length; index = index + 1) {
            to_add = to_add + the_string[index];
        }
        std::string color_string = colored_string(to_add, text, style, bkg);
        char* the_answer = new char[color_string.length()];
        for (index = 0; index < color_string.length(); index = index + 1) {
            the_answer[index] = color_string[index];
        }
        the_answer[index] = '\0';
        return the_answer; // This will have deleted

        return the_string;
    }


    /**
     * @brief  Get a deepcopy of the std::string.
     * @note   
     * @param  the_string: The string to be copied.
     * @retval The deepcopy.
     */
    std::string copy_string(std::string the_string) {
        std::string the_answer;
        unsigned long index;
        char* copied_str = string_to_char(the_string);
        for (index = 0; index < the_string.length(); index = index + 1) {
            the_answer = the_answer + std::to_string(copied_str[index]);
        }
        free(copied_str);
        return the_answer;
    }


    /**
     * @brief  Get a deepcopy of the char*.
     * @note   
     * @param  the_string: The char* to be copied.
     * @retval The deepcopy.
     */
    char* copy_string(char* the_string) {
        unsigned long length = string_length(the_string), index;
        char* the_answer = (char *) malloc(sizeof(char) * length);
        for (index = 0; index <= length; index = index + 1) {
            the_answer[index] = the_string[index];
        }
        return the_answer;
    }


    /**
     * @brief  Extends the string passed in by the unsigned long factor.
     * @note   
     * @param  the_string: The string to be extended by 'by'.
     * @param  by: The amount to extend the string by.
     * @retval The extended string.
     */
    std::string extend_string(std::string the_string, unsigned long by = 0) {
        unsigned long index = 0;
        // printf("Extending \"%s\" by %lu\n", the_string.c_str(), by);
        std::string the_answer = "";
        while (index < by) {
            the_answer = the_answer + the_string;
            index = index + 1;
        }
        // printf("\tExtended \"%s\"\n", the_answer.c_str());
        return the_answer;
    }


    /**
     * @brief  Extends the string passed in by the unsigned long factor.
     * @note   Be sure to free up space that this function is used in conjuction with.
     * @param  the_string: The string to be extended by 'by'.
     * @param  by: The amount to extend the string by.
     * @retval The extended string.
     */
    char* extend_string(char* the_string, unsigned long by = 0) {
        
        return string_to_char(extend_string(char_to_string(the_string), by));
    }


    /**
     * @brief  Get the index of a string within a string vector.
     * @note   -1 is returned if the vector is found to not contain the string.
     * @param  to_search: The vector to be searched.
     * @param  to_find: The string to be found in the vector.
     * @param  ignore_case: A bool specifying whether or not to ignore the cases. Defaulted to true.
     * @retval The index of the string, if it exists, or -1 if it does not exist.
     */
    signed long get_index(std::vector<std::string> to_search, std::string to_find, bool ignore_case = true) {
        
        unsigned long index;
        for (index = 0; index < to_search.size(); index = index + 1) {
            if (same_string(to_search[index], to_find, ignore_case)){
                return (signed long) index;
            }
        }
        return -1;
    }


    /**
     * @brief  Get the index of a char* string within a char* vector.
     * @note   -1 is returned if the vector is found to not contain the string.
     * @param  to_search: The vector to be searched.
     * @param  to_find: The char* string to be found in the vector.
     * @param  ignore_case: A bool specifying whether or not to ignore the cases. Defaulted to true.
     * @retval The index of the char* string, if it exists, or -1 if it does not exist.
     */
    signed long get_index(std::vector<char*> to_search, char* to_find, bool ignore_case = true) {

        unsigned long index;
        for (index = 0; index < to_search.size(); index = index + 1) {
            if (same_string(to_search[index], to_find, ignore_case)) {
                return (signed long) index;
            }
        }
        return -1;
    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_min_unsigned(unsigned long the_vector[], long length) {
        long outer_index, inner_index, min_index, temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            min_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (the_vector[min_index] > the_vector[inner_index]) {
                    min_index = inner_index;
                }

            }

            if (min_index != outer_index) {
                temp = the_vector[min_index];
                the_vector[min_index] = the_vector[outer_index];
                the_vector[outer_index] = temp;
            }

        }

    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_min_unsigned_pointers(unsigned long* the_vector[], long length) {
        long outer_index, inner_index, min_index;
        unsigned long *temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            min_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (*the_vector[min_index] > *the_vector[inner_index]) {
                    min_index = inner_index;
                }

            }

                if (min_index != outer_index) {
                    temp = the_vector[min_index];
                    the_vector[min_index] = the_vector[outer_index];
                    the_vector[outer_index] = temp;
                }

        }

    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_min_signed(long the_vector[], long length) {
        long outer_index, inner_index, min_index, temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            min_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (the_vector[min_index] > the_vector[inner_index]) {
                    min_index = inner_index;
                }

            }

            if (min_index != outer_index) {
                temp = the_vector[min_index];
                the_vector[min_index] = the_vector[outer_index];
                the_vector[outer_index] = temp;
            }

        }

    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_min_signed_pointers(signed long* the_vector[], long length) {
        long outer_index, inner_index, min_index;
        signed long* temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            min_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (*the_vector[min_index] > *the_vector[inner_index]) {
                    min_index = inner_index;
                }

            }

            if (min_index != outer_index) {
                temp = the_vector[min_index];
                the_vector[min_index] = the_vector[outer_index];
                the_vector[outer_index] = temp;
            }

        }

    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_max_unsigned(unsigned long the_vector[], long length) {
        long outer_index, inner_index, max_index, temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            max_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (the_vector[max_index] < the_vector[inner_index]) {
                    max_index = inner_index;
                }

            }

            if (max_index != outer_index) {
                temp = the_vector[max_index];
                the_vector[max_index] = the_vector[outer_index];
                the_vector[outer_index] = temp;
            }

        }

    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_max_unsigned(unsigned long* the_vector[], long length) {
        long outer_index, inner_index, max_index;
        unsigned long* temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            max_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (*the_vector[max_index] < *the_vector[inner_index]) {
                    max_index = inner_index;
                }

            }

            if (max_index != outer_index) {
                temp = the_vector[max_index];
                the_vector[max_index] = the_vector[outer_index];
                the_vector[outer_index] = temp;
            }

        }

    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_max_signed(long the_vector[], long length) {
        long outer_index, inner_index, max_index, temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            max_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (the_vector[max_index] < the_vector[inner_index]) {
                    max_index = inner_index;
                }

            }

            if (max_index != outer_index) {
                temp = the_vector[max_index];
                the_vector[max_index] = the_vector[outer_index];
                the_vector[outer_index] = temp;
            }

        }

    }


    /**
     * @brief  Sort the long array from the min to the maximum.
     * @note
     * @param  the_vector[]: The array to be sorted.
     * @param  length: The length of the long array to be sorted.
     * @retval None
     */
    void swap_sort_max_signed_pointers(signed long* the_vector[], long length) {
        long outer_index, inner_index, max_index;
        signed long* temp;
        for (outer_index = 0; outer_index < length - 1; outer_index = outer_index + 1) {

            max_index = outer_index;

            for (inner_index = outer_index + 1; inner_index < length; inner_index = inner_index + 1) {

                if (*the_vector[max_index] < *the_vector[inner_index]) {
                    max_index = inner_index;
                }

            }

            if (max_index != outer_index) {
                temp = the_vector[max_index];
                the_vector[max_index] = the_vector[outer_index];
                the_vector[outer_index] = temp;
            }

        }

    }


    /**
     * @brief  Move the terminal cursor to row 0 column 0.
     * @note   
     * @retval None
     */
    void cursor_home() {
        printf("\e[H");
    }


    /**
     * @brief  clear the screen.
     * @note   There is an option to reset the cursor to the home location (0, 0).
     * @param  reset_home: A bool specifying whether or not to reset the cursor to home. This is defaulted to false.
     * @retval None
     */
    void clear_screen(bool reset_home = false) {
        printf("\e[2J");
        if (reset_home) {
            cursor_home();
        }
    }

}







namespace test_toolbox {


    class all_tests {

        private:


            class test_instance {

                private:
                    std::string name;
                    std::string message;
                    bool passed;
                

                public:

                    test_instance() {

                    }

                    test_instance(std::string name, std::string message = "TEST PASSED", bool passed = true) {
                        this->name = name;
                        this->message = message;
                        this->passed = passed;
                    }

                    ~test_instance() {

                    }

                    /**
                     * @brief  Set the name of the test instance.
                     * @note   
                     * @param  new_name: The new name of the test_intance.
                     * @retval Return this to allow for continual test_instance methods.
                     */
                    test_instance set_name(std::string new_name) {
                        this->name = new_name;
                        return *this;
                    }

                    /**
                     * @brief  Get the name of the test_instance.
                     * @note   
                     * @retval The name of the test_instance.
                     */
                    std::string get_name() const {
                        return this->name;
                    }

                    /**
                     * @brief  Set the message of the test_instance.
                     * @note   
                     * @param  new_message: The new test_instance message.
                     * @retval Return this to allow for continual test_instance methods.
                     */
                    test_instance set_message(std::string new_message) {
                        this->message = new_message;
                        return *this;
                    }

                    /**
                     * @brief  Get the message of the current test_instance.
                     * @note   
                     * @retval Get the message of the current test_instance.
                     */
                    std::string get_message() const {
                        return this->message;
                    }

                    /**
                     * @brief  Set the pass status of the test_instance.
                     * @note   
                     * @param  pass: A bool to specify whether or not the test was passed or not.
                     * @retval Return this to allow for continual test_instance methods.
                     */
                    test_instance set_pass(bool pass) {
                        this->passed = pass;
                        return *this;
                    }

                    /**
                     * @brief  Get the status of whether or not the test_instance was passed or not.
                     * @note   
                     * @retval Returns a bool of whether or not the test was passed.
                     */
                    bool get_pass() const {
                        return this->passed;
                    }

                    /**
                     * @brief  Check if two test_instances have the same name (ignoring the case) and the same message (ignoring the case as well).
                     * @note   
                     * @param  other: The other test to be compared to.
                     * @retval true if the two tests both have the same name and message, false otherwise.
                     */
                    bool operator==(test_instance other) {
                        return ((useful_functions::same_string(this->name, other.get_name())) && (useful_functions::same_string(this->message, other.get_message())) && (this->passed == other.get_pass())) ? true : false;
                    }

                    /**
                     * @brief  Assignment operator for test_instances.
                     * @note   
                     * @param  other_test: 
                     * @retval 
                     */
                    test_instance& operator=(const test_instance& other_test) {
                        if (this == &other_test) {
                            this->set_name(other_test.get_name());
                            this->set_message(other_test.get_message());
                            this->set_pass(other_test.get_pass());
                        }
                        return *this;
                    }

                    /**
                     * @brief  Print a test_instance.
                     * @note   
                     * @param  print_name: A bool specifying whether or not to print the name of the test_instance.
                     * @param  print_message: A bool speciying whether or not to print the message of the test_instance.
                     * @param  print_pass: A bool specifying whether or not to print the passed status.
                     * @retval None
                     */
                    void print_test(bool print_name, bool print_message = true, bool print_pass = true) const {
                        
                        if (print_name) {
                            std::string the_string = useful_functions::colored_string((std::string) this->name, bold_style, (this->passed) ? (green_text) : (red_text), no_background);
                            char* the_name = useful_functions::string_to_char(the_string);
                            printf("\t%s\n", the_name);
                            free(the_name);
                        }
                        
                        if (print_message) {
                            std::string the_string = useful_functions::colored_string((std::string) this->message, bold_style, (this->passed) ? (green_text) : (red_text), no_background);
                            char* the_message = useful_functions::string_to_char(the_string);
                            printf("\t%s\n", the_message);
                            free(the_message);
                        }

                        if (print_pass) {
                            printf("PASS: %s\n", (this->passed) ? "passed" : "failed");
                        }
                        

                    }


            };

            typedef struct {
                std::string group_name;
                std::vector<test_instance> group_tests;
                unsigned long pass_count;
            } test_group;




            std::vector<test_group> test_groups;
            signed long last_added;



            /**
             * @brief  Get the index of the group name passed in.
             * @note   
             * @param  group_name: The group whose name is to be found.
             * @param  ignore_case: A bool specigying whether or ot to find the exact case or just the same group name without worrying about matching cases.
             * @retval -1 if the group name is not found. The index of the case otherwise.
             */
            signed long group_index(std::string group_name, bool ignore_case = true) const{
                signed long the_answer = 0;
                for (the_answer = 0; the_answer < this->test_groups.size(); the_answer = the_answer + 1) {
                    if (useful_functions::same_string(this->test_groups[the_answer].group_name, group_name, ignore_case)) {
                        return the_answer;
                    }
                }
                return -1;
            }
        
        public:

            all_tests(){
                this->last_added = -1;
            }


            all_tests(std::string the_group, test_instance a_test) {
                test_group group;
                group.group_name = the_group;
                group.pass_count = (a_test.get_pass()) ? 1 : 0;
                group.group_tests.push_back(a_test);
                this->test_groups.push_back(group);
                this->last_added = this->test_groups.size() - 1;
            }

            
            /**
             * @brief  Add a new test to the all_test instance.
             * @note   
             * @param  group_name: The group the test should be added to.
             * @param  test_name: The name of the test being added.
             * @param  test_message: The message of the test being added.
             * @param  pass: The pass status of the test being added.
             * @retval the current all_tests instance.
             */
            all_tests add_new_test(std::string group_name, std::string test_name, std::string test_message, bool pass = true) {
                
                signed long group_index = this->group_index(group_name);
                if (group_index == -1) {
                    test_group group;
                    group.group_name = group_name;
                    group.pass_count = (pass) ? 1 : 0;
                    group.group_tests.push_back(test_instance(test_name, test_message, pass));
                    this->test_groups.push_back(group);
                    this->last_added = this->test_groups.size() - 1;
                }
                else {
                    this->test_groups[group_index].pass_count = (pass) ? this->test_groups[group_index].pass_count + 1 : this->test_groups[group_index].pass_count;
                    this->test_groups[group_index].group_tests.push_back(test_instance(test_name, test_message, pass));
                    this->last_added = group_index;
                }
                
                return *this;
            }


            /**
             * @brief  Print all the tests.
             * @note   
             * @param  print_each_test: A bool specifying whether or not to each test should be printed or not. Defaulted to false.
             * @param  print_only_failed: A bool specifying whether or not to print only the failed tests. Defaulted to true.
             * @retval The current all_tests instance.
             */
            all_tests print_tests(bool print_each_test = false, bool print_only_failed = true) const {
                unsigned long group_index, test_index;
                std::string group;
                bool passed;
                unsigned short int text;
                for (group_index = 0; group_index < this->test_groups.size(); group_index = group_index + 1) {
                    group = useful_functions::case_caps(this->test_groups[group_index].group_name);
                    if (this->test_groups[group_index].pass_count > 0) {
                        group = useful_functions::colored_string(group + " :\t\t\t" + std::to_string(this->test_groups[group_index].pass_count) + " / " + std::to_string(this->test_groups[group_index].group_tests.size()) + " TESTS PASSED", (this->test_groups[group_index].pass_count == this->test_groups[group_index].group_tests.size()) ? green_text : yellow_text, bold_style, no_background);
                    }
                    else {
                        group = useful_functions::colored_string(group + " :\t\t\t" + std::to_string(this->test_groups[group_index].pass_count) + " / " + std::to_string(this->test_groups[group_index].group_tests.size()) + " TESTS PASSED", red_text, bold_style, no_background);
                    }
                    // printf("Group \"%s\"\n", group.c_str());
                    printf("%s\n", group.c_str());
                    if ((print_each_test) || ((print_only_failed) && (this->test_groups[group_index].pass_count < this->test_groups[group_index].group_tests.size()))) {
                        for (test_index = 0; test_index < this->test_groups[group_index].group_tests.size(); test_index = test_index + 1) {
                            passed = this->test_groups[group_index].group_tests[test_index].get_pass();
                            text = (passed) ? green_text : red_text;
                            if (!(print_each_test) && (print_only_failed) && !(passed)) {
                                printf("\t%s\t: %s\t:\t%s\n", useful_functions::colored_string((passed) ? "PASSED!" : "FAILED!", text, bold_style, no_background).c_str(), 
                                useful_functions::colored_string(this->test_groups[group_index].group_tests[test_index].get_name(), text, bold_style, no_background).c_str(), 
                                this->test_groups[group_index].group_tests[test_index].get_message().c_str());
                            }
                            else if (print_each_test) {
                                printf("\t%s\t: %s\t:\t%s\n", useful_functions::colored_string((passed) ? "PASSED!" : "FAILED!", text, bold_style, no_background).c_str(), 
                                useful_functions::colored_string(this->test_groups[group_index].group_tests[test_index].get_name(), text, bold_style, no_background).c_str(), 
                                this->test_groups[group_index].group_tests[test_index].get_message().c_str());
                            }
                            
                        }
                    }
                    printf("\n");

                }

                return *this;
            }


            /**
             * @brief  Print the last test added to the all_tests instance.
             * @note   
             * @param  print_each_test: A bool specifying whether or not to print each test. Defaulted to false.
             * @param  print_only_failed: A bool specifying whether or not to print only the tests that failed. Defaulted to true.
             * @retval The current all_tests instance.
             */
            all_tests print_last_added_group(bool print_each_test = false, bool print_only_failed = true) const {
                // printf("Pringing...\n");
                if (this->last_added != -1) {
                    unsigned test_index;
                    bool passed;
                    unsigned short int text;
                    std::string group = useful_functions::case_caps(this->test_groups[last_added].group_name);
                    // printf("Group is %s\n", group.c_str());
                    if (this->test_groups[last_added].pass_count > 0) {
                        group = useful_functions::colored_string(group + " :\t\t\t" + std::to_string(this->test_groups[this->last_added].pass_count) + " / " + std::to_string(this->test_groups[last_added].group_tests.size()) + " TESTS PASSED", (this->test_groups[this->last_added].pass_count == this->test_groups[this->last_added].group_tests.size()) ? green_text : yellow_text, bold_style, no_background);
                    }
                    else {
                        group = useful_functions::colored_string(group + " :\t\t\t" + std::to_string(this->test_groups[this->last_added].pass_count) + " / " + std::to_string(this->test_groups[last_added].group_tests.size()) + " TESTS PASSED", red_text, bold_style, no_background);
                    }
                    printf("%s\n", group.c_str());
                    for (test_index = 0; test_index < this->test_groups[this->last_added].group_tests.size(); test_index = test_index + 1) {
                        passed = this->test_groups[this->last_added].group_tests[test_index].get_pass();
                        text = (passed) ? green_text : red_text;
                        if (!(print_each_test) && (print_only_failed) && !(passed)) {
                            printf("\t%s\t: %s\t:\t%s\n", useful_functions::colored_string((passed) ? "PASSED!" : "FAILED!", text, bold_style, no_background).c_str(), 
                            useful_functions::colored_string(this->test_groups[this->last_added].group_tests[test_index].get_name(), text, bold_style, no_background).c_str(), 
                            this->test_groups[this->last_added].group_tests[test_index].get_message().c_str());
                        }
                        else if (print_each_test) {
                            printf("\t%s\t: %s\t:\t%s\n", useful_functions::colored_string((passed) ? "PASSED!" : "FAILED!", text, bold_style, no_background).c_str(), 
                            useful_functions::colored_string(this->test_groups[this->last_added].group_tests[test_index].get_name(), text, bold_style, no_background).c_str(), 
                            this->test_groups[this->last_added].group_tests[test_index].get_message().c_str());
                        }
                    }
                    printf("\n");

                }

                return *this;
            }


    };

}





