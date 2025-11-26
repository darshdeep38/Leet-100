class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(m > n) return {};
        
        vector<int> freqP(26, 0), freqS(26, 0);
        vector<int> result;

        // Build initial frequency of p
        for(char c : p) freqP[c - 'a']++;

        // Sliding window
        for(int i = 0; i < n; i++) {
            // Add current char to window
            freqS[s[i] - 'a']++;

            // Remove char left of window when window > m
            if(i >= m)
                freqS[s[i - m] - 'a']--;

            // If window size == m and both freq match → anagram found
            if(freqS == freqP)
                result.push_back(i - m + 1);
        }

        return result;
    }
};
