
bool query(string s, unordered_set<string>& dict) {
    for (int i = 0; i < s.size(); i++) {
        char original = s[i];

        for (char c = 'a'; c <= 'c'; c++) {
            if (c == original) continue;

            s[i] = c;
            if (dict.count(s)) return true;
        }

        s[i] = original;
    }

    return false;
}
