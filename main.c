#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char token;
int expr(void);
int term(void);
int factor(void);
/* report error and die */
void error(void)
{ fprintf(stderr,"REJECTED\n");
    exit(1);
}
/* match input token, read next token */
void match( char expectedToken)
{ if (token==expectedToken) token = getchar();
    else error();
}
/* process an expression */
int expr(void)
{ int temp = term();
    while (token=='+')
        switch (token)
        {
            case '+': match('+');
                temp += term();
        }
    return temp;
}
/* process a term */
int term(void)
{ int temp = factor();
    while (token=='*')
    {
        match('*');
        temp *= factor();
    }
    return temp;
}
/* process a factor */
int factor(void)
{ int temp;
    if (token=='(')
    { match('('); temp = expr(); match(')'); }
    else if (isdigit(token))
    { ungetc(token,stdin);
        scanf("%d",&temp);
        token = getchar();
    }
    else error();
    return temp;
}
/* calculator driver program */
int main()
{
    int result;
    printf("***Recursive-descent integer arithmetic calculator***\n\n");
    printf("Enter expression containing + and * arithmetic operations:    \n",token);
    token = getchar();
    result = expr();
    if (token=='\n')
    {printf("Result = %d\n",result);
    }
    else error();
    return 0;
}
