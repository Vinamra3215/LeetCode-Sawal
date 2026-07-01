/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    void trav(unordered_map<int, Employee*>& mp, int id, int& sum) {
        Employee* emp = mp[id];
        
        sum += emp->importance;
        
        for (auto sub_id : emp->subordinates) {
            trav(mp, sub_id, sum);
        }
    }
    
public:
    int getImportance(vector<Employee*> e, int id) {
        unordered_map<int, Employee*> mp;
        for (auto emp : e) {
            mp[emp->id] = emp;
        }
        if (mp.find(id) == mp.end()) return 0;

        int sum = 0;
        
        // Step 2: Run your exact recursive traversal using the map
        trav(mp, id, sum);
        
        return sum;
    }
};