#include <iostream>
#include <cmath>
using namespace std;
#include "Polygon.h"

std::string Polygon::getType()
{
    return "Polygon";
}

double Polygon::area()
{
    //koordinatareaformeln,
    //A = 1/2*abs((SUM(x[i] * (y[i-1]-y[i+1])))
    double polyArea = 0;
    for (int i = 1; i < sizeOfArray - 1; i++)
    {
        polyArea += arrayPoly[i].x * (arrayPoly[i + 1].y - arrayPoly[i - 1].y);
    }
    polyArea += arrayPoly[0].x * (arrayPoly[1].y - arrayPoly[sizeOfArray - 1].y);
    polyArea += arrayPoly[sizeOfArray-1].x*(arrayPoly[0].y-arrayPoly[sizeOfArray-2].y);
    //absolute value
    if (polyArea < 0)
    {
        polyArea *= -1;
    }

    return polyArea/2;
}

double Polygon::circumference()
{
    double circumferencePoly = 0;
    //sqrt(x1-x0)^2 + (y1-y0)^2 osv
    for(int i = 0; i < sizeOfArray-1; i++)
    {
        circumferencePoly += sqrt(pow((arrayPoly[i+1].x-arrayPoly[i].x), 2.0)+pow((arrayPoly[i+1].y-arrayPoly[i].y), 2.0));
    }
 
    circumferencePoly += sqrt(pow((arrayPoly[0].x-arrayPoly[sizeOfArray-1].x), 2.0)
                            +pow((arrayPoly[0].y-arrayPoly[sizeOfArray-1].y), 2.0));

    return circumferencePoly;
}

Coordinates Polygon::position()
{

    Coordinates coordinates;
    int sumX = 0;
    int sumY = 0;
    for (int i = 0; i < sizeOfArray; i++)
    {
        sumX += arrayPoly[i].x; // 
        sumY += arrayPoly[i].y; //
    }
    double avgX = static_cast<double>(sumX) / (sizeOfArray);
    double avgY = static_cast<double>(sumY) / (sizeOfArray);
    coordinates.x = avgX;
    coordinates.y = avgY;

    return coordinates;
}

Polygon::Polygon(Coordinates *array, int size)
{
    arrayPoly = array;
    sizeOfArray = size;
}

bool Polygon::isConvex()
{
    // convex if any inner angle is greater than 180.
    // loop over coordinates
    // create lines:
    // line1 = first coordinate -> second coordinate
    // line2 = second coordinate -> third coordinate
    // calculate scalar product(line1, line2) / (length(line1)*length(line2)) -> scalarProd
    // angle = arccos(scalarProd)
    // if angle > 180, stop loop and return false,
    // otherwise continue to next pair (second->third and third->fourth ...)
    // return true if no angle is bigger than 180
    // ...
    // >:(

    return false;
}

double Polygon::distance(Shape *s)
{
}