//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.

#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


class cell {
    public:
        char v;
        unsigned short int h;
        cell(): v('A'), h(1) {}
        cell(char v, unsigned short int h): v(v), h(h) {}

        std::pair<int, int> get_coords() const {
            return {v-'A', h - 1};
        }

        void check_for_error() {
            bool correct = 'A' <= v && v<='H' && 1 <= h && h <= 8;
            if(!correct)
                throw std::runtime_error("Incorrect coords of cells");
        }
};

class Piece {
    public:
        Piece(cell init_pos) : pos_(init_pos) {
            pos_.check_for_error();
        }
        virtual cell position() const {
            return pos_;
        }
        virtual vector<cell> moves() const {
            vector<cell> res;
            for(int x = 0; x < 8; x++)
            for(int y = 0; y < 8; y++)
            if(available(cell('A' + x, y + 1)))
            res.push_back(cell('A' + x, y + 1));
            return res;
        }
        virtual bool available(const cell& q) const = 0;
    protected:
        cell pos_;
        std::pair<int, int> get_new_coords(const cell& q) const {
            auto pos = pos_.get_coords();
            auto req = q.get_coords();;
            req.first -= pos.first;
            req.second -= pos.second;
            return req;
        }
};


class King : public Piece {
    public:
        King() : King(cell{}) {}
        King(cell init_pos) : Piece(init_pos) {}
        virtual bool available(const cell& q) const {
            auto off = get_new_coords(q);
            return std::abs(off.first) == 1 || std::abs(off.second) == 1;
        }

    friend std::istream& operator >> (std::istream& in, King& p);
};

class Rook : public virtual Piece {
    public:
        Rook() : Rook(cell{}) {}
        Rook(cell init_pos) : Piece(init_pos) {}
        virtual bool available(const cell& q) const {
            auto off = get_new_coords(q);
            return std::abs(off.first) == 0 || std::abs(off.second) == 0;
        }
    friend std::istream& operator >> (std::istream& in, Rook& p);
};


class Bishop : public virtual Piece {
    public:
        Bishop() : Bishop(cell{}) {}
        Bishop(cell init_pos) : Piece(init_pos) {}
        virtual bool available(const cell& q) const {
            auto off = get_new_coords(q);
            return std::abs(off.first) == std::abs(off.second);
        }
    friend std::istream& operator >> (std::istream& in, Bishop& p);
};

class Queen : public Bishop, public Rook {
    public:
        Queen() : Queen(cell{}) {}
        Queen(cell init_pos) : Piece(init_pos), Bishop(init_pos), Rook(init_pos)  {}
        virtual bool available(const cell& q) const {
            return Bishop::available(q) || Rook::available(q);
        }
    friend std::istream& operator >> (std::istream& in, Queen& p);
};

std::istream& operator >> (std::istream& in, King& p) {
    in >> p.pos_.v >> p.pos_.h;
    p.pos_.check_for_error();
    return in;
}
std::istream& operator >> (std::istream& in, Rook& p) {
    in >> p.pos_.v >> p.pos_.h;
    p.pos_.check_for_error();
    return in;
}
std::istream& operator >> (std::istream& in, Bishop& p) {
    in >> p.pos_.v >> p.pos_.h;
    p.pos_.check_for_error();
    return in;
}
std::istream& operator >> (std::istream& in, Queen& p) {
    in >> p.pos_.v >> p.pos_.h;
    p.pos_.check_for_error();
    return in;
}


int main() {
    King K;
    Rook R;
    Bishop B;
    Queen Q;
    try {
        cin >> K >> R >> B >> Q;
        cell a('E', 4);
        cout << std::boolalpha;
        cout << K.available(a) << endl;
        cout << R.available(a) << endl;
        cout << B.available(a) << endl;
        cout << Q.available(a) << endl;
    } catch (const std::exception& e) {
        cout << "Execution failed: " << e.what() << endl;
        return 1;
    }
    return 0;
}
