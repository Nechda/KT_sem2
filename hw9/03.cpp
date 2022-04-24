//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>

using namespace std;

template <typename T>
class Vector2D {
    using Self = Vector2D<T>;
    using reference = Self&;
    using const_reference = const reference;
  public:
    Vector2D() {}
    Vector2D(T x, T y) : x_(x), y_(y) {} 
    T getX() const {return x_;}
    T getY() const {return y_;}
    void setX(T x) {x_ = x;}
    void setY(T y) {y_ = y;}

    bool operator== (const Self& v2) const { return this->x_ == v2.x_ && this->y_ == v2.y_; }
    bool operator!= (const Self& v2) const {return !(*this == v2); }
    Self operator+ (const Self& v2) const {return {this->x_ + v2.x, this->y_ + v2.y}; }
    Self operator- (const Self& v2) const {return {this->x_ - v2.x, this->y_ - v2.y}; }
    template<typename num_t>
    Self operator* (const num_t a) const {return {this->x_ * a, this->y_ * a}; }
  private:
    T x_{};
    T y_{};
};

template<typename num_t, typename T>
Vector2D<T> operator* (num_t a, const Vector2D<T>& v) { return v * a; }

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

template<typename T>
std::istream& operator>>(std::istream &is, Vector2D<T>& v) {
    T tmp;
    is >> tmp;
    v.setX(tmp);
    is >> tmp;
    v.setY(tmp);
    return is;
}

int main() {
    Vector2D<int> v1;
    cin >> v1;
    cout << "Read vector: " << v1 << endl;
    cout << "Vector multiplied by 42: " << v1 * 42 << endl;
    Vector2D<double> v2;
    cin >> v2;
    cout << "Read vector: " << v2 << endl;
    cout << "Vector multiplied by 42: " << 42 * v2 << endl;
}