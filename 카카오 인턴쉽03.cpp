#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct tmp{
    int a;
    int c;
    int time;
};

int visited[151][151][101];
int max_alp,max_cop;
int answer=100000;

int solution(int alp, int cop, vector<vector<int>> problems) {

    for(int i=0;i<problems.size();i++)
    {
        max_alp=max(problems[i][0],max_alp);
        max_cop=max(problems[i][1],max_cop);
    }

    queue<tmp> q;
    q.push({alp,cop,0});
    visited[alp][cop][0]=1;

    while(q.size())
    {
        tmp x=q.front();

        int here_a=x.a;
        int here_c=x.c;
        int here_time=x.time;
        q.pop();

        if(here_a>=max_alp && here_c>=max_cop)
        {
            answer=here_time;
            break;
        }

        for(int i=0;i<problems.size();i++)
        {
            if(problems[i][0]<=here_a && problems[i][1]<=here_c && visited[here_a+problems[i][2]][here_c+problems[i][3]][here_c+problems[i][4]]==0)
            {
                q.push({here_a+problems[i][2],here_c+problems[i][3],here_time+problems[i][4]});
                visited[here_a+problems[i][2]][here_c+problems[i][3]][here_c+problems[i][4]]=1;
            }
        }
        if(visited[here_a+1][here_c][here_time+1]==0)
        {
        q.push({here_a+1,here_c,here_time+1});
        visited[here_a+1][here_c][here_time+1]=1;
        }
        if(visited[here_a][here_c+1][here_time+1]==0)
        {
         q.push({here_a,here_c+1,here_time+1});
        visited[here_a][here_c+1][here_time+1]=1;
        }

    }


  

    
    return answer;
}



