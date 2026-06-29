class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string pat : patterns) {
            int left = 0;
            int right = pat.length();

            while (right <= word.length()) {
                if (pat == word.substr(left, right - left)) {
                    count++;
                    break;
                }

                left++;
                right++;
            }
        }

        return count;
    }
};