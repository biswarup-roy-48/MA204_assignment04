// BISWARUP ROY
// BTECH/10048/19
// SEC A  'MECH ENGG'


// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define TOL 0.0001 //precison
#define DEL 0.001
#define NITER 45 //maximum number of iteration

int main() {
   int i,j,k,n; // declare variables and matrixes as input
   float a[10][10],b[10],x[10],x_old[100484];
   // initially assuming all solutions to be zero
   float x0[10]={0};
   cout<<"\nEnter the size of matrix: ";
   cin>>n;

   // taking inputs from user in diagonal dominating form 
   cout<<"\nEnter the coefficients row wise(diagonal dominating) :\n";
   for(i=1; i<=n; i++) {
      for(j=1; j<=n; j++) {
         cout << "A[" << i << ", " << j << " ]=";
         cin >> a[i][j];
      }
   }

   cout<<"\nEnter the right hand side constants :\n";
   for(i=1; i<=n; i++) {
      cout << "B[" << i << " ]=";
      cin>>b[i];
   }


   k = 1;
   while(k <= NITER){


      for (int i = 1; i <= n; i++)
      {
         float sum = b[i];
         float diag = a[i][i];
         if(abs(diag)<DEL){
            cout<<"Diagonal element too small";
            return 0;
         }
        
         for(j=1;j<=i-1;j++){
            sum = sum - a[i][j]*x_old[j];
         }
        
         for(j=i+1;j<=n;j++){
            sum = sum - a[i][j]*x0[j];
         }
         x[i] = sum/diag;
      }
      
      
      bool isValid = 1;
      for(i=1;i<=n;i++){
         if(abs(x[i]-x0[i]) < TOL){
            isValid = isValid && 1;
         }else{
            isValid = isValid && 0;
         }         
      }
      if(isValid){
         cout<<"\nThe solution is:\n";
         for(i = 1 ; i<=n ; i++){

            cout<<"x"<<i<<" = "<<x[i]<<endl;
         }
         cout<<"\nnumber of iteration = "<<k;
         return 0;
      }
      
      k = k+1;
      
      for (int i = 1; i <= n; i++){
         x_old[i]=x0[i];
      }
      for (int i = 1; i <= n; i++){
         x0[i]=x[i];
      }


   }
   
   cout<<"Maximum iteration reached";
   return 0;
}