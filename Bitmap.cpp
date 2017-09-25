#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;
using namespace caveofprogramming;

Bitmap::Bitmap(int width, int height): mWidth(width), mHeight(height), mPixels(new uint8_t[width * height * 3]{}) {
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t* color = mPixels.get();
    color += (y * 3) * mWidth + (x * 3);
    color[2] = red;
    color[1] = green;
    color[0] = blue;
}

bool Bitmap::writeFile(string fileName) {
    BitmapFileHeader header;
    BitmapInfoHeader info;
    
    header.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + mWidth * mHeight * 3;
    header.dataOffSet = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    
    info.width = mWidth;
    info.height = mHeight;
    
    ofstream file;
    file.open(fileName, ios::binary);
    
    if (!file) {
        return false;
    }
    
    file.write(reinterpret_cast<char*>(&header), sizeof(BitmapFileHeader));
    file.write(reinterpret_cast<char*>(&info), sizeof(BitmapInfoHeader));
    file.write(reinterpret_cast<char*>(mPixels.get()), mWidth * mHeight * 3);
    
    file.close();
    
    return true;
}

Bitmap::~Bitmap() {
}
