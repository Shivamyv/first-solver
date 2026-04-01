class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>order(n);
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int i,int j){
            return positions[i]<positions[j];
        });
        stack<int>st;
        for(int idx:order){
            if(directions[idx]=='R'){
                st.push(idx);
            }
            else{
                while(!st.empty() && healths[idx]>0){
                    int top=st.top();
                    if(healths[top]<healths[idx]){
                        st.pop();
                        healths[idx]--;
                        healths[top]=0;

                    }
                    else if(healths[top]>healths[idx]){
                        healths[top]--;
                        healths[idx]=0;
                        break;
                    }
                    else{
                        st.pop();
                    healths[top]=0;
                    healths[idx]=0;
                    break;
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(healths[i]>0)
            ans.push_back(healths[i]);
        }
      
    return ans;

    }
};