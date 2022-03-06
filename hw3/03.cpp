//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <vector>

using namespace std;

class SpacePort {
    public:
        SpacePort(unsigned int size) {
            is_free_.resize(size);
            for(int i = 0; i < size; i++)
                is_free_[i] = true;
        }
        bool requestLanding(unsigned int dockNumber) {
            // Достаточно проверить, что size <= dockNumber
            // т.к. в случае, если будет передано отрицательное число,
            // то прозойдет каст в unsigned, и реальное значение переменной
            // станет порядка 2^31
            if(is_free_.size() <= dockNumber) return false;
            if(is_free_[dockNumber]) {
                is_free_[dockNumber] = false;
                return true;
            }
            return false;
        }
        bool requestTakeoff(unsigned int dockNumber) {
            // Достаточно проверить, что size <= dockNumber
            // т.к. в случае, если будет передано отрицательное число,
            // то прозойдет каст в unsigned, и реальное значение переменной
            // станет порядка 2^31
            if(is_free_.size() <= dockNumber) return false;
            if(!is_free_[dockNumber]) {
                is_free_[dockNumber] = true;
                return true;
            }
            return false;
        }
    private:
        vector<bool> is_free_;
};

int main() {
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;
    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;
    return 0;
}