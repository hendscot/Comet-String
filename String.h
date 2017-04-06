#ifndef STRING_H
#define STRING_H

#include <iostream>

/*=================TO DO ==================
 * 1. handle s_sLen assign in Alloc
 * 2. add way to insert append numbers
 * 4. need error handling, exceptions...
 *=======================================*/
namespace Comet {
//#define NULL ( (void *) 0)
#define COMET_STRING_VERSION     "0.2.3"
#define CASEDIFF                 0x0020
#define CAP_BEG                  0x0041
#define CAP_END                  0x005A
#define LOW_BEG                  0x0061
#define LOW_END                  0x007A
#define REALLOC_BY               0x000A
    class String {
        public:
            // constructors
            explicit
            String                (size_t size = 0);
            explicit
            String                (const char*);         
            // copy constructor
            String                (const String&);           
            // destructor
            ~String               (); 
            // operator overloads
            String& operator  =   (const String&);
            String& operator  =   (const char*);
            /*************** TODO ! ***********/
            void    operator  +=  (const String&);
            void    operator  +=  (const char*);
            /**********************************/            
            bool    operator  ==  (const String&)     const;
            bool    operator  ==  (const char*)       const;
            bool    operator  !=  (const String&)     const;
            bool    operator  !=  (const char*)       const;
            bool    operator  >   (const char*)       const;
            bool    operator  >   (const String&)     const;
            bool    operator  <   (const char*)       const;
            bool    operator  <   (const String&)     const;
            bool    operator  >=  (const char*)       const;
            bool    operator  >=  (const String&)     const;
            bool    operator  <=  (const char*)       const;
            bool    operator  <=  (const String&)     const;
            char&   operator  []  (const size_t)      const;
            // Public Accessors
            size_t  End           ()                  const;
            size_t  Length        ()                  const;
            size_t  Search        (const char *)      const;
            size_t  Search        (const String&)     const;
            size_t  Search        (char)              const;
            char*   GetBuff       ()                  const;
            char    CharAt        (const size_t)      const;
            String  Substr        (const size_t, const size_t) const;
            // Public Mutators
            void    Replace       (const size_t, char);
            void    Replace       (const size_t, const size_t, const char*);
            void    Append        (char);
            void    Append        (const char*);
            void    Append        (const String&);
            void    Append        (int);
            void    Prepend       (char);
            bool    Insert        (const int, const char*);
            bool    Insert        (const int, char);
            bool    Insert        (const int, const size_t, const char*);
            void    Delete        (const size_t);
            void    Delete        (const size_t, const size_t);
            void    Reverse       ();
            bool    Upper         ();
            bool    Upper         (const size_t);
            bool    Upper         (const size_t, const size_t);
            bool    Lower         ();
            bool    Lower         (const size_t);
            bool    Lower         (const size_t, const size_t);
            static const
            size_t  strnf          = -1;
        private:
            // Private Data Members
            char*      s_buf;
            mutable 
            int        iter;
            size_t     s_bLen;
            size_t     s_sLen;
            // Private Mutators
            void    Alloc         (const size_t);
            void    Dealloc       ();
            void    Term          (const size_t);
            void    FillFrom      (const char*);
            void    FillFrom      (const char*, const size_t, const size_t);
            void    FillTo        (char*) const;
            void    Concat        (const char*, const char*);
            void    Append        (const char*, const size_t);
            // Private helper functions
            static size_t len              (const char*);
            static bool   isAlpha          (const char);
            static bool   isUpper          (const char);
            static bool   isLower          (const char);
            static char   IntToChar        (int);
            static bool   cmp              (const char*, const char*);
            // friends
            friend std::ostream& operator<<(std::ostream&, const String&);
            friend String  operator  +   (const String&, const String&);
            friend String  operator  +   (const String&, const char*);
    };
}
#endif // STRING_H