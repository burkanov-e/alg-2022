class Solution {
   public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;

        for (const auto &it : s) {
            mp[it]++;
        }

        int comp = mp[s[0]];

        for (const auto &it : mp) {
            if (it.second != comp) {
                return false;
            }
        }

        return true;
    }
};