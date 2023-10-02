#include <iostream>
#include <vector>
    #include <map>
    #include <bitset>
    
using namespace std;
    
class MegaPuzzle387 {
    private:
        vector<vector<int>> largeMatrix17;
    vector<bitset<26>> rowMarkers49, colMarkers3, boxMarkers30; 
    map<char, int> charToInt90 = {
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
            {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}
    };

    map<int, char> intToChar77;

        bool canPlace57(int x, int y, int number) {
            int boxIndex = (x / 5) * 5 + y / 5;
        return !rowMarkers49[x][number] && !colMarkers3[y][number] && !boxMarkers30[boxIndex][number];
        }
    
    void showGrid99() {
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                    if(j == 24) {
                    cout << intToChar77[largeMatrix17[i][j]];
                    } else {
                    cout << intToChar77[largeMatrix17[i][j]] << " ";
                }
                }
            cout << endl;
        }
    }

        bool solveMegaPuzzle387() {
            int row = -1, col = -1, minPossible = 26;
            for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                if (largeMatrix17[i][j] == 0) {
                        int numPossible = 0;
                        for (int number = 1; number <= 25; number++) {
                        if (canPlace57(i, j, number)) {
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
                if (canPlace57(row, col, number)) {
                largeMatrix17[row][col] = number;
                int boxIndex = (row / 5) * 5 + col / 5;
                rowMarkers49[row][number] = true;
                    colMarkers3[col][number] = true;
                    boxMarkers30[boxIndex][number] = true;
                
                if (solveMegaPuzzle387()) {
                    return true;
                    }
                    
                largeMatrix17[row][col] = 0;
                rowMarkers49[row][number] = false;
                    colMarkers3[col][number] = false;
                    boxMarkers30[boxIndex][number] = false;
            }
        }
            
            return false;
        }

public:
    MegaPuzzle387() : largeMatrix17(25, vector<int>(25, 0)), rowMarkers49(25), colMarkers3(25), boxMarkers30(25) {
            for (auto &pair : charToInt90) {
                intToChar77[pair.second] = pair.first;
        }
        }
    
        void initializeGrid61() {
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                char x;
                    cin >> x;
                    largeMatrix17[i][j] = charToInt90[x];
                if (largeMatrix17[i][j] != 0) {
                    int number = largeMatrix17[i][j];
                        int boxIndex = (i / 5) * 5 + j / 5;
                    rowMarkers49[i].set(number);    // Use set for bitset
                    colMarkers3[j].set(number);
                        boxMarkers30[boxIndex].set(number);
                    }
                }
            }
    }

        void solveAndDisplay62() {
            if (solveMegaPuzzle387()) {
            showGrid99();
            } else {
            cout << "No Solution" << endl;
        }
        }
    };
    
int main() {
    MegaPuzzle387 sudoku;
        sudoku.initializeGrid61();
    sudoku.solveAndDisplay62();
    return 0;
}


