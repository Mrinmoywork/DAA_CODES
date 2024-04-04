#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;

    int temp[100];
    while(i<=mid && j<=r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        temp[k] = arr[i];
        i++; k++;
    }
    while(j<=r)
    {
        temp[k] = arr[j];
        j++; k++;
    }

    // copying the sorted elements to the original array
    for(int i=l; i<=r; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = (l + r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}