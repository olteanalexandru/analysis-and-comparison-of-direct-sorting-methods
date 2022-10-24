
#include "Profiler.h"
#include <iostream>

using namespace std;

Profiler profiler("Favourable_case");

void selectionSort(int string_length, int string_numbers[]) //selection sort order
//add comments
{
    int aux;

   Operation Assignments = profiler.createOperation("Selection_Sort_Assignments", string_length);
    Operation Comparison = profiler.createOperation("Selection_Sort_Comparii", string_length);
//the for loop below is used to sort the array in ascending order 
    for (int i = 0; i < string_length - 1; i++)
    {
        int min = i;
        //the for loop below is used to find the minimum element in the unsorted array
        for (int j = i + 1; j < string_length; j++)
        {
            Comparison.count();
            //if the element at j is less than the element at min, then update min
            if (string_numbers[j] < string_numbers[min])
            {
                min = j;
            }}
        Assignments.count(3);
        //swap the element at min with the element at i
        aux = string_numbers[min];
        string_numbers[min] = string_numbers[i];
        string_numbers[i] = aux;
    }
    profiler.addSeries("Selection_Sort_Total", "Selection_Sort_Assignments", "Selection_Sort_Comparari");
}

void bubbleSort(int string_length, int string_numbers[] ) //bubble sort order

{
    int aux;
    Operation Assignments = profiler.createOperation("Bubble_Sort_Assignments", string_length);
    Operation Comparison= profiler.createOperation("Bubble_Sort_Comparii", string_length);
//the for loop below is used to sort the array in ascending order
    for (int i = 0; i < string_length - 1; i++)
    {
        //the for loop below is used to sort the array in ascending order
        for (int j = 0; j < string_length - i - 1; j++)
        {
            Comparison.count();
            //if the element at j is greater than the element at j+1, then swap them
            if (string_numbers[j] > string_numbers[j + 1])
            {
                Assignments.count(3);
                aux = string_numbers[j];
                string_numbers[j] = string_numbers[j + 1];
                string_numbers[j + 1] = aux;
            }}}


    profiler.addSeries("Bubble_Sort_Total", "Bubble_Sort_Assignments", "Bubble_Sort_Comparari");
}


int binarySearch(int string_numbers[], int string_length, int left, int right, int* comparison) //binarySearch order
    
    {
        //if the left index is greater than the right index, then the element is not present in the array
        int middle = (left + right) / 2;
        //if the element is present at the middle index, then return the middle index
        (*comparison)++;
        if (left > right)
        {
            return -1;
        }
        //if the element is less than the element at the middle index, then search in the left subarray
        if (string_numbers[middle] == string_length)
        {
            return middle;
        }
        //if the element is greater than the element at the middle index, then search in the right subarray
        else if (string_numbers[middle] > string_length)
        {
            return binarySearch(string_numbers, string_length, left, middle - 1, comparison);
        }
        // if the element is less than the element at the middle index, then search in the right subarray
        else
        {
            return binarySearch(string_numbers, string_length, middle + 1, right, comparison);
        }}

        void insertionSort(int string_length, int string_numbers[]) //insertion sort order
    
    {
        int aux;
    
         Operation Assignments = profiler.createOperation("Insertion_Sort_Assignments", string_length);
         Operation Comparison = profiler.createOperation("Insertion_Sort_Comparii", string_length);
        //the for loop below is used to sort the array in ascending order
        for (int i = 1; i < string_length; i++)
        {
            aux = string_numbers[i];
            
            Assignments.count();
            int j = i - 1;
            //the while loop below is used to find the correct position of the element at index i in the sorted subarray
            while (j >= 0 && string_numbers[j] > aux)
            {
                Assignments.count();
                //shift the element at index j to the right
                string_numbers[j + 1] = string_numbers[j];
                j--;
                Comparison.count();
            }
            Assignments.count();
            //insert the element at index i in the correct position
            string_numbers[j + 1] = aux;
        }
    
        profiler.addSeries("Insertion_Sort_Total", "Insertion_Sort_Assignments", "Insertion_Sort_Comparari");
    }

void binaryInsertionSort(int string_length, int string_numbers[]) //binary insertion sort order
    
    {
        int aux;
        int comparison = 0;
        int position;
    
      Operation  Assignments  = profiler.createOperation("Binary_Insertion_Sort_Assignments", string_length);
      Operation  Comparison = profiler.createOperation("Binary_Insertion_Sort_Comparari", string_length);
    //the for loop below is used to sort the array in ascending order
        for (int i = 1; i < string_length; i++)
        {
            aux = string_numbers[i];
            Assignments.count();
            //find the correct position of the element at index i in the sorted subarray
            position = binarySearch(string_numbers, aux, 0, i - 1, &comparison);
            //the for loop below is used to shift the elements to the right
            if (position == -1)
            {
                position = i;
            }
            for (int j = i - 1; j >= position; j--)
            {
                Assignments.count();
                string_numbers[j + 1] = string_numbers[j];
            }
            Assignments.count();
            //insert the element at index i in the correct position
            string_numbers[position] = aux;
        }
    
        Comparison.count(comparison);
        profiler.addSeries("Binary_Insertion_Sort_Total", "Binary_Insertion_Sort_Assignments", "Binary_Insertion_Sort_Comparii");
    }



int main()
{
 int string_numbers[10000];
    char character;
   
    do
    {
        cout << "Choose the running variant: " << endl << "1. Testing" << endl << "2. Reports" << endl;
        
        cin >> character;
        cout << endl;

        if (character == '2')
        {
            cout << "Generating report. Please wait..." << endl;
            // For favorable case
            for (int i = 100; i <= 10000; i += 100) // step of 100 to 10000
            {

                FillRandomArray(string_numbers, i, 10, 100000, true, 1);
                 
                int string_numbers2[sizeof(string_numbers) / sizeof(int)];
                int string_numbers3[sizeof(string_numbers) / sizeof(int)];
                int string_numbers4[sizeof(string_numbers) / sizeof(int)];
                
                copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers2);
                copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers3);
                copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers4);

                bubbleSort(i, string_numbers);
                insertionSort(i, string_numbers2);
                binaryInsertionSort(i, string_numbers3);
                selectionSort(i, string_numbers4);

            }

            profiler.createGroup("1_BUBBLE_SORT_Caz_Favorabil_Number_Assignments", "Bubble_Sort_Assignments");
            profiler.createGroup("1_BUBBLE_SORT_Caz_Favorabil_Numar_Comparari", "Bubble_Sort_Comparari");
            profiler.createGroup("1_BUBBLE_SORT_Caz_Favorabil_Number_Total_Operatii", "Bubble_Sort_Total");

            profiler.createGroup("2_INSERTION_SORT_Caz_Favorabil_Number_Assignments", "Insertion_Sort_Assignments");
            profiler.createGroup("2_INSERTION_SORT_Caz_Favorabil_Numar_Comparari", "Insertion_Sort_Comparari");
            profiler.createGroup("2_INSERTION_SORT_Caz_Favorabil_Number_Total_Operatii", "Insertion_Sort_Total");

            profiler.createGroup("3_BINARY_INSERTION_SORT_Caz_Favorabil_Number_Assignments", "Binary_Insertion_Sort_Assignments");
            profiler.createGroup("3_BINARY_INSERTION_SORT_Caz_Favorabil_Numar_Comparari", "Binary_Insertion_Sort_Comparari");
            profiler.createGroup("3_BINARY_INSERTION_SORT_Caz_Favorabil_Number_Total_Operatii", "Binary_Insertion_Sort_Total");

            profiler.createGroup("4_SELECTION_SORT_Caz_Favorabil_Number_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("4_SELECTION_SORT_Caz_Favorabil_Numar_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("4_SELECTION_SORT_Caz_Favorabil_Number_Total_Operatii", "Selection_Sort_Total");

            profiler.createGroup("5_Caz_Favorabil_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments", "Binary_Insertion_Sort_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("5_Caz_Favorabil_Number_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari", "Binary_Insertion_Sort_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("5_Caz_Favorabil_Number_Total_Operatii", "Bubble_Sort_Total", "Insertion_Sort_Total", "Binary_Insertion_Sort_Total", "Selection_Sort_Total");

            profiler.createGroup("6_Caz_Favorabil_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("6_Caz_Favorabil_Number_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("6_Caz_Favorabil_Number_Total_Operatii", "Bubble_Sort_Total", "Insertion_Sort_Total", "Selection_Sort_Total");

            profiler.createGroup("7_Caz_Favorabil_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments");
            profiler.createGroup("7_Caz_Favorabil_Numar_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari");
            profiler.createGroup("7_Caz_Favorabil_Number_Total_Operatii", "Bubble_Sort_Total", "Insertion_Sort_Total");


            // For bad case

            profiler.reset("Unfavorable_case");
            for (int i = 100; i <= 10000; i += 100)
            {
                FillRandomArray(string_numbers, i, 10, 100000, true, 2);
                
                int string_numbers2[sizeof(string_numbers) / sizeof(int)];
                int string_numbers3[sizeof(string_numbers) / sizeof(int)];
                int string_numbers4[sizeof(string_numbers) / sizeof(int)];

                copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers2);
                copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers3);
                copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers4);

                bubbleSort(i, string_numbers);
                insertionSort(i, string_numbers2);
                binaryInsertionSort(i, string_numbers3);
                selectionSort(i, string_numbers4);

            }
           profiler.createGroup("1_BUBBLE_SORT_Case_Adverse_Number_Assignments", "Bubble_Sort_Assignments");
            profiler.createGroup("1_BUBBLE_SORT_Case_Unfavorable_Numar_Comparari", "Bubble_Sort_Comparari");
            profiler.createGroup("1_BUBBLE_SORT_Case_Unfavorabile_Number_Total_Operatii", "Bubble_Sort_Total");

            profiler.createGroup("2_INSERTION_SORT_Caz_Adverse_Number_Assignments", "Insertion_Sort_Assignments");
            profiler.createGroup("2_INSERTION_SORT_Caz_Unfavorabil_Numar_Comparari", "Insertion_Sort_Comparari");
            profiler.createGroup("2_INSERTION_SORT_Caz_Nafavorabil_Number_Total_Operatii", "Insertion_Sort_Total");

            profiler.createGroup("3_BINARY_INSERTION_SORT_Bad_Case_Number_Assignments", "Binary_Insertion_Sort_Assignments");
            profiler.createGroup("3_BINARY_INSERTION_SORT_Bad_Case_Number_of_Comparisons", "Binary_Insertion_Sort_Comparisons");
            profiler.createGroup("3_BINARY_INSERTION_SORT_Caz_Unfavorabile_Number_Total_Operatii", "Binary_Insertion_Sort_Total");

            profiler.createGroup("4_SELECTION_SORT_Caz_Unfavorabil_Numar_Attribuiri", "Selection_Sort_Attribuiri");
            profiler.createGroup("4_SELECTION_SORT_Caz_Unfavorabil_Numar_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("4_SELECTION_SORT_Caz_Nafavorabil_Number_Total_Operatii", "Selection_Sort_Total");


            profiler.createGroup("5_Unfavorable_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments", "Binary_Insertion_Sort_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("5_Caz_Nefavorabil_Numar_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari", "Binary_Insertion_Sort_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("5_Caz_Nefavorabil_Number_Total_Operatii", "Bubble_Sort_Total", "Insertion_Sort_Total", "Binary_Insertion_Sort_Total", "Selection_Sort_Total");


            profiler.createGroup("6_Unfavorable_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("6_Caz_Nefavorabil_Numar_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("6_Caz_Nefavorabil_Number_Total_Operatii", "Bubble_Sort_Total", "Insertion_Sort_Total", "Selection_Sort_Total");

            profiler.createGroup("7_Bad_Case_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments");
            profiler.createGroup("7_Caz_Nefavorabil_Numar_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari");
            profiler.createGroup("7_Unfavorable_Number_Total_Operations", "Bubble_Sort_Total", "Insertion_Sort_Total");

            // For statistical average case
            profiler.reset("Statistical_environment_case");
            for (int j = 1; j <= 5; j++)
            {
                for (int i = 100; i <= 10000; i += 100)
                {
                    FillRandomArray(string_numbers, i, 10, 100000);
                    
                    int string_numbers2[sizeof(string_numbers) / sizeof(int)];
                    int string_numbers3[sizeof(string_numbers) / sizeof(int)];
                    int string_numbers4[sizeof(string_numbers) / sizeof(int)];

                    copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers2);
                    copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers3);
                    copy(string_numbers, string_numbers + (sizeof(string_numbers) / sizeof(int)), string_numbers4);

                    bubbleSort(i, string_numbers);
                    insertionSort(i, string_numbers2);
                    binaryInsertionSort(i, string_numbers3);
                    selectionSort(i, string_numbers4);
                }
            }
            profiler.divideValues("Bubble_Sort_Assignments", 5);
            profiler.divideValues("Bubble_Sort_Comparisons", 5);
            profiler.divideValues("Bubble_Sort_Total", 5);
            profiler.createGroup("1_BUBBLE_SORT_Caz_Meediu_Statistic_Assignments", "Bubble_Sort_Assignments");
            profiler.createGroup("1_BUBBLE_SORT_Caz_Mediu_Statistic_Comparari", "Bubble_Sort_Comparari");
            profiler.createGroup("1_BUBBLE_SORT_Caz_Environment_Statistic_Total", "Bubble_Sort_Total");

            profiler.divideValues("Insertion_Sort_Assignments", 5);
            profiler.divideValues("Insertion_Sort_Comparii", 5);
            profiler.divideValues("Insertion_Sort_Total", 5);
            profiler.createGroup("2_INSERTION_SORT_Caz_Mediu_Statistic_Assignments", "Insertion_Sort_Assignments");
            profiler.createGroup("2_INSERTION_SORT_Caz_Mediu_Statistic_Comparari", "Insertion_Sort_Comparari");
            profiler.createGroup("2_INSERTION_SORT_Caz_Environment_Statistic_Total", "Insertion_Sort_Total");

            profiler.divideValues("Insertion_Sort_Assignments", 5);
            profiler.divideValues("Insertion_Sort_Comparii", 5);
            profiler.divideValues("Insertion_Sort_Total", 5);
            profiler.createGroup("3_BINARY_INSERTION_SORT_Caz_Meiu_Statistic_Assignments", "Binary_Insertion_Sort_Assignments");
            profiler.createGroup("3_BINARY_INSERTION_SORT_Caz_Mediu_Statistic_Comparari", "Binary_Insertion_Sort_Comparari");
            profiler.createGroup("3_BINARY_INSERTION_SORT_Caz_Environment_Statistic_Total", "Binary_Insertion_Sort_Total");

            profiler.divideValues("Selection_Sort_Assignments", 5);
            profiler.divideValues("Selection_Sort_Assignments", 5);
            profiler.divideValues("Selection_Sort_Comparisons", 5);
            profiler.createGroup("4_SELECTION_SORT_Caz_Meiu_Statistic_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("4_SELECTION_SORT_Caz_Meiu_Statistic_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("4_SELECTION_SORT_Caz_Environment_Statistic_Total", "Selection_Sort_Total");

            profiler.createGroup("5_Caz_Meiu_Statistic_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments", "Binary_Insertion_Sort_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("5_Caz_Mediu_Statistic_Number_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari", "Binary_Insertion_Sort_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("5_Caz_Meiu_Statistic_Number_Total_Operations", "Bubble_Sort_Total", "Insertion_Sort_Total", "Binary_Insertion_Sort_Total", "Selection_Sort_Total");

            profiler.createGroup("6_Caz_Mediu_Statistic_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments", "Selection_Sort_Assignments");
            profiler.createGroup("6_Caz_Mediu_Statistic_Number_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari", "Selection_Sort_Comparari");
            profiler.createGroup("6_Caz_Meiu_Statistic_Number_Total_Operations", "Bubble_Sort_Total", "Insertion_Sort_Total", "Selection_Sort_Total");

            profiler.createGroup("7_Caz_Meiu_Statistic_Number_Assignments", "Bubble_Sort_Assignments", "Insertion_Sort_Assignments");
            profiler.createGroup("7_Caz_Mediu_Statistic_Number_Comparari", "Bubble_Sort_Comparari", "Insertion_Sort_Comparari");
            profiler.createGroup("7_Caz_Miediu_Statistic_Number_Total_Operations", "Bubble_Sort_Total", "Insertion_Sort_Total");

            profiler.showReport();

        }
        //  ----------------------------------------------------------------
        //  ----------------------------------------------------------------

       else if (character == '1')
        {
            int string_size {};
            cout << "String size: ";
            cin >> string_size;

            int string_numbers2[50], string_numbers3[50], string_numbers4[50];

           

            for (int i = 0; i < string_size; i++)
            {
                cout << "string_numbers[" << i << "] = ";
                cin >> string_numbers[i];
            }

            for (int i = 0; i < string_size; i++)
            {
                string_numbers2[i] = string_numbers[i];
                string_numbers3[i] = string_numbers[i];
                string_numbers4[i] = string_numbers[i];
            }

             bubbleSort(string_size, string_numbers);
             binaryInsertionSort(string_size, string_numbers2);
             selectionSort(string_size, string_numbers3);
             insertionSort(string_size, string_numbers4);

             cout << endl;
             cout << "Bubble Sort: ";
             for (int i = 0; i < string_size; i++)
                     cout << string_numbers[i] << " ";
             cout << endl << endl;

             cout << "Binary Insertion Sort: ";
             for (int i = 0; i < string_size; i++)
                 cout << string_numbers2[i] << " ";
             cout << endl << endl;

             cout << "Selection Sort: ";
             for (int i = 0; i < string_size; i++)
                 cout << string_numbers3[i] << " ";
             cout << endl << endl;

             cout << "Insertion Sort: ";
             for (int i = 0; i < string_size; i++)
                 cout << string_numbers4[i] << " ";
             cout << endl << endl;
        }
        else
            cout << "Invalid input data!" << endl << endl;
    }
    while(character != '1' && character != '2');
}

