    #include <iostream>
#include <vector>
    #include <map>
    #include <algorithm> 
    #include <ctime>

    using namespace std;

    class PuzzleBoard936 {
    private:
        vector<vector<int>> board94;
    vector<vector<bool>> rowChecks7, colChecks5, boxChecks85;
        map<char, int> charToDigit49 = {
            {'0', 0},{'1', 1},{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G',16}
    };

    map<int, char> digitToChar56;

        bool canInsert87(int x, int y, int number) {
        int boxIndex = (x / 4) * 4 + y / 4;
            return !rowChecks7[x][number] && !colChecks5[y][number] && !boxChecks85[boxIndex][number];
        }
    
    void outputBoard70() {
            for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                    if(j == 15) {
                    cout << digitToChar56[board94[i][j]];
                    } else {
                        cout << digitToChar56[board94[i][j]] << " ";
                }
                }
            cout << endl;
            }
        }

    bool solvePuzzleBoard936() {
        int row = -1, col = -1, minPossible = 17;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (board94[i][j] == 0) {
                    int numPossible = 0;
                        for (int number = 1; number <= 16; number++) {
                            if (canInsert87(i, j, number)) {
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
                if (canInsert87(row, col, number)) {
                    board94[row][col] = number;
                    int boxIndex = (row / 4) * 4 + col / 4;
                rowChecks7[row][number] = true;
                colChecks5[col][number] = true;
                    boxChecks85[boxIndex][number] = true;
    
                if (solvePuzzleBoard936()) {
                    return true;
                }

                    board94[row][col] = 0;
                    rowChecks7[row][number] = false;
                colChecks5[col][number] = false;
                    boxChecks85[boxIndex][number] = false;
                }
        }
    
            return false;
        }

public:
    PuzzleBoard936() : board94(16, vector<int>(16, 0)), rowChecks7(16, vector<bool>(17, false)), colChecks5(16, vector<bool>(17, false)), boxChecks85(16, vector<bool>(17, false)) {
        for (auto &pair : charToDigit49) {
                digitToChar56[pair.second] = pair.first;
        }
        }
    
        void initializeBoard84() {
            for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                    char x;
                    cin >> x;
                board94[i][j] = charToDigit49[x];
                if (board94[i][j] != 0) {
                    int number = board94[i][j];
                    int boxIndex = (i / 4) * 4 + j / 4;
                        rowChecks7[i][number] = true;
                        colChecks5[j][number] = true;
                    boxChecks85[boxIndex][number] = true;
                    }
                }
        }
    }
    
    void computeAndDisplay9() {
            if (solvePuzzleBoard936()) {
                outputBoard70();
        } else {
                cout << "No Solution" << endl;
        }
    }
    };

int main() {
        std::srand(std::time(nullptr));  // Initialize random seed
    PuzzleBoard936 sudoku;
    sudoku.initializeBoard84();
    sudoku.computeAndDisplay9();
        return 0;
    }



