class Solution {
public:
long long ans=0;
   array<int,21>solve(int u,int p,vector<vector<int>>&g,vector<int>&tot,vector<int>&grp){

array<int,21>cur{};
cur[grp[u]]=1;
for(int x:g[u]){
    if(x==p) continue;
    auto c=solve(x,u,g,tot,grp);

    for(int i=1;i<=20;i++){
        if(tot[i]){
            ans+=1L*c[i]*(tot[i]-c[i]);
        }
            cur[i]+=c[i];
        }
    }
    return cur;

   }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {  
   vector<vector<int>>g(n);
   for(auto x: edges){
    g[x[0]].push_back(x[1]);
    g[x[1]].push_back(x[0]);

   }
   vector<int>tot(21,0);
   for(int x: group) tot[x]++;
   solve(0,-1,g,tot,group);
   return ans;
      

        
    }
};