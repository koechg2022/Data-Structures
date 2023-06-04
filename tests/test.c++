#include "../headers/tests.h"


int main(int length, char** args) {

    printf("%s", erase_all_prev);

    std::vector<void (*)()> the_functions = {
        
    };


    unsigned short int index;

    for (index = 0; index < the_functions.size(); index = index + 1) {
        (*the_functions[index])();
        the_tests.print_last_added_group();
    }

    return 0;
}