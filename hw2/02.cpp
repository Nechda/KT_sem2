//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    // 1 -> worry
    vector<unsigned> queue;

    int Q = 0;
    cin >> Q; 
    while(Q--) {
        string command;
        int arg = 0;
        cin >> command;
        if(command != "WORRY_COUNT") {
            cin >> arg;
        }

        if(command == "WORRY") {
            queue[arg] |= 1U;
        }
        else if(command == "QUIET") {
            queue[arg] &= 0U;
        }
        else if(command == "COME") {
            if(arg > 0) {
                while(arg--) queue.push_back(0);
            }
            if(arg < 0) {
                while(arg++) queue.pop_back();
            }
        }
        else if(command == "WORRY_COUNT") {
            unsigned worry_count = 0;
            for(const auto& it : queue) worry_count += it;
            cout << worry_count << endl;
        }
    }
    return 0;
}
