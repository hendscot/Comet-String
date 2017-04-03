#include "String.h"
namespace Comet {
    // Default Constructor
    String::String(const size_t size)
        : s_buf(NULL), s_bLen(0), s_sLen(0) {
        // allocate space
        Alloc(size);
    } // String::String()

    // Construct with a c-string
    String::String(const char* str) 
        : String(len(str)) {
        s_sLen = s_bLen;
        // use assignment overload to create
        *this = str;
    } // String::String(const char*)

    // Copy Constructor
    String::String(const String& str) 
        : String(str.s_sLen) {
        s_sLen = s_bLen;
        // use assignment overload to create
        *this = str;
    } // String::String(const String&)

    // Deconstructor
    String::~String() {
        // delete the buffer on deconstruction
        Dealloc ();
    } // String::~String()

    //************* Overloaded Operators ************************

    // Assignment (Two Strings)
    String& String::operator=(const String& str) {
        // Check that we're not assigning same objs
        if (this != &str) {
            // Only resize if new length is >= to buffer length
            return (*this = str.GetBuff());
        }
    } // operator=(const String&)

    // Assignment overload (String and C-String)
    String& String::operator=(const char* str) {
        size_t length = len(str);
        // only reallocate if new string length is > buffer length
        if (length > s_bLen) {
            Alloc (length);
            s_sLen = length;
        }
        else {
            s_sLen = length;
            Term(s_sLen);
        }
        FillFrom(str, 0, length);
        return *this;
    }

    //***************COMPARATORS************************************************
    // Compare two String objects
    bool String::operator==(const String& str) const {
        bool isEqual = true;
        // if lengths are different, not equal
        if (this->s_sLen != str.s_sLen)
            return false;
        else {
            // compare each element of both strings
            for (iter = 0; iter < this->s_sLen && isEqual == true; iter++) {
                // if even one char is different, not qual
                if (this->s_buf[iter] != str.s_buf[iter])
                    isEqual = false;
            }
        }
        return isEqual;
    }

    // Compare string with c-string
    bool String::operator==(const char* str) const {
        bool isEqual = true;
        if (this->s_sLen != len(str))
            return false;
        else {
            for (iter = 0; iter < this->s_sLen && isEqual == true; iter++) {
                if (this->s_buf[iter] != str[iter])
                    isEqual = false;
            }
        }
        return isEqual;
    }

    // compare two strings
    bool String::operator!=(const String& str) const {
        return !((*this) == str);
    }

    // compare string with c-string
    bool String::operator!=(const char* str) const {
        return !((*this) == str);
    }

    // compare string with c-string
    bool String::operator>(const char* str) const {
        return (this->s_sLen > len(str)) ? true : false;
    }

    // compare two strings
    bool String::operator>(const String& str) const {
        return (this->s_sLen > str.s_sLen) ? true : false;
    }

    // compare string with c-string
    bool String::operator<(const char* str) const {
        return (this->s_sLen < len(str)) ? true : false;
    }

    // compare two strings
    bool String::operator<(const String& str) const {
        return (this->s_sLen < str.s_sLen) ? true : false;
    }

    // compare string with c-string
    bool String::operator>=(const char* str) const {
        return (this->s_sLen >= len(str)) ? true : false;
    }

    // compare two strings
    bool String::operator>=(const String& str) const {
        return (this->s_sLen >= str.s_sLen) ? true : false;
    }

    // compare string with c-string
    bool String::operator<=(const char* str) const {
        return (this->s_sLen <= len(str)) ? true : false;
    }

    // compare two strings
    bool String::operator<=(const String& str) const {
        return (this->s_sLen <= str.s_sLen) ? true : false;
    }
    
    String operator+(const String& lhs, const String& rhs) {
        String string;
        string.Alloc(string.s_sLen = lhs.Length() + rhs.Length());
        string.Concat(lhs.GetBuff(), rhs.GetBuff());
        return string;
    }

    String operator+(const String& lhs, const char* rhs) {
        String string;
        string.Alloc(string.s_sLen = lhs.Length() + Comet::String::len(rhs));
        string.Concat(lhs.GetBuff(), rhs);
        return string;
    }

    void String::operator+=(const char* str) {
        this->Append(str);
    }

    void String::operator+=(const String& str) {
        return (*this += str.s_buf);
    }

    // concatenate two c-strings
    void String::Concat(const char* str1, const char* str2) {
        // len1 = length of first string, len2 = length of second string
        size_t len1 = len(str1), len2 = len(str2);
        // fill first part of string with c-string
        for (iter = 0; iter < len1; iter++) {
            s_buf[iter] = str1[iter];
        }
        // fill second part of string with second c-string
        for (size_t i = 0; i < len2; i++, iter++) {
            s_buf[iter] = str2[i];
        }
    }

    String String::Substr(const size_t in1, const size_t sz) const {
        size_t in2 = ((in1 + sz) - 1);
        if (in1 >= 0 && in2 < s_sLen) {
            char* buff = new char[sz + 1]();
            for (int i = 0, iter = in1; iter <= in2; iter++, i++) {
                buff[i] = s_buf[iter];
            }
            String string(buff);
            delete buff;
            return string;
        }
    }

    // fill buffer with c-string
    void String::FillFrom(const char* str) {
        FillFrom(str, 0, len(str));
    }

    void String::FillFrom(const char* str, const size_t start, const size_t length) {
        size_t i;
        for (i = 0, iter = start; iter < this->s_sLen && i < length; iter++, i++) {
            this->s_buf[iter] = str[i];
        }
    }

    void String::FillTo(char* str) const {
        for (iter = 0; iter < this->s_sLen; iter++) {
            str[iter] = this->s_buf[iter];
        }       
    }

    // TODO: HANDLE OUT OF RANGE
    // subscript operator
    char& String::operator[](const size_t index) const {
        // if desired index isn't out of range
        // return reference to value
        if (index >= 0 && index < s_sLen) {
            return s_buf[index];
        }
        // else return null

    }

    // allocate space for string
    void String::Alloc(const size_t len) {
        // check if new length is positive
        if (len >= 0) {
            // deallocate if string is full already
            if (s_sLen > 0) {
                Dealloc();
            }
            // allocate if new length is greater than 0
            if (len != 0) {
                s_bLen = len;
                s_buf = new char[s_bLen + 1];
                Term(0);
            }
        }
    }

    // deallocate string space
    void String::Dealloc() {
        // deallocate if buffer is full
        if (s_bLen > 0 && s_buf != NULL) {
            s_sLen = 0;
            s_bLen = 0;
            delete [] s_buf;
            s_buf = NULL;
        }
    }

    void String::Term(const size_t spnt) {
        for (iter = spnt; iter <= s_bLen; iter++) {
            s_buf[iter] = '\0';
        }
    }

    
    // Public mutators
    void String::Reverse() {
        // used for temp storage of character
        char temp;
        for (size_t i = 0, j = s_sLen - 1; i <= j; i++, j--) {
            temp = s_buf[i];
            s_buf[i] = s_buf[j];
            s_buf[j] = temp;
        }
    }

    // replace char at index with new char
    void String::Replace(const size_t in, char ch) {
        if (in >= 0 && in < s_sLen) {
            this->s_buf[in] = ch;
        }
        else {
            std::cerr << "Operation Aborted: Boundary Error" << std::endl;
        }
    }

    // replace specified range with a new string
    void String::Replace(const size_t b_In, const size_t e_In, const char* str) {
        // first get length of cstring
        size_t slen = len(str);
        // if indices are within bounds and in order
        if (b_In >= 0 && e_In < s_sLen && b_In <= e_In) {
            // iterate starting at b_in and beginning of cstring
            for (size_t i = 0, iter = b_In; iter <= e_In && i < slen; ++iter, ++i) {
                this->s_buf[iter] = str[i];
            }
        }
    } // Replace (size_t, size_t, const char*)

    // Delete a single char *calls overloaded delete for deleting range
    void String::Delete(const size_t in) {
        // single character so range is in to in
        Delete(in, in);
    }

    // Delete a range of characters from in1 to in2 inclusive!
    void String::Delete(const size_t in1, const size_t in2) {
        // boundary checking
        if (in1 >= 0 && in1 <= in2 && in2 < s_sLen) {
            size_t range = ((in2 - in1) + 1);
            // first assign as much to range from left over after range as possible
            for (size_t i = in1, j = (in2 + 1); i <= in2, j < s_sLen; i++, j++) {
                s_buf[i] = s_buf[j];
            }
            // now null terminate leftover for cases where range and leftover are not equal
            for (size_t i = (s_sLen - range); i < s_sLen; i++) {
                s_buf[i] = '\0';
            }
            // now update string length
            s_sLen -= range;
        }
    }
    /**********************Main Append Method***********************************************
     *
     *         Takes a cstring and its length as arguments to append to current buffer
     *      Two overloaded methods allow for using a char or cstring
     *      Prgrmr ay NOT call this method, for their own protection, other appends calculate
     *      length of string for them. This is necessary to user char with Append!
     **************************************************************************************/
    void String::Append(const char* str, const size_t leng) {
        Insert(this->End() + 1, leng, str);
    }
    /****One of the two public append methods. Calculates length of string and calls overloaded
     *   append method
     */
    void String::Append(const char* str) {
        Append(str, len(str));
    }

    void String::Append(const String& str) {
        Append(str.s_buf, str.Length());
    }

    //?? WORK IN PROGRESS, MAY NEED TO USE A VEC FOR size_tTOCHAR
    // FOR MULTI-DIGIT size_tEGERS
    void String::Append(int x) {
        String num;
        char y;
        for (; !(x >= 0 && x <= 9); x /= 10) {
            y = char((x % 10) + 48);
            num.Prepend(y);
        }
         y = char((x % 10) + 48);
         num.Prepend(y);
        Append(num);
    }

    char String::IntToChar(int x) {    
    }
    /*One of the two public append methods. Passes a char by reference to be compatible with
     * cstring append method where append logic is. we pass one as the length of the character
     * if we don't pass length before calling append, we get undefined length due to lack of 
     * terminating char '\0'. This makes it necessary to pass length for cstring first ver. too
     */
    // Append a character to the end of the string
    void String::Append(char ch) {
        Append(&ch, 1);
    } // APPEND(CHAR)

    // simply inserts a char at the beginning. Unecessary, just for user-friendliness
    void String::Prepend(char ch) {
        Insert(0, 1, &ch);
    }

    bool String::Insert(const int in, const char* str) {
        Insert(in, len(str), str);
    }

    // insert a char at a specified index
    bool String::Insert(const int in, const size_t strLen, const char* str) {
        if (s_sLen == 0 && in == 0) {
            Alloc(strLen + REALLOC_BY);
            s_sLen += strLen;
            FillFrom(str);
        }
        // make sure index is within bounds
        else if (in >= 0 && in <= s_sLen) {
            size_t length = s_sLen;
            size_t sLength = s_sLen + strLen;
            // must reallocate if inserting a char will cause overflow
            if ((s_sLen + strLen) > s_bLen) {
                size_t bLength = sLength + REALLOC_BY;
                char* t_buf = new char[length + 1];
                t_buf[length] = '\0';
                FillTo(t_buf);
                Alloc(bLength);
                s_sLen = sLength;
                FillFrom(t_buf);
                delete t_buf;
            }
            else {
                s_sLen += strLen;
            }
            for (iter = length; iter >= in; --iter) {
                s_buf[iter + strLen] = s_buf[iter];
            }
            FillFrom(str, in, strLen);
        }
        // TODO: OUT OF INDEX HANDLE
        else {
            return 0;
        }
        return 1;
    } // INSERT(size_t, CHAR)

    // Capitalize every letter in the string
    bool String::Upper() {
        // call overloaded Upper() with range of entire string
        return this->Upper(0, (s_sLen - 1));
    } // UPPER

    // capitalize specific character
    bool String::Upper(const size_t in) {
        // call overloaded Upper() with range of in to in (one char)
        return this->Upper(in, in);
    }

    // capitalize all letters
    // used for overloaded methods
    bool String::Upper(const size_t in1, const size_t in2) {
        if (in1 <= in2 && in2 < s_sLen) {
            for (iter = in1; iter <= in2; iter++) {
                if (isAlpha(s_buf[iter]) && isLower(s_buf[iter])) {
                    s_buf[iter] = (s_buf[iter] - CASEDIFF);
                }
            }
            return true;
        }
        else
            return false;
    }

    // set all characters to lowercase
    bool String::Lower() {
        return this->Lower(0, (s_sLen - 1));
    }

    // set specific character to lowercase
    bool String::Lower(const size_t in) {
        return this->Lower(in, in);
    }

    // set range of characters to lowercase
    // used for other methods
    bool String::Lower(const size_t in1, const size_t in2) {
        if (in1 <= in2 && in2 < s_sLen) {
            for (iter = in1; iter <= in2; iter++) {
                if (isAlpha(s_buf[iter]) && isUpper(s_buf[iter])) {
                    s_buf[iter] = (s_buf[iter] + CASEDIFF);
                }
            }
            return true;         
        }
        else
            return false;
    }

    // Public accessors
    size_t String::Length() const {
        return s_sLen;
    }

    size_t String::End() const {
        return (s_sLen - 1);
    }

    size_t String::Search (const char* str) const {
        int leng = len(str);
        for (iter = 0; iter < s_sLen; iter++) {
            if (s_buf[iter] == str[0]) {
                if (iter + (leng - 1) < s_sLen) {
                    if (cmp (Substr (iter, leng).GetBuff(), str))
                        return iter;
                }
            }
        }
        return strnf;
    }

    size_t String::Search (const String& str) const {
        return (this->Search (str.GetBuff ()));
    }

    size_t String::Search (char ch) const {
        for (iter = 0; iter < s_sLen; iter++) {
            if (s_buf[iter] == ch) return iter;
        }
        return strnf;
    }

    char String::CharAt(const size_t in) const {
        if (in < s_sLen) return s_buf[in];
    }

    char* String::GetBuff() const {
        return s_buf;
    }

    // Print with help from a friend
    std::ostream& operator<<(std::ostream& ost, const String& str) {
        return ost << str.s_buf;
    }

    // STATIC
    // helper methods
    size_t String::len(const char* str) {
        size_t i;
        for (i = 0; str[i] != '\0'; i++) {}
        return i;
    }

    bool String::cmp (const char* str1, const char* str2) {
        int leng = len (str1);
        if (leng != len (str2)) return false;
        for (int i = 0; i < leng; ++i) {
            if (str1[i] != str2[i]) return false;
        }
        return true;
    }

    // check if character is alphabetical
    bool String::isAlpha(const char ch) {
        return ((int(ch) >= CAP_BEG && int(ch) <= CAP_END
                 || int(ch) >= LOW_BEG && int(ch) <= LOW_END)) ? true : false;
    }

    // check if character is uppercase
    bool String::isUpper(const char ch) {
        return ((isAlpha(ch) && ch <= CAP_END)) ? true : false;
    }

    // check if character is lowercase
    bool String::isLower(const char ch) {
        return ((isAlpha(ch) && ch >= LOW_BEG)) ? true : false;
    }
}