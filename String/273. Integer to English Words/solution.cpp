class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        int groupIndex = 0;
        string retval = "";
        while (num > 0) {
            if (num % 1000 != 0) {
                int part = num % 1000;
                string groupResult = "";
                
                if (part >= 100) {
                    groupResult += ones[part/100] + " Hundred ";
                    part %= 100;
                }
                if (part >= 20) {
                    groupResult += tens[part/10] + " ";
                    part %= 10;
                }
                if (part > 0) {
                    groupResult += ones[part] + " ";
                }

                groupResult += thousands[groupIndex] + " ";
                retval = groupResult + retval;
            }
            num /= 1000;
            groupIndex++;
        }
        while (retval.back() == ' ') retval.pop_back();
        return retval;
    }
};