#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <complex>
using namespace std;
using ll = long long;
const double PI = acos(-1);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}

#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}

// Custom Data Structures

struct MinStack{
    stack<pair<int, int>> stk;
    void add(int new_elem){
        stk.push({new_elem, stk.empty() ? new_elem : min(new_elem, stk.top().second)});
    }
    int remove(){
        int removed_element = stk.top().first;
        stk.pop();
        return removed_element;
    }
    int minimum(){
        return stk.top().second;
    }
};

struct MonoQueue{
    deque<int> dq;
    int minimum(){
        return dq.front();
    }
    void add(int new_element){
        while(!dq.empty() && dq.back() > new_element) dq.pop_back();
        dq.push_back(new_element);
    }
    void remove(int remove_element){
        if(!dq.empty() && dq.front() == remove_element) dq.pop_front();
    }
};

class DSU{
    private:
    vector<int> parent, size;
    int components;
    public:
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        components = n;
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
        }
    }
    int get_components(){
        return components;
    }
};

struct FenwickTree{
    vector<int> bit;
    int n;
    FenwickTree(int n) : n(n), bit(n, 0) {}
    FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
        for(int i = 0; i < n; i++){
            bit[i] += a[i];
            int next = i|(i + 1);
            if(next < n) bit[next] += bit[i];
        }
    }
    int sum(int r){
        int res = 0;
        while(r >= 0){
            res += bit[r];
            r = (r&(r + 1)) - 1;
        }
        return res;
    }
    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
    void add(int i, int delta){
        while(i < n){
            bit[i] += delta;
            i |= (i + 1);
        }
    }
};

struct FenwickTree2D{
    vector<vector<int>> bit;
    int n, m;
    FenwickTree2D(int n, int m) : n(n), m(m), bit(n, vector<int>(m, 0)) {}
    FenwickTree2D(vector<vector<int>> const &a) : FenwickTree2D(a.size(), a[0].size()){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bit[i][j] += a[i][j];
                int ii = i|(i + 1), jj = j|(j + 1);
                if(ii < n) bit[ii][j] += bit[i][j];
                if(jj < m) bit[i][jj] += bit[i][j];
                if(ii < n && jj < m) bit[ii][jj] -= bit[i][j];
            }
        }
    }
    int sum(int x, int y) {
        int res = 0;
        for(int i = x; i >= 0; i = (i&(i + 1)) - 1){
            for(int j = y; j >= 0; j = (j&(j + 1)) - 1){
                res += bit[i][j];
            }
        }
        return res;
    }
    int sum(int x1, int y1, int x2, int y2){
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }
    void add(int x, int y, int delta){
        for(int i = x; i < n; i = i|(i + 1)){
            for(int j = y; j < m; j = j|(j + 1)){
                bit[i][j] += delta;
            }
        }
    }
};

struct SparseTable{
    int n;
    vector<vector<int>> st;
    int K; 
    vector<int> lg;

    SparseTable(const vector<int>& a){
        n = (int)a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        K = lg[n];
        st.resize(K + 1);
        st[0] = a; 
        for(int i = 1; i <= K; i++){
            st[i].resize(n - (1 << i) + 1);
            for(int j = 0; j + (1 << i) <= n; j++){
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    ll sum(int L, int R){
        ll ans = 0;
        for(int i = K; i >= 0; i--){
            if((1 << i) <= R - L + 1){
                ans += st[i][L];
                L += 1 << i;
            }
        }
        return ans;
    }

    int minimum(int L, int R){
        int i = lg[R - L + 1];
        return min(st[i][L], st[i][R - (1 << i) + 1]);
    }

    int f(int a, int b){
        return a + b; 
        // return min(a, b);
    }
};

// Segment Trees

// Simple form (sum, min, max, gcd, lcm, ...)

struct SegmentTree {
    ll n;
    vector<ll> t;

    SegmentTree (ll m){
        n = m;
        t.assign(4*m, 0);
    }

    void build(const vector<ll>& a){
        build(a, 1, 0, n - 1);
    }

    void update(ll pos, ll new_val) {
        update(1, 0, n - 1, pos, new_val);
    }

    ll sum(ll l, ll r) {
        return sum(1, 0, n - 1, l, r);
    }

    ll minimum(ll l, ll r){
        return minimum(1, 0, n - 1, l, r);
    }

    void build(const vector<ll>& a, ll v, ll tl, ll tr) {
        if(tl == tr){
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);
            t[v] = t[v*2] + t[v*2 + 1];
            // t[v] = min(t[v*2] + t[v*2 + 1]);
        }
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if(tl == tr){
            t[v] = new_val;
        } else {
            ll tm = (tl + tr)/2;
            if(pos <= tm) update(v*2, tl, tm, pos, new_val);
            else update(v*2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[2*v] + t[2*v + 1];
            // t[v] = min(t[v*2] + t[v*2 + 1]);
        }
    }

    ll sum(ll v, ll tl, ll tr, ll l, ll r){
        if(l > tr || r < tl) return 0;
        if(l <= tl && tr <= r) return t[v];
        ll tm = (tl + tr)/2;
        return sum(v*2, tl, tm, l, r) + sum(v*2 + 1, tm + 1, tr, l, r);
    }

    ll minimum(ll v, ll tl, ll tr, ll l, ll r){
        if(l <= tl && r >= tr) return t[v];
        if(l > tr || r < tl) return LLONG_MAX;
        ll tm = (tl + tr)/2;
        return min(minimum(2*v, tl, tm, l, r), minimum(2*v + 1, tm + 1, tr, l, r));
    }
};

// Addition on segments

struct SegmentTree2 {
    ll n;
    vector<ll> t;

    SegmentTree2(ll k){
        n = k;
        t.assign(4*k, 0);
    }

    void build(const vector<ll>& a){
        build(a, 1, 0, n - 1);
    }

    void update(ll l, ll r, ll add){
        update(1, 0, n - 1, l, r, add);
    }

    ll get(ll pos){
        return get(1, 0, n - 1, pos);
    }

    void build(const vector<ll>& a, ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v + 1, tm + 1, tr);
            t[v] = 0;
        }
    }

    void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
        if(l > tr || r < tl) return;
        if(l <= tl && r >= tr){
            t[v] += add;
            return;
        }
        ll tm = (tl + tr)/2;
        update(2*v, tl, tm, l, r, add);
        update(2*v + 1, tm + 1, tr, l, r, add);
    }

    ll get(ll v, ll tl, ll tr, ll pos){
        if(tl == tr) return t[v];
        ll tm = (tl + tr)/2;
        if(pos <= tm) return get(2*v, tl, tm, pos) + t[v];
        return get(2*v + 1, tm + 1, tr, pos) + t[v];
    }
};

// Assignment on segments

struct SegmentTree3 {
    ll n;
    vector<ll> t;
    vector<bool> marked;

    SegmentTree3(ll k){
        n = k;
        t.assign(4*k, 0);
        marked.assign(4*k, false);
    }

    void build(ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = 0;
            marked[v] = true;
        } else {
            ll tm = (tl + tr)/2;
            build(2*v, tl, tm);
            build(2*v + 1, tm + 1, tr);
            t[v] = 0;
        }
    }

    void update(ll v, ll tl, ll tr, ll l, ll r, ll new_val){
        if(l > tr || r < tl) return;
        if(l <= tl && r >= tr){
            t[v] = new_val;
            marked[v] = true;
        } else {
            push(v);
            ll tm = (tl + tr)/2;
            update(2*v, tl, tm, l, r, new_val);
            update(2*v + 1, tm + 1, tr, l, r, new_val);
        }
    }

    void push(ll v){
        if(marked[v]){
            t[2*v] = t[2*v + 1] = t[v];
            marked[2*v] = marked[2*v + 1] = true;
            marked[v] = false;
        }
    }

    ll get(ll v, ll tl, ll tr, ll pos){
        if(tl == tr){
            return t[v];
        } else {
            if(marked[v]) return t[v];
            // push(v);
            ll tm = (tl + tr)/2;
            if(pos <= tm) return get(2*v, tl, tm, pos);
            return get(2*v + 1, tm + 1, tr, pos);
        }
    }
};

// Modular arithmetic

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

int vector_gcd(vector<int> a){
    int result = a[0];
    for(int i = 1; i < a.size(); i++){
        result = gcd(result, a[i]);
    }
    return result;
}

int lcm(int a, int b){return a*b/gcd(a, b);}

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a%b);
}

ll vector_gcd(vector<ll> a){
    ll result = a[0];
    for(int i = 1; i < a.size(); i++){
        result = gcd(result, a[i]);
    }
    return result;
}

ll lcm(ll a, ll b){return a*b/gcd(a, b);}

ll fast_exponentiation(ll a, ll b, ll m){
    ll result = 1;
    while(b > 0){
        if(b%2) result = result*a%m;
        a = a*a%m;
        b /= 2;
    }
    return result;
}

vector<vector<ll>> matrix_multiplication(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B[0].size(); j++){
            for(int k = 0; k < B.size(); k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return C;
}

vector<vector<ll>> binary_matrix_exponentiation(vector<vector<ll>> A, ll b){
    vector<vector<ll>> result(A.size(), vector<ll>(A.size(), 0));
    for(int i = 0; i < A.size(); i++) result[i][i] = 1;
    while(b > 0){
        if(b%2) result = matrix_multiplication(result, A);
        A = matrix_multiplication(A, A);
        b /= 2;
    }
    return result;
}

ll inverse(ll a, ll m){
    return fast_exponentiation(a, m - 2, m);
}

bool is_prime(const int x){
    for(int d = 2; d*d <= x; d++) if(x%d == 0) return false;
    return true;
}

vector<ll> linear_sieve(ll n){
    vector<ll> ld(n + 1, 0), pr;
    for(ll i = 2; i <= n; i++){
        if(ld[i] == 0){
            ld[i] = i;
            pr.push_back(i);
        }
        for(ll j = 0; pr[j]*i <= n; j++){
            ld[pr[j]*i] = pr[j];
            if(pr[j] == ld[i]) break;
        }
    }
    return ld;
}

bool is_quadratic_residue(ll a, ll p){
    a %= p; 
    if(a < 0) a += p;
    if(a == 0 || p == 2) return true;
    return fast_exponentiation(a, (p - 1)/2, p) == 1;
}

ll tonelli_shanks(ll a, ll p){
    a %= p; 
    if(a < 0) a += p;
    if(p == 2) return a;
    if(a == 0) return 0;
    if(!is_quadratic_residue(a, p)) return -1;
    if(p%4 == 3) return fast_exponentiation(a, (p + 1)/4, p);
    ll q = p - 1;
    int s = 0;
    while((q & 1) == 0){
        q >>= 1;
        s++;
    }
    ll z = 2;
    while(is_quadratic_residue(z, p)) z++;
    ll c = fast_exponentiation(z, q, p), x = fast_exponentiation(a, (q + 1)/2, p), t = fast_exponentiation(a, q, p), m = s;
    while(t != 1){
        ll i = 0, tt = t, b = c;
        while(tt != 1){
            tt = tt*tt%p;
            i++;
        }
        for(int j = 0; j < m - i - 1; j++) b = b*b%p;
        x = x*b%p;
        t = t*b%p*b%p;
        c = b*b%p;
        m = i;
    }
    return x;
}

// Binary functions

string bin(ll n, int width = 0){
    string s;
    do{
        s += '0' + (n % 2);
        n /= 2;
    } while(n);
    reverse(s.begin(), s.end());
    while(s.size() < width) s = '0' + s;
    return s;
}

int hamming_weight(int n){
    int cnt = 0;
    while(n > 0){
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

// Kruskal's algorithm

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

int kruskal(int n, vector<Edge> &edges, vector<Edge> &result) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int cost = 0;
    for(auto &e : edges){
        if(dsu.find(e.u) != dsu.find(e.v)){
            dsu.unite(e.u, e.v);
            cost += e.weight;
            result.push_back(e);
        }
    }
    return cost;
}

// Dijkstra's algorithm

void dijkstra(ll n, ll s, vector<ll>& d, vector<ll>& p, vector<vector<pair<ll, ll>>>& graph){
    d.assign(n, LLONG_MAX);
    p.assign(n, -1);
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while(!q.empty()){
        auto [dv, v] = q.top(); 
        q.pop();
        if(dv > d[v]) continue;
        for(auto [to, len] : graph[v]){
            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

vector<int> restore_path(int s, int t, const vector<int>& p) {
    vector<int> path;
    for(int v = t; v != -1; v = p[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    if(path[0] == s) return path;
    return {};
}

// String algorithms

vector<int> rabin_karp(string const& pattern, string const& text) {
    if(pattern.size() > text.size()) return {};
    int p = 31, m = 1e9 + 9;
    vector<ll> p_pow(text.size()), h(text.size() + 1, 0);
    p_pow[0] = 1; 
    for(int i = 1; i < p_pow.size(); i++) p_pow[i] = (p_pow[i - 1]*p)%m;
    for(int i = 0; i < text.size(); i++) h[i + 1] = (h[i] + (text[i] - 'a' + 1)*p_pow[i])%m; 
    ll h_s = 0;
    for(int i = 0; i < pattern.size(); i++) h_s = (h_s + (pattern[i] - 'a' + 1)*p_pow[i])%m; 
    vector<int> occurrences;
    for(int i = 0; i + pattern.size() - 1 < text.size(); i++) {
        ll cur_h = (h[i + pattern.size()] + m - h[i])%m;
        if(cur_h == h_s*p_pow[i]%m) occurrences.push_back(i);
    }
    return occurrences;
}

vector<ll> prefix_function(string s){
    ll n = s.size();
    vector<ll> pi(n, 0);
    for(ll i = 1; i < n; i++){
        ll j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<ll> z_function(string s){
    ll n = s.size(), l = 0, r = 0;
    vector<ll> z(n, 0);
    for(ll i = 1; i < n; i++){
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// Geometry

bool is_colinear(vector<pair<int, int>> points){
    if(points.size() < 3) return true;
    for(int i = 2; i < points.size(); i++){
        if((points[1].first - points[0].first)*(points[i].second - points[0].second) - 
        (points[i].first - points[0].first)*(points[1].second - points[0].second) != 0) return false;
    }
    return true;
}

// Game Theory

// Game on arbitrary graph
vector<vector<int>> adj_rev;

vector<bool> winning;
vector<bool> losing;
vector<bool> visited;
vector<int> degree;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj_rev[v]) {
        if (!visited[u]) {
            if (losing[v])
                winning[u] = true;
            else if (--degree[u] == 0)
                losing[u] = true;
            else
                continue;
            dfs(u);
        }
    }
}