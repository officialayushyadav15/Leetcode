class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        if (stones.size() == 1) {
            return false;
        }
        std::array<int, 3> histo;
        histo.fill(0);
        for (int val : stones) {
            ++histo[val % 3];
        }
        if ((histo[1] == 0) && (histo[2] == 0)) {
            return false;
        }
        if (histo[0] % 2 == 0) {
            return (histo[1] > 0) && (histo[2] > 0); 
        }
        return std::abs(histo[1] - histo[2]) > 2;
    }
};