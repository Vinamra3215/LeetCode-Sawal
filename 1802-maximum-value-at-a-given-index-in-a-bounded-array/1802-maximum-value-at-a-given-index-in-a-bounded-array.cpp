class Solution {
    long long getSum(long long count, long long val) {
        if (count == 0) return 0;
        
        if (count <= val) {
            return count * (val + (val - count + 1)) / 2;
        } else {
            long long remaining_ones = count - val;
            return (val * (val + 1) / 2) + remaining_ones;
        }
    }

public:
    int maxValue(int n, int i, int m) {
        long long low = 1; 
        long long high = m;
        long long ans = 1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = mid;
            long long right_count = n - 1 - i;
            sum += getSum(right_count, mid - 1);
            long long left_count = i; // 'i' elements to the left of index 'i'
            sum += getSum(left_count, mid - 1);
            
            if (sum <= m) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};