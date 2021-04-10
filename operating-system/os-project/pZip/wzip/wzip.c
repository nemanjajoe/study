#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sysinfo.h>

#define MAX 1024

void convert(int number, char *buff, int *index){
    int len = 0, remainder;
    char reverse[MAX];
    while(number > 0){
        remainder = number%10;
        reverse[len] = remainder + '0';
        len++;
        number /= 10;
    }
    while(len > 0){
        buff[*index] = reverse[len - 1];
        *index = *index + 1;
        len--;
    }
}

int main(int argc, char *argv[]){
    FILE *fptr;
    FILE *zipFile;
    size_t size = MAX;
    ssize_t strLineNum;
    char *lptr = NULL;
    for (int i = 1; i < argc; i++){/*{{{*/
        int startcpy = 0, endcpy = 0;
        const char *file = argv[i];
        char *zipName = malloc(sizeof(char)*MAX);
        // open files passed in, report error if open failure{{{
        fptr = fopen(file,"r");
        if (fptr == NULL) {
            printf("file %s is not exist\n",file);
            continue;
        } //}}}
        //create a new file and have the file name stored in zipName {{{
        for(int i = 0, len = strlen(file); i < len; i++){
            if (*(file + i) == '/') {
                startcpy = i;
                continue;
            }
        }
        for (int i = startcpy, len = strlen(file); i < len; i++){
            if(*(file + i) == '.' || (i == len)){
                endcpy = i;
                break;
            }
        }
        for (int i = startcpy + 1, j = 0; i < endcpy; i++, j++){
            zipName[j] = file[i];
        }
        strcat(zipName,".z");
        printf("zip file : %s\n",zipName);
        zipFile = fopen(zipName,"w"); // }}}
        // compress file to zipFile {{{
        while((strLineNum = getline(&lptr,&size,fptr)) != -1){
            char buffer[MAX];
            int count = 0;
            for(int i = 0,j = 0,len = strlen(lptr), pre = 0; i <= len; i++){
                if(lptr[pre] == lptr[i]){
                    count++;
                }else{
                    convert(count, buffer, &j);
                    strcpy(&buffer[j],&lptr[pre]);
                    j++;
                    pre = i;
                    count = 1;
                }
            }
            fputs(buffer,zipFile);
            //printf("line compress: %s", buffer);
        } // }}}
        fclose(fptr);
        fclose(zipFile);
        free(zipName);
    }/*}}}*/
    free(lptr);
    return 0;
}
