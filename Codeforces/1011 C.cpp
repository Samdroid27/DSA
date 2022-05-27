#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=1)
        {
            cout<<-1<<endl;
            exit(0);
        }
    }
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        if(b[i]<=1)
        {
            cout<<-1<<endl;
            exit(0);
        }
    }
    double s=m;
    s+=s/(b[0]-1);
    for(int i=n-1;i>=1;i--)
    {
        s+=s/(a[i]-1);
        s+=s/(b[i]-1);
    }
    s+=s/(a[0]-1);
    cout<<fixed<<setprecision(9)<<s-m<<endl;
}