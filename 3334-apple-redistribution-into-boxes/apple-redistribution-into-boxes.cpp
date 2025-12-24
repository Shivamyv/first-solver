class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        int sum=0;
        int cnt=0;
        int cap=0;
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<n;i++){
            sum+=apple[i];

        }
        for(int j=m-1;j>=0;j--){
            cap+=capacity[j];
            cnt++;
            if(cap >=sum){
                break;
            }
        }
      return cnt;

    }
};