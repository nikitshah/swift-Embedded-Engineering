/* Assumption in the code: Only one condition is satisfied per number. For example: number 3 is divisible by 3 and it is a prime number. But only buzz is printed
as per my code since it is the first condition in the problem statement.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primeCheck(int num){
	int i;
    for(i=2; i<=num/2; i++)
    {
        if(num%i==0)
        {
            return 1;  //return if not a prime
        }
    }
    return 0;  //it is a prime number
}
void fizzBuzz(int *arr, int size) {
    int i,j=0,flag=0;
    char str[10];
    memset(str,0,10);
    for(i=0;i<size;i++){
    	flag = primeCheck(arr[i]); //this function returns if the number is prime or not. flag=0 is prime and flag=1 is not prime
    	
		if(arr[i]%3==0){		//putting this in if as per my assumption stated at top
            sprintf(str,"%s","Buzz");  //sprintf is used to copy the string data to str
        }
        else if(arr[i]%5==0){
            sprintf(str,"%s","Fizz");
        }
        else if(arr[i]%15==0)
        {
            sprintf(str,"%s","FizzBuzz");
        }
        else if(flag==0)
		{
    		sprintf(str,"%s","BuzzFizz");
		}
        else
        {
            sprintf(str,"%d",arr[i]);
        }    
        printf("%s\n",str);  //printing the condition here
    }
   
}
int* fib(int n){
	int f1 = 0, f2 = 1, i,next,j=0;
 	int *arr=(int*)malloc(sizeof(int)*n); 
	if (n < 1)
        return 0;
 
    for (i = 1; i <= n; i++)
    {
        printf("%d ", f2);
        arr[j++] = f2;
        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    return arr;
}
int main(){
	int *arr,n;
	printf("Enter n:\n");
	scanf("%d",&n);	
	printf("Fibonacci sequence generated: ");
	arr = fib(n); //This function generates first n fibonacci numbers
	printf("\n\nOutput:\n"); //prints the fibonacci sequence 
	fizzBuzz(arr,n); //sending the entire fibonacci sequence as an array to fizzBuzz function
	free(arr);  //Since I malloced the pointer in fib function
	return 0;
}

