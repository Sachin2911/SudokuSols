    #include <iostream>
    #include <vector>
    
    using namespace std;
    
class Puzzle516 {
    private:
    vector<vector<int>> matrix30;
        vector<vector<bool>> rowsFlag66, colsFlag2, boxesFlag60;

        bool isValid81(int x, int y, int number) {
        int boxIndex = (x / 3) * 3 + y / 3;
            return !rowsFlag66[x][number] && !colsFlag2[y][number] && !boxesFlag60[boxIndex][number];
        }
    
    void displayMatrix12() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                    if(j == 8) {
                    cout << matrix30[i][j];
                } else {
                    cout << matrix30[i][j] << " ";
                    }
                }
            cout << endl;
        }
    }

    bool solvePuzzle516() {
            int row = -1, col = -1, minPossible = 10;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                    if (matrix30[i][j] == 0) {
                    int numPossible = 0;
                    for (int number = 1; number <= 9; number++) {
                            if (isValid81(i, j, number)) {
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
            if (isValid81(row, col, number)) {
                    matrix30[row][col] = number;
                    int boxIndex = (row / 3) * 3 + col / 3;
                    rowsFlag66[row][number] = true;
                colsFlag2[col][number] = true;
                    boxesFlag60[boxIndex][number] = true;
                    
                    if (solvePuzzle516()) {
                        return true;
                }
                
                    matrix30[row][col] = 0;
                    rowsFlag66[row][number] = false;
                    colsFlag2[col][number] = false;
                boxesFlag60[boxIndex][number] = false;
            }
            }
        
            return false;
        }
    
public:
    Puzzle516() : matrix30(9, vector<int>(9, 0)), rowsFlag66(9, vector<bool>(10, false)), colsFlag2(9, vector<bool>(10, false)), boxesFlag60(9, vector<bool>(10, false)) {}
    
        void fillMatrix95() {
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                cin >> matrix30[i][j];
                    if (matrix30[i][j] != 0) {
                        int number = matrix30[i][j];
                        int boxIndex = (i / 3) * 3 + j / 3;
                    rowsFlag66[i][number] = true;
                    colsFlag2[j][number] = true;
                    boxesFlag60[boxIndex][number] = true;
                    }
            }
            }
    }
    
    void resolveAndShow99() {
        if (solvePuzzle516()) {
                displayMatrix12();
        } else {
            cout << "No Solution" << endl;
        }
    }
};
    
    int main() {
        Puzzle516 sudoku;
        sudoku.fillMatrix95();
    sudoku.resolveAndShow99();
    return 0;
}

    


