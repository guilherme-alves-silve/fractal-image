/* 
 * File:   BitmapHeaderFile.h
 * Author: Guilherme Alves Silveira
 *
 * Created on March 28, 2017, 12:33 PM
 */

#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

namespace caveofprogramming {

#include <cstdint>

    using namespace std;

#pragma pack(2)

    struct BitmapInfoHeader {
        int32_t headerSize{40};
        int32_t width;
        int32_t height;
        int16_t planes{1};
        int16_t bitsPerPixel{24};
        int32_t compression{0};
        int32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};
    };

}

#endif /* BITMAPINFOHEADER_H */
