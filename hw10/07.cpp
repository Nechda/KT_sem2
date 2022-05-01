//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Info {
    long min_value = 0;
    long max_value = 0;
    unsigned int event_count = 0;
};

class TelemetryController {
    public:
        TelemetryController() {}
        void handleEvent(const string& device, long value) {
            auto search_it = table.find(device);
            if(search_it == table.end()) {
                table[device] = {value, value, 1};
                return;
            }
            search_it->second.event_count++;
            search_it->second.min_value = std::min(search_it->second.min_value, value);
            search_it->second.max_value = std::max(search_it->second.max_value, value);
        }
        unsigned int getEventsCount(const string& device) const {
            auto search_it = table.find(device);
            return search_it->second.event_count;
        }
        long getMinValue(const string& device) const {
            auto search_it = table.find(device);
            return search_it->second.min_value;
        }
        long getMaxValue(const string& device) const {
            auto search_it = table.find(device);
            return search_it->second.max_value;
        }
    private:
        unordered_map<string, Info> table;
};

int main() {
    TelemetryController tc;
    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", -42);
    tc.handleEvent("d2", 100);
    cout << "Events count for d1: " << tc.getEventsCount("d1") << endl;
    cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
    cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;
}