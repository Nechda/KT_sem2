//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

// коды для операций
#define SET 1
#define DEL 2

// порядок полей в структуре важен!!!
struct Event {
    int time;
    int type;
    string name;
    string value;
    int id;
};

int main() {
    int n;
    cin >> n;

    // сначала посто считываем все операции в вектор
    vector<Event> saved_events;
    while(n--) {
        Event ev;
        string tmp;
        cin >> ev.time >> tmp >> ev.name;
        if(tmp == "SET") {
            ev.type = SET;
            cin >> ev.value;
        } else {
            ev.type = DEL;
        }
        ev.id = -1;
        saved_events.push_back(ev);
    }

    // затем к этим операциям добавляем запросы
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        saved_events.push_back({t, 0, "", "", i});
    }

    std::vector<map<string, string>> ans(n);
    std::map<string, string> current_state;

    // можно было написать оператор сравнения структур Event, но я решил использовать лямбду
    // запросы нужно упорядочить, для того, чтобы за один проход по запросам ответить на все
    std::sort(saved_events.begin(), saved_events.end(), [&](const Event& lhs, const Event& rhs) {
        return lhs.time == rhs.time ? lhs.type < rhs.type : lhs.time < rhs.time;
    }
    );

    // поодерживаем текущее состояние всех переменных, при этом если встречаем "запрос",
    // то сохраняем ответ
    for (int i = 0; i < saved_events.size(); i++) {
        switch (saved_events[i].type) {
            case SET: current_state[saved_events[i].name] = saved_events[i].value; break;
            case DEL: current_state.erase(saved_events[i].name);                   break;
            default:  ans[saved_events[i].id] = current_state;                     break;
        }
    }

    // а затем печатаем сохраненный ответ
    for (const auto& state : ans) {
        bool was_prev = false;
        for (const auto& record : state) {
            cout << (was_prev ? ", " : "") << record.first <<  ": " <<  record.second;
            was_prev = true;
        }
        cout <<  endl;
    }
}