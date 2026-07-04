class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] - x < x - arr[l]) {
                l++; 
            } 
            else {
                break;
            }
        }
        vector<int> a;
        for (int i = l; i < l + k; i++) {
            a.push_back(arr[i]);
        }
        
        return a;
    }
};