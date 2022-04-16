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

/*
    Сведем задачу к известной задаче о вычислении Z функции
    для входной строки.
*/

int main() {
    string s;
    cin >> s;
    string ss = s;
    std::reverse(ss.begin(), ss.end());
    ss += s;

	vector<int> res = z(ss);

	int i = res.size() - 1;
	printf("%d", res[i]);
	for (--i; i >= s.size(); i--) printf(" %d", res[i]);
	printf("\n");
	return 0;
}