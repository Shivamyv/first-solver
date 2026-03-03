class DisjointSet{
public:
    vector<int>size,parent;
    DisjointSet(int n){
       size.resize(n+1);
       parent.resize(n+1);
       for(int i=0;i<=n;i++){
        size[i]=1;
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
private:
  bool isvalid(int newr,int newc,int n){
    return newr>=0 && newr<n && newc>=0 && newc<n;
  }
  public:

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n); // step 1 for making 
      for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==0) continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int ind=0;ind<4;ind++){
                int newr=row+dr[ind];
                int newc=col+dc[ind];
                if(isvalid(newr,newc,n) && grid[newr][newc]==1){
                    int nodeno=row*n+col;
                    int adjnodeno=newr*n+newc;
                    ds.unionBysize(nodeno,adjnodeno);
                }
            }
        }
      }
      //step2
      int mx=0;
      for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==1) continue;
          int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            set<int>components;
            for(int ind=0;ind<4;ind++){
                int newr=row+dr[ind];
                int newc=col+dc[ind];
             if(isvalid(newr,newc,n)){
                if(grid[newr][newc]==1){
                components.insert(ds.findUpar(newr*n+newc));
                }
             }
        }
        int sizetotal=0;
        for(auto it:components){
             sizetotal+=ds.size[it];
        }
         mx=max(mx,sizetotal+1);

        }

      }
      // for all the given matrix grid is 1;
     for(int celno=0;celno<n*n;celno++){
        mx=max(mx,ds.size[ds.findUpar(celno)]);
     }

       return mx; 

    }
};