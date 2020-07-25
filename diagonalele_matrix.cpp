#include<iostream>
#define N 3

using namespace std;

int main()
{
        int i,j,Matrix[N][N];
 
        cout<<"\nENTER MATRIX\n";
        for(i=0 ; i<N ; i++)
        {
                for(j=0 ; j<N ; j++)
                {
                        cout<<"ENTER ["<<i<<"]["<<j<<"] ELEMENT: ";
                        cin>>Matrix[i][j]; 
                 } 
        }
 
        cout<<"\nGIVEN MATRIX:\n";
        for(i=0 ; i<N ; i++)
        {
                for(j=0 ; j<N ; j++)
                {
                         cout<<Matrix[i][j]<<"  "; 
                } 
                cout<<endl;
        }
 
        cout<<"\nDIAGONAL ELEMENTS\n";
 
        cout<<"\nFIRST DIAGONAL: ";
        for(i=0 ; i<N ; i++)
        {
                 cout<<Matrix[i][i]<<"  ";
        }
 
        cout<<"\nSECOND DIAGONAL: ";
        for(i=0,j=N-1 ; i<N ; i++,j--)
        {
                cout<<Matrix[i][j]<<"  ";
        }
 
         return 0; 
}
