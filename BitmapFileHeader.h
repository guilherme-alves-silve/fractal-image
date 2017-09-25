/* 
 * File:   BitmapHeaderFile.h
 * Author: Guilherme Alves Silveira
 *
 * Created on March 28, 2017, 12:33 PM
 */

#ifndef BITMAPHEADERFILE_H
#define BITMAPHEADERFILE_H

#include <cstdint>

using namespace std;

namespace caveofprogramming {

#pragma pack(2)

    struct BitmapFileHeader {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffSet;
    };

}

#endif /* BITMAPHEADERFILE_H */

