#pragma once

#include <string>
#include <cmath>

class Equation {
private:
    double a,b,c;
public:
    Equation(double a,double b, double c) : a(a), b(b), c(c){}
    ~Equation() = default;

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    double getDiscriminant()const {
        return b*b - 4 * a * c;
    }
    std::string toString() {
        std::string result;
        if (a != 0) {
            result += std::to_string(a) + "X^2";
        }
        if (b != 0) {
            result += (b > 0 ? "+" : "") + std::to_string(b) + "X";
        }
        if (c != 0) {
            result += (c > 0 ? "+" : "") + std::to_string(c);
        }
        return result;
    }

    void setA(double newA) { a = newA; }
    void setB(double newB) { b = newB; }
    void setC(double newC) { c = newC; }

    std::string solve() {
        double d = getDiscriminant();
        if (d < 0) {
            return "x1 = " + std::to_string(-b / (2 * a)) + " + " +
                   std::to_string(sqrt(-d) / (2 * a)) +
                   "i, x2 = " + std::to_string(-b / (2 * a)) + " - " +
                   std::to_string(sqrt(-d) / (2 * a)) + "i";
        } else if (d == 0) {
            return "x = " + std::to_string(-b / (2 * a));
        } else {
            return "x1 = " + std::to_string((-b + sqrt(d)) / (2 * a)) +
                   ", x2 = " + std::to_string((-b - sqrt(d)) / (2 * a));
        }
    }

    bool hadRealRoot() const {
        return getDiscriminant() >= 0;
    }
};