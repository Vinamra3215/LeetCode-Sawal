class Solution {
private:
    // Helper function to calculate the number of distinct permutations
    // of a set of characters given their frequencies.
    // It returns the count, capped at 1000001 to prevent overflow since k <= 10^6.
    long long countPermutations(int length, const vector<int>& freqs) {
        long long ways = 1;
        int current_len = 0;
        
        for (int count : freqs) {
            if (count == 0) continue;
            
            // Mathematically compute (current_len + count) Choose (count)
            // Example: To interleave 'b' (count 3) into an existing sequence of 'a's (length 5)
            // we calculate 8 C 3.
            for (int i = 1; i <= count; i++) {
                ways = ways * (current_len + i) / i;
                if (ways > 1000001) return 1000001; // Cap to avoid overflow
            }
            current_len += count;
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        char mid_char = 0;
        int half_length = 0;
        vector<int> half_freq(26, 0);
        
        // Find the middle character (if odd) and build the frequency array for the first half
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                mid_char = i + 'a';
            }
            half_freq[i] = freq[i] / 2;
            half_length += half_freq[i];
        }
        
        // If the total possible permutations are less than k, return ""
        long long total_perms = countPermutations(half_length, half_freq);
        if (total_perms < k) {
            return "";
        }
        
        string first_half = "";
        
        // Greedily build the first half character by character
        for (int i = 0; i < half_length; i++) {
            for (int c = 0; c < 26; c++) {
                if (half_freq[c] > 0) {
                    // Try placing character 'c' here
                    half_freq[c]--;
                    
                    // How many permutations can we make with the remaining characters?
                    long long ways = countPermutations(half_length - 1 - i, half_freq);
                    
                    if (ways >= k) {
                        // The k-th permutation falls within this branch!
                        // Lock in character 'c' and move to the next position in the string.
                        first_half += (char)(c + 'a');
                        break; 
                    } else {
                        // The k-th permutation is NOT in this branch.
                        // Skip these 'ways' combinations, restore the character, and try the next letter.
                        k -= ways;
                        half_freq[c]++;
                    }
                }
            }
        }
        
        // Build the final string: First Half + Mid (if exists) + Reversed First Half
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
        if (mid_char != 0) {
            return first_half + mid_char + second_half;
        }
        
        return first_half + second_half;
    }
};