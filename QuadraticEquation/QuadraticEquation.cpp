#include <iostream>

using namespace std;

class Equation {
public:
    // Виртуальная функция для нахождения корней уравнения
    virtual void CalculateRoots() = 0;
};

class LinearEquation : public Equation {
protected:
    double a, b; // Коэффициенты уравнения ax + b = 0

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void CalculateRoots() override {
        if (a == 0) {
            cout << "The equation is not linear" << endl;
        }
        else {
            double x = -b / a;
            cout << "Root of the equation: x = " << x << endl;
        }
    }
};

class QuadraticEquation : public Equation {
protected:
    double a, b, c; // Коэффициенты уравнения ax^2 + bx + c = 0

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void CalculateRoots() override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double sqrt_discriminant = 1;
            for (int i = 0; i < 10; ++i) { // Приближенное вычисление квадратного корня
                sqrt_discriminant = 0.5 * (sqrt_discriminant + discriminant / sqrt_discriminant);
            }

            double root1 = (-b + sqrt_discriminant) / (2 * a);
            double root2 = (-b - sqrt_discriminant) / (2 * a);
            cout << "Roots of the equation: x1 = " << root1 << ", x2 = " << root2 << endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "The equation has only one root: x = " << root << endl;
        }
        else {
            cout << "The equation ain't having rootz" << endl;
        }
    }
};

int main() {
    LinearEquation linear(2, 3);
    QuadraticEquation quadratic(1, -3, 2);

    cout << "Solving linear equation:" << endl;
    linear.CalculateRoots();

    cout << "\nSolving quadratic equation:" << endl;
    quadratic.CalculateRoots();

    return 0;
}