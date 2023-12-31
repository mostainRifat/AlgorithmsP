#include <iostream>
using namespace std;

int calculateSum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return arr[n - 1] + calculateSum(arr, n - 1);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = calculateSum(arr, n);
    cout << sum << endl;
    return 0;
}
