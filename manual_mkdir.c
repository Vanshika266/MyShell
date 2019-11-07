
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(int argc,const char** argv)
{

    char num[256];
    char *place;
    place = getcwd(num,sizeof(num));
    int i;
    int made;

    if(argc==1)
    {
        printf("mkdir: missing operand\n");
        printf("Try 'mkdir --help' for more information.\n");
    }
    else if(strcmp(argv[1],"-v")==0 || strcmp(argv[1],"--verbose")==0)
    {
        for(i=0;i<argc;i++)
        {
            if(i!=0 && i!=1)
            {
                strcat(place,"/");
                strcat(place,argv[i]);
                made = mkdir(place,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
                if(made==0)
                {
                    printf("%s'%s'\n","mkdir: created directory ",argv[i]);
                }
                else
                {
                    printf("mkdir: cannot create directory '%s': File exists\n", argv[i]);
                }
                place = getcwd(num,sizeof(num));
            }
        }

    }
    else if(strcmp(argv[1],"--help") == 0)
    {
        printf("Usage: mkdir [OPTION]... DIRECTORY...\n");
        printf("Create the DIRECTORY(ies), if they do not already exist.\n");
        printf("Mandatory arguments to long options are mandatory for short options too.\n");
        printf("  -v, --verbose     print a message for each created directory\n");
        printf("  --help     display this help and exit\n\n");
      
    }
    else
    {
        for(i=0;i<argc;i++)
        {
            if(i!=0)
            {
                strcat(place,"/");
                strcat(place,argv[i]);
                made = mkdir(place,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
                if(made!=0)
                {
                    printf("mkdir: cannot create directory '%s': File exists\n", argv[i]);
                }

                place = getcwd(num,sizeof(num));
            }
        }
    }
}
