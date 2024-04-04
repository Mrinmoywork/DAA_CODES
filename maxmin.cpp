#include <iostream>
using namespace std;

int maxMin(int arr[], int i, int j, int *max, int *min)
{
    if(i == j)
    {
        *max = *min = arr[i];
    }
    else if(i+1 == j)
    {
        if(arr[i] > arr[j])
        {
            *max = arr[i];
            *min = arr[j];
        }
        else
        {
            *max = arr[j];
            *min = arr[i];
        }
    }
    else
    {
        int mid = (i+j)/2;
        int max1 = *max;
        int min1 = *min;
        maxMin(arr, i, mid, max, min);
        maxMin(arr, mid+1, j, &max1, &min1);

        if(*max < max1)
        {
            *max = max1;
        }
        if(*min > min1)
        {
            *min = min1;
        }
    }
}

int main()
{
    int arr[100];
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int max, min;
    maxMin(arr, 0, n-1, &max, &min);
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    return 0;
}