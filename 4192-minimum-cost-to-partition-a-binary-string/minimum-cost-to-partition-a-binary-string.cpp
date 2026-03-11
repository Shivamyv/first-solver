class Solution {
public:
     
    long long f(int l,int r,string &s,int encCost,int flatCost,vector<int>&prefix){
        int n=s.size();
        int L=r-l+1;
        int X=prefix[r];
        if(l>0) X-= prefix[l-1];
       long long nosplit_cost;
       if(X==0) nosplit_cost=flatCost;
       else{
        nosplit_cost=1LL*L*X*encCost;
       }
       if(L%2==1) return nosplit_cost;
       
        int mid=(l+r)/2;
     long long cost_split=f(l,mid,s,encCost,flatCost,prefix)+f(mid+1,r,s,encCost,flatCost,prefix);
     return min(cost_split,nosplit_cost);

    }
    long long minCost(string s, int encCost, int flatCost) {
         int n=s.size();
         vector<int>prefix(n);
       prefix[0]=(s[0]=='1');
       for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+(s[i]=='1');
       }

    return f(0,n-1,s,encCost,flatCost,prefix);

    }
};