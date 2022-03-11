//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
public:
    ZooKeeper() {}
    void handleAnimal(Animal* a) {
        dangerous_ += a->isDangerous();
    }
    int getDangerousCount() {
        return dangerous_;
    }
private:
    int dangerous_ = 0;
};

// Several examples of implementations for test
class Monkey : public Animal {
    public:
        Monkey() {}
        virtual string getType() { return ""; }
        virtual bool isDangerous() { return 0; }
};

class Lion : public Animal {
    public:
        Lion() {}
        virtual string getType() { return ""; }
        virtual bool isDangerous() { return 1; }
};

int main() {
    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;
    return 0;
}