#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int main()
{
    int n;
    int s=1000000;
    while(scanf("%d",&n)!=EOF)
    {
        vector < int > a;
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            a.push_back(k-1);
        }
        printf("%d\n",n);
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
                printf("%d\n",s-a[i]);
            else
                printf("%d ",s-a[i]);
        }
    }
}