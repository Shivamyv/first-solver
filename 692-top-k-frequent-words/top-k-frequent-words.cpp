class Solution {
public:
class comp {
    public:
        bool operator()(pair<int,string>& a, pair<int,string>& b){
            if(a.first == b.first)
                return a.second < b.second; 
            return a.first > b.first;       
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mpp;
        for(auto it:words){
            mpp[it]++;
        }
        vector<string>ans;

        priority_queue
        <pair<int,string>,
        vector<pair<int,string>>,
        comp>pq;
        for(auto ite:mpp){
            pq.push({ite.second,ite.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;

    }
};