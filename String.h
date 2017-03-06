#ifndef STRING_H
#define STRING_H

#include <iostream>

/*=================TO DO ==================
 * 1. handle s_sLen assign in Alloc
 * 2. add way to insert append numbers
 *=======================================*/

//#define NULL ( (void *) 0)
#define COMET_STRING_VERSION     0.1.5
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
            String                (int size = 0);
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
            bool    operator  ==  (const String&)  const;
            bool    operator  ==  (const char*)    const;
            bool    operator  !=  (const String&)  const;
            bool    operator  !=  (const char*)    const;
            bool    operator  >   (const char*)    const;
            bool    operator  >   (const String&)  const;
            bool    operator  <   (const char*)    const;
            bool    operator  <   (const String&)  const;
            bool    operator  >=  (const char*)    const;
            bool    operator  >=  (const String&)  const;
            bool    operator  <=  (const char*)    const;
            bool    operator  <=  (const String&)  const;
            char&   operator  []  (const int)      const;

            // Public Accessors
            int     End         ()                 const;
            int     Length      ()                 const;
            char*   GetBuff     ()                 const;
            char    CharAt      (int)              const;

            // Public Mutators
            void    Replace       (int, char);
            void    Replace       (int, int, const char*);
            void    Append        (char);
            void    Append        (const char*);
            void    Append        (const String&);
            void    Append        (const int);
            void    Prepend       (char);
            bool    Insert        (int, const char*);
            bool    Insert        (int, const char*, int);
            void    Delete        (int);
            void    Delete        (int, int);
            void    Reverse       ();
            bool    Upper         ();
            bool    Upper         (int);
            bool    Upper         (int, int);
            bool    Lower         ();
            bool    Lower         (int);
            bool    Lower         (int, int);
            void    Concat        (const String&);
            String  Substr        (int, int);

        private:
            // Private Data Members
            mutable 
            int     iter;
            char*   s_buf;
            int     s_bLen;
            int     s_sLen;

            // Private Mutators
            void    Alloc         (int);
            void    Dealloc       ();
            void    Term          (int);
            void    FillFrom      (const char*);
            void    FillFrom      (const char*, int);
            void    FillTo        (char*) const;
            void    Concat        (const char*, const char*);
            void    Append        (const char*, int);


            // Private helper functions
            int  len              (const char*)    const;
            bool isAlpha          (const char)     const;
            bool isUpper          (const char)     const;
            bool isLower          (const char)     const;
            char IntToChar        (int);

            // friends
            friend std::ostream& operator<<(std::ostream&, const String&);
            friend String  operator  +   (const String&, const String&);
    };
}

#endif // STRING_H