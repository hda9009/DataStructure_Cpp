#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <cstring>
#include <math.h>

#include <bits/stdc++.h>
using namespace std;

struct matrixElement
{
    int iPosition;
    int jPosition; 
    int xValue;
};
class sparseMatrix
{
    private: 
        int Rows;
        int Columns;
        int numbersPresent;
        matrixElement *elements;

    public:
        sparseMatrix(int rows = 0, int columns = 0, int no_Elements = 0);
        void createMatrix (sparseMatrix *x);
        void displayMatrix (void);
        sparseMatrix addMatrix (sparseMatrix &a, sparseMatrix &b);
        
        friend istream & operator>> (istream &is, sparseMatrix *x); 
        friend ostream & operator<< (istream &os, sparseMatrix *x); 
        sparseMatrix operator+(sparseMatrix &a);
        ~sparseMatrix(void);
};

sparseMatrix::sparseMatrix(int rows, int columns, int no_Elements)
{
    this->Rows = rows;
    this->Columns = columns;
    this->numbersPresent = no_Elements;
}
sparseMatrix::~sparseMatrix(void)
{
    
}

void sparseMatrix::createMatrix (sparseMatrix *x)
{
#if 0
    cout << "Enter the dimension of the matrix: " << endl;
    cout << "Rows: ";
    cin >> x->Rows ;
    cout << "Columns: ";
    cin >> x->Columns ;
    cout << "Number of non zero Elements: ";
    cin >> x->numbersPresent ;
#endif
    static int y = 0;

    if ( y == 0)
    {
        x->Rows = 5;
        x->Columns = 6 ;
        x->numbersPresent = 5;
    }

    if ( y == 1)
    {
        x->Rows = 5;
        x->Columns = 6 ;
        x->numbersPresent = 6;
    }
    
    x->elements = new matrixElement [x->numbersPresent];

    for (int i = 0 ; i < x->numbersPresent ; i++)
    {
    #if 0
        cout << "Enter at position for " << endl ;
        cout << i << " row position: " ;
        cin >> x->elements[i].iPosition ;
        cout << i << " column position: " ;
        cin >> x->elements[i].jPosition ;
        cout << i << " value : " ;
        cin >> x->elements[i].Value ;
    #endif

        if (y == 0)
        {
            x->elements[0].iPosition = 1;
            x->elements[0].jPosition = 4;
            x->elements[0].xValue    = 6;

            x->elements[1].iPosition = 2;
            x->elements[1].jPosition = 2;
            x->elements[1].xValue    = 7;

            x->elements[2].iPosition = 3;
            x->elements[2].jPosition = 2;
            x->elements[2].xValue    = 2;

            x->elements[3].iPosition = 3;
            x->elements[3].jPosition = 4;
            x->elements[3].xValue    = 5;

            x->elements[4].iPosition = 5;
            x->elements[4].jPosition = 1;
            x->elements[4].xValue    = 4;

        }
        if (y == 1)
        {
            x->elements[0].iPosition = 2;
            x->elements[0].jPosition = 2;
            x->elements[0].xValue    = 3;

            x->elements[1].iPosition = 2;
            x->elements[1].jPosition = 5;
            x->elements[1].xValue    = 5;

            x->elements[2].iPosition = 3;
            x->elements[2].jPosition = 3;
            x->elements[2].xValue    = 2;

            x->elements[3].iPosition = 3;
            x->elements[3].jPosition = 6;
            x->elements[3].xValue    = 7;

            x->elements[4].iPosition = 4;
            x->elements[4].jPosition = 4;
            x->elements[4].xValue    = 9;

            x->elements[5].iPosition = 5;
            x->elements[5].jPosition = 1;
            x->elements[5].xValue    = 8;
        }
    }
    y++;
}

void sparseMatrix::displayMatrix (void)
{
    cout << "\nThe entered matrix is: " << endl;
    for (int j=1; j<= this->Columns; j++)
    {
        cout << "  \t" << j;
    }
    cout << "\n---------------------------------------------------------" << endl;
    
    int k = 0;

    for (int i=1; i<= this->Rows; i++)
    {
        cout << i <<".|\t";
        for (int j=1; j<= this->Columns; j++)
        {
            if ( (i == this->elements[k].iPosition) && (j == this->elements[k].jPosition) )
            {
                cout << this->elements[k].xValue << "\t";
                k++;
            }
            else
            {
                cout << "0" << "\t";
            }
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------\n" << endl;
    
    
    for (int i=0; i< this->numbersPresent; i++)
    {
        cout << (*this).elements[i].iPosition << "\t" ;
    }
    
    cout << endl;
    for (int i=0; i< this->numbersPresent; i++)
    {
        cout << (*this).elements[i].jPosition << "\t" ;
    }

    cout << endl;
    for (int i=0; i< this->numbersPresent; i++)
    {
        cout << (*this).elements[i].xValue << "\t" ;
    }

    cout << "\n---------------------------------------------------------" << endl;
}

sparseMatrix sparseMatrix::addMatrix (sparseMatrix &a, sparseMatrix &b)
{
    // Check the dimensions of both the matrix -> They should be same
    if ( (a.Rows == b.Rows) && (a.Columns == b.Columns) )
    {
        this->Rows = a.Rows;
        this->Columns = a.Columns;
        this->numbersPresent = (a.numbersPresent + b.numbersPresent);
        this->elements = new matrixElement [this->numbersPresent];

        cout << "\n\n--------------------------------------------------------------" << endl;
        cout<< "The sum of two Sparse Matrix: \n\n";
        
        int  i = 0, j = 0, k = 0;

        while ( (i< a.numbersPresent) && (j< b.numbersPresent) )
        {
            if (a.elements[i].iPosition > b.elements[j].iPosition)
            {
                this->elements[k].iPosition = b.elements[j].iPosition;
                this->elements[k].jPosition = b.elements[j].jPosition;
                this->elements[k].xValue    = b.elements[j].xValue;
                k++; j++; 
            }

            else if (a.elements[i].iPosition < b.elements[j].iPosition)
            {
                this->elements[k].iPosition = a.elements[i].iPosition;
                this->elements[k].jPosition = a.elements[i].jPosition;
                this->elements[k].xValue    = a.elements[i].xValue;
                k++;  i++; 
            }

            else        // if both the rows are equal
            {
                if (a.elements[i].jPosition > b.elements[j].jPosition)
                {
                    this->elements[k].iPosition = b.elements[j].iPosition;
                    this->elements[k].jPosition = b.elements[j].jPosition;
                    this->elements[k].xValue    = b.elements[j].xValue;
                    k++; j++;
                }

                else if (a.elements[i].jPosition < b.elements[j].jPosition)
                {
                    this->elements[k].iPosition = a.elements[i].iPosition;
                    this->elements[k].jPosition = a.elements[i].jPosition;
                    this->elements[k].xValue    = a.elements[i].xValue;
                    k++; i++; 
                }

                else        // if both the columns are equal -> Both Rows and Columns are equal -> Add the number
                {
                    // this->elements[k] = b.elements[i];
                    this->elements[k].iPosition = a.elements[i].iPosition;
                    this->elements[k].jPosition = a.elements[i].jPosition;
                    this->elements[k].xValue    = a.elements[i].xValue + b.elements[j].xValue;
                    k++; i++; j++;
                }
            }
        }
        for (; i< a.numbersPresent; i++)    
            this->elements[k++] = a.elements[i++];
        for (; j< b.numbersPresent; j++)    
            this->elements[k++] = a.elements[j++];

        this->Rows = a.Rows;        // Change the values of Rows according to Rows of Matrix A
        this->Columns = b.Columns;  // Change the values of Columns according to Columns of Matrix B
        this->numbersPresent = k;
    }

    return *this;
}

int main()
{
    sparseMatrix matrixA;
    sparseMatrix matrixB;
    matrixA.createMatrix(&matrixA);
    matrixB.createMatrix(&matrixB);
    matrixA.displayMatrix();
    matrixB.displayMatrix();

    sparseMatrix matrixC;
    matrixC = matrixC.addMatrix(matrixA, matrixB);
    matrixC.displayMatrix();

}
