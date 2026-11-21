class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        auto assign_parents = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = last_seen[c];
            if (prev != -1) {
                new_parent[u] = prev;
            }
            last_seen[c] = u;

            for (int v : children[u]) {
                self(self, v);
            }

            last_seen[c] = prev;
        };

        assign_parents(assign_parents, 0);

        vector<vector<int>> new_children(n);
        for (int i = 1; i < n; ++i) {
            new_children[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        auto calc_size = [&](auto& self, int u) -> int {
            for (int v : new_children[u]) {
                ans[u] += self(self, v);
            }
            return ans[u];
        };

        calc_size(calc_size, 0);
        return ans;
    }
};
