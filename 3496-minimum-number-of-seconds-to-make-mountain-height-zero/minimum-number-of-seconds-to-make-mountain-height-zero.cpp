class Solution {
public:
typedef long long ll;
   bool check(int mh, vector<int>& workerTimes,ll mid){
     ll h=0;
     for(int &t:workerTimes){
        h+=(ll)(sqrt(2.0*mid/t+0.25)-0.5);
        if(h>=mh) return true;

     }

    return h>=mh;

   }


    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n=workerTimes.size();
        int maxtime=*max_element(workerTimes.begin(),workerTimes.end());

        ll l=1;
        ll r=(ll)maxtime*mountainHeight*(mountainHeight+1)/2;
      ll result=0;

        while(l<=r){
            ll mid=l+(r-l)/2;
            if(check(mountainHeight,workerTimes,mid)){
                result=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }

        }



   return result;




    }
};