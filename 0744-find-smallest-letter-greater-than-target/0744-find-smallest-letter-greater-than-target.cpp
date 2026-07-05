class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        if (l[l.size()-1] <= t) return l[0];
        for (int i = 0; i < l.size(); i++) {
            if (l[i] > t) return l[i];
        }
        return '-1';
    }
};