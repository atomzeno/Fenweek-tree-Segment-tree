#include<stdio.h>
using namespace std;
#define N 100001
#define M 100001
int n, m;
int inp[M], tree[N + M], loc[N];
int sz;
int f(int x) {
	return (x & -x);
}
int sum(int pos) {
	int ans = 0;
	while (pos > 0) {
		ans += tree[pos];
		pos -= f(pos);
		//f : 값이 1인 최하위 비트 
	}
	return ans;
}
void update(int pos, int diff) {
	while (pos <= sz) { // n은 가장 큰 인덱스 번호
		tree[pos] += diff;
		pos += f(pos);
	}
}
void proc() {
	scanf("%d%d", &n, &m);
	sz = n + m;
	int i;
	for (i = 1; i <= n; i++) {
		update(m + i, 1);
		loc[i] = m + i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &inp[i]);
		printf("%d ", sum(loc[inp[i]] - 1));
		update(loc[inp[i]], -1);
		loc[inp[i]] = m + 1 - i;
		update(loc[inp[i]], 1);
	}
	for (i = 1; i <= n + m; i++) {
		tree[i] = 0;
	}
	for (i = 1; i <= n; i++) {
		loc[i] = 0;
	}
	printf("\n");
}
int main() {
	int t, i;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		proc();
	}
}
