#include <stdio.h>
#include <conio.h>
#include <string.h>
char input[20];
int l, x, y, z, a, b, c, val1, val2, fl1, fl2, dec, decloc, invfp, inttemp, idetemp, identifier, integer, op, chlit, stlit, floatlit, string;
main()
 {
    identifier=0;
    idetemp=0;
    integer=0;
    inttemp=0;
    invfp=0;
    floatlit=0;
    fl1=0;
    fl2=0;
    val1=0;
    val2=0;
    dec=0;
    l=strlen(input);
    op=0;
    chlit=0;
    stlit=0;
    string=0;
    clrscr();
    printf("Input: ");
    gets(input);
 
 /* For Operators */
 
    if (strlen(input)==1)
     {
      if ((input[0]=='+' || input[0]=='-' || input[0]=='*' || input[0]=='/'))
      op=1;
     }
 
 /* End */
 
 /*For Character and String Literals */
 
    if ((input[0]=='"' && input[l]=='"'))
     {
      if (input[2]=='"')
      chlit=1;
      else
      stlit=1;
     }
 /* End */
 
 /* For Floating Literals */
 
     for (x=0; x<=strlen(input); x++)
      {
       if (input[x]=='.')
        {
         dec=dec+1;
         decloc=x;
        }
      }
     if (dec==1)
      {
       for (y=0; y<decloc; y++)
        {
         if ((input[y]=='0' || input[y]=='1' || input[y]=='2' || input[y]=='3' || input[y]=='4' || input[y]=='5' || input[y]=='6' || input[y]=='7' || input[y]=='8' || input[y]=='9' || input[y]=='.'))
         val1=val1+1;
        }
       for (z=decloc+1; z<=strlen(input); z++)
        {
         if ((input[z]=='0' || input[z]=='1' || input[z]=='2' || input[z]=='3' || input[z]=='4' || input[z]=='5' || input[z]=='6' || input[z]=='7' || input[z]=='8' || input[z]=='9'))
         val2=val2+1;
        }
      }
     else if (dec>=2)
     invfp=1;
 
     if (val1==decloc)
      {
       fl1=1;
      }
     if (val2==(strlen(input)-decloc)-1)
      {
       fl2=1;
      }
 
 /* End */
 
 /* For Integer */
 
    for (a=0; a<=strlen(input); a++)
      {
       if ((input[a]=='0' || input[a]=='1' || input[a]=='2' || input[a]=='3' || input[a]=='4' || input[a]=='5' || input[a]=='6' || input[a]=='7' || input[a]=='8' || input[a]=='9'))
        {
         inttemp=inttemp+1;
        }
      }
 
 
 /* End */
 
 /* For Identifiers */
 
    for (c=0; c<=strlen(input); c++)
     {
      if ((input[c]=='_' || input[c]>=65 && input[c]<=122))
      idetemp=idetemp+1;
     }
    if ((idetemp==strlen(input) && strlen(input)!=0))
     {
      identifier=1;
     }
 
 /* End */
 
     if (op==1)
     printf("Operator");
     else if (chlit==1)
     printf("Character Literal");
     else if (stlit==1)
     printf("String Literal");
     else if (identifier==1)
     printf("Identifier");
 
     if ((fl1==1 && fl2==1 && dec!=0))
      {
       floatlit=1;
      }
     if (floatlit==1)
     printf("Floating Literal");
     if ((inttemp==strlen(input) && strlen(input)!=0))
      {
       integer=1;
       printf("Integer Literal");
      }
     else if ((op==0 && chlit==0 && stlit==0 && floatlit==0 && integer==0 && identifier==0))
           {
        if (invfp==0 && input[0]!=0)
        printf("INVALID");
        else if ((invfp==0 && input[0]==0))
        printf("Please Enter a Value!");
        else if (invfp==1)
        printf("Invalid Floating Point Literal");
           }
 
    getch();
 }