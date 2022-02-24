#include <stdio.h>
#include <string.h>


void load_networks(char *** networks, int * count)
{
    *count=0;
    *networks=malloc(0);
    void *temp;
    char t;

    FILE *fp;
    fp=popen("netsh wlan show profiles", "r");
    while(fgetc(fp)!=':');
    while(1)
    {
        while((t=fgetc(fp))!=':') if(t==EOF) break;
        if(t==EOF) break;

        fgetc(fp);
        (*count)++;

        if((temp=realloc(*networks, (*count)*sizeof(char*)))==NULL)
        {
            printf("Error allocating data!\n");
            exit(1);
        }
        *networks=temp;
        (*networks)[*count-1]=malloc(0);
        int l=0;
        while(1)
        {
            t=fgetc(fp);
            l++;
            if((temp=realloc( (*networks)[*count-1], l*sizeof(char)))==NULL)
            {
                printf("Error allocating data!\n");
                exit(1);
            }
            (*networks)[*count-1]=temp;
            if(t=='\n')
            {
                (*networks)[*count-1][l-1]='\0';
                break;
            }
            (*networks)[*count-1][l-1]=t;
        }
    }
    pclose(fp);
}

void get_key(char ** networks, int n, char ** key)
{
    int net_len=strlen(networks[n]);
    char buf[52+net_len];
    sprintf(buf, "netsh wlan show profile name=\"%s\" key=clear", networks[n]);

    int found=0;

    FILE *fp;
    fp=popen(buf, "r");
    char t;
    while(1)
    {
        while((t=fgetc(fp))!='\n') if(t==EOF) break;
        if(t==EOF) break;

        char test1[3];
        fscanf(fp, "%3s", &test1);
        if(strcmp(test1, "Key")==0)
        {
            char test2[7];
            fscanf(fp, "%7s", &test2);
            if(strcmp(test2, "Content")==0)
            {
                found=1;
                while(fgetc(fp)!=':');
                fgetc(fp);
                *key=malloc(0);
                int l=0;
                char t;
                void * temp;

                while(1)
                {
                    t=fgetc(fp);
                    l++;
                    if( (temp=realloc((*key), l*sizeof(char)))==NULL )
                    {
                        printf("Error allocating data!\n");
                        exit(1);
                    }
                    (*key)=temp;
                    if(t=='\n')
                    {
                        (*key)[l-1]='\0';
                        break;
                    }
                    (*key)[l-1]=t;
                }
            }
        }
    }
    if(!found)
    {
        *key=malloc(21*sizeof(char));
        *key="[password not found]\0";
    }
    pclose(fp);
}

int main()
{
    char **networks;

    int count=0;
    load_networks(&networks, &count);

    int i;
    char * key;
    printf("\t\tNetwork name:\t\tPassword:\n");
    for(i=0; i<52; i++) printf("-"); printf("\n");
    for(i=0; i<count; i++)
    {
        get_key(networks, i, &key);
        printf("Net no. %-2d:\t%-20s\t%s\n", i+1, networks[i], key);
        free(key);
    }

    if(count==0)
        printf("\t[No networks found!]\n");

	for(i=0; i<count; i++)
    	free(networks[i]);
    free(networks);	

    printf("\n");
    system("pause");
    return 0;
}