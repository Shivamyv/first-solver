class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>dist(n+1,vector<int>(2,INT_MAX));
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        dist[1][0]=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int currtime=it.first;
            int node=it.second;
            if(currtime > dist[node][1]) continue;
            for(int next:adj[node]){
                int departtime=currtime;
                int cycle=departtime/change;
                if(cycle%2==1){
                departtime=(cycle+1)*change;
                }
           int newtime= departtime+time;
           if(newtime<dist[next][0]){
            dist[next][1]=dist[next][0];
            dist[next][0]=newtime;
            pq.push({newtime,next});
           }
           else if( newtime >dist[next][0] && newtime<dist[next][1]){
           dist[next][1]=newtime;
           pq.push({newtime,next});


        }
          
              }
                }
    

    return dist[n][1];

    }
};