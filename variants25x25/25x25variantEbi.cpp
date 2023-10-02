#include <iostream>
#include <vector>
#include <map>
#include <bitset>
    
using namespace std;
    
class MegaPuzzle141 {
    private:
        vector<vector<int>> largeMatrix35;
    vector<bitset<26>> rowMarkers28, colMarkers64, boxMarkers9; 
        map<char, int> charToInt63 = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
            {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}
    };

        map<int, char> intToChar84;
    
    bool canPlace61(int x, int y, int number) {
            int boxIndex = (x / 5) * 5 + y / 5;
        return !rowMarkers28[x][number] && !colMarkers64[y][number] && !boxMarkers9[boxIndex][number];
    }
    
    void showGrid14() {
            for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                if(j == 24) {
                    cout << intToChar84[largeMatrix35[i][j]];
                } else {
                        cout << intToChar84[largeMatrix35[i][j]] << " ";
                    }
                }
                cout << endl;
        }
        }
    
        bool solveMegaPuzzle141() {
            int row = -1, col = -1, minPossible = 26;
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                if (largeMatrix35[i][j] == 0) {
                    int numPossible = 0;
                    for (int number = 1; number <= 25; number++) {
                            if (canPlace61(i, j, number)) {
                            numPossible++;
                            }
                    }
                    if (numPossible < minPossible) {
                            minPossible = numPossible;
                        row = i;
                        col = j;
                        }
                    }
                }
        }

            if (row == -1 && col == -1) return true; // All cells filled
        
        for (int number = 1; number <= 25; number++) {
            if (canPlace61(row, col, number)) {
                largeMatrix35[row][col] = number;
                    int boxIndex = (row / 5) * 5 + col / 5;
                rowMarkers28[row][number] = true;
                    colMarkers64[col][number] = true;
                    boxMarkers9[boxIndex][number] = true;
                    
                if (solveMegaPuzzle141()) {
                        return true;
                }
                    
                    largeMatrix35[row][col] = 0;
                    rowMarkers28[row][number] = false;
                colMarkers64[col][number] = false;
                    boxMarkers9[boxIndex][number] = false;
                }
            }
        
            return false;
        }

public:
        MegaPuzzle141() : largeMatrix35(25, vector<int>(25, 0)), rowMarkers28(25), colMarkers64(25), boxMarkers9(25) {
            for (auto &pair : charToInt63) {
            intToChar84[pair.second] = pair.first;
            }
        }
    
        void initializeGrid27() {
            for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                    char x;
                    cin >> x;
                    largeMatrix35[i][j] = charToInt63[x];
                    if (largeMatrix35[i][j] != 0) {
                    int number = largeMatrix35[i][j];
                        int boxIndex = (i / 5) * 5 + j / 5;
                    rowMarkers28[i].set(number);    // Use set for bitset
                        colMarkers64[j].set(number);
                        boxMarkers9[boxIndex].set(number);
                }
            }
        }
    }
    
    void solveAndDisplay38() {
        if (solveMegaPuzzle141()) {
                showGrid14();
        } else {
                cout << "No Solution" << endl;
        }
    }
};

int main() {
    MegaPuzzle141 sudoku;
    sudoku.initializeGrid27();
    sudoku.solveAndDisplay38();
    return 0;
}


