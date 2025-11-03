#include <bits/stdc++.h>
using namespace std;
typedef struct job{
    int hour;
    int fee;
}job;
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        bitset<100> bitt;
        int number;
        cin>>number;
        job jobless[number];
        for(int i=0;i<number;i++)
        {
            cin>>jobless[i].hour>>jobless[i].fee;
        }
        sort(jobless,jobless+number,[](const job &a,const job &b)
    {
        return a.fee>b.fee;
    });
    int count=0;
        for(int i=0;i<number;i++)
        {
            if(bitt.test(jobless[i].hour))
            {
                continue;
            }
            else
            {
                count+=jobless[i].fee;
                bitt.set(jobless[i].hour);
            }
        }
    cout<<count<<endl;
}
