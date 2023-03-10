#include "header.h"

int compCounter = 0;

//returns a pointer to a new node with passed in value;
Node* newNode(int value)
{
    Node* n1 = new Node;
    n1->setValue(value);
    return n1;
}
//Can be used to populate a random array of 5 elements
void GenerateArray(int* array)
{
    int newNum = 0;
    bool isIn = false;

    srand((unsigned)time(0));

    for (int i = 0; i < 5; i++) {
        newNum = (rand() % 100);
        for (int x = 0; x < 5; x++)
        {
            if (array[x] == newNum)
            {
                isIn = true;
            }
        }
        if (isIn == true)
        {
            isIn = false;
            i--;
        }
        else
        {
            array[i] = newNum;
        }
    }

}

void PrintArray(int* array)
{
    std::cout << "[";
    for (int l = 0; l < 5; l++)
    {
        if (l != 4)
        {
            std::cout << array[l] << ",";
        }
        else
        {
            std::cout << array[l];
        }
    }
    std::cout << "]\n";
}

void PrintComparisons()
{
    compCounter++;
    // std::cout << compCounter << " " << "Comparisons!\n";
}

void SortArray(int* array)
{
   /* int* one = array, *two = array + 1, *three = array + 2, *four = array + 3, *five = array + 4;*/
    LinkedListHolder L1;
    
    Node* n1;
    Node n2;
    int positionOfLast = 0;
    int positionOfa = 0;
    int positionOfE = 4;
    PrintComparisons();
    if (array[0] < array[1]) // is a < b?
    {
        positionOfa = 0;
        n1 = newNode(array[0]);
        L1.InsertAtFront(n1);
        n1 = newNode(array[1]);
        L1.InsertAtEnd(n1);

    }
    else
    {
        positionOfa = 1;
        n1 = newNode(array[1]);
        L1.InsertAtFront(n1);
        n1 = newNode(array[0]);
        L1.InsertAtEnd(n1);
       
    }
    PrintComparisons();
    if (array[2] < array[3])// is c < d?
    {
        positionOfLast = 2;
        PrintComparisons();
        if (array[3] > L1.getTail()->getValue()) // is d > a ? ie, do we need our sorted "top list" to be a-d or d-a
        {
            n1 = newNode(array[3]);
            L1.InsertAtEnd(n1);
        }
        else
        {
            n2 = *(L1.getTail());
            L1.WipeList();
            n1 = newNode(array[2]);
            L1.InsertAtFront(n1);
            n1 = newNode(array[3]);
            L1.InsertAtEnd(n1);
            L1.InsertAtEnd(&n2);
            positionOfLast = positionOfa;
        }

    }
    else //array[2] > array[3]
    {
        positionOfLast = 3;
        PrintComparisons();
        if (array[2] > L1.getTail()->getValue()) // is d > a ? ie, do we need our sorted "top list" to be a-d or d-a
        {
            n1 = newNode(array[2]);
            L1.InsertAtEnd(n1);
        }
        else
        {
            n2 = *(L1.getTail());
            L1.WipeList();
            n1 = newNode(array[3]);
            L1.InsertAtFront(n1);
            n1 = newNode(array[2]);
            L1.InsertAtEnd(n1);
            L1.InsertAtEnd(&n2);
            positionOfLast = positionOfa;
        }


    }
    n1 = newNode(array[positionOfE]);
    L1.InsertE(n1);
    n1 = newNode(array[positionOfLast]);
    L1.InsertLast(n1);
    L1.FinalizeArray(array);
    
}
//Returns true if array is sorted, otherwise false
bool TestArray(int* array)
{
    return std::is_sorted(array, array + 5);
}

int main(void)
{
    int array[5] = {1,2,3,4,5};
    int counter_array[5] = {1,2,3,4,5};
    int count = 0;
    int passed = 0;
    do 
    {
        std::copy(counter_array, counter_array+5,array);
        SortArray(array);
        if (TestArray(array))
        {
            std::cout << "Final Array: ";
            PrintArray(array);
            std::cout << "Permutation Tested: "; 
            PrintArray(counter_array);
            std::cout << "\n";
            passed++;
        }
        else
        {
            PrintArray(array);
            std::cout << "Failed: "; PrintArray(counter_array); std::cout << "\n";
        }
        count++;
        compCounter = 0;
    } while (std::next_permutation(counter_array, counter_array + 5));
    std::cout << "Tests Passed: " << passed << "/" << count << "\n";

    return 0;
}

