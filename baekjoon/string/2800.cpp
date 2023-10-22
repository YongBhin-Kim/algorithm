// 23.8.14 괄호 제거 (G5)

// 괄호 2개 -> 2C0 + 2C1
// 괄호 3개 -> 3C0 + 3C1 + 3C2
// 괄호 n개 -> nC0 + nC1 + ... + nCn-1

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define TRUE   1
#define FALSE  0

using namespace std;

string str;
vector<int> bracket;
vector< pair<int, int> > bracket_pair;
vector<int> visit;
map<string, int> express;


void recursion(int n, int count) {
    string res = "";

    if ( count > 0 ) {
        for (int i=0; i<visit.size(); i++) {
            if( visit[i]==FALSE )
                res+=str[i];
        }
        express.insert(make_pair(res, 0));
    }

    for (int i=n; i<bracket_pair.size(); i++) {

        if( visit[bracket_pair[i].first] == TRUE && visit[bracket_pair[i].second] == TRUE ) continue;

        visit[bracket_pair[i].first]=TRUE;
        visit[bracket_pair[i].second]=TRUE;

        recursion(i, count+1);

        visit[bracket_pair[i].first]=FALSE;
        visit[bracket_pair[i].second]=FALSE;

    }
}

int main(){

    cin >> str;

    for ( int i=0; i<str.length(); i++ ) {
        if(str[i]=='(') {
            bracket.push_back(i);
        }
        else if(str[i]==')') {
            bracket_pair.push_back(make_pair(bracket.back(), i));
            bracket.pop_back();
        }
    }

    visit.resize(str.length(), 0);
    recursion(0, 0);

    for(auto iter=express.begin(); iter!=express.end(); iter++) {
        cout << iter->first << '\n';
    }
}


// (2+(2*2)+2)
// (1+(2*(3+4)))
// ios::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);

// for (auto iter=bracket.begin(); iter!=bracket.end(); iter++) {
//     cout << "( : " << *iter << endl;
// }