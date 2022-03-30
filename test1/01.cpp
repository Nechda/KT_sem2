//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

struct Force {
    float x = 0;
    float y = 0;
};
Force operator+(const Force& lhs, const Force& rhs) {
    return Force{lhs.x + rhs.x, lhs.y + rhs.y};
}

int main() {
    int N = 0;
    cin >> N;
    Force res;
    while(N--) {
        Force t;
        float len = 0;
        cin >> t.x >> t.y >> len;
        len /= std::sqrt(t.x * t.x + t.y * t.y);
        t.x *= len;
        t.y *= len;
        res = res + t;
    }

    cout.precision(4);
    cout << std::fixed << res.x << " " << res.y << endl;
    return 0;
}