// use priority queue
// - always choose the station with maximun fuel

// Problem: https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int res = 0, idx = 0, range = startFuel;
        while (range < target) {
            while (idx < stations.size() && stations[idx][0] <= range)
                pq.push(stations[idx++][1]);
            if (pq.empty()) return -1;
            range += pq.top(); pq.pop();
            ++res;
        }
        
        return res;
    }
};