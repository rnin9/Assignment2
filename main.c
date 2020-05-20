#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

struct stat stat1, stat2;
struct tm time1, time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    int check = stat("text1",&stat1);
    if(check !=0){
        printf("File1 stat Error!\n");
        exit(0);
    } 
    else {
        return;
    }
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
   int check = stat("text2",&stat2);
   if(check !=0){
         printf("File2 stat Error!\n");
         exit(0);
   } 
   else{
         return;
   }
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    struct tm* timecheck;
    timecheck = localtime(&stat1.st_mtime);
    if(timecheck == NULL){
        exit(0);
    } 
    else{
    time1 = *localtime(&stat1.st_mtime);
        return;
    }
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    struct tm* timecheck;
    timecheck = localtime(&stat2.st_mtime);
    if(timecheck == NULL){
        printf("Get File2 Time Error!\n");
        exit(0);
    } 
    else{
    time2 = *localtime(&stat2.st_mtime);
        return;
    }
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp()
{
	printf("size compare \n");
	if(((int)stat1.st_size) > ((int)stat2.st_size))
		printf("text1 is bigger. \n\n");
	else if(((int)stat1.st_size) < ((int)stat2.st_size))
		printf("text2 is bigger. \n\n");
	else
		printf("sizes are equal. \n\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp()
{
	printf("block compare \n");
	if(((int)stat1.st_blocks) > ((int)stat2.st_blocks))
			printf("text1 is bigger. \n\n");
		else if(((int)stat1.st_blocks) < ((int)stat2.st_blocks))
			printf("text2 is bigger. \n\n");
		else
			printf("sizes are equal. \n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    printf("date compare\n");  
	if(time1.tm_mon+1>time2.tm_mon+1)
		printf("text2 is early\n\n");
	else if(time1.tm_mon+1<time2.tm_mon+1)
		printf("text1 is early\n\n");
	else {
		if(time1.tm_mday>time2.tm_mday)
			printf("text2 is early\n");
		else if(time1.tm_mday<time2.tm_mday)
			printf("text1 is early\n");
		else
			printf("same date\n");
	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    printf("time compare\n");
	if(time1.tm_hour>time2.tm_hour)
		printf("text2 is early\n");
	else if((int)time1.tm_hour < (int)time2.tm_hour)
		printf("text1 is early\n");    
	else {
		if(time1.tm_min>time2.tm_min)
			printf("text2 is early\n");
		else if(time1.tm_min<time2.tm_min)
			printf("text1 is early\n");
		else
			printf("same time\n");
	}
}
