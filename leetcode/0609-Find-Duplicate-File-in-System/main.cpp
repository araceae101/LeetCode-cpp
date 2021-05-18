/*
* Problem: https://leetcode.com/problems/find-duplicate-file-in-system/
* My Discussion: 
*/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (auto &p : paths) {
            istringstream ss(p);
            string dir, str;
            ss >> dir;
            while (ss >> str) {
                string filename, content;
                for (int i = 0; i < str.size(); ++i) {
                    if (str[i] == '(') {
                        filename = str.substr(0, i);
                        content = str.substr(i+1);
                        m[content].push_back(dir + '/' + filename);
                        break;
                    }
                }
            }
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it)
            if (it->second.size() > 1)
                res.push_back(it->second);
        return res;
    }
};