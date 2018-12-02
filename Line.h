#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    Line(Coordinates coordinatesL1, Coordinates coordinatesL2);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;
private:
    Coordinates coordinatesL1;
    Coordinates coordinatesL2;
};

#endif