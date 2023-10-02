#include <iostream>
#include <vector>
    #include <map>
#include <algorithm> 
    #include <ctime>

    using namespace std;

class PuzzleBoard710 {
    private:
        vector<vector<int>> board18;
        vector<vector<bool>> rowChecks89, colChecks31, boxChecks54;
        map<char, int> charToDigit47 = {
            {'0', 0},{'1', 1},{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
            {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
            {'G',16}
    };
    
    map<int, char> digitToChar40;
    
    bool canInsert41(int x, int y, int number) {
            int boxIndex = (x / 4) * 4 + y / 4;
            return !rowChecks89[x][number] && !colChecks31[y][number] && !boxChecks54[boxIndex][number];
        }
    
        void outputBoard96() {
            for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if(j == 15) {
                        cout << digitToChar40[board18[i][j]];
                    } else {
                    cout << digitToChar40[board18[i][j]] << " ";
                    }
            }
            cout << endl;
            }
        }

        bool solvePuzzleBoard710() {
        int row = -1, col = -1, minPossible = 17;
        for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if (board18[i][j] == 0) {
                    int numPossible = 0;
                        for (int number = 1; number <= 16; number++) {
                        if (canInsert41(i, j, number)) {
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
                if (canInsert41(row, col, number)) {
                    board18[row][col] = number;
                int boxIndex = (row / 4) * 4 + col / 4;
                    rowChecks89[row][number] = true;
                colChecks31[col][number] = true;
                    boxChecks54[boxIndex][number] = true;

                    if (solvePuzzleBoard710()) {
                        return true;
                }
    
                    board18[row][col] = 0;
                    rowChecks89[row][number] = false;
                colChecks31[col][number] = false;
                boxChecks54[boxIndex][number] = false;
            }
        }

        return false;
    }
    
public:
        PuzzleBoard710() : board18(16, vector<int>(16, 0)), rowChecks89(16, vector<bool>(17, false)), colChecks31(16, vector<bool>(17, false)), boxChecks54(16, vector<bool>(17, false)) {
        for (auto &pair : charToDigit47) {
                digitToChar40[pair.second] = pair.first;
        }
    }
    
    void initializeBoard38() {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                char x;
                cin >> x;
                    board18[i][j] = charToDigit47[x];
                    if (board18[i][j] != 0) {
                    int number = board18[i][j];
                        int boxIndex = (i / 4) * 4 + j / 4;
                        rowChecks89[i][number] = true;
                    colChecks31[j][number] = true;
                    boxChecks54[boxIndex][number] = true;
                    }
            }
        }
    }

    void computeAndDisplay83() {
            if (solvePuzzleBoard710()) {
                outputBoard96();
        } else {
            cout << "No Solution" << endl;
        }
        }
    };
    
    int main() {
        std::srand(std::time(nullptr));  // Initialize random seed
        PuzzleBoard710 sudoku;
    sudoku.initializeBoard38();
        sudoku.computeAndDisplay83();
        return 0;
}



