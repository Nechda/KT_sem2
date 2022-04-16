//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int LevenshteinDistance(const string &source, const string &target) {
    if (source.size() > target.size()) {
        return LevenshteinDistance(target, source);
    }

    const int min_size = source.size(), max_size = target.size();
    std::vector<int> lev_dist(min_size + 1);

    for (int i = 0; i <= min_size; ++i) {
        lev_dist[i] = i;
    }

    for (int j = 1; j <= max_size; ++j) {
        int previous_diagonal = lev_dist[0], previous_diagonal_save;
        lev_dist[0]++;
        for (int i = 1; i <= min_size; ++i) {
            previous_diagonal_save = lev_dist[i];
            if (source[i - 1] == target[j - 1]) {
                lev_dist[i] = previous_diagonal;
            } else {
                lev_dist[i] = std::min(std::min(lev_dist[i - 1], lev_dist[i]), previous_diagonal) + 1;
            }
            previous_diagonal = previous_diagonal_save;
        }
    }

    return lev_dist[min_size];
}

int main() {
    string a;
    string b;
    cin >> a >> b;
    cout << LevenshteinDistance(a, b) << endl;
    return 0;
}