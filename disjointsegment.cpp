#include <bits/stdc++.h>
using namespace std;
typedef struct pairr
{
    int first;
    int second;
}pairr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    pairr segment[n];
    int trash1,trash2;
    for(int i=0;i<n;i++)
    {
        cin>>segment[i].first>>segment[i].second;
    }
    sort(segment,segment+n,[](const pairr &a,const pairr &b)
    {
        return a.second<b.second;
    });
    int lastmin=segment[0].second;
    int count=1;
    for(int i=1;i<n;i++)
    {
        if(segment[i].first>lastmin)
        {
            lastmin=segment[i].second;
            count++;
        }
    }
    cout<<count<<flush;
}
