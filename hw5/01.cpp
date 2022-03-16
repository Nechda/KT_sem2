//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

namespace A {
    class Engine {
        public:
            Engine() {}
            void run() {std::cout << "EngineA run" << std::endl;}
    };
}

namespace B {
    class Engine {
        public:
            Engine() {}
            void run() {std::cout << "EngineB run" << std::endl;}
    };
}

namespace C {
    class Engine {
        public:
            Engine() {}
            void run() {std::cout << "EngineC run" << std::endl;}
    };
}


class MyEngine {
  public:
    MyEngine() {}
    void run(unsigned number) {
        switch (number)
        {
            case 1: engine_a.run(); break;
            case 2: engine_b.run(); break;
            case 3: engine_c.run(); break;
            default: break;
        }
    }
  private:
    A::Engine engine_a;
    B::Engine engine_b;
    C::Engine engine_c;
};

int main() {
    MyEngine e;
    e.run(1);
    e.run(2);
    e.run(3);
    e.run(10);
    return 0;
}