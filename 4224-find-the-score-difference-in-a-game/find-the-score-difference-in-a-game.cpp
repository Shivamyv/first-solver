class Solution {
public:
    int scoreDifference(vector<int>& nums) {
       int n=nums.size();
       int player1=0;
       int player2=0;
       bool firstactive=true;
       for(int i=0;i<n;i++){
        if(nums[i]%2==1){
            firstactive=!firstactive;

        }
       if((i+1)%6==0){
        firstactive=!firstactive;
       }
        if(firstactive){
            player1+=nums[i];
        }
         else{
            player2+=nums[i];
         }

       } 
    return player1-player2;


    }
};
