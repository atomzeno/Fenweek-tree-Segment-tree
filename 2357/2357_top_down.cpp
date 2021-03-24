#include<stdio.h>
#define NN 200009
int n,sz,m,A[NN],Mn,Mx;
struct SEG{
    int s,e,mn,mx;
}B[NN*4];
void rnk_range(int node,int I){
    B[node].s=B[node].s>I?I:B[node].s;
    B[node].e=B[node].e>I?B[node].e:I;
    if(node==1){return;}
    rnk_range(node/2,I);
}
void rnk_ch(int node,int vl){
    B[node].mn=B[node].mn<vl?B[node].mn:vl;
    B[node].mx=B[node].mx>vl?B[node].mx:vl;
    if(node==1){return;}
    rnk_ch(node/2,vl);
}
void segment(int node,int S,int E){
    if(S<=B[node].s&&B[node].e<=E){
        Mn=Mn<B[node].mn?Mn:B[node].mn;
        Mx=Mx>B[node].mx?Mx:B[node].mx;
        return;
    }
    else if(B[node].e<S||E<B[node].s){return;}
    segment(node*2,S,E);
    segment(node*2+1,S,E);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++){scanf("%d",&A[i]);}
    for(sz=1;sz<n;sz*=2);
    for(i=1;i<=sz+n-1;i++){B[i].mn=B[i].s=1e9+1,B[i].mx=B[i].e=-1;}
    for(i=1;i<=n;i++){
        rnk_ch(sz+i-1,A[i]);
        rnk_range(sz+i-1,i);
    }
    for(i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Mn=1e9+1,Mx=-1;
        if(x>y){segment(1,y,x);}
        else{segment(1,x,y);}
        printf("%d %d\n",Mn,Mx);
    }
}
