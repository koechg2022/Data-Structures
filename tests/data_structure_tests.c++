
#include <utility>
#if not defined(_LIBCPP_IOSTREAM)
    #include <iostream>
#endif

#if not defined(_LIBCPP_VECTOR)
    #include <vector>
#endif

#if not defined(_LIBCPP_MAP)
    #include <map>
#endif

#include "../headers/structures.h"



#define GREEN 32
#define RED    31
#define YELLOW 33


unsigned long passed, total, total_pass, total_total, absolute_pass, absolute_total;




// void print_with_nums(const char* the_string, unsigned long pass, unsigned long tot, bool nl = true) {
//     #if defined(unix_os)
//         std::printf("\x1B[1;%u;49m%s%lu / %lu\x1B[0m%c", (pass == tot) ? GREEN : (pass == 0) ? RED : YELLOW, the_string, pass, tot, (nl) ? '\n' : 0);
//     #else
//         std::printf("%s%lu/%lu\n", the_string, pass, tot);
//     #endif
// }

// void print_just_words(const char* the_string, bool nl = true, unsigned short color = GREEN) {
//     #if defined(unix_os) 
//         std::printf("\x1B[1;%u49m%s\x1B[0m%c", color, the_string, (nl) ? '\n' : 0);
//     #else
//         std::printf("%s%c", the_string, (nl) ? '\n' : 0);
//     #endif
// }


unsigned long index_, extra;

std::vector<std::string> imagine_dragons_lyrics, imagine_dragons_lyrics_caps;
std::vector<unsigned long> line_lengths;

void init();

void print_results(char* the_string, unsigned long pass, unsigned long tot, bool nl = true);

bool compare_with_case(std::string& first, std::string& second);

bool compare_ignore_case(std::string& first, std::string& second);

void update_tests(bool the_test);

void linked_list_tests();

int main() {
    init();
    linked_list_tests();
    print_results((char *) "\tlinked_list tests\t:\t", total_pass, total_total);
}


void init() {

    // Was too lazy to write all this out. I'm not a sadist.

    imagine_dragons_lyrics.push_back("[Intro]");
    imagine_dragons_lyrics.push_back("(Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("(Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("[Verse 1]");
    imagine_dragons_lyrics.push_back("I wanna live a life like that");
    imagine_dragons_lyrics.push_back("Live the life of the faithful one");
    imagine_dragons_lyrics.push_back("Wanna bow to the floor");
    imagine_dragons_lyrics.push_back("With everybody else wanna be someone");
    imagine_dragons_lyrics.push_back("I wanna make some love");
    imagine_dragons_lyrics.push_back("I don't want no enemies");
    imagine_dragons_lyrics.push_back("Oh, it's the curse of the man");
    imagine_dragons_lyrics.push_back("Always living life, living life, living just to please");
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
    imagine_dragons_lyrics.push_back("Automatic");
    imagine_dragons_lyrics.push_back("C.Gambino");
    imagine_dragons_lyrics.push_back("Mussukka");
    imagine_dragons_lyrics.push_back("Vesa heimo");
    imagine_dragons_lyrics.push_back("Käpy");
    imagine_dragons_lyrics.push_back("​koira");
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
    imagine_dragons_lyrics.push_back("[Chorus]");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("And the wrath of the giver");
    imagine_dragons_lyrics.push_back("With the hands of a sinner");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("And the wrath of the giver (Woah, now)");
    imagine_dragons_lyrics.push_back("With the hands of a sinner (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("[Post-Chorus]");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river, river, river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mou-, mouth of the river");
    imagine_dragons_lyrics.push_back("Mou-, mou-, mouth of the river, river, river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("[Bridge]");
    imagine_dragons_lyrics.push_back("And I am going under");
    imagine_dragons_lyrics.push_back("Oh, I am going under");
    imagine_dragons_lyrics.push_back("I am going under");
    imagine_dragons_lyrics.push_back("Oh, I am going under");
    imagine_dragons_lyrics.push_back("I am going under");
    imagine_dragons_lyrics.push_back("Oh, I");
    imagine_dragons_lyrics.push_back("[Chorus]");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river (Woah, now)");
    imagine_dragons_lyrics.push_back("And the wrath of the giver");
    imagine_dragons_lyrics.push_back("With the hands of a sinner");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
    imagine_dragons_lyrics.push_back("And the wrath of the giver (Woah, now)");
    imagine_dragons_lyrics.push_back("With the hands of a sinner (Woah, now)");
    imagine_dragons_lyrics.push_back("Oh, the mouth of the river");
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

void print_results(char* the_string, unsigned long pass, unsigned long tot, bool nl) {
    #if defined(unix_os)
        std::printf("\x1B[1;%u;49m%s%lu / %lu\x1B[0m%c", (pass == tot) ? GREEN : (pass == 0) ? RED : YELLOW, the_string, pass, tot, (nl) ? '\n' : 0);
    #else
        std::printf("%s%lu/%lu\n", the_string, pass, tot);
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

    std::printf("linked list tests:\n");
    passed = total = 0;
    Data_Structures::linked_list<std::string> string_list;
    update_tests(string_list.empty());
    update_tests(string_list.length() == 0);
    update_tests(!string_list);
    update_tests(string_list.throws_and_distructs());
    print_results((char *) "\tCorrectly initialized a Linked list : ", passed, total);

    for (index_ = 0; index_ < imagine_dragons_lyrics.size(); index_ = index_ + 1) {
        update_tests(string_list.push(imagine_dragons_lyrics[index_]));
    }
    print_results((char*) ("\tSuccessfully added " + std::to_string(imagine_dragons_lyrics.size()) + " strings to the linked list").c_str(), passed, total);
}