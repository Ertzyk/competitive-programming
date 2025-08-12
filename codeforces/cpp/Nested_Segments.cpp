#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment{
    int l, r, idx;
    bool operator<(const Segment &other){
        if(l != other.l) return l < other.l;
        return r > other.r;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Segment> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].idx = i + 1;
    }
    sort(a.begin(), a.end());
    int max_r = 0, first_idx = -1;
    for(auto s: a){
        if(s.r <= max_r){
            cout << s.idx << ' ' << first_idx << '\n';
            return 0;
        }
        max_r = s.r;
        first_idx = s.idx;
    }
    cout << "-1 -1\n";
    return 0;
}