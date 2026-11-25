
#include <iostream>
#include "MyArray.h"

using namespace std;

int main() {

    MyArray A(3);
    MyArray B(3);

    A.set(0, 6);
    A.set(1, 8);
    A.set(2, 9);

    B.set(0, 3);
    B.set(1, 2);
    B.set(2, 4);

    cout << "A = ";
    A.display();

    cout << "B = ";
    B.display();

    MyArray C = A.merge(B);

    cout << "A merge B = ";
    C.display();

    MyArray D = A.add(B);

    cout << "A + B = ";
    D.display();

    MyArray E = A.subtract(B);

    cout << "A - B = ";
    E.display();

    MyArray F = A.multiply(B);

    cout << "A * B = ";
    F.display();

    MyArray G = A.divide(B);

    cout << "A / B = ";
    G.display();

    cout << "\n测试深拷贝：" << endl;

    MyArray H = A;

    H.set(0, 100);

    cout << "修改后的 H = ";
    H.display();

    cout << "原数组 A = ";
    A.display();

    cout << "\n测试数组长度不同：" << endl;

    MyArray X(3);
    MyArray Y(2);

    X.set(0, 1);
    X.set(1, 2);
    X.set(2, 3);

    Y.set(0, 4);
    Y.set(1, 5);

    cout << "C = ";
    X.display();

    cout << "D = ";
    Y.display();

    MyArray Z = X.add(Y);

    cout << "C + D = ";
    Z.display();

    cout << "\n测试除数为0：" << endl;

    MyArray P(3);
    MyArray Q(3);

    P.set(0, 8);
    P.set(1, 12);
    P.set(2, 16);

    Q.set(0, 2);
    Q.set(1, 0);
    Q.set(2, 4);

    MyArray R = P.divide(Q);

    cout << "P / Q = ";
    R.display();

    return 0;
}
