#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 100009
#define M 100009
#define SZN 262144
int lc[N], st[N + M];
struct SEG {
	int s, e, sm;
};
SEG seg[SZN * 2];
void init() {
	for (int i = 1; i <= SZN; i++) {
		seg[SZN + i - 1].s = seg[SZN + i - 1].e = i;
	}
	for (int i = SZN * 2 - 1; i >= 2; i--) {
		if (seg[i / 2].s == 0) {
			seg[i / 2].s = seg[i].s;
			seg[i / 2].e = seg[i].e;
		}
		else {
			seg[i / 2].s = min(seg[i / 2].s, seg[i].s);
			seg[i / 2].e = max(seg[i / 2].e, seg[i].e);
		}
	}
	//s, e만 다 갱신해줌
}
int sum_seg(int node, int st, int ed) {
	if (ed < seg[node].s || seg[node].e < st) {
		return 0;
	}
	if (st <= seg[node].s && seg[node].e <= ed) {
		return seg[node].sm;
	}
	return sum_seg(node * 2, st, ed) + sum_seg(node * 2 + 1, st, ed);
}
int sum(int st, int ed) {
	return sum_seg(1, st, ed);
}

void upd(int node, int val) {
	node += (SZN - 1);
	while (node > 0) {
		seg[node].sm += val;
		node = node / 2;
	}
}
void proc() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &st[m - i + 1]);
	}
	for (i = 1; i < SZN * 2; i++) {
		seg[i].sm = 0;
	}
	for (i = 1; i <= n; i++) {
		st[m + i] = i;
		lc[i] = 0;
	}
	//다 setting은 완료
	for (i = n + m; i >= 1; i--) {
		if (lc[st[i]] == 0) {
			lc[st[i]] = i;
			upd(i, 1);
		}
		else {
			//i+1~lc[st[i]]-1
			printf("%d ", sum(i + 1, lc[st[i]] - 1));
			upd(i, 1);
			upd(lc[st[i]], -1);
			lc[st[i]] = i;
		}
	}
	printf("\n");
}
int main() {
	int t;
	scanf("%d", &t);
	init();
	for (int i = 1; i <= t; i++) {
		proc();
	}
}
