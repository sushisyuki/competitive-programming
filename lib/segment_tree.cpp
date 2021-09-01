#include <bits/stdc++.h>

using namespace std;

template <typename Monoid>
class SegmentTree
{
private:
    int n;
    vector<Monoid> data;
    Monoid identity;
    function<Monoid(Monoid, Monoid)> op;
    function<Monoid(Monoid, Monoid)> ch;

    Monoid query(int a, int b, int k, int l, int r) 
    {
        if(r <= a || b <= l) return identity;
        if(a <= l && r <= b) return data[k];
        Monoid c1 = query(a, b, 2*k+1, l, (l+r)/2);
        Monoid c2 = query(a, b, 2*k+2, (l+r)/2, r);
        return op(c1, c2);
    }

public:
    SegmentTree<Monoid>(int n, Monoid identity, function<Monoid(Monoid, Monoid)> op, function<Monoid(Monoid, Monoid)> ch)
    : identity(identity), op(op), ch(ch)
    {
        nodes = 1;
        while(nodes < n) nodes *= 2;
        data = vector<Monoid>(2*nodes-1, identity);
    }

    void update(int idx, Monoid new_value)
    {
        idx += n-1;
        data[idx] = ch(data[idx], new_value);
        while(idx > 0)
        {
            idx = (idx-1)/2;
            data[idx] = op(data[idx*2+1], data[idx*2+2]);
        }
    }

    Monoid query(int a, int b)
    {
        return query(a, b, 0, 0, n);
    }

    Monoid operator[](int idx)
    {
        return data[idx+n-1];
    }
};

/*
SegmentTree<int> st(5, INF, 
    [](int a, int b) { return min(a, b); },
    [](int a, int b) { return b; }
);
*/

template <typename Monoid>
class LazySegmentTree
{
private:
    int n;
    vector<Monoid> data;
    vector<Monoid> lazy;
    Monoid identity;
    function<Monoid(Monoid, Monoid)> op;
    function<Monoid(Monoid, Monoid)> ch;

    Monoid query(int a, int b, int k, int l, int r) 
    {
        eval(k);
        if(r <= a || b <= l) return identity;
        if(a <= l && r <= b) return data[k];
        Monoid c1 = query(a, b, 2*k+1, l, (l+r)/2);
        Monoid c2 = query(a, b, 2*k+2, (l+r)/2, r);
        return op(c1, c2);
    }

    void eval(int k)
    {
        if(lazy[k] == identity) return;
        if(k < n-1)
        {
            lazy[k*2+1] = lazy[k];
            lazy[k*2+2] = lazy[k];
        }
        data[k] = ch(data[k], lazy[k]);
        lazy[k] = identity;
    }

    void update(int a, int b, Monoid x, int k, int l, int r)
    {
        eval(k);
        if(a <= l && r <= b)
        {
            lazy[k] = x;
            eval(k);
        }
        else if(a < r && l < b)
        {
            update(a, b, x, k*2+1, l, (l+r)/2);
            update(a, b, x, k*2+2, (l+r)/2, r);
            data[k] = op(data[k*2+1], data[k*2+2]);
        }
    }

public:
    LazySegmentTree<Monoid>(int nodes, Monoid identity, function<Monoid(Monoid, Monoid)> op, function<Monoid(Monoid, Monoid)> ch)
    : identity(identity), op(op), ch(ch)
    {
        n = 1;
        while(n < nodes) n *= 2;
        data = vector<Monoid>(2*n-1, identity);
        lazy = vector<Monoid>(2*n-1, identity);
    }

    void update(int idx, Monoid new_value)
    {
        idx += n-1;
        data[idx] = ch(data[idx], new_value);
        while(idx > 0)
        {
            idx = (idx-1)/2;
            data[idx] = op(data[idx*2+1], data[idx*2+2]);
        }
    }

    void update(int a, int b, Monoid x)
    {
        update(a, b, x, 0, 0, n);
    }

    Monoid query(int a, int b)
    {
        return query(a, b, 0, 0, n);
    }

    Monoid operator[](int idx)
    {
        return data[idx+n-1];
    }
};

/*
SegmentTree<int> st(5, INF, 
    [](int a, int b) { return min(a, b); },
    [](int a, int b) { return b; }
);
*/