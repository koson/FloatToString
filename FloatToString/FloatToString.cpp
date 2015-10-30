// FloatToString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*
  * Program to convert float number to string without using sprintf
  */

#include "iostream"    
#include "string"    
#include "math.h"

# define PRECISION 5

using namespace std;

char*  floatToString(float num)
{
   int whole_part = (int)num;
   int digit = 0, reminder =0;
   int log_value =(int) log10((int)num), index = log_value;
   long wt =0;

   // String containg result
   char* str = new char[20];

   //Initilise stirng to zero
   memset(str, 0 ,20);

   //Extract the whole part from float num
   for(int  i = 1 ; i < log_value + 2 ; i++)
   {
       wt  = (long) pow(10.0,i);
       reminder = whole_part  %  wt;
       digit = (reminder - digit) / (wt/10);

       //Store digit in string
       str[index--] = digit + 48;              // ASCII value of digit  = digit + 48
       if (index == -1)
          break;    
   }

    index = log_value + 1;
    str[index] = '.';

   float fraction_part  = num - whole_part;
   float tmp1 = fraction_part,  tmp =0;

   //Extract the fraction part from  num
   for( int i= 1; i < PRECISION; i++)
   {
      wt =10; 
      tmp  = tmp1 * wt;
      digit = (int)tmp;

      //Store digit in string
      str[++index] = digit +48;           // ASCII value of digit  = digit + 48
      tmp1 = tmp - digit;
   }    

   return str;
}


//Main program
void main()
{
    int i;
    float f = 123456.789f;
    char* str =  floatToString(f);
    cout  << endl <<  str;
    cin >> i;
    delete [] str;
}
