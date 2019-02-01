#include "Point.h"

std::string Point::getType()
{
    return "Point";
}

double Point::area()
{
    return -1;
}

double Point::circumference()
{
    return 0;
}

Coordinates Point::position() 
{
    return coordinates;
}
Point::Point(Coordinates c)
{
    coordinates = c;
}

bool Point::isConvex()
{
    return false;
}

double Point::distance(Shape *s)
{
    // pythagoras
    double xDistance = s->position().x - this->position().x;
    double yDistance = s->position().y - this->position().y;
    return sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
}