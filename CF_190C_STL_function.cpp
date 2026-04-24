
string solve(vector<string>& v) {
    int n = v.size();
    stack<string> st;

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == "int") st.push("int");
        else {
            if (st.size() < 2) return "Error occurred";

            string a = st.top(); st.pop();
            string b = st.top(); st.pop();

            st.push("pair<" + a + "," + b + ">");
        }
    }

    if (st.size() != 1) return "Error occurred";
    return st.top();
}
