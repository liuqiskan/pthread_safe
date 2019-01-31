#include <fun.h>

void* threadfunc(void *p)
{	
	time_t t=time(NULL);//记录当前时间
	struct tm Tm;
	gmtime_r(&t,&Tm);//转换为格林尼治时间
	printf("%04d-%02d-%02d %02d:%02d:%02d\n",(1900+Tm.tm_year),(1+Tm.tm_mon),Tm.tm_mday,(8+Tm.tm_hour),Tm.tm_min,Tm.tm_sec);        //打印
	sleep(5);       //睡眠
	printf("%04d-%02d-%02d %02d:%02d:%02d\n",(1900+Tm.tm_year),(1+Tm.tm_mon),Tm.tm_mday,(8+Tm.tm_hour),Tm.tm_min,Tm.tm_sec);      //打印
}

int main()
{
	pthread_t pthid;//线程标识
	pthread_create(&pthid,NULL,threadfunc,NULL);//创建线程
	sleep(2);      //睡眠
	time_t t=time(NULL);//记录当前时间
	struct tm Tm;
	gmtime_r(&t,&Tm);//转换为格林尼治时间
	printf("%04d-%02d-%02d %02d:%02d:%02d\n",(1900+Tm.tm_year),(1+Tm.tm_mon),Tm.tm_mday,(8+Tm.tm_hour),Tm.tm_min,Tm.tm_sec);
	pthread_join(pthid,NULL);//等待线程
	return 0;
}
