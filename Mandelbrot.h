/* 
 * File:   Mandelbrot.h
 * Author: Guilherme Alves Silveira
 *
 * Created on March 30, 2017, 12:29 PM
 */

#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace caveofprogramming {

    class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 1000;
        static int getIterations(double x, double y);
    };
}

#endif

