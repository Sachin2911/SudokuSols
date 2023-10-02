#include <iostream>
    #include <vector>
    
    using namespace std;

    class Puzzle605 {
private:
        vector<vector<int>> matrix42;
        vector<vector<bool>> rowsFlag58, colsFlag89, boxesFlag9;

    bool isValid20(int x, int y, int number) {
            int boxIndex = (x / 3) * 3 + y / 3;
        return !rowsFlag58[x][number] && !colsFlag89[y][number] && !boxesFlag9[boxIndex][number];
    }

    void displayMatrix64() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if(j == 8) {
                        cout << matrix42[i][j];
                    } else {
                        cout << matrix42[i][j] << " ";
                }
                }
                cout << endl;
            }
    }

        bool solvePuzzle605() {
            int row = -1, col = -1, minPossible = 10;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (matrix42[i][j] == 0) {
                    int numPossible = 0;
                        for (int number = 1; number <= 9; number++) {
                        if (isValid20(i, j, number)) {
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
                if (isValid20(row, col, number)) {
                    matrix42[row][col] = number;
                int boxIndex = (row / 3) * 3 + col / 3;
                rowsFlag58[row][number] = true;
                colsFlag89[col][number] = true;
                boxesFlag9[boxIndex][number] = true;
                
                if (solvePuzzle605()) {
                        return true;
                }
                
                matrix42[row][col] = 0;
                    rowsFlag58[row][number] = false;
                colsFlag89[col][number] = false;
                    boxesFlag9[boxIndex][number] = false;
            }
        }
            
        return false;
        }

public:
    Puzzle605() : matrix42(9, vector<int>(9, 0)), rowsFlag58(9, vector<bool>(10, false)), colsFlag89(9, vector<bool>(10, false)), boxesFlag9(9, vector<bool>(10, false)) {}
    
        void fillMatrix33() {
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cin >> matrix42[i][j];
                    if (matrix42[i][j] != 0) {
                        int number = matrix42[i][j];
                        int boxIndex = (i / 3) * 3 + j / 3;
                    rowsFlag58[i][number] = true;
                    colsFlag89[j][number] = true;
                    boxesFlag9[boxIndex][number] = true;
                    }
            }
        }
        }
    
        void resolveAndShow38() {
            if (solvePuzzle605()) {
                displayMatrix64();
        } else {
                cout << "No Solution" << endl;
            }
    }
};
    
int main() {
        Puzzle605 sudoku;
    sudoku.fillMatrix33();
    sudoku.resolveAndShow38();
        return 0;
}
    



