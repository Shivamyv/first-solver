class Solution {
public:
    bool checkPerfectNumber(int num) {
       int cnt=0;
    for(int i=1;i<num;i++){
        if(num%i==0){
            cnt+=i;
        }
    }
        if(cnt==num) return true;
    return false;
    }
};