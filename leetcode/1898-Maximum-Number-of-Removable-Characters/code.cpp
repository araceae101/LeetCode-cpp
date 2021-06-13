// use binary search
// and use memset to avoid wasting time for creating extra space

// Problem: https://leetcode.com/problems/maximum-number-of-removable-characters/


class Solution {
    int rm[100001];
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size();
        while (l < r) {
            int m = (l + r + 1) / 2;
            
            memset(rm, 0, sizeof(rm));
            for (int i = 0; i < m; ++i)    rm[removable[i]] = 1;
            
            int j = 0;
            for (int i = 0; i < s.size() && j < p.size(); ++i)
                if (s[i] == p[j] && rm[i] == 0)   ++j;
            if (j == p.size())  l = m;
            else    r = m-1;
        }
        return l;
    }
};