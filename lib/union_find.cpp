#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        par.resize(n);
        for(int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x)
    {
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        par[rx] = ry;
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

private:
    vector<int> par;
};