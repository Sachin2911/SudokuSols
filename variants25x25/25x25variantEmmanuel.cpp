#include <iostream>
#include <vector>
    #include <map>
#include <bitset>

using namespace std;

class MegaPuzzle717 {
private:
        vector<vector<int>> largeMatrix8;
    vector<bitset<26>> rowMarkers56, colMarkers90, boxMarkers86; 
        map<char, int> charToInt72 = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
            {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}
        };
    
    map<int, char> intToChar44;

        bool canPlace64(int x, int y, int number) {
            int boxIndex = (x / 5) * 5 + y / 5;
        return !rowMarkers56[x][number] && !colMarkers90[y][number] && !boxMarkers86[boxIndex][number];
    }
    
        void showGrid8() {
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                if(j == 24) {
                    cout << intToChar44[largeMatrix8[i][j]];
                } else {
                    cout << intToChar44[largeMatrix8[i][j]] << " ";
                    }
                }
            cout << endl;
            }
        }
    
    bool solveMegaPuzzle717() {
            int row = -1, col = -1, minPossible = 26;
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                    if (largeMatrix8[i][j] == 0) {
                        int numPossible = 0;
                        for (int number = 1; number <= 25; number++) {
                            if (canPlace64(i, j, number)) {
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
            if (canPlace64(row, col, number)) {
                largeMatrix8[row][col] = number;
                int boxIndex = (row / 5) * 5 + col / 5;
                rowMarkers56[row][number] = true;
                    colMarkers90[col][number] = true;
                    boxMarkers86[boxIndex][number] = true;
                
                    if (solveMegaPuzzle717()) {
                        return true;
                    }
                    
                    largeMatrix8[row][col] = 0;
                rowMarkers56[row][number] = false;
                colMarkers90[col][number] = false;
                    boxMarkers86[boxIndex][number] = false;
                }
            }
        
        return false;
        }
    
public:
    MegaPuzzle717() : largeMatrix8(25, vector<int>(25, 0)), rowMarkers56(25), colMarkers90(25), boxMarkers86(25) {
            for (auto &pair : charToInt72) {
                intToChar44[pair.second] = pair.first;
            }
    }
    
    void initializeGrid99() {
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                    char x;
                    cin >> x;
                    largeMatrix8[i][j] = charToInt72[x];
                if (largeMatrix8[i][j] != 0) {
                    int number = largeMatrix8[i][j];
                        int boxIndex = (i / 5) * 5 + j / 5;
                        rowMarkers56[i].set(number);    // Use set for bitset
                        colMarkers90[j].set(number);
                    boxMarkers86[boxIndex].set(number);
                }
            }
            }
    }

    void solveAndDisplay95() {
        if (solveMegaPuzzle717()) {
            showGrid8();
        } else {
            cout << "No Solution" << endl;
        }
    }
    };

    int main() {
    MegaPuzzle717 sudoku;
    sudoku.initializeGrid99();
        sudoku.solveAndDisplay95();
    return 0;
}


