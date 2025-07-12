#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    vector<int> counts(26), countt(26);
    for(char ch: s) if(ch != '?') counts[ch - 'a']++;
    for(char ch: t) countt[ch - 'a']++;
    priority_queue<pair<float, char>, vector<pair<float, char>>, greater<pair<float, char>>> pq;
    for(int i = 0; i < 26; i++) if(countt[i] != 0) pq.push({counts[i]/countt[i], (char)('a' + i)});
    for(int i = 0; i < s.size(); i++){
        while(i < s.size() && s[i] != '?') i++;
        char letter = pq.top().second;
        pq.pop();
        s[i] = letter;
        counts[letter - 'a']++;
        pq.push({counts[letter - 'a']/countt[letter - 'a'], letter});
    }
    cout << s << '\n';
    return 0;
}