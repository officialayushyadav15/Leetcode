class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = count(s.begin(), s.end(), '1');

        string paddedS = "1" + s + "1";
        vector<int> zeroRuns;

        int length = 0;

        for (char c : paddedS) {
            if (c == '0') {
                length++;
            } else if (length > 0) {
                zeroRuns.push_back(length);
                length = 0;
            }
        }

        if (zeroRuns.size() < 2) {
            return ones;
        }

        int best = 0;

        for (int i = 0; i + 1 < zeroRuns.size(); i++) {
            best = max(best, zeroRuns[i] + zeroRuns[i + 1]);
        }

        return ones + best;
    }
};