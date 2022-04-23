class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        generate(res, nums, 0);
        return res;
    }

    void generate(vector<vector<int>>& res, vector<int>& nums, size_t index) {
        if (index == nums.size()) {
            res.push_back(nums);
        } else {
            generate(res, nums, index + 1);

            for (size_t i = index + 1; i < nums.size(); i++) {
                swap(nums[index], nums[i]);
                generate(res, nums, index + 1);
                swap(nums[index], nums[i]);
            }
        }
    }
};