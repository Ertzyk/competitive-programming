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
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}

// Custom Data Structures

struct MinStack{
    stack<pair<int, int>> st;
    void add(int new_elem){
        st.push({new_elem, st.empty() ? new_elem : min(new_elem, st.top().second)});
    }
    int remove(){
        int removed_element = st.top().first;
        st.pop();
        return removed_element;
    }
    int minimum(){
        return st.top().second;
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

vector<int> prefix_function(string s){
    vector<int> pi(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

//Geometry

bool is_colinear(vector<pair<int, int>> points){
    if(points.size() < 3) return true;
    for(int i = 2; i < points.size(); i++){
        if((points[1].first - points[0].first)*(points[i].second - points[0].second) - 
        (points[i].first - points[0].first)*(points[1].second - points[0].second) != 0) return false;
    }
    return true;
}