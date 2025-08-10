#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> p;
    p.reserve(10);
    int P = 1, q;
    p.push_back(P);
    for(int i = 0; i < 9; i++){
        P *= 3;
        p.push_back(P);
    }
    set<int> comb;
    for(int mask = 0; mask < 1024; mask++){
        int num = 0, m = mask, k = 0;
        while(m > 0){
            if(m&1) num += p[k];
            k++;
            m >>= 1;
        }
        comb.insert(num);
    }
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << *comb.lower_bound(n) << '\n';
    }
    return 0;
}