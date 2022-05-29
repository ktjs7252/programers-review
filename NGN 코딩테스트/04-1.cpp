#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<long long> v;
int kk;
long long answer = 0;

void solve(int idx,int win,long long power)
{
    if(idx==v.size())
    {
        answer=max(answer,power);
        return;
    }

    if(power>=v[idx])
    {
        solve(idx+1,win+1,power+win+1);
    }

    solve(idx+1,0,power+kk);

}

long long solution(vector<long long> players, int power, int k) {
    kk=k;

    for(int i=0;i<players.size();i++) //포인터가 안먹네?
    {
        v.push_back(players[i]);
    }

    solve(0,0,power); //인덱스,연승,공격력

    return answer;
}
