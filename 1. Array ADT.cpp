#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

template <class X>
class Arithematic
{
    private:
        X a;
        X b;
    
    public:
        Arithematic(X u=0, X v=0);
        X add(X u, X v);
        X substract(X u, X v);
        void printvalues(void);
        ~Arithematic();
};

template <class X>
Arithematic<X>::Arithematic(X u, X v)
{
    this->a = u;
    this->b = v;
}

template <class X>
X Arithematic<X>::add(X u, X v)
{
    return (u+v);
}

template <class X>
X Arithematic<X>::substract(X u, X v)
{
    // int value = 0;
    return (u > v ) ? (u - v) : (v-u);
}

template <class X>
void Arithematic<X>::printvalues(void)
{
    cout << "a: " << a << " b: " << b << endl;
}

template <class X>
Arithematic<X>::~Arithematic()
{

}

template <typename x>
struct defArray
{
    int *ptr;
    int length;
    int size;
};


template <typename x>
void displayArray(x z, int n)
{
    for (int i =0; i< n ; i++)
    {
        cout << z.ptr[i] << "  ";
    }
    cout << endl;
}

void swapPreviousIndex (int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

template <typename x>
int recursiveBinarySearch(x ar ,int lvalue, int hvalue, int keyValue)
{
    int midvalue = 0;
    if (lvalue <= hvalue)
    {
        midvalue = floor((lvalue + hvalue)/2);
        if (ar.ptr[midvalue] == keyValue)
        {
            return midvalue;
        }
        else if (ar.ptr[midvalue] > keyValue)
        {
            return recursiveBinarySearch(ar, lvalue, (midvalue-1), keyValue);
        }
        else if (ar.ptr[midvalue] < keyValue)
        {
            return recursiveBinarySearch(ar, (midvalue+1), hvalue, keyValue);
        }
    }
    else
    {
        return -1;
    }

    return 0;
}

template <typename x>
int dataValue(x array, char *operation, int indexNumber, int indexValue)
{
    switch (*operation)
    {
    case 'G':
    {
        if (indexNumber>0 && indexNumber <= array.size)
        {
            return array.ptr[indexNumber];
        }
        else   
            return -1;

        break;
    }

    case 'S':          // for set and sum of the array
    {

        switch (  *(operation+1)  )
        {
        case 'e':           // for setting the value at the index
        {
            if (indexNumber>0 && indexNumber <= array.size)
            {
                array.ptr[indexNumber] = indexValue;
                return array.ptr[0];            // if there is no pointer -> then return the value directly, and stored the return value in dereference value
            }
            else   
                return -1;
            break;
            
            #if 0
                template <typename x>
                int* setDataValue(x array, int indexNumber, int indexValue)
                {
                    if (indexNumber>0 && indexNumber <= array.size)
                    {
                        array.ptr[indexNumber] = indexValue;
                        return array.ptr;   

                        // Note: If we want to pass the address of starting of an array, then return type should be int*
                        // and the return value should be stored in the array address.

                    }
                }
            #endif
        }

        case 'u':           // for sum of the array
        {
            int sum = 0;

            for (int i=0; i< array.size ; i++)
            {
                sum += array.ptr[i];
            }
            return sum;
            break;
        }
        }

        return 0;
    }

    case 'M':            // for Maximum and Minimum Value
    {
        int maxValue = array.ptr[0];
        int minValue = array.ptr[0];

        for (int i=1; i< ( array.size ); i++)
        {
            if (array.ptr[i] > maxValue)
            {
                maxValue = array.ptr[i];
            }
            if ( array.ptr[i] < minValue )
            {
                minValue = array.ptr[i];
            }

        }

        switch ( *(operation+1) )
        {
            case 'a':       // for Maximum Value
            {
                return maxValue;
                break;
            }

            case 'i':       // for Minimum Value
            {
                return minValue;
                break;
            }
        }
    }

    case 'A':
    {
        int average = 0;
        char operationPerformed[] = "Sum";
        average = ( dataValue(array, operationPerformed, NULL, NULL)  / indexValue );
        return average;
        break;
    }
    }

    return 0;
}

template <typename x>
int * arrayOperations(x array, char *Operation, int sizeArray)
{
    switch (*Operation)
    {
        case 'R':       // for Reversing the array
        {
            switch (* (Operation + 1) )
            {
            case 'e':
            {
            
            #if 0       
                // This is one approach, by taking a pointer
                // Another approach is by takning array, and use two time for loops 

                int *dummyArray = new int[sizeArray];

                for (int i = (sizeArray-1) ; i>= 0; i--)
                {
                    *dummyArray = array.ptr[i];
                    dummyArray++;
                }

                dummyArray = dummyArray - (10);
                array.ptr = dummyArray;

                dummyArray = NULL;
                delete [] dummyArray;

                return array.ptr;   // return type is pointer, so we have to return the address and store the return value in address

            #endif

            // Third Approach is: by swapping the first value and last value;

                for (int i=0; i< (array.size /2 ) ; i++)
                {
                    int z = 0;
                    z = array.ptr[i] ;
                    array.ptr[i] = array.ptr[array.size - 1 - i];
                    array.ptr[array.size - 1 - i] = z;
                }

                return array.ptr;
                break;
            }

            case 'i':       // for Right Shifting
            {
                for (int i= (array.size - 1); i>= 0  ; i--)
                {
                    array.ptr[i] = array.ptr[i - 1];
                }
                array.ptr[0] = 0; 
                return array.ptr;
            }
            }
        }

        case 'L':       // for Left Shifting
        {
            for (int i=0; i< (array.size - 1) ; i++)
            {
                array.ptr[i] = array.ptr[i + 1];
            }
            array.ptr[9] = 0;
            return array.ptr;

            break;
        }

        case 'C':
        {
            int dummyValue = array.ptr[0];
            for (int i=0; i< (array.size - 1) ; i++)
            {
                array.ptr[i] = array.ptr[i + 1];
            }
            array.ptr[9] = dummyValue;
            return array.ptr;
            break;
        }

        case 'A':
        {
            int dummyValue = array.ptr[9];
            for (int i= (array.size - 1); i>= 0  ; i--)
            {
                array.ptr[i] = array.ptr[i - 1];
            }
            array.ptr[0] = dummyValue; 
            return array.ptr;
            break;
        }
    }
    return 0;
}

template <typename x>
int * arraySorting(x array, char *Operation, int sizeArray, int insertValue)
{
    switch ( *Operation )
    {
        case 'A':       // Sorting of an Array in Ascending Order
        {
            for ( int i =0; i < ( array.size ); i++)
            {
                for ( int j = 0 ; j < ( array.size ); j++)
                {
                    if ( array.ptr[i] < array.ptr[j] )
                    {
                        int dummyValue = 0;
                        dummyValue = array.ptr[i];
                        array.ptr[i] = array.ptr[j];
                        array.ptr[j] = dummyValue;
                    }
                }
            }
            return array.ptr;
            break;
        }

        case 'D':       // Sorting of an Array in Decending Order
        {
            for ( int i =0; i < ( array.size ); i++)
            {
                for ( int j = 0 ; j < ( array.size ); j++)
                {
                    if ( array.ptr[i] > array.ptr[j] )
                    {
                        int dummyValue = 0;
                        dummyValue = array.ptr[i];
                        array.ptr[i] = array.ptr[j];
                        array.ptr[j] = dummyValue;
                    }
                }
            }
            return array.ptr;
            break;
        }

        case 'I':       // Inserting an element in ascending order only
        {               // irrespective of any index
            char operation[] = "Ascending Order";
            array.ptr = arraySorting(array, operation , array.size, NULL);
            
            int *dummy = new int[array.size + 1];
            for (int i =0; i< array.size; i++ )
            {
                *dummy = array.ptr[i];
                dummy++;
            }

            dummy = dummy - array.size;
            array.ptr = dummy;
            dummy = NULL;
            delete [] dummy;

            int i = 9;      // Total array size is now 10 indexing 0

            while( array.ptr[i] > insertValue )
            {
                array.ptr[i + 1] = array.ptr[i];
                i--;
            }
        // When the condition gets false, then also the value of i will get decremented
        // and we do not want that -> so when storing the insertValue we need to
        // increment the value of i by 1.

            array.ptr[++i] = insertValue;

            return array.ptr;
            break;
        }

        case 'N':       // Negative numbers Sorting Order -> same as sorting of array in case 1
        {
            char operation[] =  "Ascending Order";
            array.ptr = arraySorting(array, operation , array.size, NULL);
            return array.ptr;

            break;
        }
    }
    return 0;
}

int sameIndexValue = 0;     // return value is int not the class, if the array size of reduced/increased then we cannot return the size

template <typename x>
int * setOperations(x array, int *extraArray, int extraArraySize, char * Operation)
{
    int *dummyArray = new int[array.size + extraArraySize];
    int a = 0, b = 0, c = 0;

    sameIndexValue = 0;

    cout << "First Array:  ";
    displayArray(array, array.size);

    cout << "Second Array: ";
    for ( int i =0; i < ( extraArraySize ); i++)
    {
        cout << extraArray[i] << " ";
    }

    cout << endl;

    switch ( * Operation )
    {
        case 'M':       
        {
            char operation[] =  "Ascending in sorting of Array";
            array.ptr = arraySorting(array, operation , array.size, NULL);
            cout << endl << "After Sorting: " << endl;
            cout << "First Array:  ";
            displayArray(array, array.size);

            cout << "Second Array: ";
            for ( int i =0; i < ( extraArraySize ); i++)
            {
                for ( int j = 0 ; j < ( extraArraySize ); j++)
                {
                    if ( extraArray[i] < extraArray[j] )
                    {
                        int dummyValue = 0;
                        dummyValue = extraArray[i];
                        extraArray[i] = extraArray[j];
                        extraArray[j] = dummyValue;
                    }
                }
            }   
            for (int i = 0; i< extraArraySize; i++)
            {
                cout << extraArray[i] << "  ";
            }
            cout << endl;

            while( (a < (array.size)) && (b < (extraArraySize)) )
            {
                if (array.ptr[a] > extraArray[b])
                {
                    dummyArray[c++] = extraArray[b++];
                }
                else if (array.ptr[a] < extraArray[b])
                {
                    dummyArray[c++] = array.ptr[a++];
                }
                
                else if (array.ptr[a] == extraArray[b])
                {
                    dummyArray[c++] = array.ptr[a++];
                    b++;
                    sameIndexValue++;
                }
                if ( (a == (array.size)) || (b == (extraArraySize) ) )
                {
                    if ( a == (array.size) )
                    {
                        while (b <= (extraArraySize) )
                        {
                            dummyArray[c++] = extraArray[b++];
                        }
                        break;
                    }
                    else if ( b == (extraArraySize) )
                    {
                        while (a <= (array.size) )
                        {
                            dummyArray[c++] = array.ptr[a++];
                        }
                        break;
                    }
                }
            }

            int *ptr = new int [array.size + extraArraySize - sameIndexValue];

            for (int i = 0; i< (array.size + extraArraySize - sameIndexValue) ; i++)
            {
                ptr[i] = dummyArray[i];
            }

            
            array.ptr = ptr;
            array.size = array.size + extraArraySize - sameIndexValue ;

            ptr = NULL;
            dummyArray = NULL;

            delete [] ptr;
            delete [] dummyArray;

            return array.ptr;
            
            break;
        }

        case 'S':
        {   
            break;
        }

        case 'U':
        {
            
        mergeLabel:
            int optionSection = 0;
            cout << endl <<
            "1. Without sorting \n" <<
            "2. With sorting \n" <<
            "Select your option: ";
            cin >> optionSection;
            cout << endl;
            
            switch(optionSection)
            {
                case 1:
                {
                    int matchFound = 0;
                    for (int i=0; i< array.size; i++)
                    {
                        dummyArray[i] = array.ptr[i];
                    }
                    c = array.size;

                    for (int i=0; i< extraArraySize; i++)
                    {
                        for (int j=0; j<array.size; j++)
                        {
                            if (array.ptr[j] == extraArray[i])
                            {
                                matchFound = 1;
                                break;
                            }
                            else
                            {
                                matchFound = 0;
                            }
                        }
                        if (!matchFound)
                        {
                            dummyArray[c++] = extraArray[i];
                        }
                    }

                    array.ptr = dummyArray;
                    dummyArray = NULL;
                    delete [] dummyArray;

                    return array.ptr;
                    break;
                }

                case 2:
                {
                    char operation[] = "Ascending";
                    array.ptr = arraySorting(array, operation , array.size, NULL);
                    
                    for (int i=0; i< extraArraySize; i++)
                    {
                        for (int j=0; j< extraArraySize; j++)
                        {
                            if (extraArray[i] < extraArray[j])
                            {
                                int dummyVariable = 0;
                                dummyVariable = extraArray[i];
                                extraArray[i] = extraArray[j];
                                extraArray[j] = dummyVariable;
                            }
                        }
                    }
                    
                    cout << endl << "After sorting of Array " << endl;
                    cout << "First Array: ";
                    displayArray(array, array.size);
                    cout << "Second Array: ";
                    for (int i=0; i< extraArraySize; i++)
                    {
                        cout << extraArray[i] << " " ;
                    }
                    cout << endl;
                    
                    while( (a < (array.size)) && (b < (extraArraySize)) )
                    {
                        if (array.ptr[a] > extraArray[b])
                        {
                            dummyArray[c++] = extraArray[b++];
                        }
                        else if (array.ptr[a] < extraArray[b])
                        {
                            dummyArray[c++] = array.ptr[a++];
                        }
                        
                        else if (array.ptr[a] == extraArray[b])
                        {
                            dummyArray[c++] = array.ptr[a++];
                            b++;
                            sameIndexValue++;
                        }
                        if ( (a == (array.size)) || (b == (extraArraySize) ) )
                        {
                            if ( a == (array.size) )
                            {
                                while (b <= (extraArraySize) )
                                {
                                    dummyArray[c++] = extraArray[b++];
                                }
                                break;
                            }
                            else if ( b == (extraArraySize) )
                            {
                                while (a <= (array.size) )
                                {
                                    dummyArray[c++] = array.ptr[a++];
                                }
                                break;
                            }
                        }
                    }

                    int *ptr = new int [array.size + extraArraySize - sameIndexValue];

                    for (int i = 0; i< (array.size + extraArraySize - sameIndexValue) ; i++)
                    {
                        ptr[i] = dummyArray[i];
                    }

                    
                    array.ptr = ptr;
                    array.size = array.size + extraArraySize - sameIndexValue ;

                    ptr = NULL;
                    dummyArray = NULL;

                    delete [] ptr;
                    delete [] dummyArray;

                    return array.ptr;
                    break;
                }

                default:
                {
                    cout << "Wrong option Selected...\t Try again "<< endl;
                    goto mergeLabel;
                    break;
                }
            }

            break;
        }

        case 'I':
        {
            break;
        }

        case 'D':
        {

        }
    }

    return 0;
}

template <typename x>
int * findOperation(x array, char *operation)
{
    cout << "The array is: ";
    for (int i =0; i<array.size; i++)
    {
        cout << array.ptr[i] << "  ";
    }
    cout << endl;
    switch (*operation)
    {
        case 'S':      //    sorted array
        {

            switch (*(operation + 13))
            {
                case 'M':       // Missing Single/Multiple Elements
                {
                    // *** Method 1: taking difference of next element to the present element ** //
                    int difference = 0;
                    difference = array.ptr[1] - array.ptr[0];
                    if ( (array.ptr[2] - array.ptr[1]) != difference)
                    {
                        cout << "Problem in the array...";
                        return array.ptr;
                    }

                    cout << "The Missing Elements are: " ;

                    for (int i =0; i< ( array.size - 1 ); i++)
                    {
                        if (array.ptr[i+1] - array.ptr[i] != difference)
                        {
                            while (difference < (array.ptr[i+1] - array.ptr[i]))
                            {
                                cout << array.ptr[i] + difference << " ";
                                difference++;
                            }
                        }
                        difference = array.ptr[1] - array.ptr[0];
                    }

                    // **** Method: 2 Using the sum of the Array ******** //
                #if 0       // Formulas
                        Sum = (n/2)*(First Element + Last Element);        -> (n/2) * (a + l);
                    or  Sum = (n/2)*((2*First Element) + (n-1)difference); -> (n/2) *(2a + (n-1)*d);
                    or  Sum = (n*(n+1)) / 2;   
                #endif
                break;
                }

                case 'D':
                {
                    for (int i =0; i< (array.size - 1) ; i++)
                    {
                        int duplicateElements = 0;
                        int changePosition = 0;
                        for(int j = (i+1); j< array.size ; j++)
                        {
                            if ( array.ptr[i] == array.ptr[j] )
                            {
                                duplicateElements++;
                                changePosition = j;
                            }
                        }
                        if (duplicateElements)
                         {
                            cout << "The element " << array.ptr[i] << " is present " << duplicateElements + 1 << " times "  << endl;
                            i = changePosition;
                         }   
                    }
                    break;
                }
            }
            break;
        }

        case 'U':       // Multiple Missing Element in unsorted Array
        {
           int maxValue = 0;
           for ( int i = 0; i< (array.size) ; i++)
           {
               if (array.ptr[i] > maxValue)
               {
                   maxValue = array.ptr[i];
               } 
           }

           int dummyVar[maxValue + 1] = {0};

           for (int i = 0; i< array.size; i++)
           {
               dummyVar[array.ptr[i]] += 1;
           } 

            switch (*(operation + 15))
            {
                case 'M':
                {
                    cout << "Missing Elements at positions are: ";
                    for (int i =0 ; i < (maxValue + 1) ; i++)
                    {
                        if ( dummyVar[i] == 0)
                        {
                            cout << i << " ";
                        }
                    }
                    break;
                }

                case 'D':
                {
                #if 0       // Method 1: Increment the repeated positions by 1
                    cout << "Duplicate Elements at positions are: " << endl;
                    for (int i =0 ; i < (maxValue + 1) ; i++)
                    {
                        if ( dummyVar[i] > 1)
                        {
                            cout << i << " is present " << dummyVar[i] << " times " << endl;
                        }
                    }

                #endif

                // Method 2: At repeating positions -> Replace the value by -1
                    int duplicateElements = 0;
                    int duplicatePosition = 0;
                    for (int i=0;  i < (array.size - 1) ; i++ )
                    {
                        int countDuplicateElements = 0;
                        for (int j = (i+1) ; j < array.size ; j++)
                        {
                            if ( (array.ptr[i] == array.ptr[j]) && (array.ptr[j] != -1) )
                            {
                                countDuplicateElements++;
                                array.ptr[j] = -1;
                            }
                        }

                        if (countDuplicateElements)
                        {
                            cout << array.ptr[i] << " is present " << countDuplicateElements + 1 << " times " << endl;
                            
                        }
                    }
                    break;
                }
            }
        }

        case 'R':       // Resultant Sum of Element = k
        {
            int expectedResult = 0;
            
            cout << "Enter the value whose Resultant (the sum of two elements) you want ";
            cin >> expectedResult;

            for (int i =0; i< (array.size - 1) ; i++)
            {
                for (int j = (i+1) ; j < array.size; j++ )
                {
                    if ( (array.ptr[i] + array.ptr[j]) == expectedResult )
                    {
                        cout << array.ptr[i] << " + " << array.ptr[j] << " = " << expectedResult << endl;
                    }
                }
            }
            break;
        }
    }
    return 0;
}

// *************************************************************** //


int main()
{
// ************ using Heap Array ******************** //
    int operationsElement;
    defArray <int> arr;
    // cout << "Enter the sizeof the array:  ";
    // cin >> arr.size;
    arr.size = 10;
    arr.ptr = new int[arr.size];

    // cout << "\nEnter the numbers in the array "<< endl;
    // for (int i=0; i< arr.size ; i++)
    // {
    //     cout << "Enter at " << i+1 << " position ";
    //     cin >> (arr.ptr[i]);
    // }
    for (int i=0; i <10 ; i++)
    {
        arr.ptr[i] = (i+1);
    }
    arr.ptr[5] = 50;
    arr.ptr[8] = 100;
    arr.ptr[3] = 0;
    
    cout << "\nWhat operations you want to perferm: " << endl;
    cout << "1. Adding More Element \n"  << 
            "2. Inserting a new Element \n"  <<
            "3. Deleting an Element \n"  <<
            "4. Search an Element \n" <<
            "5. Array ADT (Get, Set, Sum, Avg, Max, Min) \n" <<
            "6. Operations: Reverse/Shifting on Array \n" <<
            "7. Sorting of an Array \n" <<
            "8. Operations: Merging/Set/ Compare on Array \n" <<
            "9. Finding Missing Element in an Array \n" <<
            "\n\nEnter your choice: ";
    cin >> operationsElement;


    switch (operationsElement)
    {

    case 1:      // Adding Elements
    {
        int lengthofMoreElements = 0;
        cout << "\nEnter the length of more elements: ";
        cin >> lengthofMoreElements ;

        #if 0
            If we are increasing the sizeof ptr as  arr.ptr = new int [arr.size + 
            lengthofMoreElements]. t will delete all the stored value in 
            arr.ptr & reinitialize the array
        #endif

        int *q;
        q = new int [arr.size + lengthofMoreElements];
        for (int i =0; i<arr.size; i++)
        {
            q[i] = arr.ptr[i];
        }
        arr.ptr = q;
        q = NULL;
        delete [] q;

        cout << "\nEnter the numbers in the array "<< endl;
        for (int i= arr.size; i< (arr.size + lengthofMoreElements) ; i++)
        {
            cout << "Enter at " << i << " position ";
            cin >> (arr.ptr[i]);
        }
        displayArray(arr, (arr.size + lengthofMoreElements));
        break;
    } 

// ******************   Case 2    *************************** //

    case 2:     // Inserting an Element
    {
        int lengthofMoreElements = 0;
        int insertionElements = 0;
        int insertionPosition = 0;
        cout << "\nArray size "<< arr.size << endl;
        cout << "\nAt what postion you want to insert the Element: ";
        cin >> insertionPosition ;

        cout << "What element you want to insert: ";
        cin >> insertionElements ;

        int *q;
        q = new int[arr.size + 1];
        for (int i=0; i< (arr.size+1); i++)
        {
            q[i] = arr.ptr[i];
        }
        arr.ptr = q;
        q = NULL;
        delete [] q;

        for (int i = (arr.size-1); i >= (insertionPosition-1); i--)
        {
            arr.ptr[i+1] = arr.ptr[i];
        }

        arr.ptr[insertionPosition-1] = insertionElements;

        cout << "\nThe new array is: " << endl;
        for (int i=0; i< (arr.size + 1); i++)
        {
            cout << arr.ptr[i] << "  " ;
        }

        break;
    }  

// ******************   Case 3    *************************** //

    case 3:     // delete an element
    {
        int deleteElements = 0;
        int deletePosition = 0;

        cout << "\nAt what postion you want to delete the Element: ";
        cin >> deletePosition ;

        for ( int i = (deletePosition-1) ; i < arr.size ; i++ )
        {
            arr.ptr[i] = arr.ptr[i+1];
        }

        int *q;
        q = new int[arr.size - 1];
        for (int i=0; i< (arr.size - 1); i++)
        {
            q[i] = arr.ptr[i];
        }
        arr.ptr = q;
        q = NULL;
        delete [] q;

        cout << "\nThe new array is: " << endl;

        displayArray(arr, (arr.size-1) );

        break;
    }

// ******************   Case 4    *************************** //

    case 4:     // Searching of any Element: Linear/ Binary Search
    {
        int searchElements = 0;
        char typeofSearch = 0;  
        int matchFound = 0;
        int matchFoundAtPosition = 0;
        cout << "\nEnter the Element you want to search: ";
        cin >> searchElements;

        cout << "\nDo you want Linear/Binary search (L/B): ";
        cin >> typeofSearch;

        switch (typeofSearch)
        {
            case 'L':
            {
                for (int i=0; i< arr.size; i++)
                {
                    if (searchElements == arr.ptr[i])
                    {
                        matchFoundAtPosition = i;
                        matchFound = 1;
                        break;
                    }
                }

                if (matchFound)
                {
                    cout << "\nMatch is found at position " << (matchFoundAtPosition+1) << endl;
                    swapPreviousIndex(&arr.ptr[matchFoundAtPosition],&arr.ptr[matchFoundAtPosition-1]);
                }
                cout << "\nNew Array after swapping is: " << endl;
                displayArray(arr, arr.size);

                break;
            }

            case 'B':
            {
                matchFoundAtPosition = recursiveBinarySearch(arr, 0, arr.size, searchElements);
                if (matchFoundAtPosition != -1)
                {
                    cout << "\nMatch is found at "<< (matchFoundAtPosition + 1) << endl;
                }
                else
                {
                    cout << "\nMatch is not found"<< endl;
                }
                break;
            }
        }
        break;
    }

// ******************   Case 5    *************************** //

    case 5:     // Array ADT
    {
        int optionSelection = 0;
        cout <<  
            "1. Get the data from the index \n" <<
            "2. Set the value in the index \n" <<
            "3. Find the maximum value in the array \n" <<
            "4. Find the minimum value in the array \n" <<
            "5. Get the sum of the values stored in the array \n" <<
            "6. Get the average of the values stored in the array \n" << 
            "\nSelect your operation: " ;
        cin >> optionSelection;

        switch (optionSelection)
        {
            case 1:
            {
                getLabel: 
                int index = 0;
                int indexValue = 0;
                char operationPerformed[] = "Get";
                cout << "At what index you want to get the value: ";
                cin >> index;
                indexValue = dataValue(arr, operationPerformed, index, NULL);
                if (indexValue != -1)
                {
                    cout << "The value at " << index << " is " << indexValue << endl;
                }
                else
                {
                    cout << "Invalid Entry...\tTry again" << endl;
                    goto getLabel;
                }
                break;
            }

            case 2:
            {
                setLabel: 
                int index = 0;
                int indexValue = 0;
                char operationPerformed[] = "Set";
                cout << "At what index you want to set the value: ";
                cin >> index;
                cout << "What value you want to set: ";
                cin >> indexValue;
                
                int garbageValue = arr.ptr[0];
                arr.ptr[0] = (int)dataValue(arr, operationPerformed, index, indexValue); 
                // arr.ptr = setDataValue(arr, index, indexValue);
                if(arr.ptr[0] == -1)
                {
                    arr.ptr[0] = garbageValue;
                    cout << "Invalid Entry...\tTry again \n" << endl;
                    goto setLabel;
                }

                displayArray(arr, arr.size);
                break;
            }

            case 3:
            {
                int MaxValue = 0;
                char operationPerformed[] = "Max";
                MaxValue = dataValue(arr, operationPerformed, NULL, NULL);
                cout << "The Maximum value in the array is " << MaxValue << endl;
                break;
            }
            
            case 4:
            {
                int MinValue = 0;
                char operationPerformed[] = "Min";
                MinValue = dataValue(arr, operationPerformed, NULL, NULL);
                cout << "The Minimum value in the array is " << MinValue << endl;
                break;
            }

            case 5:         // sum of the array
            {
                int sum = 0;
                char operationPerformed[] = "Sum";
                sum = dataValue(arr, operationPerformed, NULL, NULL);
                cout << "The sum of the array is " << sum << endl;
                break;
            }

            case 6:
            {
                int average = 0;
                char operationPerformed[] = "Avg";
                average = dataValue(arr, operationPerformed, NULL, arr.size);
                cout << "The average of the array is " << average << endl;
                break;
            }
        }
        break;
    }


// ******************   Case 6    *************************** //

    case 6:         // Operations of Array -> Reverse, Left Right shift and Rotating
    {
        int optionSelection = 0;
        cout <<  endl <<
            "1. Reverse the array \n" <<
            "2. Perform Left shifting of the array \n" <<
            "3. Perform Right shifting of the array \n" <<
            "4. Perform Clockwise Left shifting of the array \n" <<
            "5. Perform Anti ClockwiseRight shifting of the array \n" <<
            "\nSelect your operation: " ;
        cin >> optionSelection;

        switch (optionSelection)
        {
            case 1:
            {
                char operationPerformed[] = "Reverse";
                arr.ptr = (int *)arrayOperations(arr, operationPerformed, arr.size);
                displayArray(arr, arr.size);
                break;
            }  

            case 2:
            {
                char operationPerformed[] = "Left Shifting";
                arr.ptr = (int *)arrayOperations(arr, operationPerformed, arr.size);
                displayArray(arr, arr.size);
                break;
            }
            
            case 3:
            {
                char operationPerformed[] = "Right Shifting";
                arr.ptr = (int *)arrayOperations(arr, operationPerformed, arr.size);
                displayArray(arr, arr.size);
                break;
            }

            case 4:
            {
                char operationPerformed[] = "CW Left Shifting";
                arr.ptr = (int *)arrayOperations(arr, operationPerformed, arr.size);
                displayArray(arr, arr.size);
                break;
            }

            case 5:
            {
                char operationPerformed[] = "ACW Right Shifting";
                arr.ptr = (int *)arrayOperations(arr, operationPerformed, arr.size);
                displayArray(arr, arr.size);
                break;
            }
        }

        break;
    }


// ******************   Case 7    *************************** //
    case 7:
    {

        int optionSelection = 0;
        cout <<  endl <<
            "1. Increment Sorting Array in ascending order \n" <<
            "2. Decrement Sorting Array in decending order \n" <<
            "3. Inserting an element and sorting  the array \n" <<
            "4. Increment Sorting Array of Negative numbers in ascending order \n" <<
            "\nSelect your operation: " ;
        cin >> optionSelection;

        switch (optionSelection)
        {
            case 1:
            {
                char operationPerformed[] = "Ascending Sorting Order";
                arr.ptr = (int *)arraySorting(arr, operationPerformed, arr.size, NULL);
                displayArray(arr, arr.size);

                break;
            }

            case 2:
            {
                char operationPerformed[] = "Descending Sorting Order";
                arr.ptr = (int *)arraySorting(arr, operationPerformed, arr.size, NULL);
                displayArray(arr, arr.size);

                break;
            }

            case 3:
            {
                int valueInsert = 0; 
                char operationPerformed[] = "Inserting number while Sorting Order";
                cout << "Enter the value you want to insert: " ;
                cin >> valueInsert;
                
                arr.ptr = (int *)arraySorting(arr, operationPerformed, arr.size, valueInsert);
                displayArray(arr, ( arr.size + 1) );
                break;
            }

            case 4:     // Negative number sorting will work in same way as in case 1.
            {
                arr.ptr[2] = -4;
                arr.ptr[6] = -7;
                arr.ptr[8] = -10;

                char operationPerformed[] = "Negative numbers Sorting Order";
                arr.ptr = (int *)arraySorting(arr, operationPerformed, arr.size, NULL);
                displayArray(arr, arr.size);
                break;
            }
        }

        break;
    }


// ******************   Case 8    *************************** //

    case 8:         // Merging Operation on Array
    {
        int sizeptrArray = 10;
        int *ptrArray = new int[sizeptrArray];

        for (int i=0 ; i< sizeptrArray; i++)
        {
            ptrArray[i] = (i+3)*2;
        }

        ptrArray[1] = 45;
        ptrArray[4] = 4;
        ptrArray[7] = 11;
        ptrArray[9] = 15;

        int optionSelection = 0;
        cout <<  endl <<
            "1. Merging to two array in Ascending Order \n" <<
            "2. Comparing of two arrays \n" <<
            "3. Finding Union of two Arrays \n" <<
            "4. Finding Intersection of two Arrays \n" <<
            "5. Finding Difference of two Arrays \n" <<
            "6. Finding Set Membership of two Arrays \n" <<
            "\nSelect your operation: " ;
        cin >> optionSelection;

        switch (optionSelection)
        {
            case 1:     // Merging to two array in Ascending Order
            {
                char operationPerformed[] = "Merging to two array in Ascending Order";
                arr.ptr = setOperations(arr, ptrArray, sizeptrArray, operationPerformed);
                cout << "\nMerged Array in Ascending Order: " << endl;
                displayArray(arr, arr.size + sizeptrArray - sameIndexValue);
                break;
            }

            case 2:
            {
                cout << "Haven't Implemented yet" << endl;
                break;
            }

            case 3:
            {
                char operationPerformed[] = "Union of two array";
                arr.ptr = setOperations(arr, ptrArray, sizeptrArray, operationPerformed);
                cout << "\nUnion of two array: " << endl;
                displayArray(arr, arr.size + sizeptrArray - sameIndexValue);
                break;
            }

            case 4:
            {
                char operationPerformed[] = "Interestion of two array";
                arr.ptr = setOperations(arr, ptrArray, sizeptrArray, operationPerformed);
                cout << "\nInterestion of two array: " << endl;
                displayArray(arr, arr.size + sizeptrArray - sameIndexValue );
                break;
            }

            case 5:
            {
                char operationPerformed[] = "Difference of two array";
                arr.ptr = setOperations(arr, ptrArray, sizeptrArray, operationPerformed);
                cout << "\nDifference of two array: " << endl;
                displayArray(arr, arr.size + sizeptrArray);
                break;
            }
        }
        break;
    }

    case 9:         // Finding Missing Element
    {
        int optionSelection = 0;
        cout <<  endl <<
            "1. Find missing element in Sorted Array \n" << 
            "2. Find missing element is Unsorted Array \n" <<
            "3. Find duplicates element in Sorted Array \n" <<
            "4. Find duplicates element in Unsorted Array \n" <<
            "5. Find the resultant sum of n element = k \n"
            "\nSelect your operation: " ;
        cin >> optionSelection;

        switch (optionSelection)
        {
            case 1:
            {
                char operation[] = "Sorted Array Missing Element";
                for (int i = 0; i< arr.size; i++)
                {
                    if (i<=4)   arr.ptr[i] = i+1;
                    else if (i<=7)        arr.ptr[i] = i+5;
                    else                  arr.ptr[i] = i+10;
                }
                arr.ptr = findOperation(arr, operation);
                break;
            }

            case 2:
            {
                char operation[] = "Unsorted Array Missing Element";
                for (int i = 0; i< arr.size; i++)
                {
                    if (i<=3)   arr.ptr[i] = 10 - 3*i;
                    else if (i<=7)        arr.ptr[i] = i+2;
                    else                  arr.ptr[i] = i;
                }
                arr.ptr[5] = 20;
                arr.ptr[8] = 18;
                arr.ptr[9] = 14;
                arr.ptr = findOperation(arr, operation);
                break;
            }

            case 3:
            {
                char operation[] = "Sorted Array Duplicates Element";
                
                for (int i = 0; i< arr.size; i++)
                {
                    arr.ptr[i] = i+1;
                }

                arr.ptr[5] = 5;
                arr.ptr[6] = 5;
                arr.ptr[9] = 9;
                arr.ptr = findOperation(arr, operation);
                break;
            }
            
            case 4:
            {
                char operation[] = "Unsorted Array Duplicate Element";
                for (int i = 0; i< arr.size; i++)
                {
                    if (i<=3)   arr.ptr[i] = 10 - 3*i;
                    else if (i<=7)        arr.ptr[i] = i+2;
                    else                  arr.ptr[i] = i;
                }
                arr.ptr[5] = 10;
                arr.ptr[8] = 4;
                arr.ptr[9] = 10;
                arr.ptr = findOperation(arr, operation);
                break;
            }

            case 5:
            {
                char operation[] = "Resultant Sum of Element = k";
                
                for (int i = 0; i< arr.size; i++)
                {
                    arr.ptr[i] = i+1;
                }

                arr.ptr = findOperation(arr, operation);
                break;
            }
        }

        break;
    }

    default:
    {
        cout << "\nWrong key pressed...\n\t Exit ";
        break;
    }
    }       
}
