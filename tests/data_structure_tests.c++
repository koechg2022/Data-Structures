

#if not defined(_LIBCPP_IOSTREAM) && defined(unix_os)
    #include <iostream>
#endif

#if not defined(_LIBCPP_VECTOR)
    #include <vector>
#endif




#include "../headers/structures.h"



#define GREEN 32
#define RED    31
#define YELLOW 33


unsigned long passed, total, total_pass, total_total, absolute_pass, absolute_total;



unsigned long index_, extra, other_extra;

std::vector<std::string> imagine_dragons_lyrics, imagine_dragons_lyrics_caps;
std::vector<unsigned long> line_lengths;

void init();

void print_results(char* the_string, unsigned long pass, unsigned long tot, bool nl = true, unsigned long len_to_nums = 90, char shift_char = '.');

bool compare_with_case(std::string& first, std::string& second);

bool compare_ignore_case(std::string& first, std::string& second);

void update_tests(bool the_test);

void linked_list_tests();

int main() {
    init();
    linked_list_tests();
    print_results((char *) "\tlinked_list tests:\t\t\t", total_pass, total_total);
}


void init() {

    // Was too lazy to write all this out. I'm not a sadist.

    imagine_dragons_lyrics.push_back("[Intro]");
    imagine_dragons_lyrics.push_back("(Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("(Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Verse 1]");
    imagine_dragons_lyrics.push_back("I wanna live a life like that");
    imagine_dragons_lyrics.push_back("Live the life of the faithful one");
    imagine_dragons_lyrics.push_back("Wanna bow to the floor");
    imagine_dragons_lyrics.push_back("With everybody else wanna be someone");
    imagine_dragons_lyrics.push_back("I wanna make some love");
    imagine_dragons_lyrics.push_back("I don't want no enemies");
    imagine_dragons_lyrics.push_back("Oh, it's the curse of the man");
    imagine_dragons_lyrics.push_back("Always living life, living life, living just to please");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Chorus]");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("And the wrath of the giver");
    imagine_dragons_lyrics.push_back("With the hands of a sinner");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("And the wrath of the giver (Woah, now)");
    imagine_dragons_lyrics.push_back("With the hands of a sinner (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("See Imagine Dragons Live");
    imagine_dragons_lyrics.push_back("Get tickets as low as $49");
    imagine_dragons_lyrics.push_back("You might also like");
    // imagine_dragons_lyrics.push_back("Automatic");
    // imagine_dragons_lyrics.push_back("C.Gambino");
    // imagine_dragons_lyrics.push_back("Mussukka");
    // imagine_dragons_lyrics.push_back("Vesa heimo");
    // imagine_dragons_lyrics.push_back("Käpy");
    // imagine_dragons_lyrics.push_back("​koira");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Verse 2]");
    imagine_dragons_lyrics.push_back("Oh, I'm alkaline");
    imagine_dragons_lyrics.push_back("I'm always keeping to the basics");
    imagine_dragons_lyrics.push_back("I'm overboard");
    imagine_dragons_lyrics.push_back("I'm self-destructive");
    imagine_dragons_lyrics.push_back("And self-important");
    imagine_dragons_lyrics.push_back("And I'm anxious");
    imagine_dragons_lyrics.push_back("Oh, I'm self-assured");
    imagine_dragons_lyrics.push_back("I'm nervous");
    imagine_dragons_lyrics.push_back("And I'm pacing, oh, I'm pacing");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Chorus]");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("And the wrath of the giver");
    imagine_dragons_lyrics.push_back("With the hands of a sinner");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("And the wrath of the giver (Woah, now)");
    imagine_dragons_lyrics.push_back("With the hands of a sinner (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Post-Chorus]");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river, river, river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river, river, river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Bridge]");
    imagine_dragons_lyrics.push_back("And I am going under");
    imagine_dragons_lyrics.push_back("Oh, I am going under");
    imagine_dragons_lyrics.push_back("I am going under");
    imagine_dragons_lyrics.push_back("Oh, I am going under");
    imagine_dragons_lyrics.push_back("I am going under");
    imagine_dragons_lyrics.push_back("Oh, I");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Chorus]");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("And the wrath of the giver");
    imagine_dragons_lyrics.push_back("With the hands of a sinner");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("And the wrath of the giver (Woah, now)");
    imagine_dragons_lyrics.push_back("With the hands of a sinner (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("\n\n");
    imagine_dragons_lyrics.push_back("[Outro]");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river, river, river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river, river, river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back(" the mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river, river, river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        std::string this_line = "";
        for (extra = 0; extra < imagine_dragons_lyrics[index_].length(); extra = extra + 1) {
            this_line = this_line + useful_functions::to_caps(imagine_dragons_lyrics[index_][extra]);
        }
        line_lengths.push_back(imagine_dragons_lyrics[index_].length());
        imagine_dragons_lyrics_caps.push_back(this_line);
    }
}

void print_results(char* the_string, unsigned long pass, unsigned long tot, bool nl, unsigned long len_to_nums, char shift_char) {
    unsigned long this_index, str_len = std::string(the_string).length();
    #if defined(unix_os)
        std::printf("\x1B[1;%u;49m%s", (pass = tot) ? GREEN : (pass == 0) ? RED : YELLOW, the_string);
        for (this_index = str_len; this_index < len_to_nums; this_index = this_index + 1) {
            std::printf("%c", shift_char);
        }
        std::printf("\t%lu / %lu\x1B[0m%c", pass, tot, (nl) ? '\n' : 0);
    #else
        std::printf("%s");
        for (this_index = str_len; this_index < len_to_nums; this_index = this_index + 1) {
            std::printf("%c", shift_char);
        }
        std::printf("\t%lu / %lu%c", pass, tot, (nl) ? '\n' : 0);
    #endif
}


bool compare_with_case(std::string& first, std::string& second) {
    return useful_functions::same_string(first.c_str(), second.c_str(), false);
}

bool compare_ignore_case(std::string& first, std::string& second) {
    return useful_functions::same_string(first.c_str(), second.c_str(), true);
}

void update_tests(bool the_test) {
    passed = (the_test) ? passed + 1 : passed;
    total_pass = (the_test) ? total_pass + 1 : total_pass;
    absolute_pass = (the_test) ? absolute_pass + 1 : absolute_pass;
    total++;
    total_total++;
    absolute_total++;
}


void linked_list_tests() {

    // std::printf("length is %lu\n", std::string((char *) "Correctly initialized a std::string linked list	:\t").length());
    std::printf("linked list tests:\n");
    passed = total = 0;
    Data_Structures::linked_list<std::string> string_list;
    std::string this_string;
    #if defined(crap_os)
        char buffer[100];
    #endif
    update_tests(string_list.empty());
    update_tests(string_list.length() == 0);
    update_tests(!string_list);
    update_tests(string_list.throws_and_distructs());
    print_results((char *) "\t\tCorrectly initialized a std::string linked list\t:\t", passed, total);

    passed = total = 0;
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        update_tests(string_list.push(imagine_dragons_lyrics[index_]));
    }
    #if defined (crap_os)
        std::sprintf(buffer, "%lld", imagine_dragons_lyrics.size());
        print_results((char*) ("\t\tSuccessfully added " + std::string(buffer) + " strings to the end of the std::string linked list\t:\t").c_str(), passed, total);
    #else
        print_results((char*) ("\t\tSuccessfully added " + std::to_string(imagine_dragons_lyrics.size()) + " strings to the end of the std::string linked list\t:\t").c_str(), passed, total);
    #endif
    
    passed = total = 0;
    string_list.reset();
    update_tests(string_list.empty());
    update_tests(string_list.length() == 0);
    update_tests(!string_list);
    update_tests(string_list.throws_and_distructs());
    print_results((char *) "\t\tCorrectly resets a std::string linked list\t:\t", passed, total);

    passed = total = 0;
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        update_tests(string_list.push(imagine_dragons_lyrics[index_], 0));
    }

    #if defined (crap_os)
        std::sprintf(buffer, "%lld", imagine_dragons_lyrics.size());
        print_results((char*) ("\t\tSuccessfully added " + std::string(buffer) + " strings to the end of the std::string linked list\t:\t").c_str(), passed, total);
    #else
        print_results((char*) ("\t\tSuccessfully added " + std::to_string(imagine_dragons_lyrics.size()) + " strings to the end of the std::string linked list\t:\t").c_str(), passed, total);
    #endif
    passed = total = 0;
    string_list.reset();
    update_tests(string_list.empty());
    update_tests(string_list.length() == 0);
    update_tests(!string_list);
    update_tests(string_list.throws_and_distructs());
    print_results((char *) "\t\tCorrectly resets a std::string linked list after previously being reset\t:\t", passed, total);

    passed = total = 0;
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        string_list.push(imagine_dragons_lyrics[index_]);
    }

    extra = (imagine_dragons_lyrics_caps.size() / 2) - 10;
    for (index_ = 0; index_ < 10; index_ = index_ + 1) {
        string_list.push(imagine_dragons_lyrics_caps[extra + index_], extra + index_);
    }

    update_tests(!string_list.empty());
    update_tests(string_list.length() == imagine_dragons_lyrics.size() + 10);
    update_tests(string_list);
    for (index_ = 0; index_ < 10; index_ = index_ + 1) {
        update_tests(compare_ignore_case(imagine_dragons_lyrics[extra + index_], imagine_dragons_lyrics_caps[extra + index_]));
        update_tests(compare_ignore_case(string_list[index_ + extra], imagine_dragons_lyrics[index_ + extra]));
        update_tests(compare_with_case(string_list[index_ + extra], imagine_dragons_lyrics_caps[index_ + extra]));
    }
    print_results((char *) "\t\tCorrectly inserts into the center of a std::string linked list\t:\t", passed, total);
    
    passed = total = 0;
    unsigned long changed[10];
    extra = other_extra = 0;
    std::string changed_to = "This was manually changed";
    for (index_ = 0; index_ < string_list.length(); index_ = index_ + 1) {
        // std::printf("%lu.)\t%s\n", index_, string_list[index_].c_str());
        if (useful_functions::same_string(string_list[index_].c_str(), (char *) "\n\n")) {
            string_list[index_] = changed_to;
            changed[extra] = index_;
            extra = extra + 1;
            other_extra = other_extra + 1;
            // std::printf("Changing at index %lu\n", index_);
        }
    }
    
    for (index_ = 0; index_ < other_extra; index_ = index_ + 1) {
        this_string = string_list[changed[index_]];
        update_tests(compare_ignore_case(string_list[changed[index_]], changed_to));
        update_tests(compare_with_case(this_string, changed_to));
    }
    print_results((char *) "\t\tCorrectly changes data passed to a reference location with [] in a std::string linked list\t:\t", passed, total);

    passed = total = 0;
    string_list.reset();
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        update_tests(string_list.push(imagine_dragons_lyrics[index_]));
    }
    // list is filled
    // std::printf("string_list.length()\t:%lu\n", string_list.length());
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        update_tests(compare_with_case(imagine_dragons_lyrics[imagine_dragons_lyrics.size() - index_ - 1], string_list[ (((signed long) index_) + 1) * -1 ]));
    }

    print_results((char *) "\t\tCorrectly peeks negative indexes in a std::string linked list\t:\t", passed, total);
    index_ = 0;
    
    while (string_list) {
        this_string = string_list.pop();
        update_tests(compare_with_case(this_string, imagine_dragons_lyrics[index_]));
        // update_tests(!compare_with_case(this_string, imagine_dragons_lyrics_caps[index_]));
        update_tests(compare_ignore_case(this_string, imagine_dragons_lyrics_caps[index_]));
        update_tests(compare_ignore_case(this_string, imagine_dragons_lyrics[index_]));
        index_ = index_ + 1;
    }
    print_results((char *) "\t\tCorrectly pops from the front of the std::string linked list\t:\t", passed, total);
    // std::printf("Reached\n");
    passed = total = 0;
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        string_list.push(imagine_dragons_lyrics[index_]);
    }

    index_ = imagine_dragons_lyrics.size() - 1;
    while (string_list && index_ >= 0) {
        // std::printf("popping the data at original index %lu\n", index_);
        this_string = string_list.pop(-1);
        update_tests(compare_with_case(this_string, imagine_dragons_lyrics[index_]));
        index_ = index_ - 1;
    }
    print_results((char *) "\t\tCorrectly pops from the rear of the std::string linked list\t:\t", passed, total);


    // Need a test for popping from the center of the linked list now
    passed = total = 0;
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        string_list.push(imagine_dragons_lyrics[index_]);
    }

    index_ = (imagine_dragons_lyrics.size() / 2) - 10;
    for (extra = 0; extra < 10; extra = extra + 1) {
        this_string = string_list.pop(index_);
        update_tests(compare_with_case(this_string, imagine_dragons_lyrics[index_ + extra]));
        update_tests(compare_ignore_case(this_string, imagine_dragons_lyrics_caps[index_ + extra]));
    }
    print_results((char *) "\t\tCorrectly pops from the center of the std::string linked list\t:\t", passed, total);


    // Now for testing other data types in this linked list
    Data_Structures::linked_list<unsigned long> unsigned_list;

    passed = total = 0;
    update_tests(unsigned_list.empty());
    update_tests(unsigned_list.length() == 0);
    update_tests(unsigned_list.throws_and_distructs());
    
    print_results((char *) "\t\tCorrectly initializes an unsigned long linked list\t:\t", passed, total);

    passed = total = 0;
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        unsigned_list.push(imagine_dragons_lyrics[index_].length());
    }

    update_tests(unsigned_list.length() == imagine_dragons_lyrics.size());
    update_tests(!unsigned_list.empty());
    update_tests(unsigned_list.throws_and_distructs());

    print_results((char *) "\t\tCorrectly fills an unsigned long linked list to the proper size\t:\t", passed, total);

    passed = total = 0;
    for (index_ = 0; index_ < unsigned_list.length(); index_ = index_ + 1) {
        update_tests(unsigned_list[index_] == imagine_dragons_lyrics[index_].length());
        update_tests(unsigned_list[index_] == imagine_dragons_lyrics_caps[index_].length());
    }

    print_results((char *) "\t\tCorrectly fills an unsigned long linked list with the proper data at the proper location\t:\t", passed, total);

    index_ = passed = total = 0;
    while (unsigned_list) {
        extra = unsigned_list.pop();
        update_tests(extra == imagine_dragons_lyrics[index_].length());
        update_tests(extra == imagine_dragons_lyrics_caps[index_].length());
        index_ = index_ + 1;
    }

    print_results((char *) "\t\tCorrectly pops data from the front of an unsigned long linked list\t:\t", passed, total);
    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        unsigned_list.push(imagine_dragons_lyrics[index_].length());
    }
    passed = total = 0;
    Data_Structures::linked_list<unsigned long> copied_unsigned = unsigned_list;
    update_tests(copied_unsigned.length() == unsigned_list.length());
    update_tests(copied_unsigned.empty() == unsigned_list.empty());
    update_tests(copied_unsigned.throws_and_distructs() == unsigned_list.throws_and_distructs());
    index_ = 0;
    while (copied_unsigned && unsigned_list) {
        extra = copied_unsigned.pop();
        other_extra = unsigned_list.pop();
        update_tests(extra == other_extra);
        update_tests(imagine_dragons_lyrics[index_].length() == extra);
        update_tests(imagine_dragons_lyrics[index_].length() == other_extra);
        update_tests(imagine_dragons_lyrics[index_].length() == extra);
        update_tests(imagine_dragons_lyrics_caps[index_].length() == other_extra);
        index_ = index_ + 1;
    }

    print_results((char *) "\t\tCorrectly initializes a linked list that was assigned another linked list\t:\t", passed, total);

}