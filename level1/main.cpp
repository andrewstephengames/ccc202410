#include <fstream>

using namespace std;

struct Vector2 {
    int x, y;
};

ifstream in ("level1_example.in");
ofstream out ("level1_example.out");

int main () {
    int N, x, y;
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> x >> y;
        out << (x/3)*y << endl;
    }
    return 0;
}