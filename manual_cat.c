#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, const char** argv)
{
    if(strcmp(argv[1],"-n")==0)
    {

        if(access(argv[2],F_OK)!=-1)
        {
            if(access(argv[2],R_OK)==-1)
            {
                printf("cat: %s does not have access\n",argv[2]);
            }else{
                FILE *AllLines;
                AllLines = fopen(argv[2],"r");

                char single[256];
                int num = 0;

                while(fgets(single,100,AllLines))
                {
                    num+=1;
                    printf("%d %s",num, single);
                }
                fclose(AllLines);
            }
        }
        else
        {
            printf("cat: %s: No such file or directory\n",argv[2]);

        }
    }
    else if(strcmp(argv[1],"-E")==0)
    {
        if(access(argv[2],F_OK)!=-1)
        {

            if(access(argv[2],R_OK)==-1)
            {
                printf("cat: %s does not have access\n",argv[2]);
            }else{
                FILE *AllLines;
                AllLines = fopen(argv[2],"r");

                char single[256];
                while(fgets(single,100,AllLines))
                {
                    int i = 0;
                    for (;single[i]!='\0';i++){
                    }
                    single[i-1] = '$';
                    printf("%s\n", single);
                }
                fclose(AllLines);
            }
        }
        else
        {
            printf("cat: %s: No such file or directory\n",argv[2]);

        }
    }
    else
    {
        if(access(argv[1],F_OK)!=-1)
        {
            if(access(argv[1],R_OK)==-1)
            {
                printf("cat: %s does not have access\n",argv[1]);
            }
            else{
                FILE *AllLines;
                AllLines = fopen(argv[1],"r");

                char single[256];
                int num = 0;

                while(fgets(single,100,AllLines))
                {
                    printf("%s", single);
                }
                fclose(AllLines);
            }
        }
        else
        {
            printf("cat: %s: No such file or directory\n",argv[1]);

        }

    }


}
