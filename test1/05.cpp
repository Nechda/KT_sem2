//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.

#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using ui32 = unsigned int;
using ui16 = unsigned short int;

class ATM {
    public:
        ATM() {}
        void deposit(const std::vector<ui32>& notes, ui16 currency) {
            auto &table = currency_table[currency];
            for(auto n : notes) table[n]++;
        }
        std::vector<ui32> withdraw_large(ui32 amount, ui16 currency) {
            auto &table = currency_table[currency];
            std::vector<ui32> res;
            int amount_i = amount;
            for(auto it = table.rbegin(); it != table.rend(); it++) {
               auto note = it->first;
               auto& nums = it->second;
               while(nums && amount_i >= note) {
                   amount_i -= note;
                   nums--;
                   res.push_back(note);
               }
            }

            if(amount_i == 0) {
                return res;
            } else {
                deposit(res, currency);
                return {};
            }
        }
        std::vector<ui32> withdraw_small(ui32 amount, ui16 currency) {
            auto &table = currency_table[currency];
            std::vector<ui32> res;
            int amount_i = amount;
            for(auto it = table.begin(); it != table.end(); it++) {
               auto note = it->first;
               auto& nums = it->second;
               while(nums && amount_i >= note) {
                   amount_i -= note;
                   nums--;
                   res.push_back(note);
               }
            }

            if(amount_i == 0) {
                return res;
            } else {
                deposit(res, currency);
                return {};
            }
        }
        ui32 check_reserve(ui16 currency) {
            auto &table = currency_table[currency];
            ui32 res = 0;
            for(auto it : table) {
                res += it.first * it.second;
            }
            return res;
        }
    private:
        // note, amount
        std::map<int, int> currency_table[3];
};


const unsigned short int RUB = 0;
const unsigned short int USD = 1;
const unsigned short int NCC = 2;
int main() {
    vector<unsigned int> rubles = {50, 100, 100, 500, 50, 1000, 100, 100, 1000, 5000};
    vector<unsigned int> dollars = {100, 100, 100};
    vector<unsigned int> nuka_cola_caps = {1, 1, 1, 1, 1};
    ATM atm;
    atm.deposit(rubles, RUB);
    atm.deposit(dollars, USD);
    atm.deposit(nuka_cola_caps, NCC);
    cout << "Reserves: " << endl;
    for(unsigned short int code = 0; code <= 2; code++) {
        cout << "Currency " << code << ": " << atm.check_reserve(code) << endl;
    }
    vector<unsigned int> result;
    result = atm.withdraw_large(1000, RUB);
    cout << "Asked withdraw_large for 1000 RUB, got " << result.size() << " banknotes" << endl;
    result = atm.withdraw_small(1000, RUB);
    cout << "Asked withdraw_small for 1000 RUB, got " << result.size() << " banknotes" << endl;
    result = atm.withdraw_small(1000, USD);
    cout << "Asked withdraw_small for 1000 USD, got " << result.size() << " banknotes" << endl;
    result = atm.withdraw_large(3, NCC);
    cout << "Asked withdraw_large for 3 NCC, got " << result.size() << " banknotes" << endl;
    cout << "Reserves: " << endl;
    for(unsigned short int code = 0; code <= 2; code++) {
        cout << "Currency " << code << ": " << atm.check_reserve(code) << endl;
    }
    return 0;
}
