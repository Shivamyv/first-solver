// class Solution {
// public:
//     int xorAfterQueries(vector<int>& nums, 
//     vector<vector<int>>& queries) {
//         int n=nums.size();
//         int q=queries.size();
//          vector<int>ans;
//           int mod=1e9+7;
        
//        for(int i=0;i<q;i++){
//        int l= queries[i][0],r=queries[i][1],
//        k=queries[i][2],v=queries[i][3];
       
       
       
//         for(int idx=l;idx<=r;idx+=k){
//             nums[idx]=(1LL*nums[idx]*v)% mod ;
//         }
//        }
        
//       int cnt=0;
//         for(int i=0;i<n;i++){
//            cnt ^= nums[i];
//        }
//     return cnt;
        
//     }
// };

class Solution {
public:
    
    long long modPow(long long a, long long b, long long mod) {
        long long res = 1;
        a %= mod;
        while(b > 0) {
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, long long mod) {
        return modPow(a, mod-2, mod);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod1 = 1e9 + 7;
        int n = nums.size();

        vector<long long> vis(n+1,1);  
        vector<long long> vis2(n+2,1); 

        for(auto &it : queries){
            int u = it[0];
            int v = it[1];
            int k = it[2];
            int vv = it[3];

            if(k == 1){
                vis[u] = (1LL * vis[u] * vv) % mod1;
                if(v+1 < n+1) vis[v+1] = (vis[v+1] * modInverse(vv, mod1)) % mod1;
            }
            else if(k == 2){
                vis2[u] = (1LL * vis2[u] * vv) % mod1;
                if((v-u) % 2 == 0){
                    if(v+2 < n+2) vis2[v+2] = (vis2[v+2] * modInverse(vv, mod1)) % mod1;
                } else {
                    if(v+1 < n+2) vis2[v+1] = (vis2[v+1] * modInverse(vv, mod1)) % mod1;
                }
            }
            else {
                for(int i = u; i <= v; i += k){
                    nums[i] = (1LL * nums[i] * vv) % mod1;
                }
            }
        }

        for(int i = 2; i < n; i++){
            vis2[i] = (vis2[i-2] * vis2[i]) % mod1;
        }
        for(int i = 1; i < n; i++){
            vis[i] = (vis[i] * vis[i-1]) % mod1;
        }
        for(int i = 0; i < n; i++){
            vis[i] = (vis[i] * vis2[i]) % mod1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans ^ (1LL * vis[i] * nums[i]) % mod1);
        }

        return ans;
    }
};