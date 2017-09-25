/* 
 * File:   FractalCreator.h
 * Author: Guilherme Alves Silveira
 *
 * Created on March 31, 2017, 10:19 AM
 */

#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <memory>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace caveofprogramming {

    class FractalCreator {
    private:
        int mWidth;
        int mHeight;
        int mTotal;
        Bitmap mBitmap;
        ZoomList mZoomList;
        unique_ptr <int[] > mHistogram;
        unique_ptr <int[] > mFractal;
        vector<double> mRanges;
        vector<RGB> mColors;
        bool mGotFirstRange{false};
    public:
        FractalCreator(int width, int height) : 
            mWidth(width), 
            mHeight(height),
            mBitmap {width, height},
            mZoomList {width, height}, 
            mHistogram(new int[Mandelbrot::MAX_ITERATIONS] {0}),
            mFractal(new int[width * height] {0}) {
            mZoomList.add(Zoom(mWidth / 2, mHeight / 2, 4.0 / mWidth));
        }
    public:
        FractalCreator& addRanges(double range, RGB color);
        FractalCreator& drawFactal();
        FractalCreator& addZoom(const Zoom& zoom);
        FractalCreator& writeBitmap(string fileName);
    private:
        void calculateIteration();
        void calculateTotalIterations();
    };

}

#endif /* FRACTALCREATOR_H */

