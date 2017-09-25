#include "RGB.h"

namespace caveofprogramming {

    RGB operator-(const RGB& first, const RGB& second) {
        return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
    }

    RGB operator+(const RGB& first, const RGB& second) {
        return RGB(first.r + second.r, first.g + second.g, first.b + second.b);
    }

}