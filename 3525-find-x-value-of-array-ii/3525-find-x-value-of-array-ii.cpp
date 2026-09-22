class Solution {
public:
    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int K;
    vector<Node> seg;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        // Product of complete segment
        res.prod = (1LL * a.prod * b.prod) % K;

        // Prefixes completely inside left segment
        for (int r = 0; r < K; r++)
            res.cnt[r] = a.cnt[r];

        // Prefixes = complete left + prefix of right
        for (int r = 0; r < K; r++) {
            if (b.cnt[r] == 0)
                continue;

            int nr = (1LL * a.prod * r) % K;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int val) {
        Node res;

        res.prod = val % K;
        res.cnt[res.prod] = 1;

        return res;
    }

    void build(vector<int>& nums, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(nums, idx * 2, l, mid);
        build(nums, idx * 2 + 1, mid + 1, r);

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = makeNode(val);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        K = k;
        int n = nums.size();

        seg.resize(4 * n + 5);

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists for following queries
            update(1, 0, n - 1, index, value);

            // We need prefixes of nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};