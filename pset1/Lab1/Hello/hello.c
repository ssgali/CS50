#include<stdio.h>
#include<cs50.h>
int main(void)
{
    //Hi wassup,
    string name = get_string("What is your name?\n");
    printf("Hello %s \n", name);
}