#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("level4_5.in");
    ofstream fout("level4_5.out");

    long long N;
    fin >> N;
    
    for (int i = 0; i < N; i++) {
        long long x, y, beds;
        fin >> x >> y >> beds;

        vector<vector<char>> matrix(y, vector<char>(x, '.'));

        long long placedDesks = 0;

        // Try to place desks, prioritizing vertical placement
        for (long long j = 0; j < y && placedDesks < beds; j++) {
            for (long long k = 0; k < x && placedDesks < beds; k++) {
                // Check if we can place a desk vertically
                if (j + 2 < y && matrix[j][k] == '.' && matrix[j + 1][k] == '.' && matrix[j + 2][k] == '.') {
                    // Check surrounding cells to ensure no touching
                    bool canPlace = true;
                    for (long long dy = -1; dy <= 2; dy++) {
                        for (long long dx = -1; dx <= 0; dx++) {
                            if (dx == 0 && dy >= 0 && dy <= 2) continue; // Skip the current desk cells
                            long long newY = j + dy;
                            long long newX = k + dx;
                            if (newY >= 0 && newY < y && newX >= 0 && newX < x) {
                                if (matrix[newY][newX] == 'X') {
                                    canPlace = false;
                                    break;
                                }
                            }
                        }
                        if (!canPlace) break;
                    }

                    // Place the desk if possible
                    if (canPlace) {
                        matrix[j][k] = 'X';
                        matrix[j + 1][k] = 'X';
                        matrix[j + 2][k] = 'X';
                        placedDesks++;
                    }
                }

                // Check if we can place a desk horizontally
                if (placedDesks < beds && k + 2 < x && matrix[j][k] == '.' && matrix[j][k + 1] == '.' && matrix[j][k + 2] == '.') {
                    // Check surrounding cells to ensure no touching
                    bool canPlace = true;
                    for (long long dy = -1; dy <= 1; dy++) {
                        for (long long dx = -1; dx <= 2; dx++) {
                            if (dy == 0 && dx >= 0 && dx <= 2) continue; // Skip the current desk cells
                            long long newY = j + dy;
                            long long newX = k + dx;
                            if (newY >= 0 && newY < y && newX >= 0 && newX < x) {
                                if (matrix[newY][newX] == 'X') {
                                    canPlace = false;
                                    break;
                                }
                            }
                        }
                        if (!canPlace) break;
                    }

                    // Place the desk if possible
                    if (canPlace) {
                        matrix[j][k] = 'X';
                        matrix[j][k + 1] = 'X';
                        matrix[j][k + 2] = 'X';
                        placedDesks++;
                    }
                }
            }
        }

        // Output the matrix
        for (const auto &row : matrix) {
            for (char value : row) {
                fout << value;
            }
            fout << endl;
        }

        fout << endl << endl;
    }

    fin.close();
    fout.close();

    return 0;
}