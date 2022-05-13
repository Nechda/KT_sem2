//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <cctype> // для std::tolower
#include <algorithm> // для сортировки
#include <tuple> // для того, чтобы не писать самому сравнение пар
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

std::string make_lower(const std::string& str) {
    std::string ret(str);
    for(auto &it : ret) {
        it = std::tolower(it);
    }
    return ret;
}

int main() {
    int N = 0;
    cin >> N;

    // будем хранить множества всех разных написаний строк
    // причем для ключа в таблице будем использовать саму
    // строку, но в нижнем регистре
    std::map<string, std::set<string>> table;
    for(int i = 0; i < N; i++) {
        std::string s;
        cin >> s;
        table[make_lower(s)].insert(s);
    }


    // теперь найдем все слова, котоые имеют более 2х вариантов написания
    // хранить будем теперь не только строку, но и число её написаний
    // дальше мы будем производить сортировку
    std::vector<std::pair<std::string, unsigned>> saved;
    for(const auto &record : table) {
        if(record.second.size() > 2) {
            saved.push_back({record.first, record.second.size()});
        }
    }
    // теперь у нас есть вектор из пар, первый аргумент пары -- строка в нижнем
    // регистре, а второй аргумент пары -- число различных написаний

    // теперь отсортируем массив, а в качестве функции сравнения передадим лямбду
    
    // для того, чтобы не писать длинный тип введем обозначение
    using pp = std::pair<std::string, unsigned>;
    std::sort(saved.begin(), saved.end(), [&](pp& a, pp& b) {
        int a_s = -(int)a.second;
        int b_s = -(int)b.second;
        return std::tie(a_s, a.first) < std::tie(b_s, b.first);
        // это сравнение эквивалентно следующему коду:
        /*
            if(a.second > b.second) return true;
            return a.second == b.second ? (a.first < b.first) : false; 
        */
    }
    );

    // теперь просто выводим значение на экран
    for(const auto& record : saved) {
        std::cout << record.first << std::endl;
    }

    return 0;
}