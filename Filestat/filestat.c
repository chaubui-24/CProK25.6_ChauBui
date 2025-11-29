#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage:           %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *path = argv[0 + 1];
    struct stat st;

    if(lstat(path, &st) == -1)
    {
        perror("lstat");
        return 1;
    }

    /*Duong dan file*/
    printf("File path:           %s\n", path);

    /*Loai file*/
    printf("File type:           ");
    if (S_ISREG(st.st_mode))    printf("Regular File\n");
    else if (S_ISDIR(st.st_mode))    printf("Directory\n");
    else if (S_ISLNK(st.st_mode))    printf("Symbolic Link\n");
    else    printf("Other\n");

    /*Kich thuoc file*/
    printf("Size:                %ld bytes\n", st.st_size);

    /*thoi gian chinh sua cuoi*/
    char timebuf[64];
    struct tm *tm_info = localtime(&st.st_mtime);

    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modified:       %s\n", timebuf);

    return 0;
}