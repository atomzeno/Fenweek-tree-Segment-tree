//#pragma warning(disable:4996)
//#pragma warning(disable:6031)
#include<stdio.h>
using namespace std;
#define N 1000001
#define M 10001
#define K 10001
int n, m, k;
long long inp[N], tree[N];
int f(int x) {
	return (x & -x);
}
long long sum(int pos) {
	long long ans = 0;
	while (pos > 0) {
		ans += tree[pos];
		pos -= f(pos); 
		//f : 값이 1인 최하위 비트 
	}
	return ans;
}
void update(int pos, long long diff) {
	while (pos <= n) { // n은 가장 큰 인덱스 번호
		tree[pos] += diff;
		pos += f(pos);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &inp[i]);
		update(i, inp[i]);
	}
	for (i = 1; i <= m + k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			long long c;
			scanf("%lld", &c);
			long long diff = c - inp[b];
			inp[b] = c;
			update(b, diff);
		}
		else {
			int c;
			scanf("%d", &c);
			printf("%lld\n", sum(c) - sum(b - 1));
		}
	}
}