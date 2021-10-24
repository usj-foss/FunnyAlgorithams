#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int main()
{
    char str[100];
    gets(str);
    int l=strlen(str),i;
    
    for(i=0;i<l;i++)
    {
        push(str[i]);
    }
    for(i=0;i<l;i++)
    {
        printf("%c", pop());
    }
    
}
