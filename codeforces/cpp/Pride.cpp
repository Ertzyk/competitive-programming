#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int count_1 = 0;
    for(int x: a) if(x == 1) count_1++;
    if(count_1 == 0){
        vector<int> g(a.begin(), a.end());
        int m = -1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= n - i; j++){
                g[j] = gcd(g[j], a[i + j - 1]);
                if(g[j] == 1){
                    m = i;
                    break;
                }
            }
            if(m != -1) break;
        }
        if(m == -1) cout << "-1\n";
        else cout << n + m - 2 << '\n';
    } else cout << n - count_1 << '\n';
    return 0;
}