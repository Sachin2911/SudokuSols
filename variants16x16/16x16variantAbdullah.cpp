#include <iostream>
#include <vector>

using namespace std;
    
class Puzzle288 {
private:
        vector<vector<int>> matrix11;
    vector<vector<bool>> rowsFlag95, colsFlag15, boxesFlag80;

        bool isValid91(int x, int y, int number) {
            int boxIndex = (x / 3) * 3 + y / 3;
        return !rowsFlag95[x][number] && !colsFlag15[y][number] && !boxesFlag80[boxIndex][number];
    }

        void displayMatrix11() {
            for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                    if(j == 8) {
                    cout << matrix11[i][j];
                    } else {
                        cout << matrix11[i][j] << " ";
                }
                }
                cout << endl;
        }
        }

    bool solvePuzzle288() {
        int row = -1, col = -1, minPossible = 10;
            for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (matrix11[i][j] == 0) {
                        int numPossible = 0;
                    for (int number = 1; number <= 9; number++) {
                        if (isValid91(i, j, number)) {
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
                if (isValid91(row, col, number)) {
                    matrix11[row][col] = number;
                    int boxIndex = (row / 3) * 3 + col / 3;
                    rowsFlag95[row][number] = true;
                    colsFlag15[col][number] = true;
                    boxesFlag80[boxIndex][number] = true;
                
                    if (solvePuzzle288()) {
                        return true;
                }
                    
                matrix11[row][col] = 0;
                rowsFlag95[row][number] = false;
                    colsFlag15[col][number] = false;
                boxesFlag80[boxIndex][number] = false;
            }
            }
            
        return false;
        }
    
    public:
        Puzzle288() : matrix11(9, vector<int>(9, 0)), rowsFlag95(9, vector<bool>(10, false)), colsFlag15(9, vector<bool>(10, false)), boxesFlag80(9, vector<bool>(10, false)) {}
    
        void fillMatrix66() {
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                cin >> matrix11[i][j];
                    if (matrix11[i][j] != 0) {
                        int number = matrix11[i][j];
                        int boxIndex = (i / 3) * 3 + j / 3;
                        rowsFlag95[i][number] = true;
                        colsFlag15[j][number] = true;
                    boxesFlag80[boxIndex][number] = true;
                }
                }
            }
    }
    
        void resolveAndShow51() {
            if (solvePuzzle288()) {
                displayMatrix11();
            } else {
            cout << "No Solution" << endl;
            }
    }
};

    int main() {
    Puzzle288 sudoku;
    sudoku.fillMatrix66();
        sudoku.resolveAndShow51();
        return 0;
}

    


