class SnapshotArray {
private:
    vector<vector<pair<int, int>>> history;
    int snap_id;
public:
    SnapshotArray(int length) {
        snap_id = 0;
        history.resize(length);

        for (int i = 0; i < length; i++) {
            history[i].push_back({0, 0});
        }
    }

    void set(int index, int val) {
        auto &arr = history[index];

        if (arr.back().first == snap_id) {
            arr.back().second = val;
        }
        else {
            arr.push_back({snap_id, val});
        }
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto &arr = history[index];

        int low = 0;
        int high = arr.size() - 1;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid].first <= snap_id) {
                ans = arr[mid].second;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */