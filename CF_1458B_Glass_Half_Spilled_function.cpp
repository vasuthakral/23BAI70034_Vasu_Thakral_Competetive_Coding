
vector<double> solve(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int sum = accumulate(a.begin(), a.end(), 0);

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1e9));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (int k = 0; k <= sum - a[i]; k++) {
                if (dp[j][k] >= 0) {
                    dp[j + 1][k + a[i]] = max(dp[j + 1][k + a[i]], dp[j][k] + b[i]);
                }
            }
        }
    }

    vector<double> result(n + 1);

    for (int i = 1; i <= n; i++) {
        double best = 0;
        for (int k = 0; k <= sum; k++) {
            if (dp[i][k] >= 0) {
                best = max(best, min((double)k, (double)dp[i][k] / 2));
            }
        }
        result[i] = best;
    }

    return result;
}
