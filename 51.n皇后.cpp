/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
public:
    // 最坏时间复杂度仍然是 O(N^(N+1))
    vector<vector<string>> solveNQueens(int n) {
        // 初始化棋盘，全部设置为.
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    // 路径：board中小于row的行都应成功放置了皇后
    // 选择列表：第row的所有列都是放置皇后的选择（不合法的选择）
    // 结束条件：row超过board最后一行
    void backtrack(vector<string>& board, int row) {
        // 触发结束条件
        if(row == board.size()) {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for(int col=0; col<n; col++) {
            // 不合法的列
            if(!isValid(board, row, col))
                continue;
            
            // 做选择：在(row,col)放置皇后
            board[row][col] = 'Q';

            // 下一层决策树
            backtrack(board, row+1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

    // 是否可以在board[row][col]放置皇后
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后冲突
        for(int i=0; i<n; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // 检查右上方是否有皇后冲突
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        // 检查左上方是否有皇后冲突
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

private:
    vector<vector<string>> res;
};
// @lc code=end

