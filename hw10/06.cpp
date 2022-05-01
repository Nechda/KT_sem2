//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Info {
    unsigned long long min_timestamp = -1;
    unsigned long long max_timestamp = 0;
    unsigned long long click_count = 0;
};

class Tracker {
    public:
        Tracker() {}
        void click(const string& username, unsigned long long timestamp) {
            auto search_it = table.find(username);
            if(search_it == table.end()) {
                table[username] = {timestamp, timestamp, 1};
                return;
            }

            search_it->second.click_count++;
            search_it->second.min_timestamp = std::min(search_it->second.min_timestamp, timestamp);
            search_it->second.max_timestamp = std::max(search_it->second.max_timestamp, timestamp);
        }

        unsigned long long getClickCount(const string& username) const {
            auto search_it = table.find(username);
            return search_it->second.click_count;
        }
        unsigned long long getFirstClick(const string& username) const {
            auto search_it = table.find(username);
            return search_it->second.min_timestamp;
        }
        unsigned long long getLastClick(const string& username) const {
            auto search_it = table.find(username);
            return search_it->second.max_timestamp;
        }
    private:
        unordered_map<string, Info> table;
};

int main() {
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);
    cout << t.getClickCount("alice") << endl;
    cout << t.getClickCount("bob") << endl;
    cout << t.getFirstClick("alice") << endl;
    cout << t.getFirstClick("bob") << endl;
    cout << t.getLastClick("alice") << endl;
    cout << t.getLastClick("bob") << endl;
    return 0;
}