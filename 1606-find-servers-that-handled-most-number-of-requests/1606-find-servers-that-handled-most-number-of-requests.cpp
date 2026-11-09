#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using std::vector;
using std::priority_queue;
using std::set;
using std::pair;
using std::greater;
using std::max_element;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Track the number of requests handled by each server
        vector<int> count(k, 0);
        
        // set stores available servers in sorted order
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        // Min-heap stores pairs of {free_time, server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        
        for (int i = 0; i < arrival.size(); ++i) {
            int curr_time = arrival[i];
            int curr_load = load[i];
            
            // Release all servers that have finished their tasks by the current arrival time
            while (!busy.empty() && busy.top().first <= curr_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // If all servers are currently busy, drop the request
            if (available.empty()) {
                continue;
            }
            
            // Try to find the preferred server (i % k) or the next available one
            int target = i % k;
            auto it = available.lower_bound(target);
            
            // If no server >= target is available, wrap around to the beginning
            if (it == available.end()) {
                it = available.begin();
            }
            
            int server_id = *it;
            
            // Assign the request to the found server
            count[server_id]++;
            busy.push({curr_time + curr_load, server_id});
            available.erase(it);
        }
        
        // Find the maximum number of requests handled by any server
        int max_req = *max_element(count.begin(), count.end());
        
        // Collect all busiest servers
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_req) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
