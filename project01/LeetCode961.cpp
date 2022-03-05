class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> sets;
        for (int i = 0; i != nums.size(); i++) {
            if (sets.find(nums[i]) == sets.end()) {
                sets.insert(nums[i]);
            } else {
                return nums[i];
            }
        }
        return sets.size();
    }
};