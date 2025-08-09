#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p = 0, res = 0;
    cin >> n;
    vector<int> a(n), counter(n + 1);
    for(int &x: a) cin >> x;
    for(int x: a) counter[x]++;
    for(int i = 1; i <= n; i++){
        if(counter[i] == 0){
            while(counter[a[p]] < 2) p++;
            a[p] = i;
            counter[a[p]]--;
            counter[i] = 1;
            res++;
        }
    }
    cout << res << '\n';
    for(int x: a) cout << x << ' ';
    cout << '\n';
    return 0;
}