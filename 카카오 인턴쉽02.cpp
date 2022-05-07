#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1=0;
    long long sum2=0;

    for(int i=0;i<queue1.size();i++)
    {
        sum1+=queue1[i];
    }
    for(int i=0;i<queue2.size();i++)
    {
        sum2+=queue2[i];
    }
    
    while(1)
    {
        if(sum1==sum2)
        {
            break;
        }
        if(answer>290000)
        {
            answer=-1;
            break;
        }

        if(sum1>sum2)
        {
            int tmp=queue1[0];
            queue1.erase(queue1.begin(), queue1.begin() + 1);
            queue2.push_back(tmp);
            sum1-=tmp;
            sum2+=tmp;
            answer++;
        }
        else
        {
            int tmp=queue2[0];
            queue2.erase(queue2.begin(), queue2.begin() + 1);
            queue1.push_back(tmp);
            sum2-=tmp;
            sum1+=tmp;
            answer++;
        }

    }


    return answer;
}
//11 24 28

//14 16
//18 12
//15 15

//6 14   1 2 1 2     1 10 1 2
//7 13   1 2 1 2 1      10 1 2
//17  3   1 2 1 2 1 10   1 2
//16 4
//14 6
//13 7
//11 9
//10 10
