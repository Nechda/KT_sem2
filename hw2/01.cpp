//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> temparature(n);
    for(auto& it : temparature) cin >> it;

    int avg = 0;
    for(int it : temparature) avg += it;
    avg /= n;

    int k = 0;
    for(int it : temparature) k += it > avg;
    cout << k << endl;
    for(int it : temparature) if(it > avg) cout << it << " ";
    cout << endl;
    return 0;
}
