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

}