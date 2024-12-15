#ifndef MYSTUFF_EXCEPTIONS_H
#define MYSTUFF_EXCEPTIONS_H

# include <cassert>

#define assert(_Expression) \
     (void) ((!!(_Expression)) || (_assert(#_Expression,__FILE__,__LINE__),0))
#define MYSTUFF_DEBUG(_Expression) assert(_Expression)

#endif //MYSTUFF_EXCEPTIONS_H
