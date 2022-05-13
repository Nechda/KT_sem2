//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <exception>

class Ball {
  public:
    // Конструктор и деструктор шара, если нужны
    // Попытка сломать шар.
    // Для первого целого шара должна заканчиваться успешно.
    // Если один шар уже был сломан, выбросить std::exception
    // Если пытаемся ломать уже сломанный или потерянный шар, выбросить std::exception
    void destroy() {
        bool is_valid = !is_destr && !is_lose && n_destroy == 0;
        if(!is_valid) {
            throw std::runtime_error("something wrong...");
        }
        n_destroy++;
        is_destr = true;
    }
    // Попытка потерять шар.
    // Для первого целого шара должна заканчиваться успешно.
    // Если один шар уже был потерян, то выбросить std::exception
    // Если пытаемся терять уже сломанный или потерянный шар, выбросить std::exception
    void lose() {
        bool is_valid = !is_destr && !is_lose && n_lose == 0;
        if(!is_valid) {
            throw std::runtime_error("something wrong...");
        }
        n_lose++;
        is_lose = true;
    }

  private:
    static int n_lose;
    static int n_destroy;

    bool is_destr = false;
    bool is_lose = false;
};

int Ball::n_destroy = 0;
int Ball::n_lose = 0;


int main() {
    // какой-то тест
    return 0;
}