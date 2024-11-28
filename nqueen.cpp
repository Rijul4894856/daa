#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row)
            cout << (cell ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1, n) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueensUtil(board, 0, n))
        cout << "No solution exists for " << n << " queens." << endl;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
