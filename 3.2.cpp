
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    Triangle(double a = 1, double b = 1, double c = 1) {
        Init(a, b, c);
    }

    void Init(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    bool isTriangle() {
        return a > 0 && b > 0 && c > 0 &&
            a + b > c &&
            a + c > b &&
            b + c > a;
    }

    double getSideA() { return a; }
    double getSideB() { return b; }
    double getSideC() { return c; }

    void setSideA(double x) {
        if (x > 0)
            a = x;
        else
            cout << "边长必须为正数！" << endl;
    }

    void setSideB(double x) {
        if (x > 0)
            b = x;
        else
            cout << "边长必须为正数！" << endl;
    }

    void setSideC(double x) {
        if (x > 0)
            c = x;
        else
            cout << "边长必须为正数！" << endl;
    }

    double perimeter() {
        if (!isTriangle())
            return 0;

        return a + b + c;
    }

    double area() {
        if (!isTriangle())
            return 0;

        double p = perimeter() / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c));
    }


    int typeTriangle() {
        if (!isTriangle())
            return 0;

        if (fabs(a - b) < 1e-6 &&
            fabs(b - c) < 1e-6)
            return 4;

        if (fabs(a - b) < 1e-6 ||
            fabs(a - c) < 1e-6 ||
            fabs(b - c) < 1e-6)
            return 5;

        double x = a, y = b, z = c;

        if (x > y) swap(x, y);
        if (y > z) swap(y, z);
        if (x > y) swap(x, y);

        double diff = x * x + y * y - z * z;

        if (fabs(diff) < 1e-6)
            return 1;
        else if (diff > 0)
            return 2;
        else
            return 3;
    }

    void display() {
        cout << fixed << setprecision(2);

        cout << "Sides: "
            << a << " " << b << " " << c << endl;

        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return;
        }

        cout << "Perimeter: " << perimeter() << endl;
        cout << "Area: " << area() << endl;

        int type = typeTriangle();

        if (type == 1)
            cout << "Type: 直角三角形" << endl;
        else if (type == 2)
            cout << "Type: 锐角三角形" << endl;
        else
            cout << "Type: 钝角三角形" << endl;
    }
};

int main() {
    double a, b, c;

    cout << "请输入三角形的三条边：";
    cin >> a >> b >> c;

    Triangle t(a, b, c);

    cout << "\n输出：" << endl;
    t.display();

    return 0;
}
