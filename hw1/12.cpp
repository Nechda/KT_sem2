//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
using namespace std;

struct Box {
    int p;
    int k;
};

// for sorting by price
bool comparator(Box a, Box b) {
    return a.p > b.p;
}

void box_swap(Box* first, Box* second) {
    Box tmp = *first;
    *first = *second;
    *second = tmp;
}

void heapify(Box* array, int n, int i)
{
    int largest = i;
    int l = (i << 1) + 1;
    int r = l + 1; 

    if(l < n) largest = comparator(array[l], array[largest]) ? l : largest; 
    if(r < n) largest = comparator(array[r], array[largest]) ? r : largest; 

    if(largest != i)
    {
        box_swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

static void heapSort(Box* array, int n)
{
    for(int i = (n>>1) - 1; i>= 0;i--)
        heapify(array, n, i);

    for(int i = n -1; i > 0; i--)
    {
        box_swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    Box boxes[1000];
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> boxes[i].p >> boxes[i].k;
    }

    heapSort(boxes, n);
    int total_candy = 0;
    int total_price = 0;
    int total_box = 0;
    int S = 0;
    cin >> S;
    for(int i = 0; i < n; i++) {
        if(total_price + boxes[i].p > S) {
            break;
        }
        total_candy += boxes[i].k;
        total_price += boxes[i].p;
        total_box++;
    }

    cout << total_box << " " << total_candy << endl;

    return 0;
}