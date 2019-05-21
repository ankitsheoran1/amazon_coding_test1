#include<bits/stdc++.h>

using namespace std;

int main() {
long long n,m,x,left,right;
long long sum=0;
int a[1000001]={0};
cin>>n>>m;
for(int i=1;i<=m;i++)
{
    cin>>x;
    if(a[x]==0)
    {
        if(i==1)
        {
            sum+=(1+n);
            left=x;
            right=x;
        }
        else if(x>left&&x<right)
        {
            sum+=(2*1LL*x);
        }
        else if(x<left)
        {
            sum+=(left+x);
            left=x;
        }
        else if(x>right)
        {
            sum+=(right+x);
            right=x;
        }
    }
    a[x]=1;
    cout<<sum<<"\n";
}
return 0;
}

