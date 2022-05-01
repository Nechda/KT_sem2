//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class SessionManager {
    public:
        SessionManager() {}
        void login(const string& username) {
            online_users.insert(username);
        }
        void logout(const string& username) {
            online_users.erase(username);
        }
        int getNumberOfActiveUsers() const {
            return online_users.size();
        }
    private:
        unordered_set<string> online_users;
};

int main() {
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("whoever");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;
}