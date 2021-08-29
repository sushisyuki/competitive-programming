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
        node_n = n;
        adj.resize(n);
    }

    vector<vector<Edge<T>>> adj;

    void setEdge(int from, int to, T val) { adj[from].push_back(Edge<T>({to, val})); }

    /**
     * @brief 逆グラフの生成
     */
    Graph t()
    {
        Graph<T> res(node_n);
        for(int i = 0; i < node_n; i++)
        {
            for(Edge<T> e: adj[i])
            {
                res.setEdge(e.to, i, e.val);
            }
        }
        return res;
    }

    /**
     * @brief 深さ優先探索
     * @param[in] n 始点
     * @param[in] cnt 順序番号
     * @param[in] visited 探索済みフラグ
     * @param[out] res 各頂点の順序
     */
    void dfs(int n, int &cnt, vector<bool> &visited, vector<int> &res)
    {
        visited[n] = true;
        res[n] = cnt;
        for(Edge<T> e: adj[n]) if(!visited[e.to]) dfs(e.to, cnt, visited, res);
    }

    /**
     * @brief 行きがけ順深さ優先探索
     * @param[in] n 始点
     * @param[in] cnt 順序番号
     * @param[in] visited 探索済みフラグ
     * @param[out] res 各頂点の順序
     */
    void dfs_preorder(int n, int &cnt, vector<bool> &visited, vector<int> &res)
    {
        visited[n] = true;
        res[n] = cnt++;
        for(Edge<T> e: adj[n]) if(!visited[e.to]) dfs_postorder(e.to, cnt, visited, res);
    }

    /**
     * @brief 帰りがけ順深さ優先探索
     * @param[in] n 始点
     * @param[in] cnt 順序番号
     * @param[in] visited 探索済みフラグ
     * @param[out] res 各頂点の順序
     */
    void dfs_postorder(int n, int &cnt, vector<bool> &visited, vector<int> &res)
    {
        visited[n] = true;
        for(Edge<T> e: adj[n]) if(!visited[e.to]) dfs_postorder(e.to, cnt, visited, res);
        res[n] = cnt++;
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
            for(Edge<T> e: adj[idx])
            {
                if(d[e.to] > dist+e.val)
                {
                    d[e.to] = dist+e.val;
                    q.push(make_pair(d[e.to], e.to));
                }
            }
        }
    }
    
    // LCA

    /**
     * @brief 強連結成分分解 O( |V|+|E| )
     * @return res 各頂点が属す強連結成分
     */
    void scc()
    {
        int cnt = 0;
        vector<bool> visited(node_n, false);

        vector<int> post(node_n, 0);
        for(int i = 0; i < node_n; i++) if(!visited[i]) dfs_postorder(i, cnt, visited, post);

        vector<int> order(node_n, 0);
        for(int i = 0; i < node_n; i++) order[post[i]] = i;

        Graph<T> gt = t();
        vector<int> res(node_n, 0);
        cnt = 0;
        fill(visited.begin(), visited.end(), false);
        for(int i = node_n-1; i >= 0; i--) if(!visited[order[i]]) gt.dfs(order[i], cnt, visited, res), cnt++;

        return res;
    }

public:
    int node_n;
};

template <class T>
class Tree : Graph<T>
{
public:
    Tree(int n)
    : Graph<T>(n)
    {

    }

    // 直径
    // プリム
    // クラスカル
private:
};