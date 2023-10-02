    #include <iostream>
#include <vector>
    
    using namespace std;

    class Puzzle981 {
private:
        vector<vector<int>> matrix34;
    vector<vector<bool>> rowsFlag72, colsFlag57, boxesFlag85;

    bool isValid46(int x, int y, int number) {
            int boxIndex = (x / 3) * 3 + y / 3;
            return !rowsFlag72[x][number] && !colsFlag57[y][number] && !boxesFlag85[boxIndex][number];
        }
    
    void displayMatrix18() {
            for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(j == 8) {
                    cout << matrix34[i][j];
                } else {
                        cout << matrix34[i][j] << " ";
                    }
                }
            cout << endl;
            }
        }

    bool solvePuzzle981() {
            int row = -1, col = -1, minPossible = 10;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (matrix34[i][j] == 0) {
                        int numPossible = 0;
                    for (int number = 1; number <= 9; number++) {
                            if (isValid46(i, j, number)) {
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
                if (isValid46(row, col, number)) {
                matrix34[row][col] = number;
                int boxIndex = (row / 3) * 3 + col / 3;
                    rowsFlag72[row][number] = true;
                    colsFlag57[col][number] = true;
                boxesFlag85[boxIndex][number] = true;
                    
                    if (solvePuzzle981()) {
                        return true;
                    }
                    
                    matrix34[row][col] = 0;
                    rowsFlag72[row][number] = false;
                    colsFlag57[col][number] = false;
                boxesFlag85[boxIndex][number] = false;
            }
        }
            
            return false;
    }
    
    public:
        Puzzle981() : matrix34(9, vector<int>(9, 0)), rowsFlag72(9, vector<bool>(10, false)), colsFlag57(9, vector<bool>(10, false)), boxesFlag85(9, vector<bool>(10, false)) {}
    
    void fillMatrix99() {
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                cin >> matrix34[i][j];
                if (matrix34[i][j] != 0) {
                        int number = matrix34[i][j];
                        int boxIndex = (i / 3) * 3 + j / 3;
                    rowsFlag72[i][number] = true;
                    colsFlag57[j][number] = true;
                    boxesFlag85[boxIndex][number] = true;
                    }
                }
        }
        }

    void resolveAndShow41() {
            if (solvePuzzle981()) {
                displayMatrix18();
        } else {
                cout << "No Solution" << endl;
        }
    }
};
    
int main() {
    Puzzle981 sudoku;
        sudoku.fillMatrix99();
    sudoku.resolveAndShow41();
    return 0;
    }

    


