class Solution {
public:
    double myPowHelper(double x, int64_t n) {
        if (n == 0) return 1;
        double retval = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                retval *= x;
                n--;
            }
            x = x * x;
            n /= 2;
        }
        return retval;
    }
    double myPow(double x, int n) {
        double retval = myPowHelper(x, abs(n));
        return n < 0 ? (double) (1 / retval) : retval;
    }
};