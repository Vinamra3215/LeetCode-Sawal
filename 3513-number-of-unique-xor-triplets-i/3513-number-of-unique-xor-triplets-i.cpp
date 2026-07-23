class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map <int,int> mp;
        int n = nums.size();
        if (n <= 2) return n;
        int k = 0;
        int t = n;
        bool flag = true;
        while (t) {
            if (t%2 != 0) flag = false;
            t /=2;
            k++;
        }
        if (flag) k++;
        return pow(2,k);
    }
};