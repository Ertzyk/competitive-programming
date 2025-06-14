#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <utility>
#include <queue>
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
    for(int d = 2; d*d <= x; d++){
        if(x%d == 0){
            return false;
        }
    }
    return true;
}

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
    int count_components(){return components;}
};