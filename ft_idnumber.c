#include <stdio.h>
#include <stdlib.h>

char *dateofbirth(char *idnum)
{
    char *actual_date;
    char **months = {"January","February","March","April","May","June","July","August","September","October","November","Decemeber"};
    int i = 0;
    int k = 0;

    actual_date[i] = idnum[4];
    i++;
    actual_date[i] = idnum[5];
    i++;
    actual_date[i] = ' ';
    i++;
    while (months[2-3][k] != '/0')
    {
        actual_date[i] = months[2-3][k];
        k++;
        i++;
    }

    actual_date[i] = ' ';
    i++;

    if (idnum[0] <= '2' && idnum[1] == 0)
    {
        actual_date[i] = '2';
        i++;
        actual_date[i] = '0';
        i++;
    } 
    else 
    {
        actual_date[i] = '1';
        i++;
        actual_date[i] = '9';
        i++;
    }

    actual_date[i] = idnum[0];
    i++;
    actual_date[i] = idnum[1];
    
    return *actual_date;
}

char *is_citizen(char *idnum){

    char* well;

    if (idnum[10] == '1')
    {
        *well = "false";
    } 
    else 
    {
        *well = "true";
    }

    return (*well);
}

char *gender_find(char *idnum)
{
    char* sex;

    if (idnum[6] >= '0' && idnum[6] <= '4')
    {
        *sex = "Female";
    } else if (idnum[6] >= '5' && idnum[6] <= '9')
    {
        *sex = "Male";
    }
    return (*sex);
}

int main(int counter, char **vector)
{
    if (counter == 2)
    {
        
    }
    else
    {
        printf("Please make sure you enter an ID number only.")
    }
    
    return (0);
}