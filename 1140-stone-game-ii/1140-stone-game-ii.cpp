class Solution {
public:
    int solve(int i, int M,int n,vector<int>& suffix,vector<vector<int>>& dp) {
        if (i >= n) return 0;
        if (dp[i][M] != -1) return dp[i][M];

        int ans = 0;
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int totalRemaining = suffix[i];
            int opponent = solve(i + X, max(M, X),n,suffix,dp);
            int current = totalRemaining - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
        
        return solve(0, 1,n,suffix,dp);
    }
};