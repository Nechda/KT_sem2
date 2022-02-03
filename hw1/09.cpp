//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
using namespace std;

struct Vector {
    int x,y,z;
};

Vector sum(Vector a, Vector b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

const int N = 3;
int main()
{
    Vector res = {0, 0, 0};
    for (int i = 0; i < N; i++)
    {
        Vector tmp;
        cin >> tmp.x >> tmp.y >> tmp.z;
        res = sum(res, tmp);
    }
    cout << res.x << " " << res.y << " " << res.z << endl;
    return 0;
}