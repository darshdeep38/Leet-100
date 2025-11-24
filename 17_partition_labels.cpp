class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Step 1: Record the last index of every character in the string
        vector<int> last(26, 0);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        // Step 2: Greedily form partitions
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']); // Extend the current partition if needed

            // When i reaches the farthest last occurrence → partition ends
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1; // Next partition begins
            }
        }

        return result;
    }
};
