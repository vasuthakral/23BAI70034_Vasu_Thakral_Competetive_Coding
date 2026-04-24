
long long solve_case(vector<long long>& a) {
    auto calc = [&](long long target) {
        long long odd = 0, even = 0;
        for (auto x : a) {
            long long diff = target - x;
            odd += diff % 2;
            even += diff / 2;
        }

        if (odd > even) return odd * 2 - 1;
        return max(odd * 2, even * 2);
    };

    long long mx = *max_element(a.begin(), a.end());
    return min(calc(mx), calc(mx + 1));
}
