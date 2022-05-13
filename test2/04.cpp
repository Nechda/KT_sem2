//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <set>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    set<int> storage;
    // будем добавлять числа в упорядоченное множество множество, в случае
    // если число уже есть в данном множестве, то мы его удаляем
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        if(storage.count(t) == 1) {
            storage.erase(t);
        } else {
            storage.insert(t);
        }
    }

    // дальше просто пользуемся тем фактом, что множество упорядоченное и берем
    // его максимальный элемент
    cout << *storage.rbegin() << endl;
    return 0;
}