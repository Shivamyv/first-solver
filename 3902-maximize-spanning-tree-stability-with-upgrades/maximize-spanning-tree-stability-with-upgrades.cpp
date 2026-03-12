class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1);
     for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
     }
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void UnionBysize(int u,int v){
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
  bool check(int n, vector<vector<int>>& edges, int k,int mid){
      DisjointSet ds(n);
        vector<vector<int>> upgradeCandidates;
     for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int s=it[2];
            int m=it[3];
            if(m==1){
                if(s<mid) return false;
            
            ds.UnionBysize(u,v);
     }
     else{
        if(s>=mid){
            ds.UnionBysize(u,v);
        }
     
     else if(2*s>=mid){
        upgradeCandidates.push_back({u, v});
     }
     }
     }

  


  for(auto it:upgradeCandidates){
    int u=it[0];
    int v=it[1];
     if(ds.findUpar(u)!=ds.findUpar(v)){
        if(k<=0) return false;
        ds.UnionBysize(u,v);
        k--;

     }
  }
     int root=ds.findUpar(0);
     for(int i=1;i<=n-1;i++){
        if(ds.findUpar(i)!=root) return false;
        
     }
 return true;
  }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DisjointSet ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int s=it[2];
            int m=it[3];
         if(m==1){
            if(ds.findUpar(u)==ds.findUpar(v)) return -1;

         
           ds.UnionBysize(u,v);
         }
        }
      
        int result=-1;
       int l=1,r=2*1e5;

       while(l<=r){
          int mid=l+(r-l)/2;
           if(check(n,edges,k,mid)){
            result=mid;
            l=mid+1;
           }
           else{
           r=mid-1;
           }
       }
   return result;
    }
};