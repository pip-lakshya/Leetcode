class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        
        // free_heap stores {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_heap;
        for (int i = 0; i < n; ++i) {
            free_heap.push({servers[i], i});
        }
        
        // busy_heap stores {free_time, weight, index}
        // Using tuple: free_time (long long to prevent overflow), weight, index
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy_heap;
        
        long long current_time = 0;
        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);
            
            // Free up all servers that have finished their tasks by current_time
            while (!busy_heap.empty() && get<0>(busy_heap.top()) <= current_time) {
                auto [free_time, w, idx] = busy_heap.top();
                busy_heap.pop();
                free_heap.push({w, idx});
            }
            
            // If no servers are free, fast-forward time to the next available server release
            if (free_heap.empty()) {
                current_time = get<0>(busy_heap.top());
                while (!busy_heap.empty() && get<0>(busy_heap.top()) <= current_time) {
                    auto [free_time, w, idx] = busy_heap.top();
                    busy_heap.pop();
                    free_heap.push({w, idx});
                }
            }
            
            // Assign the task to the highest-priority free server
            auto [w, idx] = free_heap.top();
            free_heap.pop();
            
            ans[j] = idx;
            busy_heap.push({current_time + tasks[j], w, idx});
        }
        
        return ans;
    }
};
