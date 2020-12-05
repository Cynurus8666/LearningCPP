/*
Code này được dùng để thử với các điểm tạo nên một hình trong không gian Oxy 
*/
#include <iostream>
#include <math.h>
using namespace std;

//Định nghĩa đối tượng tọa độ trong không gian Oxy
struct Point
{
    //Tọa độ trên trục Ox
    int x;
    //Tọa độ trên trục Oy
    int y;
};

/*
 * Description: Hàm tính diện tích của hình tam giác bằng công thức Huron
 * Param: Tọa độ 3 đỉnh của tam giác trong mặt phẳng Oxy
 * Return: 
 *          -1 nếu 3 điểm đưa vào không tạo thành tam giác
 *          Diện tích tam giác tạo ra từ 3 đỉnh nếu có 
 */
double areaOfTriangle(Point a1, Point a2, Point a3)
{
    /*
    * Công thức huron: diện tích tam giác = sqrt(nua_chu_vi*(nua_chu_vi - canh_1)*(nua_chu_vi - canh_2)*(nua_chu_vi - canh_3))
    */

    // Kiểm tra 3 điểm đưa vào có phải thể tạo ra một tam giác không bằng yêu cầu: 3 điểm không nằm trên cùng một tọa độ x hoặc y.

    if ((a1.x == a2.x && a1.x == a3.x) || (a1.y == a2.y && a1.y == a3.y))
    {
        return -1;
    }
    else
    {

        //Tính toán độ dài 3 cạnh tạo bởi 3 đỉnh
        int first_edge = sqrt(pow(a2.x - a1.x, 2) + pow(a2.y - a1.y, 2));
        int second_edge = sqrt(pow(a2.x - a3.x, 2) + pow(a2.y - a3.y, 2));
        int third_edge = sqrt(pow(a3.x - a1.x, 2) + pow(a3.y - a1.y, 2));

        //Tính toán nữa chu vi dùng cho công thức heron
        int p = (first_edge + second_edge + third_edge) / 2;

        //Trả về diện tích theo công thức heron
        return sqrt(p * (p - first_edge) * (p - second_edge) * (p - third_edge));
    }
}

/**
 * Description: Hàm in ra giá trị 2 đỉnh còn lại của một tứ giác vuông khi đưa vào 2 đỉnh đối
 * Param: 2 đỉnh đối nhau của một hình vuông
 * Return:
 *          Trả về  0 nếu không thể tạo thành tứ giác vuông
 *          In ra tọa độ 2 đỉnh còn lại và trả về 1 nếu thành công
 */
int otherPointOfSquare(Point p1, Point p2)
{
    // Nếu 2 đỉnh nằm trên cùng tọa độ x hoặc y thì sẽ không thể là 2 đỉnh đối của một hình tứ giác vuông
    if (p1.x == p2.x || p1.y == p2.y)
    {
        return 0;
    }
    cout << p1.x << " - " << p2.y << endl;
    cout << p2.x << " - " << p1.y << endl;
    return 1;
}

int main()
{
    Point x1{0, 0};
    Point x2{0, 4};
    Point x3{4, 0};
}