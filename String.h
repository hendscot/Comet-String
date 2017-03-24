#ifndef STRING_H
#define STRING_H

#include <iostream>

/*=================TO DO ==================
 * 1. handle s_sLen assign in Alloc
 * 2. add way to insert append numbers
 *=======================================*/

//#define NULL ( (void *) 0)
#define COMET_STRING_VERSION     "0.1.9"
#define CASEDIFF                 0x0020
#define CAP_BEG                  0x0041
#define CAP_END                  0x005A
#define LOW_BEG                  0x0061
#define LOW_END                  0x007A
#define REALLOC_BY               0x000A

namespace Comet {
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
            
            void  operator  +=  (const String&);
            void  operator  +=  (const char*);
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
            char*   GetBuff       ()                  const;
            char    CharAt        (const size_t)      const;

            // Public Mutators
            void    Replace       (const size_t, char);
            void    Replace       (const size_t, const size_t, const char*);
            void    Append        (char);
            void    Append        (const char*);
            void    Append        (const String&);
            void    Append        (int);
            void    Prepend       (char);
            bool    Insert        (const int, const char*);
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
            void    Concat        (const String&);
            String  Substr        (const size_t, const size_t);

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
            size_t len              (const char*)    const;
            bool   isAlpha          (const char)     const;
            bool   isUpper          (const char)     const;
            bool   isLower          (const char)     const;
            char   IntToChar        (int);

            // friends
            friend std::ostream& operator<<(std::ostream&, const String&);
            friend String  operator  +   (const String&, const String&);
    };
}

#endif // STRING_H