class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int m=tasks[0].size();
        int task=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                    int sum=tasks[i][j]+tasks[i][j+1];
                    task=min(task,sum);
                
            }
        }
       
   return task;
    }
};