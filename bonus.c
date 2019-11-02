#include <stdio.h>
#include <unistd.h>
#include<stdlib.h> 
#include<sys/wait.h> 
  
int main(int argc, char **argv)
{
    printf("Parent proccess: %d\n", getpid() );   // Check Parent ID
    int n ;
    scanf("%d", &n);
    pid_t pid = fork();  // Creating Child Proccess
    if(pid==0){
        // If Our Child Proccess Created Successfully
        while(1+1==2){  // Collatz Conjecture  Algorithm
            printf("proccess ID: %d\n", getpid() ); // Check if our Process ID is not Parent ID
            printf("%d\n", n);
            if(n==1){
                break;  
            } 
            if(n%2==0){
                n = n / 2; 
            }else{
                n = 3 * n + 1;
            }
        }
    }else if(pid<0){
        // If some error occured
        return 1; 
    }
    else if( pid>0){
        wait(NULL); // Waiting for our Child proccess for Finishing 
        printf("proccess ID: %d\n", getpid() );  
        printf("End of programm\n"  );
    }
    return 0;
}