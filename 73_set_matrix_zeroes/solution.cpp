#include <vector>

using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool is_row_zero = false;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == 0) {
                    if (row == 0) {
                        is_row_zero = true;
                    } else {
                        matrix[row][0] = 0;
                    }

                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < m; row++) {
            if (matrix[row][0] == 0) {
                for (int col = 0; col < n; col++) {
                    matrix[row][col] = 0;
                }
            }
        }

        for (int col = 0; col < n; col++) {
            if (matrix[0][col] == 0) {
                for (int row = 0; row < m; row++) {
                    matrix[row][col] = 0;
                }
            }
        }

        if (is_row_zero) {
            for (int col = 0; col < n; col++)
                matrix[0][col] = 0;
        }
    }
};
