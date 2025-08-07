#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), cycle_lengths;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }
    vector<bool> visited(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            int length = 1, p = a[i];
            visited[i] = true;
            while(!visited[p]){
                visited[p] = true;
                p = a[p];
                length++;
            }
            if(p != i){
                cout << "-1\n";
                return 0;
            }
            cycle_lengths.push_back(length);
        }
    }
    int l = cycle_lengths[0];
    for(int i = 1; i < cycle_lengths.size(); i++) l = lcm(l, cycle_lengths[i]);
    if(l%2 == 1) cout << l << '\n';
    else cout << l/2 << '\n';
    return 0;
}