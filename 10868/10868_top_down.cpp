#include<stdio.h>
using namespace std;
#define N 500001
#define SZN 524288
typedef long long int ll;
int n,  m, k;
ll A[N * 2];
int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y) { return x > y ? x : y; }
struct SEG {
	int s, e;
	ll vl;
}sg[SZN * 4];
int find_min(int node, int s, int e) {
	if (e < sg[node].s || sg[node].e < s) { return 1e9 + 1; }
	if (s <= sg[node].s&&sg[node].e <= e) { return sg[node].vl; }
	return min(find_min(node * 2, s, e), find_min(node * 2 + 1, s, e));
}
int main() {
	int i, nn = 0;
	ll ans = (ll)0;
	scanf("%d%d", &n, &m);
	for (nn = 1; nn < n; nn *= 2);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &A[i]);
	}
	for (i = 1; i <= n; i++) {
		sg[i + nn - 1].s = sg[i + nn - 1].e = i, sg[i + nn - 1].vl = A[i];
	}
	for (i = nn + n - 1; i >= 2; i--) {
		if (sg[i / 2].s == 0) {
			sg[i / 2].s = sg[i].s, sg[i / 2].e = sg[i].e, sg[i / 2].vl = sg[i].vl;
		}
		else {
			sg[i / 2].s = min(sg[i / 2].s, sg[i].s);
			sg[i / 2].e = max(sg[i / 2].e, sg[i].e);
			sg[i / 2].vl = min(sg[i / 2].vl, sg[i].vl);
		}
	}
	for (i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", find_min(1, a, b));
	}
}
