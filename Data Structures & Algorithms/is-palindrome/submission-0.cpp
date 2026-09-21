class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 1) {return true;}

        int i = 0;
        int j = s.length() - 1;

        while(j >= i) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            j--;
            i++;
        }

        return true;
    }
};
