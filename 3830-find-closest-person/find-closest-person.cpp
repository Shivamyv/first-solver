class Solution {
public:
    int findClosest(int x, int y, int z) {
        int ans=0;
        int p1=0;
        int p2=0;
        p1=abs(z-x);
        p2=abs(z-y);
        if(p1<p2)  return 1;
        else if(p1>p2) return 2;
        return 0;

    }
};