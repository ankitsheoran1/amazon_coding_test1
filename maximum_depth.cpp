#include<bits/stdc++.h>
using namespace std;
int a[200001],maxDepth,visit[200001];
map<int,vector<int> > level;
void solve(vector<vector<int> > &v,int d,int id)
{
    visit[id]=1;
    level[d].push_back(a[id]);
    for(auto it : v[id])
    {
        if(!visit[it])
        {
            solve(v,d+1,it);
        }
    }
    maxDepth=max(d,maxDepth);
}

int main()
{
    int n,q,x,y,l;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<vector<int> > v(n);
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
    solve(v,0,0);
    for(int i=0;i<=maxDepth;i++)
    {
        sort(level[i].begin(),level[i].end());
        
    }
    while(q--)
    {
        cin>>l>>x;
        l=l%(maxDepth+1);
        int id=lower_bound(level[l].begin(),level[l].end(),x)-level[l].begin();
        if(id>=level[l].size())
        {
            cout<<"-1"<<"\n";
        }
        else
        cout<<level[l[id]<<"\n";
    }
    return 0;
}
