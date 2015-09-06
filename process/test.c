#include <stdio.h>
void print_some(char *string){

printf("%s\n",string);

}
int main(void){
// Function can declare in main function! awesome.
void print_some(char *string);
char myname[] = {'l','i', 'n', 'u' , 'x'};
print_some(myname);
return 0;
}
