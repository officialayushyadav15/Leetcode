class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
       
        vector<int>extra(n);
        for(int i=0;i<n;i++)extra[i] = i;


        vector<vector<int>>adj(n);
        for(vector v : invocations){
            adj[v[0]].push_back(v[1]);
        }
        set<int>sus;
        
        stack<int>st;
        st.push(k);
        vector<int>vis(n);

        while(!st.empty()){
            int node = st.top();
            vis[node] = 1;
            st.pop();
            sus.insert(node);
            for(int i : adj[node]){
                if(!vis[i])st.push(i);
            }

        }
        set<int>ans;

        for(int i=0;i<n;i++){
            if(!sus.count(i))ans.insert(i);
        }

        int m = ans.size();

        vector<int>vis1(n);
        for(vector v : invocations){
            if(!sus.count(v[0]))st.push(v[0]);
        }
        while(!st.empty()){
            int node = st.top();
            st.pop();
            vis1[node] = 1;
            ans.insert(node);
            for(int i : adj[node]){
                if(!vis1[i])st.push(i);
            }
        }

        if(ans.size() > m)return extra;

        vector<int>ans1;
        for(int i : ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};