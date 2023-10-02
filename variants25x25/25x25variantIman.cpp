#include <iostream>
#include <vector>
#include <map>
    #include <bitset>

    using namespace std;

    class MegaPuzzle370 {
private:
        vector<vector<int>> largeMatrix28;
    vector<bitset<26>> rowMarkers3, colMarkers85, boxMarkers75; 
        map<char, int> charToInt30 = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}
    };
    
    map<int, char> intToChar74;

        bool canPlace93(int x, int y, int number) {
            int boxIndex = (x / 5) * 5 + y / 5;
            return !rowMarkers3[x][number] && !colMarkers85[y][number] && !boxMarkers75[boxIndex][number];
        }
    
    void showGrid23() {
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                    if(j == 24) {
                    cout << intToChar74[largeMatrix28[i][j]];
                } else {
                        cout << intToChar74[largeMatrix28[i][j]] << " ";
                }
            }
                cout << endl;
        }
    }
    
    bool solveMegaPuzzle370() {
        int row = -1, col = -1, minPossible = 26;
        for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                if (largeMatrix28[i][j] == 0) {
                        int numPossible = 0;
                    for (int number = 1; number <= 25; number++) {
                        if (canPlace93(i, j, number)) {
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
                if (canPlace93(row, col, number)) {
                largeMatrix28[row][col] = number;
                    int boxIndex = (row / 5) * 5 + col / 5;
                    rowMarkers3[row][number] = true;
                    colMarkers85[col][number] = true;
                    boxMarkers75[boxIndex][number] = true;
                
                    if (solveMegaPuzzle370()) {
                        return true;
                }
                    
                    largeMatrix28[row][col] = 0;
                rowMarkers3[row][number] = false;
                    colMarkers85[col][number] = false;
                    boxMarkers75[boxIndex][number] = false;
                }
        }
            
        return false;
    }
    
public:
    MegaPuzzle370() : largeMatrix28(25, vector<int>(25, 0)), rowMarkers3(25), colMarkers85(25), boxMarkers75(25) {
            for (auto &pair : charToInt30) {
            intToChar74[pair.second] = pair.first;
        }
        }

    void initializeGrid74() {
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                char x;
                    cin >> x;
                largeMatrix28[i][j] = charToInt30[x];
                    if (largeMatrix28[i][j] != 0) {
                    int number = largeMatrix28[i][j];
                        int boxIndex = (i / 5) * 5 + j / 5;
                        rowMarkers3[i].set(number);    // Use set for bitset
                        colMarkers85[j].set(number);
                        boxMarkers75[boxIndex].set(number);
                    }
                }
            }
    }
    
    void solveAndDisplay16() {
            if (solveMegaPuzzle370()) {
                showGrid23();
            } else {
                cout << "No Solution" << endl;
        }
    }
    };

int main() {
    MegaPuzzle370 sudoku;
    sudoku.initializeGrid74();
    sudoku.solveAndDisplay16();
    return 0;
    }


