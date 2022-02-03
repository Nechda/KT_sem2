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
    
    double avg = 0;
    for(int i = 0; i < n; i++) {
        avg += arr[i];
    }
    avg /= n;

    for(int i = 0; i < n; i++) {
        if(arr[i] > avg)
            cout << arr[i] << " ";
    }
    return 0;
}