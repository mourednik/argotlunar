#ifndef DEBUG_H
#define DEBUG_H

#ifdef LINUX
#define DEBUG
#endif

#ifdef DEBUG
#include <iostream>

namespace dbg
{
inline void string(std::string text)
{
    std::cout << text << "\n";
}
inline void value(std::string text, float val)
{
    std::cout << text << ": " << val << "\n";
}
}
#endif //DEBUG
#endif //DEBUG_H

