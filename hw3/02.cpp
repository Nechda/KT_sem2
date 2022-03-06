//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;

class GasHolder {
    public:
        GasHolder(float v) : v_{v}, T_{273} {}
        ~GasHolder() {}
        void inject(float m, float M) {
            nu_ += m / M;
        }
        void heat(float dT) {
            T_ += dT;
        }
        void cool(float dT) {
            T_ -= dT;
            if(T_ < 0) T_ = 0;
        }
        float getPressure() {
            const float R = 8.31;
            return nu_ * T_ * R / v_;
        }
    private:
        float v_;
        float nu_;
        float T_;
};

int main() {
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    return 0;
}