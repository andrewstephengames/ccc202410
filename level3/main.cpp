#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("level3_example.in");
    ofstream fout("level3_example.out");

    long long N;
    fin >> N;
    
    for (int i = 0; i < N; i++) {
        long long x, y, beds;
        fin >> x >> y >> beds;

        vector<vector<int>> matrix(y, vector<int>(x, 0));
        long long id = 1;

        // Fill the matrix row-wise first
        for (long long j = 0; j < y; j++) {
            long long count = 0;
            for (long long k = 0; k < x - (x % 3); k += 3) {
                while (count < 3) {
                    matrix[j][k + count] = id;
                    count++;
                }
                count = 0;
                id++;
            }
            for (int counter = 0; counter < x % 3; counter++) {
                matrix[j][x - x % 3 + counter] = 0;
            }
            //if (x % 3 != 0) id++;
        }

        // Check columns for three consecutive zeros and fill with new id
        for (long long col = 0; col < x; col++) {
            for (long long row = 0; row < y - 2; row++) {
                if (matrix[row][col] == 0 && matrix[row + 1][col] == 0 && matrix[row + 2][col] == 0) {
                    matrix[row][col] = id;
                    matrix[row + 1][col] = id;
                    matrix[row + 2][col] = id;
                    id++;
                }
            }
        }

        for (const auto &row : matrix) {
            for (int value : row) {
                fout << value << ' ';
            }
            fout << endl;
        }

        fout << endl << endl;
    }

    fin.close();
    fout.close();

    return 0;
}