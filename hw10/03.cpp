//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

class Person {
    public:
        Person() {}
        Person(string surname, string name, string middle_name) :
            surname_(surname), name_(name), middle_name_(middle_name) {}
        
        bool operator < (const Person& rhs) const {
            return std::tie(surname_, name_, middle_name_) < std::tie(rhs.surname_, rhs.name_, rhs.middle_name_);
        }
    private:
        string surname_;
        string name_;
        string middle_name_;
    
    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend std::istream& operator>>(std::istream&, Person&);
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.surname_ << " " << p.name_ << " " << p.middle_name_;
    return os;
}

std::istream& operator>>(std::istream& is, Person& p) {
    is >> p.surname_ >> p.name_ >> p.middle_name_;
    return is;
}

int main() {
    cout << "Testing I/O" << endl;
    Person p;
    cin >> p;
    cout << p << endl;
    cout << "Testing sorting" << endl;
    vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));
    sort(people.begin(), people.end());
    for(vector<Person>::const_iterator it = people.begin(); it < people.end(); it++) {
        cout << *it << endl;
    }
}