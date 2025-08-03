#include <iostream>
using namespace std;

int selction_sort(int arr[],int n)
{
   
    // Traverse through all array elements
    for(int i=0 ; i<n-1 ; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for(int j=i+1; j<n ; j++)
        {
           if(arr[j]<arr[min_idx])
           {
               min_idx = j;
           }
        
        }
        // Swap the found minimum element with the first element    
        swap(arr[min_idx],arr[i]);
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

    selction_sort(arr,n);
    print_arr(arr,n);


    return 0;
}
