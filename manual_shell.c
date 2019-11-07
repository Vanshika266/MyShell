#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include <stdlib.h>

char *pwd()
{
    char num[256];
    return getcwd(num,sizeof(num));
}

int cd(char *way)
{
    return chdir(way);
}

char* findway(char *way)
{
    getchar();
    char direction=getchar();
    int i=0;

    while(direction!='\n')
    {
        way[i]=direction;
        i+=1;
        direction=getchar();
           //     printf("%c",direction);
    }
    way[i]='\0';
    return way;

}

int main()
{
    printf("%s\n","Welcome");

    FILE *codeshistory_file;
    codeshistory_file = fopen("./codes_history.txt","a+");

    int value=1;
    while(1)
    {
        char myinput[256][256] = {};
        char *mi[256] = {};
        char input[256]={};
        char argument[256] = {};

        // printf("null\n");

        int i=0;
        int flag=0;

        // char myinput[256][256];

        // char input[256];

        printf(">>");
        while(1)
        {

            // printf("fsk\n");
            scanf("%s",&myinput[i]);
            // printf("%d\n", strlen(input));
            // printf("%s\n", &myinput[0]);
            strcat(input,myinput[i]);
            mi[i] = myinput[i];
            // printf("gahjm\n");
            if(flag==1)
            {
                strcat(argument,myinput[i]);
            }

            // printf("%s\n", myinput[i]);

            if(getchar()=='\n')
            {
                strcat(input,"\n");
                break;
            }
            else
            {
                if (flag == 1){
                    strcat(argument," ");
                }
                strcat(input," ");
            }
            flag=1;

            i++;


        }

        if(strcmp(myinput[0],"pwd")==0)
        {
            fputs(input,codeshistory_file);
            // printf("%s", argument);

            if(strcmp(argument, ""))
            {
                if(strcmp(myinput[1],"--help")==0)
                {
                    printf("pwd: ");
                    printf("Print the current working directory name\n");
                }else{
                    printf("Invalid option\n");
                }
            }
            else{
                char *path;
                path =pwd();
                printf("%s\n",path);
            }
            


           continue;
        }
        else if(strcmp(myinput[0],"cd")==0)
        {
            fputs(input,codeshistory_file);

            int op = cd(argument);
            if(op==-1)
            {
                printf("cd: '%s' : no such file or directory\n",myinput[1]);
            }
            continue;

        }
        else if(strcmp(myinput[0],"echo")==0)
        {

            fputs(input,codeshistory_file);
            // printf("%d\n", value);
            // value++;

            // fputs("\n",codeshistory_file);
            if(sizeof(myinput)>1)
            {
                if(strcmp(myinput[1],"-n")==0)
                {
                    int h=2;
                    while(mi[h]!=NULL)
                    {
                        printf("%s " ,mi[h]);
                        h++;
                    }
                 //   printf("%s",argument);
                }
                else
                {
                    printf("%s\n",argument);
                }
            }
            else
            {
                printf("\n");
            }

            continue;
        }
        else if(strcmp(myinput[0],"exit")==0)
        {
            fputs(input,codeshistory_file);
            if(strcmp(argument, ""))
            {
                if(strcmp(myinput[1],"--help") == 0)
                {
                    printf("exit: ");
                    printf("Exit the shell\n");
                }
            }
            else
            {
                break;
            }
            // printf("%d\n", value);
            // value++;

            // fputs("\n",codeshistory_file);
          //  break;
        }
        else if(strcmp(myinput[0],"history")==0)
        {
            fputs(input,codeshistory_file);
            // printf("%d\n", value);
            // value++;

            // fputs("\n",codeshistory_file);
            fclose(codeshistory_file);

            FILE *PrintHistory;
            PrintHistory = fopen("./codes_history.txt","r");

            char single[256];
            int num = 0;

            while(fgets(single,100,PrintHistory))
            {
                num+=1;
                printf("%d %s",num, single);
            }
            fclose(PrintHistory);
            codeshistory_file = fopen("./codes_history.txt","a+");
            continue;

        }
       else
       {
            char command[256] = {};
            strcat(command,"./");
            strcat(command,myinput[0]);
            fputs(input,codeshistory_file);

            int child = fork();
            int implement;
            if(child==0)
            {
                implement = execvp(command,mi);
                if(implement==-1)
                {
                    printf("'%s' command not found\n",myinput[0]);
                }exit(0);
            }
            else
            {
                wait(NULL);

            }
        }
    }
    // while(1);

}

