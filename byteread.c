#include <stdio.h>
#include <stdlib.h>

void main()
{
FILE *fp;
long  size;
int i,j;
char *buffer;
size_t result;


fp=fopen("passport.jpg","rb");

if(fp == NULL){
 printf("something went wrong");

 exit(1);

}
fseek (fp , 0 , SEEK_END);
  size = ftell (fp);
  rewind (fp);
buffer=(char *)malloc(sizeof(char)*size); 


result=fread(buffer,1,size,fp);

printf(" no of elements read %d\n",result);
for(i=0;i<result;i=i+4){
 for(j=i;j<i+4;j++  ){
   printf("Ox%X  ",buffer[j] & 0xFF);
   

 }
 printf("\t");
 for(j=i;j<i+4;j++  ){
   printf("     %c  ",buffer[j] & 0xFF);
   

 }
 printf("\n");

  
}
printf("%d\n",sizeof(int));
}


