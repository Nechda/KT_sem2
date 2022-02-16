//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print_record(const vector<string>& record) {
    cout << record.size() << " ";
    for(const auto& it : record) cout << it << " ";
    cout << endl;
}

void correct_table(vector<string>* ptable) {
    static int month = 0;
    const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31,31};

    bool is_increase = days[month] < days[month + 1];
    bool is_decrease = days[month] > days[month + 1];
    
    if(is_increase) {
        for(int i = days[month]; i < days[month + 1]; i++)
            ptable[i].resize(0);
    }
    if(is_decrease) {
        vector<string> collected;
        for(int i = days[month + 1]; i < days[month]; i++) {
            collected.insert(collected.end(), ptable[i].begin(), ptable[i].end());
            ptable[i].resize(0);
        }
        auto& last = ptable[days[month + 1] - 1];
        last.insert(last.end(), collected.begin(), collected.end());
    }

    month++;
    month%=12;
}


int main()
{
    vector<string> table[31];

    int Q = 0;
    cin >> Q;
    while(Q--) {
        string command;
        cin >> command;
        if(command == "NEXT") {
            correct_table(table);
            continue;
        }
        if(command == "DUMP") {
            int day = 0;
            cin >> day;
            print_record(table[day-1]);
            continue;
        }
        if(command == "ADD") {
            int day = 0;
            string record;
            cin >> day >> record;
            table[day-1].push_back(record);
        }
    }
    return 0;
}
