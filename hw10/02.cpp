//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class ResultsTable {
    public:
        void addResult(unsigned int score) {
            // insert value into sorted array, without destroying sorted order
            table.insert(std::upper_bound(table.begin(), table.end(), score), score);
        }
        unsigned int getMinScore() const {
            return table[0];
        }
        unsigned int getScoreForPosition(unsigned int positionNumber) const {
            int idx = table.size() - positionNumber;
            return table[idx];
        }
    private:
        std::vector<unsigned> table;
};

int main() {
    ResultsTable t;
    t.addResult(30);
    t.addResult(85);
    t.addResult(12);
    t.addResult(31);
    cout << "1st place score: " << t.getScoreForPosition(1) << endl;
    cout << "2nd place score: " << t.getScoreForPosition(2) << endl;
    cout << "3rd place score: " << t.getScoreForPosition(3) << endl;
    cout << "Min score during the tournament: " << t.getMinScore() << endl;
    return 0;
}