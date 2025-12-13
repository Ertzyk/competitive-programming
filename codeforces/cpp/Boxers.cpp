#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct Segment{
    ll over_limit, empty_before;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> cnt(150002, 0);
    vector<Segment> segments;
    segments.reserve(n);
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        cnt[a]++;
    }
    ll cur_empty = 0, cur_non_empty = 0, cur_over_limit = 0, res = 0;
    for(ll i = 1; i <= 150001; i++){
        if(cnt[i] == 0 && cnt[i - 1] == 0){
            cur_empty++;
        } else if(cnt[i] == 0 && cnt[i - 1] != 0){
            Segment s;
            s.empty_before = cur_empty;
            res += cur_non_empty;
            s.over_limit = cur_over_limit;
            segments.push_back(s);
            cur_over_limit = cur_non_empty = 0;
            cur_empty = 1;
        } else {
            cur_non_empty++;
            cur_over_limit += cnt[i] - 1;
        }
    }
    if(segments[0].empty_before > 0 && segments[0].over_limit > 0){
        res++;
        segments[0].over_limit--;
    }
    for(ll i = 0; i < segments.size() - 1; i++){
        if(segments[i + 1].empty_before == 1){
            if(segments[i].over_limit > 0) res++;
            else if(segments[i + 1].over_limit > 0){
                res++;
                segments[i + 1].over_limit--;
            }
        } else {
            if(segments[i].over_limit > 0) res++;
            if(segments[i + 1].over_limit > 0){
                res++;
                segments[i + 1].over_limit--;
            }
        }
    }
    if(segments.back().over_limit > 0) res++;
    cout << res << '\n';
    return 0;
}