#include <unistd.h>
#include <stdlib.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int ft_atoi(char *str)
{
    int kau;
    int i;
    int is_neg;

    kau = 0;
    is_neg = 1;
    i = 0;
    while(((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) && str[i] != '-')
        i++;

    if (str[i] == '-')
    {
        is_neg = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        kau = (kau * 10) + (str[i] - '0');
        i++;
    }
    return (kau * is_neg);
}

char * ft_gender(char unit)
{
    char *gender;

    if (unit >= '5' && unit <= '9')
        gender = "This person is Male \n";
    else 
        gender = "This person is Female \n";

    return(gender);
}

char *ft_citizen(char unit)
{
    char *here = "This person was born in South Africa.\n";
    char *not_here = "This person was not born in South Africa.\n";
    if (unit == '0')
    {
        return(here);
    }
    else
        return(not_here);
}

/* char *ft_month(char m1, char m2)
{
    char *str_month[12] = {"January", "Februay", "March", "April", "May", "June", "July", "August", "Septemper", "October", "November", "December"};
    int num_month;
    char char_month[2] = {m1, m2};

    num_month = ft_atoi(char_month);

    return (str_month[num_month]);
} */

char * ft_date_of_birth(char c1, char c2, char m1, char m2, char d1, char d2)
{
    static char date_of_birth[21];
    char str_month[][13] = {"January", "Februay", "March", "April", "May", "June", "July", "August", "Septemper", "October", "November", "December"};
    char char_month[2] = {m1, m2};
    int num_month= ft_atoi(char_month);
    int i = 0, k = 0;
    
    date_of_birth[i++] = d1;
    date_of_birth[i++] = d2;
    date_of_birth[i++] = ' ';
    
    while(str_month[num_month - 1][k] != '\0')
        date_of_birth[i++] = str_month[num_month - 1][k++];
    
    date_of_birth[i++] = ' ';
    date_of_birth[i++] = '1';
    date_of_birth[i++] = '9';
    date_of_birth[i++] = c1;
    date_of_birth[i++] = c2;
    date_of_birth[i] = '\0';

    return (date_of_birth);
}

int main(int counter, char **vector)
{
    if (counter == 2)
    {
        ft_putstr("For the ID Number: ");
        ft_putstr(vector[1]);
        ft_putchar('\n');
        ft_putstr(ft_gender(vector[1][6]));
        ft_putstr(ft_citizen(vector[1][10])); 
        ft_putstr("This Person's date of birth is: ");
        ft_putstr(ft_date_of_birth(vector[1][0], vector[1][1], vector[1][2], vector[1][3], vector[1][4], vector[1][5]));
    }
    else 
    {
        ft_putstr("Please on enter an your ID number only.");
    }
    return (0);
}