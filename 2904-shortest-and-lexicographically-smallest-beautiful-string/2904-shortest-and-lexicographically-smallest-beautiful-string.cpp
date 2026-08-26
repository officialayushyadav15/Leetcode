class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }
        if (ones < k) return "";

        int l = 0, r = 0;
        string ans = "";
        int minLen = s.length() + 1;
        ones = 0;

        while (r < s.length()) {
            if (s[r] == '1') ones++;

            while (l < r && ones > k) {
                if (s[l] == '1') ones--;
                l++;
            }

            while (l < r && s[l] == '0') l++;

            if (ones == k) {
                int currLen = r - l + 1;
                string curr = s.substr(l, currLen);
                if (minLen > currLen) {
                    minLen = currLen;
                    ans = curr;
                } else if (minLen == currLen) {
                    if (curr < ans) {
                        ans = curr;
                    }
                }
            }
            r++;
        }
        return ans;
    }
};