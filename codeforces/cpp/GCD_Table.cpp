#include <iostream>
#include <map>
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
    map<int, int> count;
    for(int i = 0; i < n*n; i++){
        int x;
        cin >> x;
        count[x]++;
    }
    vector<int> result;
    result.reserve(n);
    for(int i = 0; i < n; i++){
        int max_key = count.rbegin()->first;
        if(count[max_key] == 1) count.erase(max_key);
        else count[max_key]--;
        for(int x: result){
            int g = gcd(max_key, x);
            if(count[g] == 2) count.erase(g);
            else count[g] -= 2;
        }
        result.push_back(max_key);
    }
    for(int x: result) cout << x << ' ';
    cout << '\n';
    return 0;
}