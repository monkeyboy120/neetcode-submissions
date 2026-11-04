class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            while(i < j && !isalnum(s[i])) { // skip over non alphanumeric
                i++;
            }
            while(j > i && !isalnum(s[j])) { // skip over non alphanumeric
                j--;
            }

            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
