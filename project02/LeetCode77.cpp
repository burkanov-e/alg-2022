class Solution {
   public:
    vector<vector<int>> result;
    void combination(int valForI, int k, int n, vector<int> &ans) {
        if (k == 0) {
            result.push_back(ans);
        } else {
            for (int i = valForI; i <= n; i++) {
                ans.push_back(i);
                combination(i + 1, k - 1, n, ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;

        combination(1, k, n, ans);

        return result;
    }
};