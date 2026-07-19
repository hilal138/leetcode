class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0) return 1;

        if (n % 2 == 0) {
            double ans = solve(x, n / 2);
            return ans * ans;
        } else {
            double ans = solve(x, n / 2);
            return ans * ans * x;
        }
    }

    double myPow(double x, int n) {
        long long m = n;

        if (m < 0) {
            x = 1 / x;
            m = -m;
        }

        return solve(x, m);
    }
};