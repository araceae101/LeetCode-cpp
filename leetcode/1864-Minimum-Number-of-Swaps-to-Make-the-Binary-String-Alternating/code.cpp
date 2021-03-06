/*
* Problem: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
* My Discussion: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/discuss/1211271/C++-two-pointers-simple-O(N)
*/

class Solution {
    int findStep(string& s, int oneStart) {
        int n = s.size();
        // generate target Alternating String
        string tar(n, '0');
        for (int i = oneStart; i < n; i+=2)    tar[i] = '1';
    
        // two-pointer approach to count the difference between original string and target string
        int left = 0, right = n-1;
        int res = 0;
        while (left < right) {
            while (left < n && s[left] == tar[left])    ++left;
            while (right >=0 && s[right] == tar[right]) --right;
            if (left > right)   break;
            ++res;
            ++left; --right;
        }
        return res;
    }
public:
    int minSwaps(string s) {
        int n = s.size();
        // calculate the cout of '1' and '0' in the string, respectively
        int one = 0;
        for (auto &c : s)   one += c == '1' ? 1 : 0;
        int zero = n - one;
        if (abs(one - zero) > 1)    return -1;
        
        // find the minimun step of swap
        if (one > zero) return findStep(s, 0);
        else if (zero > one)    return findStep(s, 1);
        
        return min(findStep(s, 0), findStep(s, 1));
    }
};