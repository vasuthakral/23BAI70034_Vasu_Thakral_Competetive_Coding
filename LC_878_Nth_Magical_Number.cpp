
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, r = 1e18;
        long long mod = 1e9 + 7;
        long long lcm = (long long)a / __gcd(a, b) * b;

        while (l < r) {
            long long mid = (l + r) / 2;
            if (mid / a + mid / b - mid / lcm >= n) r = mid;
            else l = mid + 1;
        }
        return l % mod;
    }
};
