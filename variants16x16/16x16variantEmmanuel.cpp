#include <iostream>
#include <vector>
    #include <map>
    #include <algorithm> 
#include <ctime>

using namespace std;

    class PuzzleBoard921 {
private:
        vector<vector<int>> board42;
    vector<vector<bool>> rowChecks69, colChecks21, boxChecks71;
    map<char, int> charToDigit55 = {
        {'0', 0},{'1', 1},{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
            {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
            {'G',16}
    };

    map<int, char> digitToChar40;
    
        bool canInsert97(int x, int y, int number) {
        int boxIndex = (x / 4) * 4 + y / 4;
            return !rowChecks69[x][number] && !colChecks21[y][number] && !boxChecks71[boxIndex][number];
    }

        void outputBoard77() {
            for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if(j == 15) {
                        cout << digitToChar40[board42[i][j]];
                } else {
                        cout << digitToChar40[board42[i][j]] << " ";
                }
                }
                cout << endl;
            }
        }
    
    bool solvePuzzleBoard921() {
            int row = -1, col = -1, minPossible = 17;
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if (board42[i][j] == 0) {
                    int numPossible = 0;
                    for (int number = 1; number <= 16; number++) {
                        if (canInsert97(i, j, number)) {
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
            if (canInsert97(row, col, number)) {
                    board42[row][col] = number;
                    int boxIndex = (row / 4) * 4 + col / 4;
                    rowChecks69[row][number] = true;
                    colChecks21[col][number] = true;
                    boxChecks71[boxIndex][number] = true;

                    if (solvePuzzleBoard921()) {
                    return true;
                    }

                    board42[row][col] = 0;
                    rowChecks69[row][number] = false;
                    colChecks21[col][number] = false;
                boxChecks71[boxIndex][number] = false;
            }
            }
    
        return false;
        }
    
public:
        PuzzleBoard921() : board42(16, vector<int>(16, 0)), rowChecks69(16, vector<bool>(17, false)), colChecks21(16, vector<bool>(17, false)), boxChecks71(16, vector<bool>(17, false)) {
        for (auto &pair : charToDigit55) {
                digitToChar40[pair.second] = pair.first;
        }
        }

    void initializeBoard6() {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                char x;
                    cin >> x;
                    board42[i][j] = charToDigit55[x];
                    if (board42[i][j] != 0) {
                    int number = board42[i][j];
                        int boxIndex = (i / 4) * 4 + j / 4;
                        rowChecks69[i][number] = true;
                        colChecks21[j][number] = true;
                        boxChecks71[boxIndex][number] = true;
                }
            }
        }
        }

    void computeAndDisplay77() {
        if (solvePuzzleBoard921()) {
            outputBoard77();
            } else {
                cout << "No Solution" << endl;
        }
        }
    };

int main() {
    std::srand(std::time(nullptr));  // Initialize random seed
        PuzzleBoard921 sudoku;
    sudoku.initializeBoard6();
    sudoku.computeAndDisplay77();
        return 0;
    }
    


