//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>

using namespace std;

// Also add simple implementation for testing
class Item {
public:
    Item(string title, int weight, int level, bool magical) : weight_(weight), level_(level), magical_(magical) {};
    int getWeight() { return weight_; }
    int getLevel() { return level_; }
    int isMagical() {return magical_; }
private:
    int weight_;
    int level_;
    bool magical_;
};

class Player {
protected:
    int strength;
    int level;
public:
    Player() {}
    virtual ~Player() {}
    void setStrength(int strength) { this->strength = strength; }
    void setLevel(int level) { this->level = level; }
    int getStrength() { return this->strength; }
    int getLevel() { return this->level; }
    virtual bool canUse(Item* item) = 0;
};

class Knight : public Player {
    public:
        Knight() {}
        virtual ~Knight() {}
        virtual bool canUse(Item* item) {
            return !item->isMagical()
                && this->getLevel() >= item->getLevel()
                && this->getStrength() >= item->getWeight();
        }
};

class Wizard : public Player {
    public:
        Wizard() {}
        virtual ~Wizard() {}
        virtual bool canUse(Item* item) {
            return this->getLevel() >= item->getLevel()
                && this->getStrength() >= item->getWeight();
        }
};


int main() {
    Item* items[3];
    items[0] = new Item("Small sword", 1, 1, false);
    items[1] = new Item("Big sword", 5, 3, false);
    items[2] = new Item("Ward", 1, 3, true);
    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Can use: " << players[i]->canUse(items[j]) << endl;
        }
    }
    return 0;
}