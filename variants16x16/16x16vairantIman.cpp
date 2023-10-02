    #include <iostream>
#include <vector>
    #include <map>
#include <algorithm> 
    #include <ctime>
    
using namespace std;
    
class PuzzleBoard779 {
private:
        vector<vector<int>> board28;
        vector<vector<bool>> rowChecks47, colChecks65, boxChecks9;
    map<char, int> charToDigit46 = {
            {'0', 0},{'1', 1},{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G',16}
        };

    map<int, char> digitToChar35;
    
    bool canInsert13(int x, int y, int number) {
            int boxIndex = (x / 4) * 4 + y / 4;
            return !rowChecks47[x][number] && !colChecks65[y][number] && !boxChecks9[boxIndex][number];
        }
    
    void outputBoard83() {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                if(j == 15) {
                    cout << digitToChar35[board28[i][j]];
                } else {
                        cout << digitToChar35[board28[i][j]] << " ";
                    }
                }
                cout << endl;
        }
        }

    bool solvePuzzleBoard779() {
        int row = -1, col = -1, minPossible = 17;
        for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if (board28[i][j] == 0) {
                    int numPossible = 0;
                    for (int number = 1; number <= 16; number++) {
                        if (canInsert13(i, j, number)) {
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

            // Shuffle the numbers for randomness
            vector<int> numbers(16);
            for (int i = 0; i < 16; i++) {
                numbers[i] = i + 1;
            }
            std::random_shuffle(numbers.begin(), numbers.end());

        for (const int &number : numbers) {
                if (canInsert13(row, col, number)) {
                    board28[row][col] = number;
                int boxIndex = (row / 4) * 4 + col / 4;
                    rowChecks47[row][number] = true;
                colChecks65[col][number] = true;
                    boxChecks9[boxIndex][number] = true;
    
                if (solvePuzzleBoard779()) {
                    return true;
                }
    
                    board28[row][col] = 0;
                    rowChecks47[row][number] = false;
                    colChecks65[col][number] = false;
                boxChecks9[boxIndex][number] = false;
                }
        }

            return false;
    }

public:
        PuzzleBoard779() : board28(16, vector<int>(16, 0)), rowChecks47(16, vector<bool>(17, false)), colChecks65(16, vector<bool>(17, false)), boxChecks9(16, vector<bool>(17, false)) {
        for (auto &pair : charToDigit46) {
            digitToChar35[pair.second] = pair.first;
            }
        }

    void initializeBoard40() {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    char x;
                    cin >> x;
                    board28[i][j] = charToDigit46[x];
                    if (board28[i][j] != 0) {
                    int number = board28[i][j];
                        int boxIndex = (i / 4) * 4 + j / 4;
                    rowChecks47[i][number] = true;
                        colChecks65[j][number] = true;
                        boxChecks9[boxIndex][number] = true;
                }
            }
        }
    }

        void computeAndDisplay43() {
        if (solvePuzzleBoard779()) {
            outputBoard83();
            } else {
            cout << "No Solution" << endl;
            }
    }
    };
    
int main() {
    std::srand(std::time(nullptr));  // Initialize random seed
        PuzzleBoard779 sudoku;
    sudoku.initializeBoard40();
    sudoku.computeAndDisplay43();
        return 0;
    }



