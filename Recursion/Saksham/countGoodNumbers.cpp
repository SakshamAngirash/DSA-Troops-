class Solution {
public:
    const long long MOD = 1e9+7;

    long long myPow(long long x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x % MOD;

        long long half = myPow(x, n / 2) % MOD;
        long long result = (half * half) % MOD;

        if (n % 2 == 1) {
            result = (result * (x % MOD)) % MOD;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;  // positions with 5 choices
        long long oddPos  = n / 2;        // positions with 4 choices

        long long ans = (myPow(5, evenPos) * myPow(4, oddPos)) % MOD;
        return (int)ans;
    }
};
