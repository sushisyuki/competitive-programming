#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Edge
{
    int to;
    T val;
};

template <class T>
class Graph
{
public:
    Graph(int n)
    {
        nodes = n;
        data.resize(n);
    }

    /**
     * @brief ダイクストラ法 O( |E|log|V| ) 
     * @param[in] s 始点
     * @param[out] d 始点からの距離
     * @param[in] unit ゼロ元
     * @param[in] max_unit minに対する単位元
     */
    void djikstra(int s, vector<T> &d, T unit, T max_unit)
    {
        fill(d.begin(), d.end(), max_unit);
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
        d[s] = unit; q.push(make_pair(d[s], s));
        while(!q.empty())
        {
            pair<T, int> p = q.top(); q.pop();
            T dist = p.first;
            int idx = p.second;
            if(dist > d[idx]) continue;
            for(Edge<T> e: data[idx])
            {
                if(d[e.to] > dist+e.val)
                {
                    d[e.to] = dist+e.val;
                    q.push(make_pair(d[e.to], e.to));
                }
            }
        }
    }

    int getNodes() const { return nodes; }

    void setEdge(int from, int to, T val) { data[from].push_back(Edge<T>({to, val})); }

private:
    int nodes;
    vector<vector<Edge<T>>> data;
};