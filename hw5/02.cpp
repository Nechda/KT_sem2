//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

class Storage {
  public:
    Storage(unsigned n) {
        data_ = new int[n];
    }
    virtual ~Storage() {
        delete[] data_;
    }

    int getValue(unsigned i) {
        return data_[i];
    }
    void setValue(unsigned i, int value) {
        data_[i] = value;
    }
  private:
    int *data_ = nullptr;
};

class TestStorage : public Storage {
  protected:
    int* more_data;

  public:
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }
    ~TestStorage() {
        delete[] more_data;
    }
};


int main() {
    Storage* st = new TestStorage(42);
    delete st;
    return 0;
}