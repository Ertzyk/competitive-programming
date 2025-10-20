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
    int n, m, x, result = 0;
    cin >> n >> m >> x;
    for(int i = 0; i < n*m; i++){
        int l;
        cin >> l;
        result += ((gcd(l, x) == 1) ? 0 : 1);
    }
    cout << result << '\n';
    return 0;
}