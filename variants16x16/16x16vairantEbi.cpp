#include <iostream>
    #include <vector>
    #include <map>
    #include <algorithm> 
    #include <ctime>

using namespace std;

    class PuzzleBoard825 {
    private:
        vector<vector<int>> board87;
        vector<vector<bool>> rowChecks64, colChecks49, boxChecks24;
        map<char, int> charToDigit66 = {
        {'0', 0},{'1', 1},{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
            {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
        {'G',16}
    };

        map<int, char> digitToChar49;
    
    bool canInsert52(int x, int y, int number) {
        int boxIndex = (x / 4) * 4 + y / 4;
        return !rowChecks64[x][number] && !colChecks49[y][number] && !boxChecks24[boxIndex][number];
        }

        void outputBoard75() {
            for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if(j == 15) {
                    cout << digitToChar49[board87[i][j]];
                } else {
                        cout << digitToChar49[board87[i][j]] << " ";
                    }
            }
                cout << endl;
            }
        }
    
        bool solvePuzzleBoard825() {
        int row = -1, col = -1, minPossible = 17;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (board87[i][j] == 0) {
                    int numPossible = 0;
                    for (int number = 1; number <= 16; number++) {
                            if (canInsert52(i, j, number)) {
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
            if (canInsert52(row, col, number)) {
                    board87[row][col] = number;
                int boxIndex = (row / 4) * 4 + col / 4;
                rowChecks64[row][number] = true;
                    colChecks49[col][number] = true;
                    boxChecks24[boxIndex][number] = true;
    
                if (solvePuzzleBoard825()) {
                    return true;
                    }
    
                    board87[row][col] = 0;
                rowChecks64[row][number] = false;
                colChecks49[col][number] = false;
                boxChecks24[boxIndex][number] = false;
            }
            }
    
            return false;
    }

public:
    PuzzleBoard825() : board87(16, vector<int>(16, 0)), rowChecks64(16, vector<bool>(17, false)), colChecks49(16, vector<bool>(17, false)), boxChecks24(16, vector<bool>(17, false)) {
        for (auto &pair : charToDigit66) {
                digitToChar49[pair.second] = pair.first;
            }
    }
    
    void initializeBoard80() {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                char x;
                cin >> x;
                board87[i][j] = charToDigit66[x];
                    if (board87[i][j] != 0) {
                        int number = board87[i][j];
                        int boxIndex = (i / 4) * 4 + j / 4;
                    rowChecks64[i][number] = true;
                        colChecks49[j][number] = true;
                    boxChecks24[boxIndex][number] = true;
                }
            }
        }
        }
    
    void computeAndDisplay78() {
        if (solvePuzzleBoard825()) {
                outputBoard75();
            } else {
            cout << "No Solution" << endl;
        }
    }
    };
    
    int main() {
        std::srand(std::time(nullptr));  // Initialize random seed
        PuzzleBoard825 sudoku;
        sudoku.initializeBoard80();
    sudoku.computeAndDisplay78();
        return 0;
    }



