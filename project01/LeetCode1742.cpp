class Solution {
   public:
    int sum(int x) {
        int ans = 0;
        while (x > 0) {
            int n = x % 10;
            ans += n;
            x = x / 10;
        }

        return ans;
    }

    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp;

        for (int i = lowLimit; i < highLimit; i++) {
            int count = sum(i);
            ++mp[count];
        }

        int ans = 0;

        for (auto &e : mp) {
            ans = max(ans, e.second);
        }

        return ans;
    }
};