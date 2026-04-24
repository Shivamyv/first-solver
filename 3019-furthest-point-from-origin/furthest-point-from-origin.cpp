class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int l=0,r=0,spec=0;
        int ans=0;
        for(char ch:moves){
            if(ch=='R') r++;
            else if(ch=='L') l++;
            else spec++;

        }
        ans=abs(r-l);
        ans+=abs(spec);
        return ans;

    }
};