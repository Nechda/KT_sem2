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

void swap_ints(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool search_value(int* arr, int size, int value) {
    int* start = arr;
    int* end = arr + size;
    while(arr != end) {
        if(*arr == value) {
            swap_ints(start, arr);
            return true;
        }
        arr++;
    }
    return false;
}

int main() {
    int arr[1000] = {};
    int n = 0;
    int m = 0;
    cin >> n;

    int old_array[1000] = {};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        old_array[i] = arr[i];
    }
    heap_sort(arr, n);

    cin >> m;
    int size = m;
    for(int i = 0; i < n; i++) {
        bool found = search_value(&arr[n - size], size, old_array[i]);
        if(found) {
            cout << old_array[i] << " ";
            size--;
        }
    }
    return 0;
}