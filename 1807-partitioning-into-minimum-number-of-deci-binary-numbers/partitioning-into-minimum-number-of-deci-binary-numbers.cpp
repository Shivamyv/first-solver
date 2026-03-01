class Solution {
public:
    int minPartitions(string n) {
       char max=*max_element(n.begin(),n.end());
       return max-'0'; 

    }
};