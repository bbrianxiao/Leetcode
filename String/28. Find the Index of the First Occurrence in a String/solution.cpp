class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        size_t pos = haystack.find(needle);
        if (pos != string::npos) {
            return pos;
        }
        return -1;
    }
};