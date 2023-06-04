








// ESCAPE SEQUENCES
#define ansi_escape "\033["
#define default_console "\033[0m"



/* Interface dynamics */
#define cursor_up "\033[A" // Does not erase anything.
#define cursor_down "\033[B"
#define cursor_right "\033[C"
#define cursor_left "\033[D"
#define erase_all_prev "\033[2K"





/* TEXT STYLES */
#define no_style 0
#define bold_style 1
#define negative_1 2
#define italics 3
#define underline 4
#define flashing 5
#define negative_3 6
#define highlighted 7
#define highlight_no_text 8
#define crossed_out 9





/* TEXT COLORS */
#define black_text 30
#define red_text 31
#define green_text 32
#define yellow_text 33
#define blue_text 34
#define purple_text 35
#define cyan_text 36
#define white_text 37





/* BACKGROUND COLOR */
#define black_background 40
#define red_background 41
#define green_background 42
#define yellow_background 44
#define blue_background 44
#define purple_background 45
#define cyan_background 46
#define white_background 47
#define no_background 48







/* Format for using ansi escape
* \033[(text_style);(text_color);(background_color)m
* */










#define is_caps(letter) ((letter >= 'A') && (letter <= 'Z')) ? (true) : (false)
#define is_lower(letter) ((letter >= 'a') && (letter <= 'z')) ? (true) : (false)
#define is_letter(letter) ((is_caps(letter)) || (is_lower(letter))) ? (true) : (false)
#define is_number(letter) ((letter >= '0') && (letter <= '9')) ? (true) : (false)
#define to_caps(letter) ((is_letter(letter)) && (is_lower(letter))) ? (((char) letter) - ((char) ('a' - 'A'))) : (letter)
#define to_lower(letter) ((is_letter(letter)) && (is_caps(letter))) ? (((char) letter) + ((char) ('a' - 'A'))) : (letter)
#define char_to_int(letter) (is_number(letter)) ? (letter - (char) '0') : (letter)
#define min(a, b) (a <= b) ? (a) : (b)
#define max(a, b) (a >= b) ? (a) : (b)


