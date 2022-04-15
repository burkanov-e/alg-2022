class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        generate(res, nums, 0, vector<int>());
        return res;
    }

    void generate(vector<vector<int>>& res, const vector<int>& nums, size_t index, vector<int> curSet) {
        if (nums.size() == index) {
            res.push_back(curSet);
        } else {
            generate(res, nums, index + 1, curSet);
            curSet.push_back(nums[index]);
            generate(res, nums, index + 1, curSet);
        }
    }
};