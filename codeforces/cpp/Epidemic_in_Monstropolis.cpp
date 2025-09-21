#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void solve_small_case(const vector<int>& cur_v, const int& shifter, vector<pair<int, char>>& result_v){
    int Max_elem = *max_element(cur_v.begin(), cur_v.end());
    for(int i = 0; i < cur_v.size(); i++){
        if(cur_v[i] == Max_elem){
            if(i > 0 && cur_v[i - 1] != Max_elem){
                for(int j = i; j >= 1; j--) result_v.push_back({j + shifter, 'L'});
                for(int j = 0; j < cur_v.size() - i - 1; j++) result_v.push_back({shifter, 'R'});
                return;
            } else if(i < cur_v.size() - 1 && cur_v[i + 1] != Max_elem){
                for(int j = 0; j < cur_v.size() - i - 1; j++) result_v.push_back({i + shifter, 'R'});
                for(int j = i; j >= 1; j--) result_v.push_back({j + shifter, 'L'});
                return;
            }
        }
    }
    return;
}

bool all_equal(const vector<int>& v){
    for(int i = 0; i < v.size() - 1; i++) if(v[i] != v[i + 1]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, bp = 0, cur_sum = 0;
    cin >> n;
    vector<int> a(n), cur_v;
    vector<pair<int, char>> result_v;
    for(int &x: a) cin >> x;
    cin >> k;
    vector<int> b(k);
    for(int &x: b) cin >> x;
    for(int ap = 0; ap < n; ap++){
        if(bp == k){
            cout << "NO\n";
            return 0;
        }
        cur_sum += a[ap];
        cur_v.push_back(a[ap]);
        if(cur_sum == b[bp]){
            if(cur_v.size() == 1){
                cur_v.clear();
                cur_sum = 0;
                bp++;
                continue;
            }
            if(all_equal(cur_v)){
                cout << "NO\n";
                return 0;
            }
            solve_small_case(cur_v, bp + 1, result_v);
            cur_v.clear();
            cur_sum = 0;
            bp++;
        } else if(cur_sum > b[bp]){
            cout << "NO\n";
            return 0;
        }
    }
    if(cur_sum == 0 && bp == k){
        cout << "YES\n";
        for(auto pr: result_v) cout << pr.first << ' ' << pr.second << '\n';
    } else cout << "NO\n";
    return 0;
}