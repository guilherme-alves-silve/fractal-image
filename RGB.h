/* 
 * File:   RGB.h
 * Author: Guilherme Alves Silveira
 *
 * Created on March 31, 2017, 12:10 PM
 */

#ifndef RGB_H
#define RGB_H

namespace caveofprogramming {

    struct RGB {
        double r;
        double g;
        double b;

        RGB(double r, double g, double b) : r(r), g(g), b(b) {
        }
    };

    RGB operator-(const RGB& first, const RGB& second);
    
    RGB operator+(const RGB& first, const RGB& second);
}


#endif /* RGB_H */

