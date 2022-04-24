//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;

template <typename T>
T get_min_value(T a, T b) {
    return a < b ? a : b;
}

int main() {
    int a = 5;
    int b = 4;
    string s1 = "abc";
    string s2 = "zxc";
    cout << "Min int: " << get_min_value(a, b) << endl;
    cout << "Min string: " << get_min_value(s1, s2) << endl;
    return 0;
}