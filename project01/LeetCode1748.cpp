class Solution {
   public:
    int sumOfUnique(vector<int> &nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (auto &s : nums) {
            mp[s]++;
        }

        for (auto &s : mp) {
            if (s.second == 1) {
                ans += s.first;
            }
        }

        return ans;
    }
};