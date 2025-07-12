#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

bool is_colinear(vector<pair<ll, ll>> points){
    if(points.size() < 3) return true;
    for(int i = 2; i < points.size(); i++){
        if((points[1].first - points[0].first)*(points[i].second - points[0].second) - 
        (points[i].first - points[0].first)*(points[1].second - points[0].second) != 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for(int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
    if(n <= 4){
        cout << "YES\n";
        return 0;
    }
    if(is_colinear({points[0], points[1], points[2]})){
        vector<pair<ll, ll>> non_colinear;
        for(int i = 3; i < n; i++){
            if(!is_colinear({points[0], points[1], points[i]})) non_colinear.push_back(points[i]);
        }
        if(is_colinear(non_colinear)) cout << "YES\n";
        else cout << "NO\n";
    } else if(is_colinear({points[0], points[1], points[3]})){
        vector<pair<ll, ll>> non_colinear;
        for(int i = 2; i < n; i++){
            if(i == 3) continue;
            if(!is_colinear({points[0], points[1], points[i]})) non_colinear.push_back(points[i]);
        }
        if(is_colinear(non_colinear)) cout << "YES\n";
        else cout << "NO\n";
    } else if(is_colinear({points[0], points[2], points[3]})){
        vector<pair<ll, ll>> non_colinear;
        for(int i = 1; i < n; i++){
            if(i == 2 || i == 3) continue;
            if(!is_colinear({points[0], points[2], points[i]})) non_colinear.push_back(points[i]);
        }
        if(is_colinear(non_colinear)) cout << "YES\n";
        else cout << "NO\n";
    } else if(is_colinear({points[1], points[2], points[3]})){
        vector<pair<ll, ll>> non_colinear;
        for(int i = 0; i < n; i++){
            if(i == 1 || i == 2 || i == 3) continue;
            if(!is_colinear({points[1], points[2], points[i]})) non_colinear.push_back(points[i]);
        }
        if(is_colinear(non_colinear)) cout << "YES\n";
        else cout << "NO\n";
    } else {
        bool comb_1 = true;
        for(int i = 4; i < n; i++){
            if(!is_colinear({points[0], points[1], points[i]}) && !is_colinear({points[2], points[3], points[i]})){
                comb_1 = false;
                break;
            }
        }
        if(comb_1){
            cout << "YES\n";
            return 0;
        }
        bool comb_2 = true;
        for(int i = 4; i < n; i++){
            if(!is_colinear({points[0], points[2], points[i]}) && !is_colinear({points[1], points[3], points[i]})){
                comb_2 = false;
                break;
            }
        }
        if(comb_2){
            cout << "YES\n";
            return 0;
        }
        bool comb_3 = true;
        for(int i = 4; i < n; i++){
            if(!is_colinear({points[0], points[3], points[i]}) && !is_colinear({points[1], points[2], points[i]})){
                comb_3 = false;
                break;
            }
        }
        if(comb_3){
            cout << "YES\n";
            return 0;
        }
        cout << "NO\n";
    }
    return 0;
}