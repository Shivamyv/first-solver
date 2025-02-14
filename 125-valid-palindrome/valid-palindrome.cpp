class Solution{	
	public:		
		bool isPalindrome(string& s){
		 int n=s.size();
         int l=0,r=n-1;
        if(s[l]==0 && s[r]==0) return false;
         while(l<=r){
             while (l < r && !isalnum(s[l])) l++;
            // Move the right pointer to the previous alphanumeric character
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            
           l++,r--;
             
         }
            
                return true;
         
		}
        
};