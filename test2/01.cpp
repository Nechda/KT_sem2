//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <cmath>

using namespace std;

class Point {
    protected:
    double _x;
    double _y;
    double _z;
    public:
    Point(double x, double y, double z): _x(x), _y(y), _z(z) {
    }

    double x() const {
        return _x;
    }
    double y() const {
        return _y;
    }
    double z() const {
        return _z;
    }
};

class Sphere {
  public:
    Sphere(const Point& center, double r) : _center(center), _r(r) {}

    // Проверка, попадает ли заданная точка p в данную сферу.
    // (Расстояния сравнивать с точностью 1e-6.)
    bool covers(const Point& p) const {
        auto dx = p.x() - _center.x();
        auto dy = p.y() - _center.y();
        auto dz = p.z() - _center.z();
        auto len = std::sqrt(dx * dx + dy * dy + dz * dz);
        const double EPS = 1e-6;
        return _r + EPS > len;
    }
  private:
    Point _center;
    float _r;
};


int main() {
    Point center(10.0, 10.0, 10.0);
    Sphere s(center, 0.5);
    Point p1(10.1, 10.1, 10.1);
    Point p2(2, 2, 2);
    cout << boolalpha << s.covers(p1) << endl;
    cout << boolalpha << s.covers(p2) << endl;
    return 0;
}