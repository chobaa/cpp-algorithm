#include <stdio.h>
#define IMAX 2000000
using namespace std;

class Tree
{
    int node[1 << 22];

public:
    int Insert(int cur, int left, int right, int index)
    {
        if (left == right)
        {
            node[cur] += 1;
            return node[cur];
        }

        int mid = (left + right) / 2;
        int ret = 0;
        if (index <= mid)
            Insert(cur * 2, left, mid, index);
        if (index > mid)
            Insert(cur * 2 + 1, mid + 1, right, index);
        return node[cur] = node[cur * 2] + node[cur * 2 + 1];
    }

    int Delete(int cur, int left, int right, int rank)
    {
        if (left == right)
        {
            node[cur] -= 1;
            return left;
        }

        int mid = (left + right) / 2;
        int ret = 0;
        if (rank <= node[cur * 2])
            ret = Delete(cur * 2, left, mid, rank);

        // right subtree를 볼 때는 query의 rank를 바꿔줘야함 (node[left_child]의 값 만큼 제해야함)
        else
            ret = Delete(cur * 2 + 1, mid + 1, right, rank - node[cur * 2]);
        node[cur] = node[cur * 2] + node[cur * 2 + 1];
        return ret;
    }
};
int main()
{
    int N;
    scanf("%d", &N);

    Tree *t = new Tree();
    for (int i = 0; i < N; i++)
    {
        int q, a;
        scanf("%d %d", &q, &a);
        if (q == 1)
        {
            t->Insert(1, 0, IMAX - 1, a - 1);
        }
        else
        {
            printf("%d\n", t->Delete(1, 0, IMAX - 1, a) + 1);
        }
    }
}