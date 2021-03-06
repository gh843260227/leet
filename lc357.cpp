bool dp[1000000000];
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n)
            return 1;
        int len = pow(10,n);
        //bool dp[len];
        int i;
        for (i = 0;i < 10;i++) {
            dp[i] = true;
        }
        int count = 10;
        for (i = 10;i < len;i++)
        {
            if (!dp[i / 10]) {
                dp[i] = false;
                continue;
            }
            else {
                dp[i] = fun(i);
                count += dp[i];
            }
        }
        return count;
    }
    bool fun(int k)
    {
        int hash[10] = {0};
        while (k)
        {
            if (hash[k % 10])
                return false;
            else
                hash[k % 10] = 1;
            k /= 10;
        }
        return true;
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n)
            return 1;
        int dp[11];
        dp[0] = 10;
        dp[1] = 81;

        int i,count = 0;
        for (i = 2;i <= 10;i++)
        {
            dp[i] = dp[i-1] * (10 - i);
        }
        if (n <= 10) {
            for (i = 0;i < n;i++)
            {
                count += dp[i];
            }
        }
        else {
            for (i = 0;i <= 10;i++)
            {
                count += dp[i];
            }
        }
        return count;
    }
};
