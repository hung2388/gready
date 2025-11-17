#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l1,l2;
    cin>>n>>l1>>l2;
    vector <int> warehouse;
    vector <int> F(n);
    int maximum=INT_MIN;
    int trash;
    for(int i=0;i<n;i++)
    {
        cin>>trash;
        warehouse.push_back(trash);
    }
    deque <int> dq;
    for(int i=0;i<n;i++)
    {
        if(i<l1)
        {
            F[i]=warehouse[i];
            maximum=max(maximum,F[i]);
        }
        else
        {
            while(!dq.empty()&&F[i-l1]>F[dq.back()]) dq.pop_back();
            dq.push_back(i-l1);
            while(!dq.empty()&&i-dq.front()>l2) dq.pop_front();
            F[i]= warehouse[i] +F[dq.front()];
            maximum=max(maximum,F[i]);
        }
    }
    cout<<maximum<<endl;
}
