#include "bits/stdc++.h"

using i64 = long long;

void print(auto edges, std::string msg)
{
    std::cout << msg << ":\n";
    long long mstWeight = 0;
    for (auto [u, v, w] : edges)
    {
        mstWeight += w;
        std::cout << u << " " << v << " " << w << "\n";
    }

    std::cout << "MST Weight: " << mstWeight << "\n";
}

class DSU
{
    std::vector<int> rnk, par;

public:
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x])
            x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);

            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
};

/**
 * Finds Minimum Spanning Tree using Kruskal Algorithm
 * Time Complexity: O((n + m) * log(n) * invAckerman(n))
 * Space Complexity: O(n + m)
 */
std::vector<std::array<int, 3>> kruskal(std::vector<std::vector<std::pair<int, int>>> &adj)
{
    int n = std::size(adj);
    std::vector<std::array<int, 3>> edges, mstEdges;

    for (int u = 0; u < n; u++)
    {
        for (auto [v, w] : adj[u])
            edges.push_back({u, v, w});
    }

    std::sort(std::begin(edges), std::end(edges),
              [&](std::array<int, 3> &a, std::array<int, 3> &b)
              {
                  return a[2] < b[2];
              });

    DSU dsu(n);

    for (auto &[u, v, w] : edges)
    {
        if (dsu.unite(u, v))
            mstEdges.push_back({u + 1, v + 1, w});
    }

    return mstEdges;
}

/**
 * Finds minimum spanning tree using Prim's Algorithm
 * Time Complexity: O((n + m) * log(n))
 * Space Complexity: O(n + m)
 */
std::vector<std::array<int, 3>> prims(std::vector<std::vector<std::pair<int, int>>> &adj)
{
    int n = std::size(adj);
    std::vector<int> inTree(n);

    std::priority_queue<std::array<int, 3>,
                        std::vector<std::array<int, 3>>,
                        std::greater<std::array<int, 3>>>
        pq;

    std::vector<std::array<int, 3>> mstEdges;

    inTree[0] = 1;
    for (auto [v, w] : adj[0])
        pq.push({w, v, 0});

    while (!pq.empty())
    {
        auto [w, u, p] = pq.top();
        pq.pop();

        if (inTree[u])
            continue;

        inTree[u] = 1;
        mstEdges.push_back({p + 1, u + 1, w});
        for (auto &[v, w] : adj[u])
            pq.push({w, v, u});
    }

    return mstEdges;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    auto mstEdgesKruskal = kruskal(adj);
    print(mstEdgesKruskal, "MST Found using Kruskal Algorithm");

    auto mstEdgesPrims = prims(adj);
    print(mstEdgesPrims, "MST found using Prims Algorithm");

    return 0;
}