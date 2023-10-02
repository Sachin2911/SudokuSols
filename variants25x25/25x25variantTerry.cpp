    #include <iostream>
#include <vector>
#include <map>
    #include <bitset>

    using namespace std;
    
class MegaPuzzle163 {
private:
    vector<vector<int>> largeMatrix23;
        vector<bitset<26>> rowMarkers71, colMarkers15, boxMarkers46; 
    map<char, int> charToInt51 = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
            {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}
        };
    
        map<int, char> intToChar99;
    
        bool canPlace74(int x, int y, int number) {
        int boxIndex = (x / 5) * 5 + y / 5;
            return !rowMarkers71[x][number] && !colMarkers15[y][number] && !boxMarkers46[boxIndex][number];
    }
    
    void showGrid54() {
            for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                if(j == 24) {
                        cout << intToChar99[largeMatrix23[i][j]];
                    } else {
                    cout << intToChar99[largeMatrix23[i][j]] << " ";
                }
                }
            cout << endl;
            }
        }

        bool solveMegaPuzzle163() {
        int row = -1, col = -1, minPossible = 26;
            for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                    if (largeMatrix23[i][j] == 0) {
                    int numPossible = 0;
                        for (int number = 1; number <= 25; number++) {
                            if (canPlace74(i, j, number)) {
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
                if (canPlace74(row, col, number)) {
                    largeMatrix23[row][col] = number;
                int boxIndex = (row / 5) * 5 + col / 5;
                    rowMarkers71[row][number] = true;
                colMarkers15[col][number] = true;
                boxMarkers46[boxIndex][number] = true;
                
                if (solveMegaPuzzle163()) {
                        return true;
                }
                    
                largeMatrix23[row][col] = 0;
                rowMarkers71[row][number] = false;
                colMarkers15[col][number] = false;
                    boxMarkers46[boxIndex][number] = false;
            }
            }
        
        return false;
    }
    
public:
        MegaPuzzle163() : largeMatrix23(25, vector<int>(25, 0)), rowMarkers71(25), colMarkers15(25), boxMarkers46(25) {
        for (auto &pair : charToInt51) {
            intToChar99[pair.second] = pair.first;
            }
    }
    
        void initializeGrid46() {
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                char x;
                    cin >> x;
                largeMatrix23[i][j] = charToInt51[x];
                if (largeMatrix23[i][j] != 0) {
                    int number = largeMatrix23[i][j];
                        int boxIndex = (i / 5) * 5 + j / 5;
                        rowMarkers71[i].set(number);    // Use set for bitset
                    colMarkers15[j].set(number);
                        boxMarkers46[boxIndex].set(number);
                }
            }
        }
        }
    
        void solveAndDisplay49() {
        if (solveMegaPuzzle163()) {
            showGrid54();
            } else {
                cout << "No Solution" << endl;
            }
    }
};
    
int main() {
    MegaPuzzle163 sudoku;
        sudoku.initializeGrid46();
        sudoku.solveAndDisplay49();
    return 0;
    }


