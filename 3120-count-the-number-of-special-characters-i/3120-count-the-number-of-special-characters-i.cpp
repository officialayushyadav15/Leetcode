class Solution {
public:
    int numberOfSpecialChars(string word) {
        int a = 0, b = 0;
        for (auto& it : word) {
            if (it >= 'a' && it <= 'z') {
                a |= (1 << (it - 'a'));
            } else {
                b |= (1 << (it - 'A'));
            }
        }

        int ans = 0;
        while (a && b) {
            if (a & b & 1)
                ans++;
            a >>= 1;
            b >>= 1;
        }
        return ans;
    }
};