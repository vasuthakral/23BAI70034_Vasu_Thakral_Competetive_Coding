
int solve(vector<int>& a) {
    int n = a.size();
    vector<int> cnt(n + 1, 0);

    for (int x : a) cnt[x]++;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum <= n && cnt[sum] > 0) {
                ans += cnt[sum];
                cnt[sum] = 0;
            }
        }
    }

    return ans;
}
