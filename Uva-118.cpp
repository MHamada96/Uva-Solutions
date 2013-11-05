#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <vector>
#include <new>
#include <fstream>
#include <map>
#include <bitset>
#include <cstring>
 using namespace std;
#define ll long long int 
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
int sc[55][55][4];
int x, y, inx, iny, l, i, j, flag;
char dir, ins[111];
int main()
{
    scanf("%d %d", &x, &y);
    while(scanf("%d %d %c", &inx, &iny, &dir)!=EOF)
    {
        scanf("%s", ins);
        l=strlen(ins);
        flag=0;
        for(i=0;i<l;++i)
        {
            if(ins[i]=='F' && dir=='N' && sc[inx][iny][0])
                continue;
            if(ins[i]=='F' && dir=='E' && sc[inx][iny][1])
                continue;
            if(ins[i]=='F' && dir=='S' && sc[inx][iny][2])
                continue;
            if(ins[i]=='F' && dir=='W' && sc[inx][iny][3])
                continue;
            if(ins[i]=='F')
            {
                if(dir=='N')
                    iny+=1;
                if(dir=='E')
                    inx+=1;
                if(dir=='S')
                    iny-=1;
                if(dir=='W')
                    inx-=1;
                if(inx<0||inx>x||iny<0||iny>y)
                {
                    flag=1;
                    break;
                }
            }
            else
            if(ins[i]=='R')
            {
                if(dir=='N')
                    dir='E';
                else if(dir=='E')
                    dir='S';
                else if(dir=='S')
                    dir='W';
                else if(dir=='W')
                    dir='N';
            }
            else
            if(ins[i]=='L')
            {
                if(dir=='N')
                    dir='W';
                else if(dir=='W')
                    dir='S';
                else if(dir=='S')
                    dir='E';
                else if(dir=='E')
                    dir='N';
            }
        }
        if(flag)
        {
            if(inx<0)inx=0;
            if(inx>x)inx=x;
            if(iny<0)iny=0;
            if(iny>y)iny=y;
            printf("%d %d %c LOST\n", inx, iny, dir);
            if(dir=='N')
                sc[inx][iny][0]=1;
            if(dir=='E')
                sc[inx][iny][1]=1;
            if(dir=='S')
                sc[inx][iny][2]=1;
            if(dir=='W')
                sc[inx][iny][3]=1;
            if(inx==0 && iny==0)
                sc[inx][iny][2]=sc[inx][iny][3]=1;
            if(inx==x && iny==y)
                sc[inx][iny][0]=sc[inx][iny][1]=1;
            if(inx==x && iny==0)
                sc[inx][iny][1]=sc[inx][iny][2]=1;
            if(inx==0 && iny==y)
                sc[inx][iny][0]=sc[inx][iny][3]=1;
        }
        else
        {
            printf("%d %d %c\n", inx, iny, dir);
        }
    }
    return 0;
}
