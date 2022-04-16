//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> z(const string& s)
{
	int i, l, r, n = s.size();
	vector<int> z(n, 0);
	for (i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}


int main() {
    string a;
    string b;
    cin >> a >> b;

    string ss = b + '#' + a + a;
    int len = b.size();
    int start = len + 1;

	vector<int> res = z(ss);

    int answ = -1;
    for(int i = start; i < res.size(); i++) {
        if(res[i] == len) {
            answ = i - start;
            break;
        }
    }
    cout << answ << endl;
	
	return 0;
}