#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    ll result = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> ld(100001, 0), pr;
    for(int i = 2; i <= 100000; i++){
        if(ld[i] == 0){
            ld[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; pr[j]*i <= 100000; j++){
            ld[pr[j]*i] = pr[j];
            if(pr[j] == ld[i]) break;
        }
    }
    unordered_map<int, int> hashmap;
    for(int i = 0; i < n; i++){
        unordered_map<int, int> cnt;
        int l = a[i];
        while(l != 1){
            cnt[ld[l]]++;
            l /= ld[l];
        }
        for(auto pr: cnt){
            for(int j = pr.second; j%k != 0; j++){
                l *= pr.first;
                if(l > 100000) break;
            }
            if(l > 100000) break;
        }
        if(l <= 100000) result += (ll)hashmap[l];
        l = 1;
        for(auto pr: cnt){
            for(int j = 0; j < pr.second%k; j++){
                l *= pr.first;
            }
        }
        hashmap[l]++;
    }
    cout << result << '\n';
    return 0;
}