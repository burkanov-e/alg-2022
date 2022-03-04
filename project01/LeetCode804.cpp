class Solution {
   public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        unordered_set<string> uniqueTransformations;

        for (const auto& w : words) {
            string transformation;

            for (auto c : w) {
                transformation += codes[c - 'a'];
            }
            uniqueTransformations.insert(transformation);
        }

        return uniqueTransformations.size();
    }
};