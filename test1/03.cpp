//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Coon {
    unsigned int id;
    char name[100];
    double weight;
    double food;
};


Coon* find_the_most_fed_cat(Coon* atc, unsigned int n_cats) {
    double max_ = -1;
    for(int i = 0; i < n_cats; i++) {
        max_ = std::max(atc[i].food/atc[i].weight, max_);
    }
    const double EPS = 0.0001;
    for(int i = 0; i < n_cats; i++) {
        double param = atc[i].food/atc[i].weight;
        if(std::abs(param - max_) < EPS) {
            return atc + i;
        }
    }
    return atc;
}

int main() {
    Coon all_the_coons[1000];
    unsigned int n;
    cin >> n;
    for(unsigned int i = 0; i < n; i++) {
        cin >> all_the_coons[i].id >> all_the_coons[i].name >> all_the_coons[i].weight >> all_the_coons[i].food;
    }
    cout << find_the_most_fed_cat(all_the_coons, n)->name << endl;
    return 0;
}