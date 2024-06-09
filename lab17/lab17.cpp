#include <iostream>
#include <string.h>
#include "windows.h"

using namespace std;

class ColorPoint {
private:
    int x;
    int y;
    int red;
    int green;
    int blue;

public:
    ColorPoint() : x(0), y(0), red(0), green(0), blue(0) {}

    ColorPoint(int x, int y, int red, int green, int blue) {
        setCoordinates(x, y);
        setColor(red, green, blue);
    }

    void setCoordinates(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setColor(int red, int green, int blue) {
        if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
            cerr << "Error: Invalid color components. Each component should be in the range [0, 255]." << endl;
            exit(1);
        }
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    void getCoordinates(int& x, int& y) const {
        x = this->x;
        y = this->y;
    }

    void getColor(int& red, int& green, int& blue) const {
        red = this->red;
        green = this->green;
        blue = this->blue;
    }

    void print() const {
        cout << "Point coordinates: (" << x << ", " << y << "), Color: RGB(" << red << ", " << green << ", " << blue << ")" << endl;
    }
};

class Line : public ColorPoint {
private:
    int endX;
    int endY;

public:
    Line() : ColorPoint(), endX(0), endY(0) {}

    Line(int startX, int startY, int endX, int endY, int red, int green, int blue) : ColorPoint(startX, startY, red, green, blue) {
        setEndCoordinates(endX, endY);
    }

    void setEndCoordinates(int endX, int endY) {
        this->endX = endX;
        this->endY = endY;
    }

    void getEndCoordinates(int& endX, int& endY) const {
        endX = this->endX;
        endY = this->endY;
    }

    void print() const {
        int startX, startY, endX, endY, red, green, blue;
        getColor(red, green, blue);
        getCoordinates(startX, startY);
        getEndCoordinates(endX, endY);
        cout << "Line coordinates: (" << startX << ", " << startY << ") to (" << endX << ", " << endY << "), Color: RGB(" << red << ", " << green << ", " << blue << ")" << endl;
    }
};

int main() {
    ColorPoint point1(1, 2, 100, 150, 200);
    point1.print();

    Line line1(3, 4, 7, 9, 255, 0, 0);
    line1.print();

    return 0;
}


