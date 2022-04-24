//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;

template<typename T>
bool check_them(T& x, T& y, T& z) {
    // это просто заглушка
    return x == y && y == z;
}

struct student {
    std::string name;
    std::string id_number_string;
    bool operator==(const student& rhs) const {
        const auto& lhs = *this;
        return lhs.id_number_string == rhs.id_number_string;
    }
};

int main()
{
    student a = {"Andy", "1234 123123"};
    student b = {"Andrew", "1234 123123"};
    student c = {"Andy", "1234123123"};
    cout << boolalpha << "Check result is: " << check_them(a, b, c) << endl;
    return 0;
}