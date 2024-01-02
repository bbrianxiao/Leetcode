class Solution {
public:
    vector<int> psa;
    Solution(vector<int>& w) {
        for (auto n : w) {
            psa.push_back(n + (psa.empty() ? 0 : psa.back()));
        }
    }
    
    int pickIndex() {
        float randnum = (float) rand() / RAND_MAX;
        randnum = randnum * psa.back();
        return lower_bound(psa.begin(), psa.end(), randnum) - psa.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */