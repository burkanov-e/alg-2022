class Solution {
   public:
    string kthDistinct(vector<string> &arr, int k) {
        unordered_map<string, int> map;
        int curr = 0;
        for (auto &it : arr) {
            map[it]++;
        }
        for (auto &it : arr) {
            if (map[it] < 1) {
                continue;
            }
            curr++;
            if (curr == k) {
                return it;
            }
        }
        return "";
    }
};