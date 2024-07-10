#include <stdio.h>
#include <stdlib.h>
#include<dirent.h>

struct dirent *dptr;
void main()
	{
	char buff[256];
	DIR *dirp;
	printf("Enter Directory Name :");
	scanf("%s",buff);
	if((dirp=opendir(buff))==NULL){
		printf("Error");
		exit(0);
		}
	while(dptr=readdir(dirp)){
		printf("%s\n",dptr->d_name);
		}
	closedir(dirp);
	}
