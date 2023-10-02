#include <iostream>
    #include <vector>
    
using namespace std;

    class Puzzle313 {
    private:
        vector<vector<int>> matrix54;
    vector<vector<bool>> rowsFlag28, colsFlag6, boxesFlag1;

    bool isValid21(int x, int y, int number) {
            int boxIndex = (x / 3) * 3 + y / 3;
        return !rowsFlag28[x][number] && !colsFlag6[y][number] && !boxesFlag1[boxIndex][number];
    }
    
        void displayMatrix31() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(j == 8) {
                    cout << matrix54[i][j];
                } else {
                    cout << matrix54[i][j] << " ";
                }
            }
                cout << endl;
        }
    }
    
        bool solvePuzzle313() {
            int row = -1, col = -1, minPossible = 10;
            for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                    if (matrix54[i][j] == 0) {
                    int numPossible = 0;
                        for (int number = 1; number <= 9; number++) {
                        if (isValid21(i, j, number)) {
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
                if (isValid21(row, col, number)) {
                matrix54[row][col] = number;
                int boxIndex = (row / 3) * 3 + col / 3;
                    rowsFlag28[row][number] = true;
                colsFlag6[col][number] = true;
                boxesFlag1[boxIndex][number] = true;
                    
                if (solvePuzzle313()) {
                    return true;
                    }
                    
                    matrix54[row][col] = 0;
                    rowsFlag28[row][number] = false;
                colsFlag6[col][number] = false;
                boxesFlag1[boxIndex][number] = false;
            }
            }
        
        return false;
    }
    
    public:
        Puzzle313() : matrix54(9, vector<int>(9, 0)), rowsFlag28(9, vector<bool>(10, false)), colsFlag6(9, vector<bool>(10, false)), boxesFlag1(9, vector<bool>(10, false)) {}
    
    void fillMatrix40() {
            for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                    cin >> matrix54[i][j];
                if (matrix54[i][j] != 0) {
                    int number = matrix54[i][j];
                        int boxIndex = (i / 3) * 3 + j / 3;
                        rowsFlag28[i][number] = true;
                    colsFlag6[j][number] = true;
                    boxesFlag1[boxIndex][number] = true;
                }
            }
        }
        }
    
        void resolveAndShow82() {
            if (solvePuzzle313()) {
                displayMatrix31();
            } else {
            cout << "No Solution" << endl;
            }
    }
};
    
    int main() {
    Puzzle313 sudoku;
    sudoku.fillMatrix40();
        sudoku.resolveAndShow82();
        return 0;
    }
    



