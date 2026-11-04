class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();


        if(target < matrix[0][0]) return false;
        if(target > matrix[ROWS - 1][COLS - 1]) return false;
        
        int top = 0;
        int bot = ROWS - 1;

        // search which row it is in
        while(top <= bot) {
            int row = top + (bot - top) / 2;
            if(target > matrix[row][COLS - 1]) {
                top = row + 1;
            } else if (target < matrix[row][0]) {
                bot = row - 1;
            } else { 
                break;
            }
        }

        if(!(top <= bot)) { // valid found
            return false;
        }

        int row = top + (bot - top) / 2;

        int l = 0;
        int r = COLS - 1;
        // binary search suspect row
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(matrix[row][mid] < target) {
                l = mid + 1;
            } else if (matrix[row][mid] > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
