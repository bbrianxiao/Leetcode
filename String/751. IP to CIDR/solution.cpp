class Solution {
public:
    string toCIDR(unsigned int binRep, int step) {
        return to_string((binRep >> 24) & 255) + "." +
               to_string((binRep >> 16) & 255) + "." +
               to_string((binRep >> 8) & 255) + "." +
               to_string(binRep & 255) + "/" +
               to_string(32 - (int)log2(step));
    }

    vector<string> ipToCIDR(string ip, int n) {
        vector<string> retval;
        unsigned int binRep = 0;
        int j = 0;
        for (int i = 0; i <= ip.size(); i++) {
            if (ip[i] == '.' || i == ip.size()) {
                string temp = ip.substr(j, i - j);
                binRep = (binRep << 8) + stoi(temp);
                j = i + 1;
            }
        }
        while (n > 0) {
            unsigned int step = binRep & -binRep;
            if (step == 0 || step > n) {
                step = 1 << (31 - __builtin_clz(n));
            }
            retval.push_back(toCIDR(binRep, step));
            binRep += step;
            n -= step;
        }
        return retval;
    }
};