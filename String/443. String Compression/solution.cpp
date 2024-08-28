class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0;
        int i = 0;

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

            chars[k++] = currentChar;
            
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[k++] = c;
                }
            }
        }
        
        return k;
    }
};
