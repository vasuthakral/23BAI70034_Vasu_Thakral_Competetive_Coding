
vector<long long> solve(vector<pair<long long,long long>>& segments) {
    int n = segments.size();
    map<long long, long long> mp;

    for (auto &seg : segments) {
        mp[seg.first]++;
        mp[seg.second + 1]--;
    }

    vector<long long> ans(n + 1, 0);

    long long cur = 0, prev = 0;

    for (auto &[x, v] : mp) {
        if (cur > 0) ans[cur] += x - prev;
        cur += v;
        prev = x;
    }

    return ans;
}
