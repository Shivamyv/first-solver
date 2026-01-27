class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
      int n=passingFees.size();
      vector<vector<pair<int,int>>>adj(n);
      for(auto it:edges){
        int x=it[0],y=it[1],time=it[2];
        adj[x].push_back({y,time});
        adj[y].push_back({x,time});

      }
      priority_queue<pair<int,pair<int,int>>,
      vector<pair<int,pair<int,int>>>,
      greater<pair<int,pair<int,int>>>>pq;

      vector<int>vis(n,0);
      vector<int>minTime(n,INT_MAX);
       minTime[0]=0;
      pq.push({passingFees[0],{0,0}});
      
      while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        int cost=node.first;
        int time=node.second.first;
        int city=node.second.second;
        if(city==n-1) return cost;

      for(auto it:adj[city]){
        int neighbor=it.first;
        int travelTime=it.second;
        int newTime=time+travelTime;
       if(newTime<=maxTime && newTime <minTime[neighbor]){
        minTime[neighbor]=newTime;
        int newCost=cost+passingFees[neighbor];
        pq.push({newCost,{newTime,neighbor}});
       }



      }


      }
      



   return -1;



    }
};