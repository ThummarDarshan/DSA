#include <iostream>
using namespace std;

int bubble_sort(int arr[],int n)
{
    bool swapped=false;
    // Traverse through all array elements
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        
        }

    }

    if(swapped == false)
    {
        return 0; // Array is already sorted
    }
    else
    {
        return 1; // Array was sorted
    }
}

int print_arr(int arr[], int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr,n);
    print_arr(arr,n);


    return 0;
}
