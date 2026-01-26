class Solution {
public:
void dfs(int node,int par,int time,vector<int> &dis,
 vector<vector<int>> &adj){
    dis[node]=time;
    for(auto child:adj[node]){
        if(child!=par){
            dfs(child,node,time+1,dis,adj);
        }
    }
}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

    
        vector<vector<int>>adj(n);
      for(auto &e:edges){
        int u=e[0];
        int v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
     vector<int>dx(n),dy(n),dz(n);
     dfs(x,-1,0,dx,adj);
      dfs(y,-1,0,dy,adj);
      dfs(z,-1,0,dz,adj);

     int ans=0;

     for(int i=0;i<n;i++){
        long long a=dx[i],b=dy[i],c=dz[i];
        vector<long long>v={a,b,c};
        sort(v.begin(),v.end());
        if(v[0]*v[0]+v[1]*v[1]==v[2]*v[2]){
            ans++;
        }
     }


   return ans;


    }
};