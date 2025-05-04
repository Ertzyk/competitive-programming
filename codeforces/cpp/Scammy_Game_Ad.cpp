#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<pair<char, ll>, pair<char, ll>>> game(n);
        for(int i = 0; i < n; i++){
            char p, q;
            ll r, s;
            cin >> p >> r >> q >> s;
            game[i].first.first = p;
            game[i].first.second = r;
            game[i].second.first = q;
            game[i].second.second = s;
        }
        vector<int> optimal_choice(n);
        ll l_multi = 1, r_multi = 1;
        int cur_optimal = 0;
        for(int i = n - 1; i >= 0; i--){
            optimal_choice[i] = cur_optimal;
            if(game[i].first.first == 'x' && game[i].second.first == 'x'){
                if(game[i].first.second > game[i].second.second) cur_optimal = 0;
                else if(game[i].first.second < game[i].second.second) cur_optimal = 1;
            } else if(game[i].first.first == 'x' && game[i].second.first == '+') cur_optimal = 0;
             else if(game[i].first.first == '+' && game[i].second.first == 'x') cur_optimal = 1;
        }
        ll l = 1, r = 1;
        for(int i = 0; i < n; i++){
            ll gained = 0;
            if(game[i].first.first == '+') gained += game[i].first.second;
            else gained += (game[i].first.second - 1)*l;
            if(game[i].second.first == '+') gained += game[i].second.second;
            else gained += (game[i].second.second - 1)*r;
            if(optimal_choice[i] == 0) l += gained;
            else r += gained;
        }
        cout << l + r << '\n';
    }
    return 0;
}