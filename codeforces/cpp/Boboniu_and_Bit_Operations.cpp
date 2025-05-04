#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_set<int> b;
    for(int &x: a) cin >> x;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    bool flag = true;
    while(flag){
        
    }

}