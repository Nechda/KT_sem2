//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;

bool comparator(int a, int b) {
    return a > b;
}

void heapify(int* array, int n, int i)
{
    int largest = i;
    int l = (i << 1) + 1;
    int r = l + 1; 

    if(l < n) largest = comparator(array[l], array[largest]) ? l : largest; 
    if(r < n) largest = comparator(array[r], array[largest]) ? r : largest; 

    if(largest != i)
    {
        array[i] ^= array[largest];
        array[largest] ^= array[i];
        array[i] ^= array[largest];

        heapify(array, n, largest);
    }
}

void heap_sort(int* array, int n)
{
    for(int i = (n>>1) - 1; i>= 0;i--)
        heapify(array, n, i);

    for(int i = n -1; i > 0; i--)
    {
        array[0] ^= array[i];
        array[i] ^= array[0];
        array[0] ^= array[i];

        heapify(array, i, 0);
    }
}

int main() {
    char mat[10][10]={};
    int n = 0;
    int m = 0;
    cin >> n >> m;
    cin.get(); // remove `\n`
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            mat[i][j] = cin.get();
        cin.get();
    }

    for(int col = m - 1; col >= 0; col--) {
        for(int row = 0; row < n; row++) 
            cout << mat[row][col];
        cout << endl;
    }

    return 0;
}