#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc,const char** argv)
{
    char num[256]={};
    getcwd(num,sizeof(num));
    DIR *curr_direct = opendir(num);
    struct dirent* data;
    data = readdir(curr_direct);

    if(argc>1)
    {
        if(strcmp(argv[1],"-a")==0)
        {
            while(data!=NULL)
            {
                printf("%s\n",data->d_name);
                data = readdir(curr_direct);
            }
        }
        else if(strcmp(argv[1],"-A")==0)
        {
            while(data!=NULL)
            {
                if(strcmp(data->d_name, ".") && strcmp(data->d_name, ".."))
                {
                    printf("%s\n",data->d_name);
                }
                data = readdir(curr_direct);
            }
        }
        else
        {
            printf("ls: '%s' Invalid Option\n",argv[1]);
        }
    }

    else
    {
        while(data!=NULL)
        {
            if(data->d_name[0]!='.')
            {
                printf("%s\n",data->d_name);
            }
            data = readdir(curr_direct);
        }
    }

    closedir(curr_direct);

}
