#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, result = 0;
    cin >> k >> n;
    int cur = 0;
    unordered_set<int> a;
    vector<int> b(k);
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        cur += x;
        a.insert(cur);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b[i] = x;
    }
    for(int ref_point: a){
        int add = 1;
        for(int i = 1; i < n; i++){
            if(!a.count(b[i] - b[0] + ref_point)){
                add = 0;
                break;
            }
        }
        result += add;
    }
    cout << result << '\n';
    return 0;
}