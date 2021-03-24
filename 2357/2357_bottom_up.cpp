#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define NN 1000002
int n, m, k, sz;
int A[NN];
struct SEG {
    int mn, mx;
};
SEG seg[NN * 4];
void segment(int SS, int EE) {
    int l = SS + sz - 1, r = EE + sz - 1;
    int ans_mx = 0, ans_mn=2e9;
    while (l <= r) {
        if (l % 2 == 1) {
            ans_mn = min(ans_mn, seg[l].mn);
            ans_mx = max(ans_mx, seg[l].mx);
            ++l;
        }
        if (r % 2 == 0) {
            ans_mn = min(ans_mn, seg[r].mn);
            ans_mx = max(ans_mx, seg[r].mx);
            --r;
        }
        l = l >> 1, r = r >> 1;
    }
    printf("%d %d\n", ans_mn, ans_mx);
}
int main() {
    int i;
    scanf("%d%d", &n, &m);
    for (sz = 1; sz < n; sz *= 2);
    for (i = 1; i <= n; i++) { scanf("%d", &A[i]); }
    for (i = 1; i < sz; i++) {
        seg[i].mn = 2e9;
        seg[i].mx = 0;
    }
    for (i = 1; i <= n; i++) {
        seg[sz + i - 1].mn = A[i];
        seg[sz + i - 1].mx = A[i];
    }
    for (i = sz + n - 1; i >= 2; i--) {
        seg[i / 2].mn = min(seg[i].mn, seg[i / 2].mn);
        seg[i / 2].mx = max(seg[i].mx, seg[i / 2].mx);
    }
    for (i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        segment(a, b);
    }
}
