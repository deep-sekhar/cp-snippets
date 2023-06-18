class DisSet {
public:
    vector<int> sz, parent;

    DisjointSet(int n) {
        sz.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUpar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionbySize(int u, int v) {
        int u_v = findUpar(u);
        int u_u = findUpar(v);
        if (u_v == u_u) return;
        if (sz[u_u] >= sz[u_v]) {
            parent[u_v] = u_u;
            sz[u_u] += sz[u_v];
        } else {
            parent[u_u] = u_v;
            sz[u_v] += sz[u_u];
        }
    }
};
