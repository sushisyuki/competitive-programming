#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for(int i = 0; i < (n); i++)
#define REPS(i, n)  for(int i = 1; i <= (n); i++)
#define RREP(i, n)  for(int i = (n)-1; i >= 0; i--)
#define RREPS(i, n) for(int i = (n); i > 0; i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl

using ll  = long long;
using pi  = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.141592653589793;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

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

    int getNodes() const { return node_n; }

    void setEdge(int from, int to, T val) { adj[from].push_back(Edge<T>({to, val})); }

    Graph t()
    {
        Graph<T> gt(node_n);
        for(int i = 0; i < node_n; i++)
        {
            for(Edge<T> e: adj[i])
            {
                gt.setEdge(e.to, i, e.val);
            }
        }
        return gt;
    }

    void dfs(int n, int cnt, vector<bool> &visited, vector<int> &res)
    {
        visited[n] = true;
        res[n] = cnt;
        for(Edge<T> e: adj[n]) if(!visited[e.to]) dfs(e.to, cnt, visited, res);
    }

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

    // SCC
    vector<int> scc()
    {
        int cnt = 0;
        vector<bool> visited(node_n, false);
        vector<int> post(node_n, 0);
        for(int i = 0; i < node_n; i++) if(!visited[i]) dfs_postorder(i, cnt, visited, post);

        vector<int> order(node_n, 0);
        for(int i = 0; i < node_n; i++) order[post[i]] = i;

        Graph<T> gt = t();
        fill(visited.begin(), visited.end(), false);
        vector<int> res(node_n, 0);
        cnt = 0;
        for(int i = node_n-1; i >= 0; i--) if(!visited[order[i]]) gt.dfs(order[i], cnt, visited, res), cnt++;

        return res;
    }

protected:
    int node_n;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, M; cin >> N >> M;
    Graph<int> g(N);
    REP(i, M)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        g.setEdge(a, b, 0);
    }
    vi s = g.scc();
    vl c(N, 0);
    REP(i, N) c[s[i]]++;
    ll ans = 0;
    REP(i, N) ans += c[i]*(c[i]-1);
    cout << ans/2 << endl;
}