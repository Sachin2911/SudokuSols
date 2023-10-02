    #include <iostream>
    #include <vector>
    
using namespace std;

    class Puzzle613 {
    private:
        vector<vector<int>> matrix37;
    vector<vector<bool>> rowsFlag7, colsFlag33, boxesFlag81;
    
    bool isValid85(int x, int y, int number) {
            int boxIndex = (x / 3) * 3 + y / 3;
            return !rowsFlag7[x][number] && !colsFlag33[y][number] && !boxesFlag81[boxIndex][number];
    }
    
        void displayMatrix99() {
            for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(j == 8) {
                    cout << matrix37[i][j];
                } else {
                    cout << matrix37[i][j] << " ";
                }
                }
                cout << endl;
        }
    }

        bool solvePuzzle613() {
            int row = -1, col = -1, minPossible = 10;
            for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                    if (matrix37[i][j] == 0) {
                    int numPossible = 0;
                    for (int number = 1; number <= 9; number++) {
                        if (isValid85(i, j, number)) {
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
            
            for (int number = 1; number <= 9; number++) {
                if (isValid85(row, col, number)) {
                    matrix37[row][col] = number;
                int boxIndex = (row / 3) * 3 + col / 3;
                    rowsFlag7[row][number] = true;
                    colsFlag33[col][number] = true;
                    boxesFlag81[boxIndex][number] = true;
                
                if (solvePuzzle613()) {
                        return true;
                    }
                    
                matrix37[row][col] = 0;
                rowsFlag7[row][number] = false;
                colsFlag33[col][number] = false;
                boxesFlag81[boxIndex][number] = false;
                }
            }
            
        return false;
        }
    
public:
        Puzzle613() : matrix37(9, vector<int>(9, 0)), rowsFlag7(9, vector<bool>(10, false)), colsFlag33(9, vector<bool>(10, false)), boxesFlag81(9, vector<bool>(10, false)) {}
    
        void fillMatrix84() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                cin >> matrix37[i][j];
                    if (matrix37[i][j] != 0) {
                        int number = matrix37[i][j];
                    int boxIndex = (i / 3) * 3 + j / 3;
                        rowsFlag7[i][number] = true;
                    colsFlag33[j][number] = true;
                    boxesFlag81[boxIndex][number] = true;
                }
                }
        }
        }
    
    void resolveAndShow65() {
        if (solvePuzzle613()) {
                displayMatrix99();
            } else {
                cout << "No Solution" << endl;
        }
        }
    };
    
    int main() {
        Puzzle613 sudoku;
        sudoku.fillMatrix84();
    sudoku.resolveAndShow65();
        return 0;
}




