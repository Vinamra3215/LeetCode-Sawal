#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int n = events.size();
        int cnt = 0;
        int i = 0;
        int current_day = 0; 
        priority_queue<int, vector<int>, greater<int>> pq;
        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                current_day = events[i][0];
            }
            while (i < n && events[i][0] <= current_day) {
                pq.push(events[i][1]); 
                i++;
            }
            while (!pq.empty() && pq.top() < current_day) {
                pq.pop();
            }
            if (!pq.empty()) {
                cnt++;
                pq.pop();
                current_day++; 
            }
        }
        
        return cnt;
    }
};