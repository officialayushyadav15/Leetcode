#include <bits/stdc++.h>
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int s;
        sort(arr.begin(), arr.end());
        s = 0;
        for(int i=0;i<arr.size();i++){
            s = min(s+1,arr[i]);
        }
        return s;
    }
};
/*
Time Complexity: O(n log n)
- Sorting the array takes O(n log n)
- Single loop takes O(n)

Space Complexity: O(1)
- No extra space used (ignoring sorting space)
*/