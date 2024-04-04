#include <iostream>
using namespace std;

void maxheapify(int arr[], int i, int n)
{
    int left = 2 * i;
    int right = 2*i + 1;
    int largest;
    if(left<=n && arr[left] > arr[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if(right <= n && arr[right] > arr[i])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheapify(arr, largest, n);
    }
}

void buildmaxHeap(int arr[], int n)
{
    for(int i=n/2; i>=1; i--)
    {
        maxheapify(arr, i, n);
    }
}

void heapSort(int arr[], int n)
{
    buildmaxHeap(arr, n);
    for(int i=n; i>=2; i--)
    {
        swap(arr[i], arr[1]);
        maxheapify(arr, 1, i-1);
    }
}

int main()
{
    int arr[100];
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);
    cout << "Sorted array: ";
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}