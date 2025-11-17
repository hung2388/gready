#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l1,l2;
    unordered_map <int,int> warehouse;
    priority_queue <pair<int,int>> pq;
    int Curmax=INT_MIN;
    int trash;
    cin>>n>>l1>>l2;
    int F[n];
    for(int i=0;i<n;i++)
    {
        cin>>warehouse[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i-l1>=0) pq.push({F[i-l1],i-l1});
        while(!pq.empty()&&pq.top().second<i-l2)
        {
            pq.pop();
        }
        F[i]=warehouse[i]+(pq.empty()?0:pq.top().first);
        Curmax=max(F[i],Curmax);
    }
    cout<<Curmax<<endl;
}
