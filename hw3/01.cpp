//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;

class Train {
    public:
        Train(double m) : mass_{m}, p_{0}, x_{0} {};
        void move(double dt) {
            double delta_x = p_ / mass_ * dt;
            x_ += delta_x;
        }
        void accelereate(double dp) {
            p_ += dp;
        }
        double getX() {
            return x_;
        }
        void print() {
            cout << "Current X: " << x_ << endl;
        }
    private:
        double mass_;
        double p_;
        double x_;
};


int main() {
    Train t(10);
    t.accelereate(1);
    t.move(1);
    t.print();
    t.move(1);
    t.print();
    t.accelereate(-2);
    t.move(3);
    t.print();
    return 0;
}