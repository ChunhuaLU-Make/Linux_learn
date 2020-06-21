#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void dir_output(char* dir_name)
{
    struct dirent* p_readdir;
    DIR* p_dir;
    char* new_dir_name = (char*)malloc(32);

    if(dir_name == NULL)
    {
        return;
    }
    
    /* open the dir */
   p_dir =  opendir(dir_name);

   /* if open dir success */
   if(p_dir == NULL)
   {
       perror("errno");
       exit(1);
   }

   /* read dir*/
    while((p_readdir = readdir(p_dir)) != NULL)
    {
        if(strcmp(p_readdir->d_name, ".") == 0 || strcmp(p_readdir->d_name, "..") == 0 )
        {
            continue;
        }

        if(p_readdir->d_type == DT_REG)
        {
            printf("%s\n",p_readdir->d_name);
        }

        if(p_readdir->d_type == DT_DIR)
        {
            printf("d_%s\n",p_readdir->d_name);
            sprintf(new_dir_name, "%s/%s",dir_name, p_readdir->d_name);
            dir_output(new_dir_name);

        }
    }
    printf("\n");
    closedir(p_dir);
    free(new_dir_name);
}
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Please input dir\n");
        exit(1);
    }
    dir_output(argv[1]);
    return 0;
}
