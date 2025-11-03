#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int change;
    cin>>change;
    vector <int> A (5);
    while(change>0)
    {
        if(change>=100)
        {
            A[0]++;
            change-=100;
            continue;
        }
        else if(change>=25)
        {
            A[1]++;
            change-=25;
            continue;
        }
        else if(change>=10)
        {
            A[2]++;
            change-=10;
            continue;
        }
        else if(change>=5)
        {
            A[3]++;
            change-=5;
            continue;
        }
        else if(change>=1)
        {
            A[4]++;
            change-=1;
            continue;
        }
    }
    for(int i=4;i>=0;i--)
    {
        cout<<A[i]<<" "<<flush;
    }
}