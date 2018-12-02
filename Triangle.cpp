#include "Triangle.h"

std::string Triangle::getType()
{   
    return "Triangle";
}
double Triangle::area()
{
    return ((coordinatesT2.x - coordinatesT1.x)*(coordinatesT3.y - coordinatesT1.y))/2; //(b*h)/2
}

double Triangle::circumference()
{
    //(x1-x0)+(y1-y0) etc
    double line1 = sqrt(pow((coordinatesT2.x-coordinatesT1.x), 2.0)
                +pow((coordinatesT2.y-coordinatesT1.y), 2.0));

    double line2 = sqrt(pow((coordinatesT3.x-coordinatesT2.x), 2.0)
                +pow((coordinatesT3.y-coordinatesT2.y), 2.0));

    double line3 = sqrt(pow((coordinatesT1.x-coordinatesT3.x), 2.0)
                +pow((coordinatesT1.y-coordinatesT3.y), 2.0));

    return line1+line2+line3;

}

Coordinates Triangle::position() 
{
    Coordinates coordinates;
    //sum of coordinates divided by amount of coordinates
    coordinates.x = (coordinatesT1.x + coordinatesT2.x + coordinatesT3.x)/3;
    coordinates.y = (coordinatesT1.y + coordinatesT2.y + coordinatesT3.y)/3;
    return coordinates;
}

Triangle::Triangle(Coordinates cT1, Coordinates cT2, Coordinates cT3)
{
    coordinatesT1 = cT1;
    coordinatesT2 = cT2;
    coordinatesT3 = cT3;
}

bool Triangle::isConvex()
{
    return false;
}

double Triangle::distance(Shape *s)
{

}