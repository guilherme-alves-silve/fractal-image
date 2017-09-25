/* 
 * File:   FractalCreator.cpp
 * Author: Guilherme Alves Silveira
 * 
 * Created on March 31, 2017, 10:19 AM
 */

#include "FractalCreator.h"

namespace caveofprogramming {

    void FractalCreator::calculateIteration() {
        for (int x = 0; x < mWidth; x++) {
            for (int y = 0; y < mHeight; y++) {
                pair<double, double> coordinates = mZoomList.doZoom(x, y);
                int iterations = Mandelbrot::getIterations(coordinates.first, coordinates.second);
                mFractal[y * mWidth + x] = iterations;
                mHistogram[iterations]++;
            }
        }
    }

    void FractalCreator::calculateTotalIterations() {
        int total = 0;
        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
            total += mHistogram[i];
        }

        this->mTotal = total;
    }
    
    void FractalCreator::addRanges(double range, const RGB& color) {
    
    }

    FractalCreator& FractalCreator::drawFactal() {

        calculateIteration();
        calculateTotalIterations();

        RGB startColor(0, 20, 0);
        RGB endColor(255, 0, 255);
        RGB diffColor = endColor - startColor;
        
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        double hue;

        for (int x = 0; x < mWidth; x++) {
            for (int y = 0; y < mHeight; y++) {

                red = 0;
                green = 0;
                blue = 0;

                int iterations = mFractal[y * mWidth + x];
                if (iterations != Mandelbrot::MAX_ITERATIONS) {
                    hue = 0.0;
                    for (int i = 0; i < iterations; i++) {
                        hue += ((double) mHistogram[i]) / mTotal;
                    }

                    red = startColor.r + diffColor.r * hue;
                    green = startColor.g + diffColor.g * hue;
                    blue = startColor.b + diffColor.b * hue;
                }

                mBitmap.setPixel(x, y, red, green, blue);
            }
        }

        return *this;
    }

    FractalCreator& FractalCreator::addZoom(const Zoom& zoom) {
        mZoomList.add(zoom);
        return *this;
    }

    FractalCreator& FractalCreator::writeBitmap(string fileName) {
        mBitmap.writeFile(fileName);
        return *this;
    }
}