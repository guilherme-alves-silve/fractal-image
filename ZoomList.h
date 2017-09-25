/* 
 * File:   ZoomList.h
 * Author: Guilherme Alves Silveira
 *
 * Created on March 30, 2017, 6:04 PM
 */

#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include "Zoom.h"

using namespace std;

namespace caveofprogramming {

    class ZoomList {
    private:
        int mWidth{0};
        int mHeight{0};
        double mXCenter{0};
        double mYCenter{0};
        double mScale{1.0};
        vector<Zoom> zooms;
    public:
        ZoomList(int width, int height);
        void add(const Zoom& zoom);
        pair<double, double> doZoom(int x, int y);
    };

}

#endif /* ZOOMLIST_H */
