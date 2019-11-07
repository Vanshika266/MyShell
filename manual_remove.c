#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc,const char** argv)
{
    int check;
    if(argc==1)
    {
        printf("rm: missing operand\n");
    //    printf("Try 'rm --help' for more information.\n");

    }
    else if(strcmp(argv[1],"-i")==0)
    {
        if(access(argv[2],F_OK)!=-1)
        {
            printf("rm: remove regular file '%s' ?",argv[2]);
            char done[256];
            scanf("%s",&done);
            if(strcmp(done,"y") == 0)
            {
                check=remove(argv[2]);
            }
        }
        else
        {
            printf("rm: cannot remove '%s' : No such file or directory exist\n",argv[2]);
        }

    }
    else if(strcmp(argv[1],"-v") == 0)
    {
        check = remove(argv[2]);
        if(check==0)
        {
            printf("removed '%s'\n",argv[2]);
        }
        else
        {
            printf("rm: cannot remove '%s' : No such file or directory exist\n",argv[2]);
        }
    }
    else
    {
        if(access(argv[1],F_OK)!=-1)
        {
            check=remove(argv[1]);
        }
        else
        {
            printf("rm: cannot remove '%s' : No such file or directory exist\n",argv[1]);

        }
    }
}
