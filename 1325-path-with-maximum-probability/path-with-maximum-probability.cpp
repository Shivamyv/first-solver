class Solution {
public:
double f(int n,int src,int end, vector<vector<pair<int,double>>>&adj){
    //  priority_queue<pair<double,int>,
    //  vector<pair<double,int>>,
    //  greater<pair<double,int>>>pq;
    priority_queue<pair<double,int>>pq;
      vector<double>dist(n,0.0);
     
     pq.push({1.0,src});
     dist[src]=1.0;
     while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        double cost=it.first;
        int node=it.second;
        if(node==end) return cost;
        for(auto &it:adj[node]){
            int newnode=it.first;
            double wt=it.second;
            double current=cost*wt;
            if(current>dist[newnode]){
                dist[newnode]=current;
                pq.push({current,newnode});
               
            }
        }
     }
     return 0.0;
}
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n+1);
       
         for(int i=0;i<edges.size();i++){
           
            int a=edges[i][0];
            int b=edges[i][1];

            adj[b].push_back({a,succProb[i]});
            adj[a].push_back({b,succProb[i]});
        }
        
        return f(n,start_node,end_node,adj);

        
    }
};