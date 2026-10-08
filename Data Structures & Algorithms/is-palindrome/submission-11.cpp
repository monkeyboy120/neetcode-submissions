class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j) {
            while(!std::isalnum(s[i]) && i < j) {
                i++;
            }
            while(!std::isalnum(s[j]) && j > i) {
                j--;
            }
            if(std::tolower(s[i]) != std::tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }

        return true;
        
    }
};
