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