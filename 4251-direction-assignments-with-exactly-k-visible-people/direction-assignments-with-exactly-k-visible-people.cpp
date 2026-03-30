class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    void init(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        int L = pos;
        int R = n - pos - 1;

        init(n);

        long long ans = 0;

        for (int x = 0; x <= L; x++) {
            if (k - x >= 0 && k - x <= R) {
                long long ways = (nCr(L, x) * nCr(R, k - x)) % MOD;
                ans = (ans + ways) % MOD;
            }
        }

        return (ans * 2) % MOD;
    }
};