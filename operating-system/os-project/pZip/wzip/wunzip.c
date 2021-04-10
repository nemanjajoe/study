#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sysinfo.h>

#define MAX 1024

int get_num_word(char *str, int begin, int end){
    char charType;
    int result = 0, temp;
    for(int i = begin, j = 0, len = end - begin; j < len; i++, j++){
        charType = *(str + i);
        temp = atoi(&charType);
        result = result * 10;
        result += temp;
    }
    return result;
}

int main(int argc, char *argv[]){
    FILE *fptr;
    FILE *unzipFile;
    size_t size = MAX;
    ssize_t strLineNum;
    char *lptr = NULL;
    for (int i = 1; i < argc; i++){
        const char *zipedFile = argv[i];
        char *unzipName = malloc(sizeof(char)*MAX);
        // open the ziped file and report error if failed {{{
        fptr = fopen(zipedFile,"r");
        if (fptr == NULL){
            printf("file %s is not exist\n",zipedFile);
            continue;
        } // }}}
        //create a new file and have the file name stored in unzipName {{{
        for(int i = 0, len = strlen(zipedFile); i < len; i++){
               // printf("%c\n",*(zipedFile + i));
            if(*(zipedFile + i) == '.'){
                strncpy(unzipName,zipedFile,i);
                printf("%s\n",unzipName);
                break;
            }
        }
        unzipFile = fopen(unzipName,"w"); // }}}
        // extract the zipedFile decoding to unzipFile {{{
        while ((strLineNum = getline(&lptr,&size,fptr)) != -1){
            int num_count_start = 0,num_count_end = 0;
            int num_word;
            char word;
            for(int i = 0, len = strlen(lptr); i < len; i++){
                if(*(lptr + i) >= '0' && *(lptr + i) <= '9'){
                    num_count_end++;
                }else {
                    num_word = get_num_word(lptr, num_count_start, num_count_end);
                    num_count_start = ++num_count_end;
                    word = *(lptr + i);
                    printf("num of word is %d, and word is '%c'",num_word,word);
                    //for (int i = 0; i < num_word; i++){
                    //    printf("%c",word);
                    //    fputc(word,unzipFile);
                    //}
                }
            }
        } // }}}
        fclose(fptr);
        fclose(unzipFile);
        free(unzipName);
    }
    free(lptr);
return 0;
}
