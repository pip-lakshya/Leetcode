class Solution {
    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(string &s) {
            n = s.size();
            tree.assign(4 * n, 0);
            build(1, 0, n - 1, s);
        }

        void build(int node, int l, int r, string &s) {
            if (l == r) {
                tree[node] = 1 << (s[l] - 'a');
                return;
            }
            int mid = (l + r) / 2;
            build(node * 2, l, mid, s);
            build(node * 2 + 1, mid + 1, r, s);
            tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
        }

        void update(int node, int l, int r, int pos, int val) {
            if (l == r) {
                tree[node] = val;
                return;
            }
            int mid = (l + r) / 2;
            if (pos <= mid)
                update(node * 2, l, mid, pos, val);
            else
                update(node * 2 + 1, mid + 1, r, pos, val);
            tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) return tree[node];
            if (r < ql || l > qr) return 0;
            int mid = (l + r) / 2;
            return query(node * 2, l, mid, ql, qr) ^
                   query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        void update(int pos, int val) {
            update(1, 0, n - 1, pos, val);
        }

        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n), sz(n, 1);
        vector<int> heavy(n, -1), head(n), pos(n);
        int timer = 0;

        function<void(int, int)> dfs1 = [&](int u, int p) {
            parent[u] = p;
            int largest = 0;
            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs1(v, u);
                sz[u] += sz[v];
                if (sz[v] > largest) {
                    largest = sz[v];
                    heavy[u] = v;
                }
            }
        };

        function<void(int, int)> dfs2 = [&](int u, int h) {
            head[u] = h;
            pos[u] = timer++;
            if (heavy[u] != -1) dfs2(heavy[u], h);
            for (int v : adj[u]) {
                if (v == parent[u] || v == heavy[u]) continue;
                dfs2(v, v);
            }
        };

        dfs1(0, -1);
        dfs2(0, 0);

        string base(n, 'a');
        for (int u = 0; u < n; u++) base[pos[u]] = s[u];

        SegTree seg(base);
        vector<bool> ans;

        auto pathXor = [&](int u, int v) {
            int mask = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) swap(u, v);
                mask ^= seg.query(pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            mask ^= seg.query(pos[u], pos[v]);
            return mask;
        };

        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                s[u] = c;
                seg.update(pos[u], 1 << (c - 'a'));
            } else {
                int v;
                ss >> v;
                int mask = pathXor(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};