#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to check if we can place a desk vertically at (row, col)
bool canPlaceVertical(const vector<string>& layout, int row, int col) {
    if (row + 1 >= layout.size() || layout[row][col] != '.' || layout[row + 1][col] != '.') 
        return false;

    // Check surrounding cells to avoid touching
    for (int r = -1; r <= 2; ++r) {
        for (int c = -1; c <= 1; ++c) {
            int newRow = row + r, newCol = col + c;
            if (newRow >= 0 && newRow < layout.size() && newCol >= 0 && newCol < layout[0].size() && layout[newRow][newCol] == 'X') {
                return false;
            }
        }
    }
    return true;
}

// Function to check if we can place a desk horizontally at (row, col)
bool canPlaceHorizontal(const vector<string>& layout, int row, int col) {
    if (col + 1 >= layout[0].size() || layout[row][col] != '.' || layout[row][col + 1] != '.') 
        return false;

    // Check surrounding cells to avoid touching
    for (int r = -1; r <= 1; ++r) {
        for (int c = -1; c <= 2; ++c) {
            int newRow = row + r, newCol = col + c;
            if (newRow >= 0 && newRow < layout.size() && newCol >= 0 && newCol < layout[0].size() && layout[newRow][newCol] == 'X') {
                return false;
            }
        }
    }
    return true;
}

// Function to place or remove a desk vertically
void placeVertical(vector<string>& layout, int row, int col, bool place) {
    layout[row][col] = place ? 'X' : '.';
    layout[row + 1][col] = place ? 'X' : '.';
}

// Function to place or remove a desk horizontally
void placeHorizontal(vector<string>& layout, int row, int col, bool place) {
    layout[row][col] = place ? 'X' : '.';
    layout[row][col + 1] = place ? 'X' : '.';
}

// Backtracking function to place desks
bool backtrack(vector<string>& layout, int width, int length, int& deskCount, int totalDesks, int row, int col) {
    // If we have placed all desks, return true
    if (deskCount == totalDesks) return true;

    // Move to the next position
    if (col >= length) {
        col = 0;
        row++;
    }
    if (row >= width) return false; // If we've checked all rows

    // Try placing horizontally first
    if (col < length - 1 && canPlaceHorizontal(layout, row, col)) {
        placeHorizontal(layout, row, col, true);
        deskCount++;
        if (backtrack(layout, width, length, deskCount, totalDesks, row, col + 2)) return true; // Move to the next pair
        placeHorizontal(layout, row, col, false); // Backtrack
        deskCount--;
    }

    // Try placing vertically next
    if (row < width - 1 && canPlaceVertical(layout, row, col)) {
        placeVertical(layout, row, col, true);
        deskCount++;
        if (backtrack(layout, width, length, deskCount, totalDesks, row, col)) return true;
        placeVertical(layout, row, col, false); // Backtrack
        deskCount--;
    }

    // Move to the next column if neither placement worked
    return backtrack(layout, width, length, deskCount, totalDesks, row, col + 1);
}

// Function to generate the room layout based on given dimensions and number of desks
vector<string> generateRoomLayout(int length, int width, int desks) {
    vector<string> layout(width, string(length, '.')); // Initialize the room with empty spaces
    int deskCount = 0;

    // Start the backtracking process
    if (backtrack(layout, width, length, deskCount, desks, 0, 0)) {
        return layout;
    }

    return layout; // Return an empty layout if placing desks fails
}

// Function to write the room layouts to an output file
void writeRoomLayoutsToFile(const string& outputFileName, const vector<vector<string>>& allLayouts) {
    ofstream outFile(outputFileName);
    if (!outFile) {
        cerr << "Could not open the output file!" << endl;
        return;
    }

    for (const auto& layout : allLayouts) {
        for (const auto& row#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to check if we can place a desk vertically at (row, col)
bool canPlaceVertical(const vector<string>& layout, int row, int col) {
    if (row + 1 >= layout.size() || layout[row][col] != '.' || layout[row + 1][col] != '.') 
        return false;

    // Check surrounding cells to avoid touching
    for (int r = -1; r <= 2; ++r) {
        for (int c = -1; c <= 1; ++c) {
            int newRow = row + r, newCol = col + c;
            if (newRow >= 0 && newRow < layout.size() && newCol >= 0 && newCol < layout[0].size() && layout[newRow][newCol] == 'X') {
                return false;
            }
        }
    }
    return true;
}

// Function to check if we can place a desk horizontally at (row, col)
bool canPlaceHorizontal(const vector<string>& layout, int row, int col) {
    if (col + 1 >= layout[0].size() || layout[row][col] != '.' || layout[row][col + 1] != '.') 
        return false;

    // Check surrounding cells to avoid touching
    for (int r = -1; r <= 1; ++r) {
        for (int c = -1; c <= 2; ++c) {
            int newRow = row + r, newCol = col + c;
            if (newRow >= 0 && newRow < layout.size() && newCol >= 0 && newCol < layout[0].size() && layout[newRow][newCol] == 'X') {
                return false;
            }
        }
    }
    return true;
}

// Function to place or remove a desk vertically
void placeVertical(vector<string>& layout, int row, int col, bool place) {
    layout[row][col] = place ? 'X' : '.';
    layout[row + 1][col] = place ? 'X' : '.';
}

// Function to place or remove a desk horizontally
void placeHorizontal(vector<string>& layout, int row, int col, bool place) {
    layout[row][col] = place ? 'X' : '.';
    layout[row][col + 1] = place ? 'X' : '.';
}

// Backtracking function to place desks
bool backtrack(vector<string>& layout, int width, int length, int& deskCount, int totalDesks, int row, int col) {
    // If we have placed all desks, return true
    if (deskCount == totalDesks) return true;

    // Move to the next position
    if (col >= length) {
        col = 0;
        row++;
    }
    if (row >= width) return false; // If we've checked all rows

    // Try placing horizontally first
    if (col < length - 1 && canPlaceHorizontal(layout, row, col)) {
        placeHorizontal(layout, row, col, true);
        deskCount++;
        if (backtrack(layout, width, length, deskCount, totalDesks, row, col + 2)) return true; // Move to the next pair
        placeHorizontal(layout, row, col, false); // Backtrack
        deskCount--;
    }

    // Try placing vertically next
    if (row < width - 1 && canPlaceVertical(layout, row, col)) {
        placeVertical(layout, row, col, true);
        deskCount++;
        if (backtrack(layout, width, length, deskCount, totalDesks, row, col)) return true;
        placeVertical(layout, row, col, false); // Backtrack
        deskCount--;
    }

    // Move to the next column if neither placement worked
    return backtrack(layout, width, length, deskCount, totalDesks, row, col + 1);
}

// Function to generate the room layout based on given dimensions and number of desks
vector<string> generateRoomLayout(int length, int width, int desks) {
    vector<string> layout(width, string(length, '.')); // Initialize the room with empty spaces
    int deskCount = 0;

    // Start the backtracking process
    if (backtrack(layout, width, length, deskCount, desks, 0, 0)) {
        return layout;
    }

    return layout; // Return an empty layout if placing desks fails
}

// Function to write the room layouts to an output file
void writeRoomLayoutsToFile(const string& outputFileName, const vector<vector<string>>& allLayouts) {
    ofstream outFile(outputFileName);
    if (!outFile) {
        cerr << "Could not open the output file!" << endl;
        return;
    }

    for (const auto& layout : allLayouts) {
        for (const auto& row : layout) {
            outFile << row << endl;
        }
        outFile << endl; // Separate rooms with a blank line
    }

    outFile.close();
}

int main() {
    // Input and output file names
    string inputFileName = "level5_1.in"; // Input file name
    string outputFileName = "level5_1.out";     // Output file name
    
    ifstream inFile(inputFileName);
    if (!inFile) {
        cerr << "Could not open the input file!" << endl;
        return 1;
    }

    int N; // Number of rooms
    inFile >> N;

    vector<vector<string>> allLayouts; // To store layouts for all rooms

    for (int i = 0; i < N; ++i) {
        int length, width, desks;
        inFile >> length >> width >> desks;

        // Generate the room layout
        vector<string> layout = generateRoomLayout(length, width, desks);
        allLayouts.push_back(layout);
    }

    // Close the input file
    inFile.close();

    // Write the layouts to the output file
    writeRoomLayoutsToFile(outputFileName, allLayouts);

    return 0;
} layout) {
            outFile << row << endl;
        }
        outFile << endl; // Separate rooms with a blank line
    }

    outFile.close();
}

int main() {
    // Input and output file names
    string inputFileName = "level5_5.in"; // Input file name
    string outputFileName = "level5_5.out";     // Output file name
    
    ifstream inFile(inputFileName);
    if (!inFile) {
        cerr << "Could not open the input file!" << endl;
        return 1;
    }

    int N; // Number of rooms
    inFile >> N;

    vector<vector<string>> allLayouts; // To store layouts for all rooms

    for (int i = 0; i < N; ++i) {
        int length, width, desks;
        inFile >> length >> width >> desks;

        // Generate the room layout
        vector<string> layout = generateRoomLayout(length, width, desks);
        allLayouts.push_back(layout);
    }

    // Close the input file
    inFile.close();

    // Write the layouts to the output file
    writeRoomLayoutsToFile(outputFileName, allLayouts);

    return 0;
}