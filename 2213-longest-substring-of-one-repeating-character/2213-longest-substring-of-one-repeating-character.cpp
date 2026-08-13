class Solution {
public:

    struct Node {
        char lc, rc;

        int len;
        int pref;
        int suff;
        int best;

        Node() {
            lc = rc = '#';
            len = 0;
            pref = suff = best = 0;
        }

        Node(char c) {
            lc = rc = c;
            len = 1;
            pref = suff = best = 1;
        }
    };

    Node merge(Node a, Node b) {

        if(a.len == 0)
            return b;

        if(b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;

        res.lc = a.lc;
        res.rc = b.rc;

        // Best answer from either side
        res.best = max(a.best, b.best);

        // Prefix
        res.pref = a.pref;

        if(a.pref == a.len && a.rc == b.lc) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        if(b.suff == b.len && a.rc == b.lc) {
            res.suff = b.len + a.suff;
        }

        // Middle combination
        if(a.rc == b.lc) {
            res.best = max(
                res.best,
                a.suff + b.pref
            );
        }

        return res;
    }


    void build(int node, int l, int r, string &s) {

        if(l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }


    void update(int node, int l, int r, int idx, char c) {

        if(l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid) {
            update(node * 2, l, mid, idx, c);
        }
        else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }


    vector<Node> tree;


    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};