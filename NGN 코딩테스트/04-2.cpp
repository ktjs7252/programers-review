#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct 
{
    long long idx;
    long long win;
    long long p;
}tmp;

long long solution(vector<long long> players, int power, int k) {
    long long answer = 0;

    queue<tmp> q;
    q.push({0,0,power});

    while(1)
    {
        tmp kk=q.front();

        long long x=kk.idx;
        long long y=kk.win;
        long long z=kk.p;
        q.pop();

        if(x==players.size())
        {
            answer=max(answer,z);
        }
        if(x>players.size())
        {
            break;
        }

        if(z>=players[x])
        {
            q.push({x+1,y+1,z+y+1});
        }
    
        q.push({x+1,0,z+k});




    }
    return answer;
}
