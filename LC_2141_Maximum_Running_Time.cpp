
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, r = 1e14;

        while (l < r) {
            long long mid = (l + r + 1) / 2;
            long long total = 0;

            for (auto b : batteries)
                total += min((long long)b, mid);

            if (total >= mid * n) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
