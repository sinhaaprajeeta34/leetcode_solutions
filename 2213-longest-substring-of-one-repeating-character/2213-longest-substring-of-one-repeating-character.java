class Solution {

    class Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            len = prefix = suffix = best = 0;
        }
    }

    Node[] tree;
    String s;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res = new Node();

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.len = a.len + b.len;

        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.best = Math.max(a.best, b.best);

        if (a.rightChar == b.leftChar) {

            // Combine suffix of left + prefix of right
            res.best = Math.max(
                res.best,
                a.suffix + b.prefix
            );

            // Entire left part is same character
            if (a.prefix == a.len) {
                res.prefix = a.len + b.prefix;
            }

            // Entire right part is same character
            if (b.suffix == b.len) {
                res.suffix = b.len + a.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node].leftChar = s.charAt(l);
            tree[node].rightChar = s.charAt(l);

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    void update(int node, int l, int r, int pos, char c) {

        if (l == r) {

            tree[node].leftChar = c;
            tree[node].rightChar = c;

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * node, l, mid, pos, c);
        } else {
            update(2 * node + 1, mid + 1, r, pos, c);
        }

        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    public int[] longestRepeating(
        String s,
        String queryCharacters,
        int[] queryIndices
    ) {

        this.s = s;

        int n = s.length();

        tree = new Node[4 * n];

        for (int i = 0; i < 4 * n; i++) {
            tree[i] = new Node();
        }

        build(1, 0, n - 1);

        int[] ans = new int[queryIndices.length];

        for (int i = 0; i < queryIndices.length; i++) {

            int pos = queryIndices[i];
            char c = queryCharacters.charAt(i);

            update(1, 0, n - 1, pos, c);

            ans[i] = tree[1].best;
        }

        return ans;
    }
}