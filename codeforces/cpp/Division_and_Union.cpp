#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment{
    int idx, l, r;
    bool operator<(const Segment &other) const {
        return l < other.l;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, end = 0, cur_group = 2;
        cin >> n;
        vector<Segment> segments(n);
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            segments[i].idx = i;
            cin >> segments[i].l >> segments[i].r;
        }
        sort(segments.begin(), segments.end());
        bool at_least_1_two = false;
        for(int i = 0; i < n; i++){
            if(segments[i].l > end){
                cur_group = 3 - cur_group;
                if(cur_group == 2) at_least_1_two = true;
            }
            result[segments[i].idx] = cur_group;
            end = max(end, segments[i].r);
        }
        if(at_least_1_two) for(int x: result) cout << x << ' ';
        else cout << -1;
        cout << '\n';
    }
    return 0;
}