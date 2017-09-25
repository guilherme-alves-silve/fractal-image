/* 
 * File:   Bitmap.h
 * Author: Guilherme Alves Silveira
 *
 * Created on March 28, 2017, 12:51 PM
 */

#ifndef BITMAP_H
#define BITMAP_H

#include <cstdint>
#include <memory>
#include <string>

using namespace std;

namespace caveofprogramming {

    class Bitmap {
    private:
        int mWidth{0};
        int mHeight{0};
        unique_ptr<uint8_t[]> mPixels{nullptr};
    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool writeFile(string fileName);
        virtual ~Bitmap();
    };

}

#endif /* BITMAP_H */

