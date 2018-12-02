#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape
{
public:
    Polygon(Coordinates *arrayPoly, int sizeOfArray);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;
private:
    Coordinates *arrayPoly;
    int sizeOfArray;
};

#endif