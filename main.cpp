#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace std::chrono;
void Swap(int *num1, int *num2); //Function for Swapping two numbers
void QuickSort_using_DynamicPivot(int Data[], int First, int Last, int Pivot); //Function for QuickSort Using Dynamic Pivot Selection
//Function for Swapping two numbers
int Partition_last_Element_pivot (int arr[], int l, int r);
void Quick_sort_LastElement_Pivot(int arr[], int left, int right);
//int partition_pivot_median(int array[], int low, int high);
void Quick_sort_with_median(int arr[], int left, int right);

void Swap(int *num1, int *num2)
{
    int temp;
    temp= *num1;
    *num1=*num2;
    *num2=temp;
}
//Function for QuickSort Using Dynamic Pivot Selection
void QuickSort_using_DynamicPivot(int Data[], int First, int Last, int Pivot)
{
    if(First<Last)
    {
        int i, z, j, v,K;
        int Pivot1=0, Pivot2=0; //Pivot 1 for Left Sub-Array containing less element than pivot. Pivot 2 for Right Sub-Array containing larger element than pivot
        int Countless=0, Countlarge=0; //Countless for counting number of elements less than pivot. Countlarge for counting number of elements larger than pivot.
        int Sumless, Sumlarge;//Sum of the values of the elements smaller than the pivot and the Sum of those larger than the pivot are stored in SumLess and SumLarger, respectively
        bool N = true;//Boolean variable to recognize an already sorted array or sub array which reduces the number of recursive calls.
        // z will be passed as first index for next recursive call of left Sub-array
        // v will be passed as first index for next recursive call of Right Sub-array
        // i and j are iterating variables
        i=z=First;
        j=v=Last;
        K=Data[Last];// K is to check if the array is sorted and to update the N
        while (i<=j)
        {
            if(Data[i]<=Pivot)
            {
                Countless++;// Counting smaller elements than the pivot
                Sumless+=Data[i]; // Sum of smaller elements than the pivot
                if(N == true && K>=(Pivot-Data[i]))
                    //If K is increasing than elements are increasing in sorted order
                    K = Pivot - Data[i];
                else // Else not in sorted order
                    N = false;
                i++;
            }
            else
            {
                Countlarge++;// Counting larger elements than the pivot
                Sumlarge += Data[i];// Sum of larger elements than the pivot
                Swap(&Data[i], &Data[j]);//Swap the elements
                j--;
            }
        }
        // For Left Sub-array containing smaller elements than pivot
        if(Countless != 0)
        {
            Pivot1= Sumless/Countless; //Average of the values smaller than the pivot is passed as the pivot value for left Sub-array
            if (N != true) // If sub-array is not sorted
                QuickSort_using_DynamicPivot(Data, z, i-1, Pivot1);
        }
        // For Right Sub-array containing larger elements than pivot
        if(Countlarge != 0)
        {
            Pivot2= Sumlarge/Countlarge;//Average of the values larger than the pivot is passed as the pivot value for Right Sub-array
            QuickSort_using_DynamicPivot(Data, i, v, Pivot2);
        }
    }
}

// Partition_last_Element_pivot the array using last element as pivot
int Partition_last_Element_pivot (int arr[], int l, int r)
{
    int pivot = arr[r]; // for storing pivot
    int i = (l - 1);

    for (int j = l; j <= r- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}
void Quick_sort_LastElement_Pivot(int arr[], int left, int right) // Left and right are the same first and the last index of array respectively
{
    if(left<right)
    {
    int pivot;
    pivot = Partition_last_Element_pivot(arr,left,right);
    Quick_sort_LastElement_Pivot(arr,left, pivot-1);
    Quick_sort_LastElement_Pivot(arr,pivot+1,right);
    }
}
int partition_pivot_median(int array[], int low, int high)
{
    int pivot;
	int mid = (low + high) / 2;
	if (array[mid] < array[low])
		Swap(&array[mid], &array[low]);
	if (array[high] < array[low])
		Swap(&array[high], &array[low]);
	if (array[high] < array[mid])
		Swap(&array[high], &array[mid]);
	Swap(&array[mid], &array[high-1]);

	pivot = array[high-1];

	return Partition_last_Element_pivot(array, low, high);
}
void Quick_sort_with_median(int arr[], int left, int right)
{
    if(left<right)
    {
    int pivot;
    pivot = partition_pivot_median(arr,left,right);
    Quick_sort_with_median(arr,left, pivot-1);
    Quick_sort_with_median(arr,pivot+1,right);
    }
}
int Partition_pivot_first(int array[], int low, int high)
{
	int pivot = array[low];
	int i = (low + 1);

	for (int j = low + 1; j <= high; j++) {
		if (array[j] < pivot) {
		if (j != i) {
		Swap(&array[i], &array[j]);
		}
		i++;
		}
	}
	Swap(&array[i - 1], &array[low]);
	return (i - 1);
}
void Quick_sort_with_first(int arr[], int left, int right) // Left and right are the same first and the last index of array respectively
{
    if(left<right)
    {
    int pivot;
    pivot = Partition_pivot_first(arr,left,right);
    Quick_sort_with_first(arr,left, pivot-1);
    Quick_sort_with_first(arr,pivot+1,right);
    }
}
//Main Function
int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    srand(time(0));

    cout<< "\t\t\t\tCode for Enhancing QuickSort Algorithm using a Dynamic Pivot Selection Technique"<<endl;
   // int inputs[5] = {1000,5000,10000,50000,100000};
   // for (int x = 0; x<5; x++){
    int Size=100000; //inputs[x]; // Size of Array
    int arr[Size],arr1[Size],arr2[Size],arr3[Size];
    cout<< "\nGenerating Random numbers for Array...."<<endl;
    //Generating 50 random numbers and storing them in array
    for (int i = Size; i > 0; i--)
        arr[i] = i/*rand()%20000*/;
     for (int i = 0; i < Size; i++)
        arr1[i] = arr[i];
    for (int i = 0; i < Size; i++)
        arr2[i] = arr[i];
    for (int i = 0; i < Size; i++)
        arr3[i] = arr[i];
    cout << "\n\nBefore Sorting:" << endl;
    /*for(int i=0; i<Size; i++)
        cout<<arr[i]<<" ";*/
    //Calling the Quick Sort function
//    auto t1 = high_resolution_clock::now();
//        Quick_sort_with_first(arr3,0,Size-1);
//        /*cout << "\n\nQuick Sort with first element as pivot :" << endl;
//        for(int i=0; i<Size; i++)
//            cout<<arr3[i]<<" ";*/
//    auto t2 = high_resolution_clock::now();
//    auto ms_int1 = duration_cast < milliseconds > (t2 - t1);
//    duration < double, std::milli > ms_double1 = t2 - t1;
//    std::cout << "\n Quick Sort with first element as pivot time is =" << ms_int1.count() << " ms\n";
//    std::cout << "\t\t" << ms_double1.count() << "ms";

//    auto t3 = high_resolution_clock::now();
//        Quick_sort_LastElement_Pivot(arr1,0,Size-1);
//        /*cout << "\n\nQuick Sort using last element as pivot: " << endl;
//        for(int i=0; i<Size; i++)
//            cout<<arr1[i]<<" ";*/
//    auto t4 = high_resolution_clock::now();
//    auto ms_int2 = duration_cast < milliseconds > (t4 - t3);
//    duration < double, std::milli > ms_double2 = t4 - t3;
//    std::cout << "\n Quick Sort using last element as pivot time is =" << ms_int2.count() << " ms\n";
//    std::cout << "\t\t" << ms_double2.count() << "ms";

    auto t5 = high_resolution_clock::now();
        Quick_sort_with_median(arr2,0,Size-1);
        /*cout << "\n\nQuick Sort with pivot as median of three:" << endl;
        for(int i=0; i<Size; i++)
            cout<<arr2[i]<<" ";*/
    auto t6 = high_resolution_clock::now();
    auto ms_int3 = duration_cast < milliseconds > (t6 - t5);
    duration < double, std::milli > ms_double3 = t6 - t5;
    std::cout << "\n Quick Sort with pivot as median of three time is =" << ms_int3.count() << " ms\n";
    std::cout << "\t\t" << ms_double3.count() << "ms";

//    auto t7 = high_resolution_clock::now();
//        QuickSort_using_DynamicPivot(arr, 0, Size-1, arr[Size-1]);
//        /*cout << "\n\nDynamic Pivot Sorting:" << endl;
//        for(int i=0; i<Size; i++)
//            cout<<arr[i]<<" ";*/
//    auto t8 = high_resolution_clock::now();
//    auto ms_int4 = duration_cast < microseconds > (t8 - t7);
//    duration < double, std::micro > ms_double4 = t8 - t7;
//    std::cout << "\n Dynamic Pivot Sorting time is =" << ms_int4.count() << " ms\n";
//    std::cout << "\t\t" << ms_double4.count() << "ms";

    //}
    return 0;
}
