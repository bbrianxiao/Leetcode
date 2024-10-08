class SnapshotArray {
    vector<vector<pair<int, int>>> snapshot;
    int snap_id = 0;
public:
    SnapshotArray(int length) {
        snapshot.resize(length);
        for (int i = 0; i < length; i++) {
            snapshot[i].push_back({snap_id, 0});
        }
    }
    
    void set(int index, int val) {
        snapshot[index].push_back({snap_id, val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(snapshot[index].begin(), snapshot[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */