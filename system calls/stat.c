#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {
char filename[50];
struct stat fileStat;

printf("Enter the filename:");
scanf("%s",filename);

// Call stat() to get file status

if (stat(filename, &fileStat) == -1) {
perror("Error");
return 1;
}

printf("Information for %s\n",filename);
printf("---------------------------\n");
printf("File Size: \t\t%ld bytes\n", fileStat.st_size);
printf("Number of Links: \t%ld\n", fileStat.st_nlink);
printf("File inode: \t\t%ld\n", fileStat.st_ino);

printf("File Permissions: \t");
printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
printf((fileStat.st_mode & S_IXOTH) ? "x\n" : "-\n");

printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
printf("Last access time: \t%s", ctime(&fileStat.st_atime)); 
printf("Last modification time: \t%s", ctime(&fileStat.st_mtime)); 
printf("Last status change time: \t%s", ctime(&fileStat.st_ctime));

return 0;
}
