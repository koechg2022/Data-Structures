

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)

    #if not defined(crap_os)
        #define crap_os
    #endif


#else
    #define unix_os

    #if defined(__APPLE__) || defined(__APPLE_CC__)
        #define mac_os
    #else
        #define linix_os
    #endif


#endif







#if not defined(__EXCEPTION_)
    #include <exception>
#endif



namespace useful_functions {

    inline bool is_caps(const char c) {
        return (c >= 'A' && c <= 'Z');
    }

    inline bool is_lower(const char c) {
        return (c >= 'a' && c <= 'z');
    }

    inline bool is_letter(const char c) {
        return (is_caps(c) || is_lower(c));
    }

    inline bool is_number(const char c) {
        return (c >= '0' && c <= '9');
    }

    inline char to_caps(const char c) {
        return (is_lower(c)) ? (c - ('a' - 'A')) : c;
    }

    inline char to_lower(const char c) {
        return (is_caps(c)) ? (c + ('A' - 'a')) : c;
    }

    inline bool same_char(const char a, const char b, bool ignore_case = true) {
        return (ignore_case) ? to_caps(a) == to_caps(b) : a == b;
    }

    inline bool same_string(const char* a, const char* b, bool ignore_case = true) {
        if (a == b) {
            return true;
        }
        unsigned long index_;
        for (index_ = 0; a[index_] != '\0' && b[index_] != '\0'; index_ = index_ + 1) {
            if (!same_char(a[index_], b[index_], ignore_case)) {
                return false;
            }
        }
        return (a[index_] == '\0' && b[index_] == '\0');
    }

}