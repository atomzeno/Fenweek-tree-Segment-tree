#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define NN 1000002
int n, m, k, sz;
long long seg[NN * 4], A[NN];
void rnk_vl(int node, long long int vvl) {
    seg[node] += vvl;
    if (node == 1) { return; }
    rnk_vl(node / 2, vvl);
}
long long segment(int SS, int EE) {
    int l = SS + sz - 1, r = EE + sz - 1;
    long long ret = 0;
    while (l <= r) {
        if (l % 2 == 1) {
            ret += seg[l];
            ++l;
        }
        if (r % 2 == 0) {
            ret += seg[r];
            --r;
        }
        l = l >> 1, r = r >> 1;
    }
    return ret;
}
int main() {
    int i;
    scanf("%d%d%d", &n, &m, &k);
    for (sz = 1; sz < n; sz *= 2);
    for (i = 1; i <= n; i++) { scanf("%lld", &A[i]); }
    for (i = 1; i <= n; i++) {
        seg[sz + i - 1] = A[i];
    }
    for (i = sz + n - 1; i >= 2; i--) {
        seg[i / 2] += seg[i];
    }
    for (i = 1; i <= m + k; i++) {
        int xx, yy;
        scanf("%d", &xx);
        if (xx == 1) {
            long long int zz;
            scanf("%d%lld", &yy, &zz);
            rnk_vl(sz + yy - 1, zz - A[yy]);
            A[yy] = zz;
        }
        else {
            int zz;
            scanf("%d%d", &yy, &zz);
            printf("%lld\n", segment(yy, zz));
        }
    }
}
