//============================================================================
// Name        : 150160223.cpp
// Author      : Selin Eylul Bilen
//============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <fstream>

using namespace std;
using namespace std::chrono;

void swap(int *x, int *y)
{
	int temp; 
	temp = *x;
	*x = *y;
	*y = temp;
}
 
int Partition(int array[], int lowest, int highest)
{
	int pivot, index, i;
	index = lowest;
	pivot = highest;
 
	for(i=lowest; i < highest; i++)
	{
		if(array[i] < array[pivot])
		{
			swap(&array[i], &array[index]);
			index++;
		}
	}

	swap(&array[pivot], &array[index]);
 
	return index;
}
 

int RandomPivotPartition(int array[], int lowest, int highest)
{
	int pv, n, temp;
	n = rand();
	pv = lowest + n%(highest-lowest+1);
	swap(&array[highest], &array[pv]);
 
	return Partition(array, lowest, highest);
}
 
int quicksort(int array[], int lowest, int highest)
{
	int index;
	if(lowest < highest)
	{
		index = RandomPivotPartition(array, lowest, highest);
		quicksort(array, lowest, index-1);
		quicksort(array, index+1, highest);
	}
	return 0;
}
int main(int argc, char*argv[]){
    clock_t t;
    t=clock();
	ifstream iFile;
	iFile.open("data.txt");
	int Num = atoi(argv[1]);
	int temp;
	string line;
	int *arr = new int[Num];
    int a = 0;
    while(a < Num){
        getline(iFile, line);
        istringstream isstemp(line);
        isstemp >> temp;
        arr[a] = temp;
        a++;
    }
	int size = Num;
    quicksort(arr, 0, size - 1);
	string outName= "sorted.txt";
    ofstream Out;
    Out.open(outName.c_str());
    int b = 0;
    while (b < size){
        Out<< arr[b] << endl;
        b++;
    }
    Out.close();
    t = clock()-t;
    cout<<(float(t)/CLOCKS_PER_SEC)<<endl;
    return 0;
}


	
	


		
