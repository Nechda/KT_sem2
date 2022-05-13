//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <exception>

using namespace std;


class GasStation {
public:
    GasStation(unsigned capacity = 0) : cap_(capacity) {}
    // Конструктор, принимающий один параметр - ёмкость резервуара колонки
    // Резервуар создаётся пустой
    // Залить в резервуар колонки n литров топлива
    // Если столько не влезает в резервуар - не заливать ничего, выбросить std::exception
    void fill(unsigned n) {
        if(cur_ + n > cap_) {
            throw std::runtime_error("Too much");
        }
        cur_ += n;
    }
    // Заправиться, забрав при этом из резервура n литров топлива
    // Если столько нет в резервуаре - не забирать из резервуара ничего, выбросить
    void tank(unsigned n) {
        if(n > cur_) {
            throw std::runtime_error("Not enough");
        }
        cur_ -= n;
    }
    // Запросить остаток топлива в резервуаре
    unsigned get_limit() const {
        return cur_;
    }
  private:
    unsigned cap_;
    unsigned cur_ = 0;
};


int main() {
    GasStation s = GasStation(1000); // Колонка на 1000, пока пустая
    s.fill(300); // Это влезет в резервуар,
    cout << s.get_limit() << endl; // ... так что здесь увидим на экране 300.
    s.tank(100); // Забрали из резервуара 100,
    s.fill(300); // ... после чего долили ещё 300,
    cout << s.get_limit() << endl; // ... так что на экране ожидаем 500.
    for(unsigned int i = 0; i < 5; i++) // В цикле забрали 5 раз по 50,
    s.tank(50);
    cout << s.get_limit() << endl; // ... так что на экране ожидаем 250.

    try {
        s.fill(1000); // А вот тут ожидаем exception.
    } catch (std::exception& e) {
        cout << e.what() << endl;
    }

    // (После проверки exception-а строку стоит просто убрать.)
    for(unsigned int i = 0; i < 50; i++) { // Теперь пытаемся забрать 50 раз по 100,
        try{
            s.tank(100); // из-за чего на третьей попытке ждём exception.
        } catch (std::exception& e) {
            if(i == 2) {
                cout << e.what() << endl;
            }
        }
        cout << s.get_limit() << endl;
    }

    return 0;
}