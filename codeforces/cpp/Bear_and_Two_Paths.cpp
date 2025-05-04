#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    if(n >= k || n == 4){
        cout << -1;
        return 0;
    }
    unordered_set<int> x = {a, b, c, d};
    cout << a << ' ' << c << ' ';
    for(int i = 1; i <= n; i++) if(!x.count(i)) cout << i << ' ';
    cout << d << ' ' << b << '\n' << c << ' ' << a << ' ';
    for(int i = 1; i <= n; i++) if(!x.count(i)) cout << i << ' ';
    cout << b << ' ' << d;
    return 0;
}