풀수 있는데 시간부족 담에 풀어보기



#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <deque>

using namespace std;


vector<int> solution(vector<int> balance, vector<vector<int>> transaction, vector<int> abnormal) {
    vector<int> answer;
    stack<pair<int,int>> s[balance.size()+1];

    for(int i=0;i<balance.size();i++)
    {
        s[i+1].push({i+1,balance[i]});
    }

    for(int i=0;i< transaction.size();i++)
    {
        int from= transaction[i][0];
        int to= transaction[i][1];
        int num=  transaction[i][2];

        if(s[from].top().second>=num)
        {
            int x=s[from].top().first;
            int y=s[from].top().second;
            s[from].pop();
            s[from].push({x,y-num}); //자기꺼 더해줌
            s[to].push({from,num});
        }
        else
        {
            while(1)
            {
                int x=s[from].top().first;
                int y=s[from].top().second;
                if(y>=num)
                {
                    s[from].pop();
                    s[from].push({x,y-num});
                    s[to].push({})
                }


            }
        }
    }


    return answer;
}
