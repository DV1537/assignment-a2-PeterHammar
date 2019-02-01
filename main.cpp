#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printType(Shape *shape);
void printPosition(Shape *shape);
void printArea(Shape *shape);
void printCircumference(Shape *shape);

int main()
{
    float p;
    int sizeOfArray = 1;
    float *array = new float[sizeOfArray];

    ifstream myReadFile;

    myReadFile.open("a2.txt");

    int count = 0;
    if (!myReadFile)
    {
        return EXIT_FAILURE;
    }
    else
    {
        while (myReadFile >> p)
        {
            // array size increases for every number that is read from file
            if (sizeOfArray <= count)
            {
                sizeOfArray += 1;
                float *oldArray = array;
                array = new float[sizeOfArray];
                for (int i = 0; i < count; i++)
                {
                    array[i] = oldArray[i];
                }
                delete[] oldArray;
            }
            array[count] = p;
            ++count;
        }

        if (count % 2 == 1)
        {
            cout << "File needs an even amount of numbers.\n";
            return EXIT_FAILURE;
        }
    }
    myReadFile.close();


    if (sizeOfArray == 2) // 1 coordinate
    {
        //Point
        Coordinates coordinates;

        coordinates.x = array[0];
        coordinates.y = array[1];

        Point point(coordinates);
        printType(&point);
        printPosition(&point);
        printArea(&point);
        printCircumference(&point);
    }
    else if (sizeOfArray == 4) // 2 coordinates
    {
        //Line
        Coordinates coordinatesL1, coordinatesL2;

        coordinatesL1.x = array[0];
        coordinatesL1.y = array[1];
        coordinatesL2.x = array[2];
        coordinatesL2.y = array[3];

        Line line(coordinatesL1, coordinatesL2);
        printType(&line);
        printPosition(&line);
        printArea(&line);
        printCircumference(&line);
    }
    else if (sizeOfArray == 6) // 3 coordinates
    {
        //Triangle
        Coordinates coordinatesT1, coordinatesT2, coordinatesT3;
        coordinatesT1.x = array[0];
        coordinatesT1.y = array[1];
        coordinatesT2.x = array[2];
        coordinatesT2.y = array[3];
        coordinatesT3.x = array[4];
        coordinatesT3.y = array[5];

        Triangle triangle(coordinatesT1, coordinatesT2, coordinatesT3);
        printType(&triangle);
        printPosition(&triangle);
        printArea(&triangle);
        printCircumference(&triangle);
    }
    else if (sizeOfArray > 6) // 4+ coordinates
    {
        //Polygon
        Coordinates *arrayPoly = new Coordinates[sizeOfArray/2];

        for (int i = 0; i < sizeOfArray; i += 2)
        {
            /**
             * arrayPoly[0].x = array[0]
             * arrayPoly[0].y = array[1]
             * 
             * arrayPoly[1].x = array[2]
             * arrayPoly[1].y = array[3]
             * 
             * arrayPoly[2].x = array[4]
             * arrayPoly[2].y = array[5]
             */
            arrayPoly[i/2].x = array[i];
            arrayPoly[i/2].y = array[i+1];

        }

        Polygon polygon(arrayPoly, sizeOfArray / 2);
        printType(&polygon);
        printPosition(&polygon);
        printArea(&polygon);
        printCircumference(&polygon);
    }
    return 0;
}

void printType(Shape *shape)
{
    std::cout << "Type is: " << shape->getType() << std::endl;
}
void printPosition(Shape *shape)
{
    Coordinates coordinates = shape->position();
    std::cout << "Center coordinates: (" << coordinates.x << ", " << coordinates.y << ")" << std::endl;
}

void printArea(Shape *shape)
{
    double area = shape->area();

    std::cout << "area is: " << area << std::endl;
}

void printCircumference(Shape *shape)
{
    double circumference = shape->circumference();

    std::cout << "circumference is: " << circumference << std::endl;
}