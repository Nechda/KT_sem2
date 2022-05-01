//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <vector>

using namespace std;

class Task {
    protected:
        int cpuNum;
        int size;
    public:
        Task(int cpuNum, int size) {
            this->cpuNum = cpuNum;
            this->size = size;
        }
        int getCPU() const {
            return cpuNum;
        }
        int getSize() const {
            return size;
        }
};

class Analyzer {
    public:
        Analyzer(int numCores) {
            complexity.resize(numCores);
        }
        void analyze(const vector<Task>& tasks) {
            for(const auto &task : tasks) {
                complexity[task.getCPU()] += task.getSize();
            }
        }
        int getLoadForCPU(int cpuNum) {
            return complexity[cpuNum];
        }
    private:
        std::vector<int> complexity;
};

int main() {
    int numberOfCores = 4;
    vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
    Analyzer a(numberOfCores);
    a.analyze(data);
    for(int i = 0; i < numberOfCores; i++)
    cout << a.getLoadForCPU(i) << endl;
    return 0;
}