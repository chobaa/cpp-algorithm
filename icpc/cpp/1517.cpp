#include <iostream>
#include <vector>

using namespace std;

long long answer = 0;

void merge(vector<int> &arr, int start, int end)
{
    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;
    vector<int> temp;

    if (start == end)
        return;

    merge(arr, start, mid);
    merge(arr, mid + 1, end);

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
            answer += mid + 1 - left;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= end)
    {
        temp.push_back(arr[right]++);
    }
    for (int i = start, j = 0; i <= end; i++, j++)
    {
        arr[i] = temp[j];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge(arr, 0, n - 1);
    printf("%lld", answer);
}