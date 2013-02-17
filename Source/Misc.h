#ifndef MISC_H
#define MISC_H

namespace MathFunc
{

inline int roundFtoI(float f)
{
    return static_cast<int>(f + (f > 0.0 ? + 0.5 : -0.5));
}

}

#endif //MISC_H
