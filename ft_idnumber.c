#include <stdio.h>
#include <stdlib.h>

const char *dateofbirth(char *idnum)
{
    char* actual_date;
    char months[][] = {"January","February","March","April","May","June","July","August","September","October","November","Decemeber"};
    int i = 3;
    int k = 0;
    int j = 0;
    int which_month;
    printf("we are getting here");

    // Errors start here hahahahahaha 
    
    which_month = ((atoi(idnum[2]) * 10) + atoi(idnum[3]));
    
    while (months[which_month][j])
    {
        j++;
    }
     
    actual_date = (char*)malloc(sizeof(char) * (8 + j));
   
    actual_date[0] = idnum[4];
    actual_date[1] = idnum[5];
    actual_date[2] = ' ';
    while (months[which_month][k] != '/0')
    {
        actual_date[i] = months[which_month][k];
        k++;
        i++;
    }
   
    actual_date[i] = ' ';
    i++;
    if (idnum[0] <= '2' && idnum[1] == '0')
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
    
    return (actual_date);
}

const char *is_citizen(char *idnum)
{

    char* well;

    if (idnum[10] == '1')
    {
        well = "This person was not born in South Africa.";
    } 
    else 
    {
        well = "This person was born in South Africa.";
    }

    return (well);
}

const char *gender_find(char *idnum)
{
    char* sex;

    if (idnum[6] < '5')
    {
        sex = "Female";
    } 
    else if (idnum[6] > '4')
    {
        sex = "Male";
    }
    return (sex);
}

int main(int counter, char **vector)
{
    if (counter == 2)
    {
        printf("%s \n", dateofbirth(vector[1])); 
        printf("%s \n", gender_find(vector[1]));
        printf("%s \n", is_citizen(vector[1]));  
    }
    else
    {
        printf("Please make sure you enter an ID n only.");
    }
    
    return (0);
}