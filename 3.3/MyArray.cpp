
#include <iostream>
#include "MyArray.h"

using namespace std;

MyArray::MyArray() {
    p = nullptr;
    N = 0;
}

MyArray::MyArray(int n, int value) {
    if (n <= 0) {
        p = nullptr;
        N = 0;
        return;
    }

    N = n;
    p = new int[N];

    for (int i = 0; i < N; i++) {
        p[i] = value;
    }
}

MyArray::MyArray(const MyArray& other) {
    N = other.N;

    if (N > 0) {
        p = new int[N];

        for (int i = 0; i < N; i++) {
            p[i] = other.p[i];
        }
    }
    else {
        p = nullptr;
    }
}

MyArray& MyArray::operator=(const MyArray& other) {
    if (this == &other)
        return *this;

    int* newP = nullptr;

    if (other.N > 0) {
        newP = new int[other.N];

        for (int i = 0; i < other.N; i++) {
            newP[i] = other.p[i];
        }
    }

    delete[] p;

    p = newP;
    N = other.N;

    return *this;
}

MyArray::~MyArray() {
    delete[] p;
    p = nullptr;
    N = 0;
}

int MyArray::size() const {
    return N;
}

int MyArray::get(int index) const {
    if (index < 0 || index >= N) {
        cout << "Error: index out of range!" << endl;
        return 0;
    }

    return p[index];
}

void MyArray::set(int index, int value) {
    if (index < 0 || index >= N) {
        cout << "Error: index out of range!" << endl;
        return;
    }

    p[index] = value;
}

void MyArray::display() const {
    cout << "{";

    for (int i = 0; i < N; i++) {
        cout << p[i];

        if (i != N - 1)
            cout << ", ";
    }

    cout << "}" << endl;
}

MyArray MyArray::merge(const MyArray& other) const {
    MyArray result(N + other.N);

    for (int i = 0; i < N; i++) {
        result.p[i] = p[i];
    }

    for (int i = 0; i < other.N; i++) {
        result.p[N + i] = other.p[i];
    }

    return result;
}

MyArray MyArray::add(const MyArray& other) const {
    int len = (N < other.N) ? N : other.N;

    if (N != other.N)
        cout << "Warning: different sizes ("
        << N << " vs " << other.N
        << "), use the shorter one" << endl;

    MyArray result(len);

    for (int i = 0; i < len; i++) {
        result.p[i] = p[i] + other.p[i];
    }

    return result;
}

MyArray MyArray::subtract(const MyArray& other) const {
    int len = (N < other.N) ? N : other.N;

    if (N != other.N)
        cout << "Warning: different sizes ("
        << N << " vs " << other.N
        << "), use the shorter one" << endl;

    MyArray result(len);

    for (int i = 0; i < len; i++) {
        result.p[i] = p[i] - other.p[i];
    }

    return result;
}

MyArray MyArray::multiply(const MyArray& other) const {
    int len = (N < other.N) ? N : other.N;

    if (N != other.N)
        cout << "Warning: different sizes ("
        << N << " vs " << other.N
        << "), use the shorter one" << endl;

    MyArray result(len);

    for (int i = 0; i < len; i++) {
        result.p[i] = p[i] * other.p[i];
    }

    return result;
}

MyArray MyArray::divide(const MyArray& other) const {
    int len = (N < other.N) ? N : other.N;

    if (N != other.N)
        cout << "Warning: different sizes ("
        << N << " vs " << other.N
        << "), use the shorter one" << endl;

    MyArray result(len);

    for (int i = 0; i < len; i++) {
        if (other.p[i] == 0) {
            cout << "Warning: division by zero at index "
                << i << endl;

            result.p[i] = 0;
        }
        else {
            result.p[i] = p[i] / other.p[i];
        }
    }

    return result;
}
