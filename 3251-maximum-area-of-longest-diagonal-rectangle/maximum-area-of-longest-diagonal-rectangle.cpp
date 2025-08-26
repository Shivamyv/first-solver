class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       int n=dimensions.size();
       int m=dimensions[0].size();
       int length=0;
       int width=0;
       double maxdiag=0.0;
       double diaglen=0.0;
       int maxarea=0;
        
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         length=dimensions[i][0];
         width=dimensions[i][1];
      diaglen=sqrt((length*length)+(width*width));
        int area=length*width;
        if(diaglen>maxdiag){
            maxdiag=diaglen;
            maxarea=area;
        }
        else if(maxdiag==diaglen){
            maxarea=max(maxarea,area);
        }
    
        }
       } 
       return maxarea;

        
    }
};