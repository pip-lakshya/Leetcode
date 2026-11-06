#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q_size = queries.size();
        vector<int> ans(q_size);
        
        // Store original indices of queries to sort them offline
        vector<int> query_indices(q_size);
        iota(query_indices.begin(), query_indices.end(), 0);
        
        sort(query_indices.begin(), query_indices.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });
        
        // Sort logs based on their arrival time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Map to keep track of active server request counts in the current window
        unordered_map<int, int> active_servers;
        
        int left = 0;
        int right = 0;
        int log_size = logs.size();
        
        // Process each query in increasing order of time
        for (int i = 0; i < q_size; ++i) {
            int q_idx = query_indices[i];
            int q_time = queries[q_idx];
            int window_start = q_time - x;
            
            // Expand the window to include all logs up to q_time
            while (right < log_size && logs[right][1] <= q_time) {
                active_servers[logs[right][0]]++;
                right++;
            }
            
            // Shrink the window to exclude all logs before window_start
            while (left < log_size && logs[left][1] < window_start) {
                int server_id = logs[left][0];
                active_servers[server_id]--;
                if (active_servers[server_id] == 0) {
                    active_servers.erase(server_id);
                }
                left++;
            }
            
            // Unused servers = Total servers - Active servers in the current window
            ans[q_idx] = n - active_servers.size();
        }
        
        return ans;
    }
};
