class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        for(auto ele: s) freq[ele-'a']++;
        
        string ans = "";
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                int x =freq[i]/2;
                freq[i]-=2*x;
                while(x--) ans+=(i+'a');
            }
        }
        
        string temp = ans;
        for(int i=0;i<26;i++){
            if(freq[i]>0) ans+=(i+'a');
        }
        reverse(begin(temp),end(temp));
        return ans+temp;
    }
};