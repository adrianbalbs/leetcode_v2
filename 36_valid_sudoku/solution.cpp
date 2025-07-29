#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_map<int, unordered_set<char>> rows, cols, squares;
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (board[row][col] != '.' &&
                    (rows[row].count(board[row][col]) > 0 ||
                     cols[col].count(board[row][col]) > 0 ||
                     squares[(row / 3) * 3 + (col / 3)].count(board[row][col]) >
                         0)) {
                    return false;
                }
                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
                squares[(row / 3) * 3 + (col / 3)].insert(board[row][col]);
            }
        }
        return true;
    }
};
