//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.

#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

struct Point {
    float x = 0;
    float y = 0;
    float z = 0;
    float get_len() {
        return std::sqrt(x*x + y*y + z*z);
    }
};
Point operator-(const Point& lhs, const Point& rhs) {
    return Point{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}


int main() {
    int N = 0;
    cin >> N;
    std::vector<Point> points(N);
    for(auto& p : points)
        cin >> p.x >> p.y >> p.z;
    float need_dist = 0;
    cin >> need_dist;

    int answ = -1;
    float current_dist = 0;
    for(int i = 1; i < N; i++) {
        current_dist += (points[i] - points[i-1]).get_len();
        if(current_dist >= need_dist) {
            answ = i;
            break;
        }
    }

    cout << answ << endl;

    return 0;
}