//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.

#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;


class Point2D {
    protected:
        double _x;
        double _y;
    public:
        Point2D(double x, double y) : _x(x), _y(y) {}
        double x() const {return _x;}
        double y() const {return _y;}
};

Point2D operator-(Point2D a, Point2D b) {
    return Point2D(a.x() - b.x(), a.y() - b.y());
}

double cross_product(Point2D a, Point2D b) {
    return a.x() * b.y() - a.y() * b.x();
}

class Polygone {
    public:
        Polygone(const std::vector<Point2D>& points) : vertices(points) {}

        double area() const {
            double res = 0;
            const int N = vertices.size();
            for(int i = 1; i < N - 1; i++) {
                res += cross_product(vertices[i] - vertices[0], vertices[i+1] - vertices[0]);
            }
            return std::abs(res) / 2.0;
        }

        unsigned int size() const {return vertices.size();}

        Point2D vertex(unsigned int N) const {
            auto sz = vertices.size();
            return vertices[N % sz];
        }
    protected:
        std::vector<Point2D> vertices;
};


int main()
{
    std::vector<Point2D> points = {{-1.0, -1.0}, {-1.0, 1.0},
    {1.0, 1.0}, {1.0, -1.0}};
    Polygone p(points);
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.size(); i++) {
        cout << p.vertex(i).x() << " " << p.vertex(i).y() <<
        endl;
    }
    cout.precision(2);
    cout << std::fixed;
    cout << "Area: " << p.area() << endl;
    return 0;
}