class Solution {
public:


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
      vector<vector<pair<int,int>>>adj(n+1);
      for(auto &it:times){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});

      }
      priority_queue<pair<int,int>,
      vector<pair<int,int>>,
      greater<pair<int,int>>>pq;


     vector<int>dist(n+1,1e9);
     dist[k]=0;
     pq.push({0,k});

     while(!pq.empty()){
        int nodedist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(nodedist>dist[node]) continue;
        for(auto it:adj[node]){
            int neigh=it.first;
            int weight=it.second;

            if(dist[neigh]> nodedist+weight){
                dist[neigh]=nodedist+weight;
                pq.push({dist[neigh],neigh});
            }
        }
     }
     int ans=0;
     for(int i=1;i<=n;i++){
   if(dist[i]==1e9) return -1;
   ans=max(ans,dist[i]);
     }
return ans;
    }
};