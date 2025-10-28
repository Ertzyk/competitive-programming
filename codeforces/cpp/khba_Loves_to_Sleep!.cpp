#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

struct Segment{
    ll l, r, cur, m = 1, c = 1, closest;
    bool lim = false;
    bool operator<(const Segment& other) const {
        return closest < other.closest;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n), result;
        for(auto &e: a) cin >> e;
        sort(a.begin(), a.end());
        priority_queue<Segment> max_heap;
        Segment e, t;
        e.l = -1;
        e.r = a[0];
        e.cur = 0;
        e.lim = true;
        e.closest = a[0];
        if(e.closest > 0) max_heap.push(e);
        t.l = a[n - 1];
        t.r = x + 1;
        t.cur = x;
        t.lim = true;
        t.m = -1;
        t.closest = x - a[n - 1];
        if(t.closest > 0) max_heap.push(t);
        for(int i = 0; i < n - 1; i++){
            Segment s;
            s.l = a[i];
            s.r = a[i + 1];
            s.cur = (s.l + s.r)/2;
            s.closest = min(s.cur - s.l, s.r - s.cur);
            if(s.closest > 0) max_heap.push(s);
        }
        result.reserve(k);
        while(result.size() < k && !max_heap.empty()){
            Segment s = max_heap.top();
            max_heap.pop();
            result.push_back(s.cur);
            s.cur += s.m*s.c;
            if(!s.lim){
                s.m *= -1;
                s.c++;
                s.closest = min(s.cur - s.l, s.r - s.cur);
            } else s.closest = ((s.cur <= a[0]) ? s.r - s.cur : s.cur - s.l);
            if(s.closest > 0) max_heap.push(s);
        }
        ll i = 0;
        while(result.size() < k){
            if(i == 0 || a[i] != a[i - 1]) result.push_back(a[i]);
            i++;
        }
        for(int x: result) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}