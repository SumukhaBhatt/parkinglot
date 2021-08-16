#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
int gl=0,arry[10];
struct park
{	char s[30];
	int b;
	char c[30];
	char s1[30];
}a[10],o[10];
void music()
{
    Beep(314,1500);
    Beep(350,1500);
    Beep(390,1500);
    Beep(467,1500);
    Beep(526,1500);
    Beep(624,1500);
    Beep(314,2000);

     Beep(314,500);
    Beep(350,500);
    Beep(390,500);
    Beep(467,500);
    Beep(526,500);
    Beep(624,500);
    Beep(314,500);
}
int streql(char *f,int j)
{int i;	if(strlen(f)==strlen(a[j].c))
{
for(i=0;i<strlen(f);i++)
if(f[i]!=a[j].c[i])
return 1;
return 0;}else return 1;	
}
void strcpyin(struct park *ll,int j,char*f)
{int i,n=strlen(f);
for(i=0;i<n-1;i++)
{ll[j].s1[i]=f[i];
}ll[j].s1[i]='\0';
}
void strcpynum(struct park *ll,int j,char*f)
{int i,n=strlen(f);
for(i=0;i<n;i++)
{ll[j].c[i]=f[i];
}ll[j].c[i]='\0';
}
void strcpyy(struct park *ll,int j,char*f)
{int i,n=strlen(f);
for(i=0;i<n-1;i++)
{ll[j].s[i]=f[i];
}ll[j].s[i]='\0';
}
void out1(int i)
{time_t t = time(NULL);
struct tm *tm = localtime(&t);
strcpyy(o,i,asctime(tm));	
}
void arr(struct park *a)
{int i;
printf("%1s %10s %17s %15s\n","position","status","car number","time");
 for(i=0;i<10;i++) 
 if(a[i].b!=-2)
	printf("|%1d| %11d  %15s %30s \n",i,a[i].b,a[i].c,a[i].s);
	else printf("|%1d| %11s  \n",i,"res");
}
void ress(int i)
{char s1[10];
if(a[i].b==-2)
{
	printf("Please enter the car number\n");
	scanf("%s",s1);
	if(!streql(s1,i))
	{
	a[i].b=1; time_t t = time(NULL);
struct tm *tm = localtime(&t);arry[i]=gl;gl++;
strcpyy(a,i,asctime(tm));strcpyin(o,arry[i],asctime(tm));strcpynum(o,arry[i],a[i].c);o[arry[i]].b=i;
printf("Done\n");}else printf("\n Error in entring car number\n");
}else printf("\nThis position is not reserved, please check your possition id\n");
}
int res(struct park *a)
{int i;char s1[10];for(i=0;i<10;i++)
 if((a[i].b==0)&&(a[i].b!=-2))
{a[i].b=1;
printf("\nEnter the vehicle number\n");
scanf(" %s",&a[i].c);a[i].b=1;
time_t t = time(NULL);
struct tm *tm = localtime(&t);arry[i]=gl;gl++;
strcpyy(a,i,asctime(tm));strcpyin(o,arry[i],asctime(tm));strcpynum(o,arry[i],a[i].c);o[arry[i]].b=i;
return i;
}printf("\nSeats are full");return(-1);
}
void out(struct park *a,int n)
{int x;if((a[n].b!=0)&&(a[n].b!=-2)){printf("Enterd position is %d and vehicle number is %s \nIf not,Press 0 to cancel it else press any number\n",a[n].b,a[n].c);
scanf("%d",&x);if(x){
a[n].b=0;
a[n].c[0]='\0';
a[n].s[0]='\0';out1(arry[n]);printf("Done");}else printf("Entry is canceled");}else printf("Plese enter correct position\n");
}
void reserve(struct park *a)
{ int n=res(a);
if(n>-1) {
printf("Your position id is %d\n",n);
a[n].b=-2;o[arry[n]].c[0]='\0';o[arry[n]].s1[0]='\0';gl--;}
}
int strequal(char *f,int j)
{int i;	if(strlen(f)==strlen(o[j].c))
{
for(i=0;i<strlen(f);i++)
if(f[i]!=o[j].c[i])
return 1;
return 0;}else return 1;
}
void pdetail(int i)
{if(a[i].b!=-2){
printf("%1s %11s %20s \n","position","car number","arived time");
printf("|%1d| %11s  %30s \n",i,a[i].c,a[i].s);}else printf("\n Sorry ,cant display it.it is reserved to someone\n ");
}
void cdetail(char *f)
{int i;for(i=0;a[i].b!=-2&&strequal(f,i);i++);if(a[i].b!=-2){
printf("%1s %11s %20s %35s\n","position","car number","arived time","departure time");
printf("|%1d| %11s  %30s %35s \n",o[i].b,o[i].c,o[i].s1,o[i].s);} else printf("\n Sorry ,cant display it.it is reserved to someone\n ");
}
void detail()
{int i;printf("  %1s %11s %20s %35s\n","position","car number","arived time","departure time");
 for(i=0;i<gl;i++)
	printf("%d)  |%1d| %11s  %30s %35s \n",i+1,o[i].b,o[i].c,o[i].s1,o[i].s);
}
void save()
{int i;FILE *fp;fp=fopen("F:/par.txt","a");
time_t t = time(NULL);
struct tm *tm = localtime(&t);
fprintf(fp,"                                           %s",asctime(tm));
fprintf(fp,"  %1s %11s %20s %35s\n","position","car number","arived time","departure time");
 for(i=0;i<gl;i++)
	fprintf(fp,"%d)  |%1d| %11s  %30s %35s \n",i+1,o[i].b,o[i].c,o[i].s1,o[i].s);
	fprintf(fp,"----------------------------------------------------------------------------------------------------------------------------------");
	fclose(fp);}
int main()
{
	int i=1,j,n,m,gg;char sum,g[8];
	printf("------------------------------------------------------WELCOME TO PARKING LOT------------------------------------------------------\n");
	while(i){
	printf("For reserving the seat press 1 \n For administrator use press 2\n");
	scanf("%d",&j);
	if(j==1) reserve(a);
	else if(j==2){
	while(i)
	{
	printf("Do you want to see the arrangement press 1\nDo you want to park the car press 2\nDo you want to takeout the car press 3\nDo you want to reserve the seat press 4 \nIf reserved car comes press 5\nFor more option press 6\n");
	scanf("%d",&n);
	if(n==1) arr(a);
	else if(n==2){
	if((m=res(a))>-1) printf("\nYour position id is %d",m);}
	else if(n==3) {printf("\nEnter the position of the vehicle\n");scanf("%d",&j);
	out(a,j);}
	else 
	if(n==4)reserve(a);
	else if(n==5){printf("Plese enter the position\n");scanf("%d",&j);ress(j);
	}
	else if(n==6)
	{printf("Do you want to find car detail using the position of car,press 1\nDo you want to find car detail using  the number of car,press 2\nFull datail press 3\nDo you want to hear a muscic press 4\n");
	scanf("%d",&n);
	if(n==3)detail();
	else if(n==2){printf("Enter the car number\n");scanf("%s",g);cdetail(g);}
	else if(n==1){printf("Enter the car position\n");scanf("%d",&gg);pdetail(gg);}
	else if(n==4)music();else  printf("Please enter valid choice\n");
	}
	else printf("\nEnter the valid choice\n");
	printf("\nEnter 1 for continue or 0 for break\n");
	scanf("%d",&i);} save();return 0;}else printf("Prinf invalid choice");
printf("\nEnter 1 for continue or 0 for break\n");
	scanf("%d",&i);}return 0;}