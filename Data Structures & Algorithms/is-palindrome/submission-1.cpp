class Solution {
   public:
    bool isPalindrome(string s) {
        int i = 0, n = s.length(), j = s.length() - 1;
        while (i < j) {
            // if not alphaNum skip
            while (i < j && !isAlphaNum(s[i])) {
                i++;
            }
            while (j > i && !isAlphaNum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool isAlphaNum(char ch) {
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
    }
};
