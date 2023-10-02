#include <iostream>
    #include <vector>
    #include <map>
#include <algorithm> 
#include <ctime>
    
using namespace std;

    class PuzzleBoard588 {
    private:
    vector<vector<int>> board48;
        vector<vector<bool>> rowChecks48, colChecks6, boxChecks2;
    map<char, int> charToDigit73 = {
            {'0', 0},{'1', 1},{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
            {'G',16}
    };
    
    map<int, char> digitToChar25;
    
        bool canInsert68(int x, int y, int number) {
            int boxIndex = (x / 4) * 4 + y / 4;
            return !rowChecks48[x][number] && !colChecks6[y][number] && !boxChecks2[boxIndex][number];
        }

    void outputBoard16() {
            for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if(j == 15) {
                        cout << digitToChar25[board48[i][j]];
                    } else {
                    cout << digitToChar25[board48[i][j]] << " ";
                    }
            }
                cout << endl;
        }
        }
    
        bool solvePuzzleBoard588() {
        int row = -1, col = -1, minPossible = 17;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                    if (board48[i][j] == 0) {
                    int numPossible = 0;
                        for (int number = 1; number <= 16; number++) {
                        if (canInsert68(i, j, number)) {
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
            if (canInsert68(row, col, number)) {
                    board48[row][col] = number;
                    int boxIndex = (row / 4) * 4 + col / 4;
                    rowChecks48[row][number] = true;
                    colChecks6[col][number] = true;
                boxChecks2[boxIndex][number] = true;
    
                    if (solvePuzzleBoard588()) {
                    return true;
                }

                    board48[row][col] = 0;
                    rowChecks48[row][number] = false;
                colChecks6[col][number] = false;
                    boxChecks2[boxIndex][number] = false;
                }
            }

        return false;
    }
    
    public:
        PuzzleBoard588() : board48(16, vector<int>(16, 0)), rowChecks48(16, vector<bool>(17, false)), colChecks6(16, vector<bool>(17, false)), boxChecks2(16, vector<bool>(17, false)) {
        for (auto &pair : charToDigit73) {
            digitToChar25[pair.second] = pair.first;
        }
    }

    void initializeBoard95() {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    char x;
                cin >> x;
                    board48[i][j] = charToDigit73[x];
                    if (board48[i][j] != 0) {
                    int number = board48[i][j];
                    int boxIndex = (i / 4) * 4 + j / 4;
                        rowChecks48[i][number] = true;
                        colChecks6[j][number] = true;
                        boxChecks2[boxIndex][number] = true;
                    }
                }
            }
        }

        void computeAndDisplay70() {
            if (solvePuzzleBoard588()) {
                outputBoard16();
            } else {
            cout << "No Solution" << endl;
            }
    }
};
    
int main() {
    std::srand(std::time(nullptr));  // Initialize random seed
    PuzzleBoard588 sudoku;
        sudoku.initializeBoard95();
        sudoku.computeAndDisplay70();
        return 0;
    }
    


