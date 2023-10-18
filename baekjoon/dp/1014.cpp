#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int dp[11][(1 << 10)]; //dp[row][state] : row행에 state일 때 최대 학생의 수
string arr[11];
string state[(1 << 10)];
int n, m;
 
string ret_bin(int x) {
	string tmp = "";
	while (x) {
		if (x % 2 == 0) tmp += '0';
		else tmp += '1';
		x /= 2;
	}
	while (tmp.size() < m) tmp += '0';
	reverse(tmp.begin(), tmp.end());
	return tmp;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	
 
	int t; cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
 
		cin >> n >> m;
		for (int i = 0; i < (1 << m); i++) {
			state[i] = ret_bin(i);
		}
		for (int i = 0; i < n; i++) cin >> arr[i];
 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (1 << m); j++) {
				//행 체크
				string bin_str = state[j];
				bool flag = false; int cnt = 0;
				for (int a = 0; a < bin_str.size(); a++) {
					if (bin_str[a] == '1' && arr[i][a] == 'x') {
						flag = true;
						break;
					}
					if (bin_str[a] == '1' && a < bin_str.size() - 1) {
						if (bin_str[a + 1] == '1') {
							flag = true;
							break;
						}
					}
					if (bin_str[a] == '1') cnt++;
				}
				if (flag) continue;
 
				if (i == 0) {
					dp[i][j] = cnt;
					continue;
				}
 
				//윗 행 체크
				for (int k = 0; k < (1 << m); k++) {
					string up_str = state[k]; // 윗 행
					if (dp[i - 1][k] == 0) continue; //불가능한 배열이라면 pass
					flag = false;
					for (int a = 0; a < bin_str.size(); a++) {
						if (bin_str[a] == '1') {
							if (a > 0 && up_str[a - 1] == '1') {
								flag = true;
								break;
							}
							if (a < bin_str.size() - 1 && up_str[a + 1] == '1') {
								flag = true;
								break;
							}
						}
					}
					if (flag) continue;
					dp[i][j] = max(dp[i][j], cnt + dp[i - 1][k]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < (1 << m); i++) {
			ans = max(ans, dp[n - 1][i]);
		}
		cout << ans << "\n";
	}
	return 0;
}