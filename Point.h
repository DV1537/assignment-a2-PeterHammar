#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point : public Shape
{
public:
    Point(Coordinates coordinates);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;
private:
    Coordinates coordinates;
};

#endif
