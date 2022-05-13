//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

class MoneyBox {
  public:
    // Конструктор и деструктор, если нужны
    // Добавить монетку достоинством value
    void addCoin(unsigned value) {
        table[value]++;
    }
    // Получить текущее количество монеток в копилке
    unsigned int getCoinsNumber() const {
        unsigned ret = 0;
        for(const auto& record : table) {
            ret += record.second;
        }
        return ret;
    }
    // Получить текущее общее достоинство всех монеток
    unsigned int getCoinsValue() const {
        unsigned ret = 0;
        for(const auto& record : table) {
            ret += record.first * record.second;
        }
        return ret;
    }
  private:
    // first -- value, second -- count
    std::map<unsigned, int> table;
};

int main() {
    MoneyBox m;
    // Добавили монетку достоинством 10
    m.addCoin(10);
    // Добавили монетку достоинством 5
    m.addCoin(5);
    // Ожидаем, что монеток внутри 2 штуки
    cout << m.getCoinsNumber() << endl;
    // Ожидаем, что общее достоинство всех монеток 15
    cout << m.getCoinsValue() << endl;
    return 0;
}