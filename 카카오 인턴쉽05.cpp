#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    //vector<vector<int>> answer;
    int x=rc.size();  //3
    int y=rc[0].size();  //4


    for(int i=0;i<operations.size();i++)
    {

        if(operations[i][0]=='R')
        {
            printf("hi\n");
            int here=rc[0][0];

            //위쪽
            for(int i=0;i<x-1;i++)
            {
                rc[i][0]=rc[i+1][0];
            }
            //아래쪽
            for(int i=0;i<y-1;i++)
            {
                rc[x-1][i]=rc[x-1][i+1];
            }
            //오른쪽
            for(int i=x-1;i>0;i--)
            {
                rc[i][y-1]=rc[i-1][y-1];
            }
            for(int i=y-1;i>1;i--)
            {
                rc[0][i]=rc[0][i-1];
            }
            rc[0][1]=here;
        }
        else
        {
            //printf("kkk\n");
            vector<int> k;
            for(int i=0;i<y;i++)
            {
                k.push_back(rc[x-1][i]);
            }
            for(int i=x-1;i>0;i--)
            {
                for(int j=0;j<y;j++)
                {
                    rc[i][j]=rc[i-1][j];
                }
            }
            for(int i=0;i<y;i++)
            {
                rc[0][i]=k[i];
            }
        }
    }



    return rc;
}
