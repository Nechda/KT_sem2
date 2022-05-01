//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Animal {
    public:
        virtual string getType() const = 0;
        virtual ~Animal() {} 
};

/* Несколько релизаций для тестирования */
class Monkey : public Animal {
    public:
        string getType() const override { return "monkey"; }
};

class Lion : public Animal {
    public:
        string getType() const override { return "lion"; }
};

class Cat : public Animal {
    public:
        string getType() const override { return "cat"; }
};

class ZooKeeper {
    public:
        ZooKeeper() {}
        void handleAnimal(const Animal& a) {
            table[a.getType()]++;
        }
        int getAnimalCount(const string& type) const {
            auto search_it = table.find(type);
            return search_it == table.end() ? 0 : search_it->second;
        }
    private:
        unordered_map<string, int> table;
};

int main() {
    ZooKeeper z;
    Animal *a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Lion();
    z.handleAnimal(*a);
    delete a;
    cout << z.getAnimalCount("monkey") << endl;
    cout << z.getAnimalCount("lion") << endl;
    cout << z.getAnimalCount("cat") << endl;
    return 0;
}