class DisjointSet{
public:
    vector<int>size,parent;
    DisjointSet(int n){
       size.resize(n+1);
       parent.resize(n+1);
       for(int i=0;i<=n;i++){
        size[i]=i;
        parent[i]=i;
       }

    }
  int findUpar(int node){
       if(node==parent[node]) return node;
       return parent[node]=findUpar(parent[node]);
  }
   void unionBysize(int u,int v){
       int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
   }

};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int m=stones[0].size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
       
        }
         DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>stone;
      for(auto it:stones){
        int noderow=it[0];
        int nodecol=it[1]+maxrow+1;
        ds.unionBysize(noderow,nodecol);
        stone[noderow]=1;
        stone[nodecol]=1;
      }

    int cnt=0;
    for(auto it:stone){
        if(ds.findUpar(it.first)==it.first){
            cnt++;
        }
    }
        return n-cnt;
    }
};