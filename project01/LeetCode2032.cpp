class Solution {
   public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;

        for (auto& s : {nums1, nums2, nums3}) {
            unordered_set<int> set(s.begin(), s.end());
            for (auto& x : set) {
                ++mp[x];
            }
        }

        vector<int> ans;
        for (auto& [key, val] : mp) {
            if (val >= 2) {
                ans.push_back(key);
            }
        }
        return ans;
    }
};