class Solution {
public:
    int dp_max[101][101], dp_way[101][101];
    int mod = 1000000007;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        dp_max[n - 1][n - 1] = 0;
        dp_way[n - 1][n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (board[n - 1][i] == 'X')
                break;
            else {
                dp_max[n - 1][i] = board[n - 1][i] - '0' + dp_max[n - 1][i + 1];
                dp_way[n - 1][i] = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (board[i][n - 1] == 'X')
                break;
            else {
                dp_max[i][n - 1] = board[i][n - 1] - '0' + dp_max[i + 1][n - 1];
                dp_way[i][n - 1] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (board[i][j] == 'X')
                    dp_max[i][j] = 0, dp_way[i][j] = 0;

                else {
                    int mx = max(dp_max[i][j + 1], dp_max[i + 1][j]);
                    mx = max(mx, dp_max[i + 1][j + 1]);
                    dp_max[i][j] = board[i][j] + mx - '0';
                    dp_way[i][j] =
                        (dp_way[i][j] +
                         ((mx == dp_max[i + 1][j]) ? dp_way[i + 1][j] : 0)) %
                        mod;
                    dp_way[i][j] = (dp_way[i][j] + ((mx == dp_max[i + 1][j + 1])
                                                        ? dp_way[i + 1][j + 1]
                                                        : 0)) %
                                   mod;
                    dp_way[i][j] =
                        (dp_way[i][j] +
                         ((mx == dp_max[i][j + 1]) ? dp_way[i][j + 1] : 0)) %
                        mod;
                }
            }
        }
        if (dp_way[0][0] == 0)
            dp_max[0][0] = 'E' - '0';
        return {dp_max[0][0] - 'E' + '0', dp_way[0][0]};
    }
};