//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;


int main() {
    int mat[10][10];
    int n = 0;
    int m = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}