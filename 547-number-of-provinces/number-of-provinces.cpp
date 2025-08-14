class Solution {
public:
void bfs(int node,vector<int>& vis,vector<vector<int>> &adj){
    vis[node]=1;
    
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(auto adjNodes: adj[i]) {
                
                if(vis[adjNodes] != 1) {
                    
                  
                    vis[adjNodes] = 1;
                    
                    
                    q.push(adjNodes);

            }
        }
    }

}
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
      vector<vector<int>> adj(n); 
      
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i != j && isConnected[i][j] == 1) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}

        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               
                cnt++;
                bfs(i,vis,adj);
            }
        }
        return cnt;

    }
};