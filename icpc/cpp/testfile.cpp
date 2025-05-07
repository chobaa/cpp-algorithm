#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;
    int start = 0;
    int end = -1;
    int total = 0;
    while (1)
    {
        if (end > sequence.size() || start > sequence.size())
            break;
        if (total < k)
        {
            end++;
            total += sequence[end];
        }
        else
        {
            if (total == k)
            {
                if (answer.empty())
                {
                    answer.push_back(start);
                    answer.push_back(end);
                }
                else
                {
                    if (answer[1] - answer[0] > end - start)
                    {
                        answer[1] = end;
                        answer[0] = start;
                    }
                }
            }
            else
            {
                total -= sequence[start];
                start++;
            }
        }
    }
    return answer;
}