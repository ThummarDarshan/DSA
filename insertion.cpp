#include <iostream>
using namespace std;

int insertion_sort(int arr[],int n)
{
    for(int i=1 ; i<n ; i++)
    {
        int curr=arr[i];
        int prev= i-1;
        
        while(prev >= 0 && arr[prev] > curr)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
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

    insertion_sort(arr,n);
    print_arr(arr,n);


    return 0;
}
