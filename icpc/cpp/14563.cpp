#include <iostream>
#include <vector>

using namespace std;

int arr[10001];

int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = i * 2; j <= 10000; j += i)
        {
            arr[j] += i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int temp;
        cin >> temp;
        if(arr[temp] == temp) cout << "Perfect\n";
        else if(arr[temp] < temp) cout << "Deficient\n";
        else cout << "Abundant\n";
    }
}