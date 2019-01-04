string longestPalindrome(string s) {
    string res;
    bool found = false;
    for (int len = s.size(); len > 0 && !found; --len) {


        for (int i = 0; i <= s.size() - len; ++i) {
            string tmp = s.substr(i, len);

            bool isPalindromic = true;
            for (int i = 0; i < tmp.length() / 2; ++i) {
                if (tmp[i] != tmp[tmp.size() - i - 1]) {
                    isPalindromic = false;
                    break;
                }
            }
            if (isPalindromic) {
                res = tmp;
                found = true;
                break;
            }

        }
    }
    return res;
}
