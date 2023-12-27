class NumArray {
private:
    vector<int> pref;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pref.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return pref[right];
        else return pref[right] - pref[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */