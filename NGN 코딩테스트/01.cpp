#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> cards1, vector<vector<int>> cards2) {
    int answer = 0;


    for(int k=0;k<cards1.size();k++)
    {
        int sign=0;
        int counting1=0;
        int counting2=0;
        for(int i=0;i<cards1[k].size();i++)
        {
            for(int j=0;j<cards2[k].size();j++)
            {
                if(cards1[k][i]==cards2[k][j])
                {
                    answer++;
                    sign=1;
                    break;
                }
                if(cards1[k][i]==cards1[k][j] || cards2[k][i]==cards2[k][j])
                {
                    if(i!=j)
                    {
                        answer++;
                        sign=1;
                        break;
                    }
                }
            }
            if(sign==1) break;
        }
        if(sign==1) continue;
        if(k==0) continue;
        for(int i=0;i<cards1[k].size();i++)
        {
            for(int j=0;j<cards1[k].size();j++)
            {
                if(cards1[k-1][i]==cards1[k][j])
                {
                    counting1++;
                    if(counting1==2)
                    {
                        answer++;
                        sign=1;
                        break;
                    }
                }
               // if(sign==1) break;
                if(cards2[k-1][i]==cards2[k][j])
                {
                    counting2++;
                    if(counting2==2)
                    {
                        answer++;
                        sign=1;
                        break;
                    }
                }
            }
            if(sign==1) break;
        }

    }
    return answer;
}
