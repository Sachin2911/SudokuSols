    #include <iostream>
    #include <vector>
#include <map>
#include <algorithm> 
    #include <ctime>

    using namespace std;
    
    class PuzzleBoard814 {
private:
    vector<vector<int>> board77;
        vector<vector<bool>> rowChecks3, colChecks24, boxChecks44;
    map<char, int> charToDigit50 = {
        {'0', 0},{'1', 1},{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G',16}
    };
    
    map<int, char> digitToChar14;

    bool canInsert27(int x, int y, int number) {
            int boxIndex = (x / 4) * 4 + y / 4;
            return !rowChecks3[x][number] && !colChecks24[y][number] && !boxChecks44[boxIndex][number];
    }

    void outputBoard12() {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if(j == 15) {
                        cout << digitToChar14[board77[i][j]];
                } else {
                        cout << digitToChar14[board77[i][j]] << " ";
                }
                }
                cout << endl;
            }
    }

    bool solvePuzzleBoard814() {
            int row = -1, col = -1, minPossible = 17;
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if (board77[i][j] == 0) {
                        int numPossible = 0;
                    for (int number = 1; number <= 16; number++) {
                            if (canInsert27(i, j, number)) {
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
                if (canInsert27(row, col, number)) {
                board77[row][col] = number;
                int boxIndex = (row / 4) * 4 + col / 4;
                rowChecks3[row][number] = true;
                colChecks24[col][number] = true;
                boxChecks44[boxIndex][number] = true;

                if (solvePuzzleBoard814()) {
                        return true;
                    }

                    board77[row][col] = 0;
                    rowChecks3[row][number] = false;
                colChecks24[col][number] = false;
                boxChecks44[boxIndex][number] = false;
            }
            }
    
            return false;
    }

    public:
    PuzzleBoard814() : board77(16, vector<int>(16, 0)), rowChecks3(16, vector<bool>(17, false)), colChecks24(16, vector<bool>(17, false)), boxChecks44(16, vector<bool>(17, false)) {
            for (auto &pair : charToDigit50) {
            digitToChar14[pair.second] = pair.first;
            }
        }

        void initializeBoard83() {
        for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    char x;
                cin >> x;
                    board77[i][j] = charToDigit50[x];
                if (board77[i][j] != 0) {
                        int number = board77[i][j];
                    int boxIndex = (i / 4) * 4 + j / 4;
                        rowChecks3[i][number] = true;
                    colChecks24[j][number] = true;
                        boxChecks44[boxIndex][number] = true;
                    }
            }
        }
    }
    
    void computeAndDisplay60() {
            if (solvePuzzleBoard814()) {
                outputBoard12();
        } else {
                cout << "No Solution" << endl;
            }
    }
    };
    
    int main() {
    std::srand(std::time(nullptr));  // Initialize random seed
        PuzzleBoard814 sudoku;
    sudoku.initializeBoard83();
    sudoku.computeAndDisplay60();
        return 0;
}
    


