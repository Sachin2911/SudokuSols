#include <iostream>
    #include <vector>
    #include <map>
    #include <bitset>
    
using namespace std;

class MegaPuzzle110 {
private:
    vector<vector<int>> largeMatrix16;
    vector<bitset<26>> rowMarkers56, colMarkers22, boxMarkers49; 
        map<char, int> charToInt58 = {
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}
    };
    
        map<int, char> intToChar60;

        bool canPlace86(int x, int y, int number) {
        int boxIndex = (x / 5) * 5 + y / 5;
        return !rowMarkers56[x][number] && !colMarkers22[y][number] && !boxMarkers49[boxIndex][number];
    }
    
    void showGrid59() {
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                if(j == 24) {
                        cout << intToChar60[largeMatrix16[i][j]];
                } else {
                    cout << intToChar60[largeMatrix16[i][j]] << " ";
                }
                }
                cout << endl;
        }
        }
    
        bool solveMegaPuzzle110() {
            int row = -1, col = -1, minPossible = 26;
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                    if (largeMatrix16[i][j] == 0) {
                        int numPossible = 0;
                        for (int number = 1; number <= 25; number++) {
                            if (canPlace86(i, j, number)) {
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
                if (canPlace86(row, col, number)) {
                largeMatrix16[row][col] = number;
                int boxIndex = (row / 5) * 5 + col / 5;
                    rowMarkers56[row][number] = true;
                colMarkers22[col][number] = true;
                boxMarkers49[boxIndex][number] = true;
                
                    if (solveMegaPuzzle110()) {
                    return true;
                    }
                    
                largeMatrix16[row][col] = 0;
                rowMarkers56[row][number] = false;
                colMarkers22[col][number] = false;
                    boxMarkers49[boxIndex][number] = false;
            }
            }
        
            return false;
        }
    
    public:
        MegaPuzzle110() : largeMatrix16(25, vector<int>(25, 0)), rowMarkers56(25), colMarkers22(25), boxMarkers49(25) {
            for (auto &pair : charToInt58) {
            intToChar60[pair.second] = pair.first;
        }
        }

    void initializeGrid19() {
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                    char x;
                cin >> x;
                largeMatrix16[i][j] = charToInt58[x];
                    if (largeMatrix16[i][j] != 0) {
                        int number = largeMatrix16[i][j];
                        int boxIndex = (i / 5) * 5 + j / 5;
                    rowMarkers56[i].set(number);    // Use set for bitset
                        colMarkers22[j].set(number);
                    boxMarkers49[boxIndex].set(number);
                    }
            }
            }
    }
    
        void solveAndDisplay55() {
            if (solveMegaPuzzle110()) {
                showGrid59();
        } else {
            cout << "No Solution" << endl;
            }
    }
};
    
    int main() {
        MegaPuzzle110 sudoku;
        sudoku.initializeGrid19();
    sudoku.solveAndDisplay55();
    return 0;
}


