#include <iostream>

#include "FractalCreator.h"
#include "RGB.h"

using namespace std;
using namespace caveofprogramming;

int main() {

    cout << "Executing..." << endl;

    const int WIDTH = 800;
    const int HEIGHT = 600;
    
    FractalCreator fractal(WIDTH, HEIGHT);
    fractal.addZoom(Zoom(295, 202, 0.1));
    fractal.addZoom(Zoom(312, 304, 0.1));
    fractal.drawFactal();
    fractal.writeBitmap("fractal.bmp");

    cout << "Finished" << endl;

    return 0;
}