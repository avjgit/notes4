#include <stdio.h>

int main ()
{
  int result;
  char oldname[] ="oldname.txt";
  char newname[] ="newname.txt";
  result= remove( newname );
  result= rename( oldname , newname );
  return 0;
}