class segment{
    public:
    vector<int> v_m;
    vector<int> v_r;
    vector<int> v_l;
    int size;
    segment(int n){
        size   = n;
        v_m.resize(4*n);
        v_r.resize(4*n);
        v_l.resize(4*n);
        build(0,n-1,0);
    }
    int  build(int l,int r,int ind ){
        v_r[ind] = 0;
        v_l[ind] = 0;
        if(l==r){
            v_l[ind] = l;
            v_r[ind] = size-l-1;
            v_m[ind] = l;
            return l;
        }
        int mid = (l+r)/2;
        int x = build(l,mid,2*ind+1);
        int y = build(mid+1,r,2*ind+2);
        v_m[ind] = max(x,y);
        return v_m[ind];

    }
    int ld(int l,int r,int ind,int s,int tar){
        

        if(l==r){
            return s + v_l[ind];

        }
        int mid = (l+r)/2;
        if(tar>mid){
            return ld(mid+1,r,2*ind+2,s + v_l[ind],tar);
        }
        else 
        return ld(l,mid,2*ind+1,s + v_l[ind],tar);

    }
    int rd(int l,int r,int ind,int s,int tar){
        

        if(l==r){
            return s + v_r[ind];

        }
        int mid = (l+r)/2;
        if(tar>mid){
            return rd(mid+1,r,2*ind+2,s + v_r[ind],tar);
        }
        else 
        return rd(l,mid,2*ind+1,s + v_r[ind],tar);

    }
    void subl(int x,int y,int ind ,int m,int n,int val){
        if(x==m && y == n){
            v_m[ind] -= val;
            v_l[ind] += -val;
            return ;

        }
        int mid = (m+n)/2;
        if(y>mid){
            subl(max(mid+1,x),y,2*ind+2,mid+1,n,val);
        }
        if(x<=mid){
            subl(x,min(mid,y),2*ind+1,m,mid,val);
        }
        v_m[ind] = max(v_m[2*ind+1],v_m[2*ind+2])+v_l[ind];
        return ;

    }
    void subr(int x,int y,int ind ,int m,int n,int val){
        if(x==m && y == n){
            v_r[ind] += -val;return ;

        }
        int mid = (m+n)/2;
        if(y>mid){
            subr(max(mid+1,x),y,2*ind+2,mid+1,n,val);
        }
        if(x<=mid){
            subr(x,min(mid,y),2*ind+1,m,mid,val);
        }
        return ;

    }
    void insert(int x){
        int left = x-ld(0,size-1,0,0,x);
        int right = x+rd(0,size-1,0,0,x);
        subr(left,x-1,0,0,size-1,right-x);
        subl(x+1,right,0,0,size-1,x-left);

    }
    int  query2(int x,int y,int ind,int m,int n,int val){
        if(m==x && n == y){
            return val+v_m[ind];
        }
        int mid  = (m+n)/2;
        int res = INT_MIN;
        if(y>mid){
            res = max(query2(max(mid+1,x),y,2*ind+2,mid+1,n,val+v_l[ind]),res);
        }
        if(x<=mid){
            res = max(query2(x,min(mid,y),2*ind+1,m,mid,val+v_l[ind]),res);
        }
        return res;

    }
    
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> res;
        int k = (1+min(5 * 10000,3*n));
        segment s(k);
        for(int i = 0;i<n;i++){
            if(queries[i][0] == 1){
                s.insert(queries[i][1]);
            }
            else{
                int r = s.query2(0,queries[i][1],0,0,k-1,0);
                if(r>=queries[i][2]){
                    res.push_back(1);
                }
                else{
                    res.push_back(0);
                }
            }
        }
        return res;

        
    }
};