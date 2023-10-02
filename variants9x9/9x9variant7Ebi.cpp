    #include <iostream>
    #include <vector>
    
    using namespace std;

    class Puzzle683 {
    private:
    vector<vector<int>> matrix44;
    vector<vector<bool>> rowsFlag20, colsFlag18, boxesFlag31;

    bool isValid23(int x, int y, int number) {
            int boxIndex = (x / 3) * 3 + y / 3;
        return !rowsFlag20[x][number] && !colsFlag18[y][number] && !boxesFlag31[boxIndex][number];
    }

    void displayMatrix65() {
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if(j == 8) {
                        cout << matrix44[i][j];
                    } else {
                        cout << matrix44[i][j] << " ";
                }
            }
            cout << endl;
            }
    }
    
    bool solvePuzzle683() {
            int row = -1, col = -1, minPossible = 10;
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (matrix44[i][j] == 0) {
                    int numPossible = 0;
                    for (int number = 1; number <= 9; number++) {
                            if (isValid23(i, j, number)) {
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
                if (isValid23(row, col, number)) {
                matrix44[row][col] = number;
                    int boxIndex = (row / 3) * 3 + col / 3;
                    rowsFlag20[row][number] = true;
                colsFlag18[col][number] = true;
                boxesFlag31[boxIndex][number] = true;
                    
                    if (solvePuzzle683()) {
                        return true;
                    }
                
                    matrix44[row][col] = 0;
                rowsFlag20[row][number] = false;
                colsFlag18[col][number] = false;
                    boxesFlag31[boxIndex][number] = false;
                }
        }
            
        return false;
        }
    
public:
    Puzzle683() : matrix44(9, vector<int>(9, 0)), rowsFlag20(9, vector<bool>(10, false)), colsFlag18(9, vector<bool>(10, false)), boxesFlag31(9, vector<bool>(10, false)) {}
    
        void fillMatrix41() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> matrix44[i][j];
                if (matrix44[i][j] != 0) {
                        int number = matrix44[i][j];
                        int boxIndex = (i / 3) * 3 + j / 3;
                    rowsFlag20[i][number] = true;
                    colsFlag18[j][number] = true;
                    boxesFlag31[boxIndex][number] = true;
                }
            }
            }
        }
    
        void resolveAndShow65() {
            if (solvePuzzle683()) {
                displayMatrix65();
            } else {
                cout << "No Solution" << endl;
            }
        }
    };

int main() {
        Puzzle683 sudoku;
        sudoku.fillMatrix41();
        sudoku.resolveAndShow65();
    return 0;
}
    



