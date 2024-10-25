#include <fstream>
#include <vector>

using namespace std;

ifstream in ("level2_example.in");
ofstream out ("level2_example.out");

int main () {
    int N, x, y, num, cnt = 0, id;
    vector<vector<int>> table(N*N);
    in >> N;
    for (int i = 0; i < N; i++)
    {
        in >> x >> y >> num;
        id = 1;
        cnt = 0;
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= y; k++) {
                table[j][k] = id;
                cnt++;
                if (cnt%3 == 0) id++;
                out << table[j][k] << " ";
            }
            out << endl;
        }
    }
    return 0;
}

