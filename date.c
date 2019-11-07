#include<stdio.h>
#include<time.h>
#include<string.h>

int main(int argc, const char* argv[])
{
    time_t current;

    tzset();
    current = time(NULL);
    char *time_now;
    struct tm *curr_time={0};

    time_now = asctime(localtime(&current));


   if(argc>1)
   {
       if(strcmp(argv[1],"-u")==0)
       {
           char *universal_time;
           universal_time = asctime(gmtime(&current));
           int u=0;
           int count=0;
           int l=0;
           char WithTimeZone[256]={};
           while(universal_time[u]!='\n')
           {
               if(universal_time[u]==' ')
               {
                WithTimeZone[l]=' ';
                l++;

                   count++;
                   if(count==4)
                   {
                       WithTimeZone[l]='U';
                       l++;
                       WithTimeZone[l]='T';
                       l++;
                       WithTimeZone[l]='C';
                       l++;
                      // strcmp(WithTimeZone,"UTC");
                       continue;
                   }
                   u++;
               }
               else
               {
                   WithTimeZone[l] = universal_time[u];
                   l++;
                   u++;

               }
           }
           printf("%s\n",WithTimeZone);
       }
   }
   else
   {
           int u=0;
           int count=0;
           int l=0;
           char WithTimeZone[256]={};
           while(time_now[u]!='\n')
           {
               if(time_now[u]==' ')
               {
                WithTimeZone[l]=' ';
                l++;
                   count++;
                   if(count==4)
                   {
                       WithTimeZone[l]='I';
                       l++;
                       WithTimeZone[l]='S';
                       l++;
                       WithTimeZone[l]='T';
                       l++;
                      // strcmp(WithTimeZone,"UTC");
                       continue;
                   }
                   u++;
               }
               else
               {
                   WithTimeZone[l] = time_now[u];
                   l++;
                   u++;

               }
           }
       printf("%s\n",WithTimeZone);
   }
}
