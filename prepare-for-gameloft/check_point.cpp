#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

double areaOfTriangle(Point a1, Point a2, Point a3)
{
    int first_edge = sqrt(pow(a2.x - a1.x, 2) + pow(a2.y - a1.y, 2));
    int second_edge = sqrt(pow(a2.x - a3.x, 2) + pow(a2.y - a3.y, 2));
    int third_edge = sqrt(pow(a3.x - a1.x, 2) + pow(a3.y - a1.y, 2));
    int p = (first_edge + second_edge + third_edge) / 2;
    return sqrt(p * (p - first_edge) * (p - second_edge) * (p - third_edge));
}

//This function is used for get two another point from two point oposite.
void otherPointOfSquare(Point p1, Point p2)
{
    if (p1.x == p2.x || p1.y == p2.y)
    {
        cout << "Cannot" << endl;
        return;
    }
    cout << p1.x << " - " << p2.y << endl;
    cout << p2.x << " - " << p1.y << endl;
    return;
}

int main()
{
    Point x1{0, 0};
    Point x2{0, 4};
    Point x3{4, 0};

    otherPointOfSquare(x1, y);
}