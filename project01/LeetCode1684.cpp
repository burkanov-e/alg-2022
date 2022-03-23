class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> sets;

        for (auto c : allowed) {
            sets.insert(c);
        }

        int ans = words.size();

        for (auto& word : words) {
            for (auto c : word) {
                if (sets.find(c) == sets.end()) {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};