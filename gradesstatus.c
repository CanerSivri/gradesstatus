#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 5

int main(){
    int grades[MAX_LIMIT];
    int sum=0 , count=0 , failed=0 , passed=0;
    double average=0;
    FILE *fptr;
    fptr=fopen("grades.txt","w");
    if(fptr==NULL){
        printf("Error!");
        return 1;
    }
    for(int i=0;i<MAX_LIMIT;i++){
        printf("Please enter %d. grade: ",i+1);
        scanf("%d",&grades[i]);
        fprintf(fptr,"%d\n",grades[i]);
    }
    fclose(fptr);

    fptr=fopen("grades.txt","r");
    while(fscanf(fptr,"%d",&grades[count]) && count<MAX_LIMIT){
        sum+=grades[count];
        count++;
    }
    fclose(fptr);
    average=(double)sum/count;  
    for(int i=0;i<MAX_LIMIT;i++){
        if(grades[i]>=average){
            passed++;
        }
        else{
            failed++;
        }
    }
    printf("Average grade of class %lf\n",average);
    printf("Passed students %d\n",passed);
    printf("Failed students %d\n",failed);
    system("pause");
    return 0;
}