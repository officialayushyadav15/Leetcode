#include <bits/stdc++.h>
class Solution {
public:
    std::string lexGreaterPermutation(std::string s, std::string target) {
        std::string quinorath = s; 
        int n = s.length();
        std::vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        std::string match = "";
        std::vector<std::vector<int>> history_counts;
        history_counts.push_back(counts);
        int match_len = 0;
        for (int i = 0; i < n; ++i) {
            int idx = target[i] - 'a';
            if (counts[idx] > 0) {
                counts[idx]--;
                match_len++;
                history_counts.push_back(counts);
            } else {
                break;
            }
        }
        for (int i = match_len; i >= 0; --i) {
            std::vector<int> current_counts = history_counts[i];
            if (i == n) continue; 
            int target_char_idx = target[i] - 'a';
            for (int j = target_char_idx + 1; j < 26; ++j) {
                if (current_counts[j] > 0) {
                    std::string result = target.substr(0, i);
                    result += (char)('a' + j);
                    current_counts[j]--;
                    for (int k = 0; k < 26; ++k) {
                        while (current_counts[k] > 0) {
                            result += (char)('a' + k);
                            current_counts[k]--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
    }
};