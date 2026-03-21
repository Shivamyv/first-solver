class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n=bank.size();
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>visited;

        
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(!q.empty()){
          auto[curr,time]=q.front();
           q.pop();
           if(curr==endGene) return time;
           for(char ch:"ACGT"){
            for(int i=0;i<curr.length();i++){
             string neighbour=curr;
             neighbour[i]=ch;

            if( visited.find(neighbour)==visited.end() &&
            bankset.find(neighbour)!=bankset.end()){
                visited.insert(neighbour);
                q.push({neighbour,time+1});

            }

            }
           } 


        }

   return -1;

    }
};