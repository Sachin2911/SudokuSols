    #include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;
    
class MegaPuzzle257 {
    private:
    vector<vector<int>> largeMatrix24;
    vector<bitset<26>> rowMarkers76, colMarkers30, boxMarkers37; 
    map<char, int> charToInt52 = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
            {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}
    };
    
        map<int, char> intToChar13;

    bool canPlace86(int x, int y, int number) {
        int boxIndex = (x / 5) * 5 + y / 5;
            return !rowMarkers76[x][number] && !colMarkers30[y][number] && !boxMarkers37[boxIndex][number];
        }

        void showGrid83() {
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 25; j++) {
                    if(j == 24) {
                    cout << intToChar13[largeMatrix24[i][j]];
                } else {
                        cout << intToChar13[largeMatrix24[i][j]] << " ";
                    }
                }
                cout << endl;
        }
        }

    bool solveMegaPuzzle257() {
            int row = -1, col = -1, minPossible = 26;
            for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                    if (largeMatrix24[i][j] == 0) {
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
                largeMatrix24[row][col] = number;
                    int boxIndex = (row / 5) * 5 + col / 5;
                    rowMarkers76[row][number] = true;
                    colMarkers30[col][number] = true;
                    boxMarkers37[boxIndex][number] = true;
                    
                if (solveMegaPuzzle257()) {
                    return true;
                }
                
                largeMatrix24[row][col] = 0;
                rowMarkers76[row][number] = false;
                colMarkers30[col][number] = false;
                boxMarkers37[boxIndex][number] = false;
                }
            }
            
        return false;
    }
    
public:
        MegaPuzzle257() : largeMatrix24(25, vector<int>(25, 0)), rowMarkers76(25), colMarkers30(25), boxMarkers37(25) {
            for (auto &pair : charToInt52) {
            intToChar13[pair.second] = pair.first;
        }
        }
    
    void initializeGrid72() {
            for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                char x;
                cin >> x;
                largeMatrix24[i][j] = charToInt52[x];
                    if (largeMatrix24[i][j] != 0) {
                    int number = largeMatrix24[i][j];
                    int boxIndex = (i / 5) * 5 + j / 5;
                        rowMarkers76[i].set(number);    // Use set for bitset
                        colMarkers30[j].set(number);
                        boxMarkers37[boxIndex].set(number);
                    }
                }
            }
        }
    
    void solveAndDisplay80() {
        if (solveMegaPuzzle257()) {
            showGrid83();
        } else {
                cout << "No Solution" << endl;
            }
        }
};

    int main() {
    MegaPuzzle257 sudoku;
    sudoku.initializeGrid72();
        sudoku.solveAndDisplay80();
    return 0;
}


