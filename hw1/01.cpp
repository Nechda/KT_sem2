//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int arr[1000] = {};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = n - 1; i >=0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}