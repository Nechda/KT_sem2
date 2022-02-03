//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
using namespace std;

int get_sum(int* start, int size) {
    int res = 0;
    int* end = start + size;
    while(start != end) {
        res += *start;
        start++;
    }
    return res;
}

int main() {
    int n, m;
    // m - rows
    cin >> n >> m;
    int mat[100][100];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[j][i];
        }
    }
    
    int max = get_sum(&mat[0][0], m);
    int idx_answ = 0;
    for(int i = 1; i < m; i++) {
        int cur_sum = get_sum(&mat[i][0], m);
        cout << cur_sum << endl;
        if(cur_sum > max) {
            max = cur_sum;
            idx_answ = i;
        }
    }

    // В задаче просят номер столбца, а в тестах выводится индекс!!
    cout << idx_answ << endl;
    return 0;
}