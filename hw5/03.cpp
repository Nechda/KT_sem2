//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

class Animal {
  public:
    virtual void pet() = 0;
    virtual ~Animal() {};
};
class NPC {
  public:
    virtual void talk() = 0;
    virtual ~NPC() {};
};

class SmartCat : public Animal, public NPC {
  public:
    SmartCat() {};
    virtual ~SmartCat() {};
    virtual void pet() {
        std::cout << "Meow!" << std::endl;
    }
    virtual void talk() {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal *a = new SmartCat();
    a->pet();
    delete a;

    NPC *n = new SmartCat();
    n->talk();
    delete n;

    return 0;
}