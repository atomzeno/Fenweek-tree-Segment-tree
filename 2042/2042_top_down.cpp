#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define NN 1000002
int n, m, k, sz;
long long int A[NN];
struct seg {
    int s, e;
    long long int vl;
}B[NN * 4];
void rnk_vl(int node, long long int vvl) {
    B[node].vl += vvl;
    if (node == 1) { return; }
    rnk_vl(node / 2, vvl);
}
long long segment(int node, int SS, int EE) {
    if (SS <= B[node].s && B[node].e <= EE) {
        return B[node].vl;
    }
    if (SS > B[node].e || EE < B[node].s) {
        return 0;
    }
    return segment(node * 2, SS, EE) + segment(node * 2 + 1, SS, EE);
}
int main() {
    int i;
    scanf("%d%d%d", &n, &m, &k);
    for (sz = 1; sz < n; sz *= 2);
    for (i = 1; i <= n; i++) { scanf("%lld", &A[i]); }
    for (i = 1; i < sz * 2; i++) { B[i].s = 1e9, B[i].e = -1; }
    for (i = 1; i <= n; i++) {
        B[sz + i - 1].s = i;
        B[sz + i - 1].e = i;
        B[sz + i - 1].vl = A[i];
    }
    for (i = sz + n - 1; i >= 2; i--) {
        B[i / 2].vl += B[i].vl;
        if (B[i / 2].s == 0) {
            B[i / 2].s = B[i].s;
            B[i / 2].e = B[i].e;
        }
        else {
            B[i / 2].s = min(B[i / 2].s, B[i].s);
            B[i / 2].e = max(B[i / 2].e, B[i].e);
        }
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
            printf("%lld\n", segment(1, yy, zz));
        }
    }
}
