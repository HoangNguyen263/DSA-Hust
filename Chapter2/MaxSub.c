#include<stdio.h>
int duyet_toan_bo(int a[],int n,int low,int high) {
    int maxsum=0;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int sum=0;
            for (int k=i;k<j;k++) {
                sum+=a[k];
                if (sum>maxsum) maxsum=sum;
            }
        }
    }
    return maxsum;
}
int duyet_toan_bo_cai_tien(int a[],int n,int low, int high) {
    int maxsum=0;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum+=a[j];
            if (sum>maxsum) maxsum=sum;
        }
    }
    return maxsum;
}
//de quy
//maxLeft duyệt từ phải qua trái,maxRight duyệt từ trái qua phải
int maxleft(int a[],int low,int high){
    int maxsum=0;
    int sum=0;
    for (int i=high;i>=low;i--) {
        sum+=a[i];
        if (sum>maxsum) maxsum=sum;
    }
    return maxsum;
}
int maxright(int a[],int low,int high){
    int maxsum=0;
    int sum=0;
    for (int i=low;i<=high;i++) {
        sum+=a[i];
        if (sum>maxsum) maxsum=sum;
    }
    return maxsum;
}
int max(int a,int b){
    int max=a;
    if (b>a) max=b;
    else if (b<a) return max;
}
int de_quy(int a[],int low,int high){
    if (low==high) return a[low];//trường hợp cơ sở, nếu thiêú sẽ tràn bộ nhớ stack
    else {
    int mid=(low+high)/2;
    int maxL = de_quy(a,low,mid);
    int maxR = de_quy(a,mid+1,high);
    int maxM = maxleft(a,low,mid)+maxright(a,mid+1,high);
    return max(max(maxL,maxR),maxM);}
}
/*quy hoach dong:Gọi s[i] là trọng lượng dãy con lớn nhất của dãy a1,a2,...ai
s[1]=a[1]
s[i]=max{ai,s[i-1]+ai}*/
int quy_hoach_dong(int a[],int n){
    int s[n];
    s[0]=a[0];
    int maxsum=a[0];
    for (int i=1;i<=n-1;i++) {
        if (s[i-1]+a[i]>a[i]) {
            s[i]=s[i-1]+a[i];
        } else s[i]=a[i];
        if (s[i]>maxsum) maxsum=s[i];
    } 
    return maxsum;
}
int main() {
    int a[]={-2,11,-4,13,-5,2};
    printf("ket qua duyet toan bo %d\n",duyet_toan_bo(a,6,0,5));
    printf("ket qua duyet toan bo co cai tien %d\n",duyet_toan_bo_cai_tien(a,6,0,5));
    printf("ket qua de quy %d\n",de_quy(a,0,5));
    printf("ket qua quy hoach dong %d\n",quy_hoach_dong(a,6));
    return 0;
}