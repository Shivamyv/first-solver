class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        // predefine case
        if(n==k)return arr;

        vector<int>ans;

        // find position of X in array
        int lo=0,hi=n-1;
        int maybe=lo+(hi-lo)/2;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]>x){
                if(abs(arr[maybe]-x)>abs(arr[mid]-x))maybe=mid;
                else if(abs(arr[maybe]-x)==abs(arr[mid]-x))maybe=min(maybe,mid);
                hi=mid-1;
            }
            else if(arr[mid]<x){
                if(abs(arr[maybe]-x)>abs(arr[mid]-x))maybe=mid;
                else if(abs(arr[maybe]-x)==abs(arr[mid]-x))maybe=min(maybe,mid);
                lo=mid+1;
            }
            else if(arr[mid]==x){
                maybe=mid;
                break;
            }
        }

        // if X present ho
        ans.emplace_back(arr[maybe]);
        k--;
        int prev=maybe-1;
        int next=maybe+1;
        while(prev>=0 && next<n && k>0){
            if(abs(arr[prev]-x)<=abs(arr[next]-x)){
                ans.emplace_back(arr[prev]);
                prev--;
                k--;
            }
            else if(abs(arr[prev]-x)>abs(arr[next]-x)){
                ans.emplace_back(arr[next]);
                next++;
                k--;
            }
        }
        if(k>0 && prev==-1){
            while(k>0){
                ans.emplace_back(arr[next]);
                next++;
                k--;
            }
        }
        else if(k>0 && next==n){
            while(k>0){
                ans.emplace_back(arr[prev]);
                prev--;
                k--;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};