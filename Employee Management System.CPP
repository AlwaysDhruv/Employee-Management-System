#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
struct department
{
	int did;
	char dname[50];
};
struct employee
{
	int id;
	char name[50];
	char city[40];
	int dd;
	int mm;
	int yy;
};
struct work_details
{
	int id;
	int did;
	long int salary;
};
typedef struct employee emp;
typedef struct department dpt;
typedef struct work_details wd;
void left(char[],int);
void header(char chr[]);
void center(char ch[]);
void line();
void lin(char[]);
void main()
{
	clrscr();
	int chr,ch,pass,pa,dp=5,ct=0,i,j,em=10,w=10,n,fg=0,id,p,dum;
	int yy,mm,dd,a,b,d;
	long int sal,sl;
	char name[50],c,s,city[50],c1,c2;
	dpt x[50] = {
			{1001,"Sales"},
			{1002,"ManuFacture"},
			{1003,"Marcketing"},
			{1004,"Telephone"},
			{1005,"Food Mading"},
		    };
	emp y[50] = {   {1, "Ramesh", "Ahmedabad", 15, 06, 2001},
			{2, "Sita", "Surat", 23,06, 2001},
			{3, "Mahesh", "Vadodara", 12, 06, 2001},
			{4, "Aarti", "Surat", 07, 01, 2002},
			{5, "Sanjay", "Bhavnagar", 19, 01, 2002},
			{6, "Anita", "Ahmedabad", 06, 06, 2002},
			{7, "Vijay", "Gandhinagar", 10, 05, 2003},
			{8, "Priya", "Bhavnagar", 10, 05, 2003},
			{9, "Amit", "Gandhidham", 05, 05, 2004},
			{10, "Kavita", "Ahmedabad", 10, 10, 2004}
		    };
	wd z[50] =  {   {1, 1001,10000},
			{6, 1001,56000},
			{2, 1003,12345},
			{7, 1003,34780},
			{8, 1002,45600},
			{9, 1002,23000},
			{3, 1004,97000},
			{4, 1004,67000},
			{5, 1005,89765},
			{10,1005,23444}
		    };
header("WellCome To Employee Management Software");
printf("\n\t\tPlease Enter Your Password :-");
scanf("%d",&pass);
if(pass==111)
{
  do
  {
	clrscr();
	header("Employee Management System");
	center("Facilities");
	lin("-");
	printf("\t\t1.Display  Records  [1] :- ");
	printf("\n\t\t2.New      Records  [2] :- ");
	printf("\n\t\t3.Modify   Records  [3] :- ");
	printf("\n\t\t4.Search   Records  [5] :- ");
	printf("\n\t\t5.Exit	            [0] :- ");
	gotoxy(1,23);
	line();
	left("Developed By : Dhruv",20);
	gotoxy(1,11);
	printf("\n\t\tEnter Choice 	        :- ");
	scanf("%d",&ch);
	if(ch==1)
	{
	  do
	  {
		clrscr();
		header("<<< Displaying Records >>>");
		center("Tables");
		lin("-");
		printf("\n\t\t1.Department   	     For Press [1] :- ");
		printf("\n\t\t2.Employee     	     For Press [2] :- ");
		printf("\n\t\t3.Work Details 	     For Press [3] :- ");
		printf("\n\t\t4.Back To Main Menu  For Press [0] :- ");
		printf("\n\n\t\tEnter Choice 	      	           :- ");
		scanf("%d",&pa);
		if(pa==1)
		{
			clrscr();
			header("<<< Department >>>");
			printf("\n%5s %-10s\n","Id","Name");
			for(i=0;i<30;i++)
			{
				printf("-");
			}
			for(i=0;i<dp;i++)
			{
				printf("\n%5d %-10s",x[i].did,x[i].dname);
				++ct;
			}
			printf("\n\nCount Of Records : %d",ct);
			ct=0;
			getch();
		}
		else if(pa==2)
		{
			clrscr();
			header("<<< Employee >>>");
			printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
			for(i=0;i<40;i++)
			{
				printf("-");
			}
			for(i=0;i<em;i++)
			{
				printf("\n%5d %-10s %-10s %3d-%d-%d",
				y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
				++ct;
			}
			printf("\n\nCount Of Records : %d",ct);
			ct=0;
			getch();
		}
		else if(pa==3)
		{
			clrscr();
			header("<<< Work Details >>>");
			printf("\n%5s %5s %7s\n","EmpId","DeptId","Salary");
			for(i=0;i<35;i++)
			{
				printf("-");
			}
			for(i=0;i<w;i++)
			{
				printf("\n%5d %5d %7ld ",z[i].id,z[i].did,z[i].salary);
				++ct;
			}
			printf("\n\nCount Of Records : %d",ct);
			ct=0;
			getch();
		}
	  }while(pa!=0);
	}
	else if(ch==2)
	{
	   do
	   {
		clrscr();
		header("<<< Adding Records >>>");
		center("Tables");
		lin("-");
		printf("\n\t\t1.Employee     	     For Press [1] :-");
		printf("\n\t\t2.Department         For Press [2] :-");
		printf("\n\t\t3.Work Details 	     For Press [3] :-");
		printf("\n\t\t4.Back To Main Menu  For Press [0] :- ");
		printf("\n\n\t\tEnter Choice 	      	           :- ");
		scanf("%d",&pa);
		if(pa==1)
		{
			fg=0;
			clrscr();
			header("<<< Adding Records >>>");
			center("Employee");
			lin("-");
			printf("\n\t\tEmployee Id :- ");
			scanf("%d",&y[em].id);
			for(j=0;j<em;j++)
			{
				if(y[j].id==y[em].id)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("The Record Already Exist");
					lin("-");
					fg=1;
					getch();
					break;
				}
			}
			if(fg==0)
			{

				clrscr();
				header("<<< Adding Records >>>");
				center("Employee");
				lin("-");
				printf("\n\t\tEmployee Name :- ");
				fflush(stdin);
				gets(y[em].name);
				printf("\n\t\tEmployee City :- ");
				fflush(stdin);
				gets(y[em].city);
				printf("\n\t\tEmployee DAY :- ");
				scanf("%d",&y[em].dd);
				if(y[em].dd<=0 || y[em].dd>31)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Wrong Date");
					lin("-");
					getch();
				}
				else
				{
					fg = 1;
				}
				if(fg==1)
				{
					printf("\n\t\tEmployee Month :- ");
					scanf("%d",&y[em].mm);
					if(y[em].mm<=0 || y[em].mm>12)
					{
						clrscr();
						lin("-");
						center("Wrong Month");
						lin("-");
						getch();
					}
					else
					{
						fg=2;
					}
				}
				if(fg==2)
				{
					printf("\n\t\tEmployee Year :- ");
					scanf("%d",&y[em].yy);
					if(y[em].yy<2000 || y[em].yy > 2024)
					{
						clrscr();
						lin("-");
						center("Wrong Year");
						lin("-");
						getch();
					}
					else
					{
						fg=3;
					}
				}
				if(fg==3)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Inserted]");
					lin("-");
					++em;
					getch();
				}
				else
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Not Inserted]");
					lin("-");
					getch();
				}
			}
		}
		else if(pa==2)
		{
			fg=0;
			clrscr();
			header("<<< Adding Records >>>");
			center("Department");
			lin("-");
			printf("\n\t\tDepartment Id :- ");
			scanf("%d",&x[dp].did);
			for(j=0;j<dp;j++)
			{
				if(x[j].did==x[dp].did)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("The Record Already Exist");
					lin("-");
					fg=1;
					getch();
					break;
				}
			}
			if(fg==0)
			{
				clrscr();
				header("<<< Adding Records >>>");
				center("Department");
				lin("-");
				printf("\n\t\tDepartment Name :- ");
				fflush(stdin);
				gets(x[dp].dname);
				clrscr();
				gotoxy(1,12);
				lin("-");
				center("[Record Has Inserted]");
				lin("-");
				++dp;
				getch();
			}
		}
		else if(pa==3)
		{
			fg=0;
			clrscr();
			header("<<< Adding Records >>>");
			center("Work Details");
			lin("-");
			printf("\n\t\tEmployee Id :- ");
			scanf("%d",&z[w].id);
			clrscr();
			header("<<< Department >>>");
			printf("\n%5s %-10s\n","Id","Name");
			for(i=0;i<30;i++)
			{
				printf("-");
			}
			for(i=0;i<dp;i++)
			{
				printf("\n%5d %-10s",x[i].did,x[i].dname);
					++ct;
			}
			printf("\n\nCount Of Records : %d",ct);
			ct=0;
			printf("\n\nWhich Department Want To Add [ID] :- ");
			scanf("%d",&z[w].did);
			for(j=0;j<em;j++)
			{
				if(y[j].id==z[w].id)
				{
					clrscr();
					header("<<< Adding Records >>>");
					center("Work Details");
					lin("-");
					printf("\n\t\tSalary :- ");
					scanf("%ld",&z[j].salary);
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Inserted]");
					lin("-");
					++w;
					fg=1;
					getch();
				}
			}
			if(fg==0)
			{
				clrscr();
				gotoxy(1,12);
				lin("-");
				center("Employee Record Not Exist");
				lin("-");
				getch();
				break;
			}
		}
	   }while(pa!=0);
	}
	else if(ch==3)
	{
	  do
	  {
		clrscr();
		header("<<< Modifying Records >>>");
		center("Tables");
		lin("-");
		printf("\n\t\t1.Employee     	     For Press [1] :-");
		printf("\n\t\t2.Department         For Press [2] :-");
		printf("\n\t\t3.Work Details 	     For Press [3] :-");
		printf("\n\t\t4.Back To Main Menu  For Press [0] :- ");
		printf("\n\n\t\tEnter Choice 	      	           :- ");
		scanf("%d",&p);
		if(p==1)
		{
		  do
		  {
			clrscr();
			header("<<< Employee >>>");
			center("Modifying By Atributes Of Employee");
			lin("-");
			printf("\n\t\t1.Modify Employee Id          For Press [1] :- ");
			printf("\n\t\t2.Modify Employee Name        For Press [2] :- ");
			printf("\n\t\t3.Modify Employee City        For Press [3] :- ");
			printf("\n\t\t4.Modify Employee Join Date   For Press [4] :- ");
			printf("\n\t\t5.Modify Employee Full Record For Press [5] :- ");
			printf("\n\t\t6.Back To Main Menu	      For Press [0] :- ");
			printf("\n\n\t\tEnter Choice		         	    :- ");
			scanf("%d",&pa);
			if(pa==1)
			{
				fg=0;
				clrscr();
				printf("\n\n\t\tOld Employee Id :- ");
				scanf("%d",&id);
				clrscr();
				header("<<< Employee >>>");
				center("Modify Employee Id");
				lin("-");
				printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
				for(i=0;i<40;i++)
				{
					printf("-");
				}
				for(i=0;i<em;i++)
				{
					if(y[i].id==id)
					{
						printf("\n%5d %-10s %-10s %3d-%d-%d",
						y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
						fg=1;
						a=i;
						getch();
					}
				}
				if(fg==1)
				{
					printf("\n\nModify Employee Id :- ");
					scanf("%d",&y[a].id);
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Modified]");
					lin("-");
					getch();

				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Employee Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==2)
			{
				fg=0;
				clrscr();
				fflush(stdin);
				printf("\n\n\t\tOld Employee Name :- ");
				gets(name);
				clrscr();
				header("<<< Employee >>>");
				center("Modify Employee Name");
				lin("-");
				printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
				for(i=0;i<40;i++)
				{
					printf("-");
				}
				for(i=0;i<em;i++)
				{
					if(strcmpi(y[i].name,name)==0)
					{
						printf("\n%5d %-10s %-10s %3d-%d-%d",
						y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
						fg=1;
						a=i;
						getch();
					}
				}
				if(fg==1)
				{
					printf("\n\nModify Employee Name :- ");
					gets(y[a].name);
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Modified]");
					lin("-");
					getch();

				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Employee Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==3)
			{
				fg=0;
				fflush(stdin);
				clrscr();
				printf("\nOld Employee City :- ");
				gets(city);
				header("<<< Employee >>>");
				center("Modify Employee City");
				lin("-");
				printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
				for(i=0;i<40;i++)
				{
					printf("-");
				}
				for(i=0;i<em;i++)
				{
					if(strcmpi(y[i].city,city)==0)
					{
						printf("\n%5d %-10s %-10s %3d-%d-%d",
						y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
						fg=1;
						a=i;
						getch();
					}
				}
				if(fg==1)
				{
					printf("\n\nModify Employee City :- ");
					gets(y[a].city);
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Modified]");
					lin("-");
					getch();
				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Employee Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==4)
			{
				fg=0;
				clrscr();
				printf("\n\n\t\tOld Employee Join Date :- ");
				scanf("%d %d %d",&dd,&mm,&yy);
				clrscr();
				header("<<< Employee >>>");
				center("Modify Employee Join Date");
				lin("-");
				printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
				for(i=0;i<40;i++)
				{
					printf("-");
				}
				for(i=0;i<em;i++)
				{
					if(y[i].dd==dd && y[i].mm==mm && y[i].yy==yy)
					{
						printf("\n%5d %-10s %-10s %3d-%d-%d",
						y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
						fg=1;
						a=i;
					}
				}
				if(fg==1)
				{
					printf("\nModify Employee DAY :- ");
					scanf("%d",&dd);
					if(dd<=0 || dd>31)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Wrong Date");
						lin("-");
						getch();
					}
					else
					{
						fg = 1;
					}
					if(fg==1)
					{
						printf("\nModify Employee Month :- ");
						scanf("%d",&mm);
						if(mm<=0 || mm>12)
						{
							clrscr();
							lin("-");
							center("Wrong Month");
							lin("-");
							getch();
						}
						else
						{
							fg=2;
						}
					}
					if(fg==2)
					{
						printf("\nModify Employee Year :- ");
						scanf("%d",&yy);
						if(yy<2000 || yy > 2024)
						{
							clrscr();
							lin("-");
							center("Wrong Year");
							lin("-");
							getch();
						}
						else
						{
							fg=3;
						}
					}
					if(fg==3)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("[Record Has Modifided]");
						lin("-");
						y[a].dd = dd;
						y[a].mm = mm;
						y[a].yy = yy;
						getch();
					}
					else
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("[Record Not Inserted]");
						lin("-");
						getch();
					}
				}

			}
			else if(pa==5)
			{
				clrscr();
				header("<<< Employee >>>");
				center("Modifying By Atributes");
				lin("-");
				printf("\n\t\t1.Modify By Employee Id          For Press [1] :- ");
				printf("\n\t\t2.Modify By Employee Name        For Press [2] :- ");
				printf("\n\t\t3.Modify By Employee City        For Press [3] :- ");
				printf("\n\t\t4.Modify By Employee Join Date   For Press [4] :- ");
				printf("\n\t\t5.Back To Main Menu	      	 For Press [0] :- ");
				printf("\n\n\t\tEnter Choice		         	    	 :- ");
				scanf("%d",&pa);
				if(pa==1)
				{
					clrscr();
					printf("\nOld Employee Id :- ");
					scanf("%d",&id);
					fg=0;
					clrscr();
					header("<<< Employee >>>");
					center("Modify By Old Id");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(y[i].id==id)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							fg=1;
							a=i;
						}
					}
					if(fg==1)
					{
						printf("\n\nModify Employee Id :- ");
						scanf("%d",&id);
						printf("\nModify Employee Name :- ");
						fflush(stdin);
						gets(name);
						printf("\nModify Employee City :- ");
						fflush(stdin);
						gets(city);
						printf("\nModify Employee DAY :- ");
						scanf("%d",&dd);
						if(dd<=0 || dd>31)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Wrong Date");
							lin("-");
							getch();
						}
						else
						{
							fg = 1;
						}
						if(fg==1)
						{
							printf("\nModify Employee Month :- ");
							scanf("%d",&mm);
							if(mm<=0 || mm>12)
							{
								clrscr();
								lin("-");
								center("Wrong Month");
								lin("-");
								getch();
							}
							else
							{
								fg=2;
							}
						}
						if(fg==2)
						{
							printf("\nModify Employee Year :- ");
							scanf("%d",&yy);
							if(yy<2000 || yy > 2024)
							{
								clrscr();
								lin("-");
								center("Wrong Year");
								lin("-");
								getch();
							}
							else
							{
								fg=3;
							}
						}
						if(fg==3)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Has Modifided]");
							lin("-");
							y[a].id = id;
							strcpy(y[a].name,name);
							strcpy(y[a].city,city);
							y[a].dd = dd;
							y[a].mm = mm;
							y[a].yy = yy;
							getch();
						}
						else
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Not Inserted]");
							lin("-");
							getch();
						}
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==2)
				{
					clrscr();
					printf("\nOld Employee Name :- ");
					gets(name);
					fg=0;
					clrscr();
					header("<<< Employee >>>");
					center("Modify By Old Id");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(strcmpi(y[i].name,name)==0)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							fg=1;
							a=i;
						}
					}
					if(fg==1)
					{
						printf("\n\nModify Employee Id :- ");
						scanf("%d",&id);
						printf("\nModify Employee Name :- ");
						fflush(stdin);
						gets(name);
						printf("\nModify Employee City :- ");
						fflush(stdin);
						gets(city);
						printf("\nModify Employee DAY :- ");
						scanf("%d",&dd);
						if(dd<=0 || dd>31)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Wrong Date");
							lin("-");
							getch();
						}
						else
						{
							fg = 1;
						}
						if(fg==1)
						{
							printf("\nModify Employee Month :- ");
							scanf("%d",&mm);
							if(mm<=0 || mm>12)
							{
								clrscr();
								lin("-");
								center("Wrong Month");
								lin("-");
								getch();
							}
							else
							{
								fg=2;
							}
						}
						if(fg==2)
						{
							printf("\nModify Employee Year :- ");
							scanf("%d",&yy);
							if(yy<2000 || yy > 2024)
							{
								clrscr();
								lin("-");
								center("Wrong Year");
								lin("-");
								getch();
							}
							else
							{
								fg=3;
							}
						}
						if(fg==3)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Has Modifided]");
							lin("-");
							y[a].id = id;
							strcpy(y[a].name,name);
							strcpy(y[a].city,city);
							y[a].dd = dd;
							y[a].mm = mm;
							y[a].yy = yy;
							getch();
						}
						else
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Not Inserted]");
							lin("-");
							getch();
						}
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==3)
				{
					clrscr();
					printf("\nOld Employee City :- ");
					gets(name);
					fg=0;
					clrscr();
					header("<<< Employee >>>");
					center("Modify By Old Id");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(strcmpi(y[i].city,city)==0)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							fg=1;
							a=i;
						}
					}
					if(fg==1)
					{
						printf("\n\nModify Employee Id :- ");
						scanf("%d",&id);
						printf("\nModify Employee Name :- ");
						fflush(stdin);
						gets(name);
						printf("\nModify Employee City :- ");
						fflush(stdin);
						gets(city);
						printf("\nModify Employee DAY :- ");
						scanf("%d",&dd);
						if(dd<=0 || dd>31)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Wrong Date");
							lin("-");
							getch();
						}
						else
						{
							fg = 1;
						}
						if(fg==1)
						{
							printf("\nModify Employee Month :- ");
							scanf("%d",&mm);
							if(mm<=0 || mm>12)
							{
								clrscr();
								lin("-");
								center("Wrong Month");
								lin("-");
								getch();
							}
							else
							{
								fg=2;
							}
						}
						if(fg==2)
						{
							printf("\nModify Employee Year :- ");
							scanf("%d",&yy);
							if(yy<2000 || yy > 2024)
							{
								clrscr();
								lin("-");
								center("Wrong Year");
								lin("-");
								getch();
							}
							else
							{
								fg=3;
							}
						}
						if(fg==3)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Has Modifided]");
							lin("-");
							y[a].id = id;
							strcpy(y[a].name,name);
							strcpy(y[a].city,city);
							y[a].dd = dd;
							y[a].mm = mm;
							y[a].yy = yy;
							getch();
						}
						else
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Not Inserted]");
							lin("-");
							getch();
						}
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==4)
				{
					clrscr();
					printf("\n\n\t\tOld Employee Join Date :- ");
					scanf("%d %d %d",&dd,&mm,&yy);
					fg=0;
					clrscr();
					header("<<< Employee >>>");
					center("Modify By Old Id");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(y[i].dd==dd && y[i].mm==mm && y[i].yy==yy)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							fg=1;
							a=i;
						}
					}
					if(fg==1)
					{
						printf("\n\nModify Employee Id :- ");
						scanf("%d",&id);
						printf("\nModify Employee Name :- ");
						fflush(stdin);
						gets(name);
						printf("\nModify Employee City :- ");
						fflush(stdin);
						gets(city);
						printf("\nModify Employee DAY :- ");
						scanf("%d",&dd);
						if(dd<=0 || dd>31)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Wrong Date");
							lin("-");
							getch();
						}
						else
						{
							fg = 1;
						}
						if(fg==1)
						{
							printf("\nModify Employee Month :- ");
							scanf("%d",&mm);
							if(mm<=0 || mm>12)
							{
								clrscr();
								lin("-");
								center("Wrong Month");
								lin("-");
								getch();
							}
							else
							{
								fg=2;
							}
						}
						if(fg==2)
						{
							printf("\nModify Employee Year :- ");
							scanf("%d",&yy);
							if(yy<2000 || yy > 2024)
							{
								clrscr();
								lin("-");
								center("Wrong Year");
								lin("-");
								getch();
							}
							else
							{
								fg=3;
							}
						}
						if(fg==3)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Has Modifided]");
							lin("-");
							y[a].id = id;
							strcpy(y[a].name,name);
							strcpy(y[a].city,city);
							y[a].dd = dd;
							y[a].mm = mm;
							y[a].yy = yy;
							getch();
						}
						else
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("[Record Not Inserted]");
							lin("-");
							getch();
						}
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}
				}
			}
		  }while(pa!=0);
		}
		else if(p==2)
		{
		  do
		  {
			clrscr();
			header("<<< Department >>>");
			center("Modifying Atributes Of Department");
			lin("-");
			printf("\n\t\t1.Modify Department Id          For Press [1] :- ");
			printf("\n\t\t2.Modify Department Name 	For Press [2] :- ");
			printf("\n\t\t3.Modify Department Full Record For Press [3] :- ");
			printf("\n\t\t4.Back To Main Menu  	        For Press [0] :- ");
			printf("\n\n\t\tEnter Choice 	      	                      :- ");
			scanf("%d",&pa);
			if(pa==1)
			{
				fg=0;
				clrscr();
				printf("\n\n\t\tOld Department Id :- ");
				scanf("%d",&id);
				clrscr();
				header("<<< Department >>>");
				center("Modify Department Id");
				lin("-");
				printf("\n%5s %-10s\n","Id","Name");
				for(i=0;i<30;i++)
				{
					printf("-");
				}
				for(i=0;i<dp;i++)
				{
					if(x[i].did==id)
					{
						printf("\n%5d %-10s",x[i].did,x[i].dname);
						fg=1;
						a=i;
					}
				}
				if(fg==1)
				{
					printf("\n\nModify Department Id :- ");
					scanf("%d",&x[a].did);
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Modified]");
					lin("-");
					getch();

				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Department Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==2)
			{
				fg=0;
				clrscr();
				fflush(stdin);
				printf("\n\n\t\tOld Department Name :- ");
				gets(name);
				clrscr();
				header("<<< Department >>>");
				center("Modify Department Id");
				lin("-");
				printf("\n%5s %-10s\n","Id","Name");
				for(i=0;i<30;i++)
				{
					printf("-");
				}
				for(i=0;i<dp;i++)
				{
					if(strcmpi(x[i].dname,name)==0)
					{
						printf("\n%5d %-10s",x[i].did,x[i].dname);
						fg=1;
						a=i;
					}
				}
				if(fg==1)
				{
					fflush(stdin);
					printf("\n\nModify Department Name :- ");
					gets(x[a].dname);
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Modified]");
					lin("-");
					getch();

				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Deapartment Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==3)
			{
				clrscr();
				header("<<< Departmnet >>>");
				center("Modifying By Atributes");
				lin("-");
				printf("\n\t\t1.Modify By Departmnet Id   For Press [1] :- ");
				printf("\n\t\t2.Modify By Departmnet Name For Press [2] :- ");
				printf("\n\t\t3.Back To Main Menu	    For Press [0] :- ");
				printf("\n\n\t\tEnter Choice		  	    	  :- ");
				scanf("%d",&pa);
				if(pa==1)
				{
					fg=0;
					clrscr();
					printf("\n\n\t\tOld Department Id :- ");
					scanf("%d",&id);
					clrscr();
					header("<<< Department >>>");
					center("Modify By Department Id");
					lin("-");
					printf("\n%5s %-10s\n","Id","Name");
					for(i=0;i<30;i++)
					{
						printf("-");
					}
					for(i=0;i<dp;i++)
					{
						if(x[i].did==id)
						{
							printf("\n%5d %-10s",x[i].did,x[i].dname);
							fg=1;
							a=i;
						}
					}
					if(fg==1)
					{
						printf("\n\nModify Department Id :- ");
						scanf("%d",&x[a].did);
						fflush(stdin);
						printf("\nModify Department Name :- ");
						gets(x[a].dname);
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("[Record Has Modified]");
						lin("-");
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Department Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==2)
				{
					fg=0;
					clrscr();
					fflush(stdin);
					printf("\n\n\t\tOld Department Name :- ");
					gets(x[a].dname);
					clrscr();
					header("<<< Department >>>");
					center("Modify By Department Name");
					lin("-");
					printf("\n%5s %-10s\n","Id","Name");
					for(i=0;i<30;i++)
					{
						printf("-");
					}
					for(i=0;i<dp;i++)
					{
						if(strcmpi(x[i].dname,name)==0)
						{
							printf("\n%5d %-10s",x[i].did,x[i].dname);
							fg=1;
							a=i;
						}
					}
					if(fg==1)
					{
						printf("\n\nModify Department Id :- ");
						scanf("%d",&x[a].did);
						fflush(stdin);
						printf("\nModify Department Name :- ");
						gets(x[a].dname);
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("[Record Has Modified]");
						lin("-");
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Department Record Not Exist");
						lin("-");
						getch();
					}
				}

			}
		  }while(pa!=0);
		}
		else if(p==3)
		{
		  do
		  {
			clrscr();
			header("<<< Work Details >>>");
			center("Modifying Atributes Of Work_Details");
			lin("-");
			printf("\n\t\t1.Modify Department Id          For Press [1] :- ");
			printf("\n\t\t2.Modify Employee   Id          For Press [2] :- ");
			printf("\n\t\t3.Modify Employee   Salary      For Press [3] :- ");
			printf("\n\t\t4.Back To Main Menu  	        For Press [0] :- ");
			printf("\n\n\t\tEnter Choice 	      	                      :- ");
			scanf("%d",&pa);
			if(pa==1)
			{
				fg=0;
				clrscr();
				printf("\n\n\t\tOld Department And Employee Id :- ");
				scanf("%d %d",&id,&b);
				clrscr();
				header("<<< Department >>>");
				center("Modify Department Id");
				lin("-");
				printf("\n%5s %5s %7s\n","EmpId","DeptId","Salary");
				for(i=0;i<35;i++)
				{
					printf("-");
				}
				for(i=0;i<w;i++)
				{
					if(z[i].did==id && z[i].id==b)
					{
						printf("\n%5d %5d %7ld ",z[i].id,z[i].did,z[i].salary);
						fg=1;
						a=i;
					}
				}
				if(fg==1)
				{
					printf("\n\nModify Department Id :- ");
					scanf("%d",&z[a].did);
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("[Record Has Modified]");
					lin("-");
					getch();
				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Work Details Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==2)
			{
				fg=0;
				clrscr();
				printf("\n\n\t\tOld Employee Id :- ");
				scanf("%d",&id);
				clrscr();
				header("<<< Department >>>");
				center("Modify Employee Id");
				lin("-");
				printf("\n%5s %5s %7s\n","EmpId","DeptId","Salary");
				for(i=0;i<35;i++)
				{
					printf("-");
				}
				for(i=0;i<w;i++)
				{
					if(z[i].id==id)
					{
						printf("\n%5d %5d %7ld ",z[i].id,z[i].did,z[i].salary);
						fg=1;
						a=i;
					}
				}
				if(fg==1)
				{
					printf("\n\nModify Employee Id :- ");
					scanf("%d",&id);
					for(i=0;i<em;i++)
					{
						if(y[i].id!=id)
						{
							c=0;
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
							c=1;
						}
					}
					if(c==1)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("[Record Has Modified]");
						lin("-");
						z[i].id=id;
						getch();
					}
				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Work Details Record Not Exist");
					lin("-");
					getch();
				}
			}

		  }while(pa!=0);
		}
	  }while(p!=0);
	}
	else if(ch==4)
	{
	  do
	  {
		clrscr();
		header("<<< Searching Records >>>");
		center("Tables");
		lin("-");
		printf("\n\t\t1.Employee     	     For Press [1] :-");
		printf("\n\t\t2.Department         For Press [2] :-");
		printf("\n\t\t3.Work Details 	     For Press [3] :-");
		printf("\n\t\t4.Back To Main Menu  For Press [0] :- ");
		printf("\n\n\t\tEnter Choice 	      	           :- ");
		scanf("%d",&p);
		if(p==1)
		{
		  do
		  {
			clrscr();
			fg=0;
			header("<<< Employee >>>");
			center("Search By");
			lin("-");
			printf("\n\t\t1.Search By Employee Id          For Press [1] :-");
			printf("\n\t\t2.Search By Employee Name	 For Press [2] :-");
			printf("\n\t\t3.Search By Employee City	 For Press [3] :-");
			printf("\n\t\t4.Search By Employee Join Date   For Press [4] :- ");
			printf("\n\t\t5.Back To Main Menu    	         For Press [0] :- ");
			printf("\n\n\t\tEnter Choice 	      	                       :- ");
			scanf("%d",&pa);
			if(pa==1)
			{

				clrscr();
				printf("\n\n\t\tEmployee Id :- ");
				scanf("%d",&id);
				clrscr();
				header("<<< Employee >>>");
				center("Search By Id");
				lin("-");
				printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
				for(i=0;i<40;i++)
				{
					printf("-");
				}
				for(i=0;i<em;i++)
				{
					if(y[i].id==id)
					{
						printf("\n%5d %-10s %-10s %3d-%d-%d",
						y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
						++ct;
						fg=1;
					}
				}
				if(fg==1)
				{
					printf("\n\nCount Of Records : %d",ct);
					ct=0;
					getch();
				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Employee Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==2)
			{
				clrscr();
				header("<<< Employee >>>");
				center("Search By Name");
				lin("-");
				printf("\n\t\t1.Serch  By Name 	     For Press [1] :-");
				printf("\n\t\t2.Search By First Character  For Press [2] :-");
				printf("\n\n\t\tEnter Your Choice 			   :-");
				scanf("%d",&pa);
				if(pa==1)
				{
					clrscr();
					fflush(stdin);
					printf("\n\n\t\tEmployee Name :- ");
					gets(name);
					clrscr();
					header("<<< Employee >>>");
					center("Search By City");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(strcmpi(y[i].name,name)==0)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==2)
				{
					clrscr();
					fflush(stdin);
					printf("\n\n\t\tFirst Character :- ");
					scanf("%c",&c);
					c1 = toupper(c);
					c2 = tolower(c);
					clrscr();
					header("<<< Employee >>>");
					center("Serch By First Character Of Name");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(y[i].name[0]==c1 || y[i].name[0]==c2)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}
				}
			}
			else if(pa==3)
			{
				clrscr();
				header("<<< Employee >>>");
				center("Search By City");
				lin("-");
				printf("\n\t\t1.Serch  By City 	     For Press [1] :-");
				printf("\n\t\t2.Search By First Character  For Press [2] :-");
				printf("\n\n\t\tEnter Your Choice 			   :-");
				scanf("%d",&pa);
				if(pa==1)
				{
					clrscr();
					fflush(stdin);
					printf("\n\n\t\tEmployee City :- ");
					gets(city);
					clrscr();
					header("<<< Employee >>>");
					center("Search By City");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(strcmpi(y[i].city,city)==0)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}

				}
				else if(pa==2)
				{
					clrscr();
					fflush(stdin);
					printf("\n\n\t\tFirst Character :- ");
					scanf("%c",&c);
					c1 = toupper(c);
					c2 = tolower(c);
					clrscr();
					header("<<< Employee >>>");
					center("Serch By First Character Of City");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(y[i].city[0]==c1 || y[i].city[0]==c2)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}

				}
			}
			else if(pa==4)
			{
				clrscr();
				header("<<< Employee >>>");
				center("Search By Join Date");
				lin("-");
				printf("\n\t\t1.Search By Day           For Press[1] :- ");
				printf("\n\t\t2.Search By Month 	  For Press[2] :- ");
				printf("\n\t\t3.Search By Year  	  For Press[3] :- ");
				printf("\n\t\t4.Search By Custome Date  For Press[4] :- ");
				printf("\n\n\t\tEnter Your Choice   	   	       :-");
				scanf("%d",&pa);
				if(pa==1)
				{
					clrscr();
					header("<<< Employee >>>");
					center("Search By Day");
					lin("-");
					printf("\n\t\t1.Search By Date    	     For Press [1] :- ");
					printf("\n\t\t2.Search By Date To Now      For Press [2] :- ");
					printf("\n\t\t3.Start Day To End Day       For Press [3] :- ");
					printf("\n\n\t\tEnter Your Choice  		   	   :- ");
					scanf("%d",&pa);
					if(pa==1)
					{
						clrscr();
						printf("\n\t\tDay :-");
						scanf("%d",&dd);
						printf("\n\t\tWhich Month :-");
						scanf("%d",&mm);
						printf("\n\t\tWhich Year :-");
						scanf("%d",&yy);
						clrscr();
						header("<<< Employee >>>");
						center("Search By Only Day");
						lin("-");
						printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
						for(i=0;i<40;i++)
						{
							printf("-");
						}
						for(i=0;i<em;i++)
						{
							if(y[i].dd==dd && y[i].mm==mm && y[i].yy==yy)
							{
								printf("\n%5d %-10s %-10s %3d-%d-%d",
								y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
								++ct;
								fg=1;
							}
						}
						if(fg==1)
						{
							printf("\n\nCount Of Records : %d",ct);
							ct=0;
							getch();
						}
						else if(fg==0)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
						}
					}
					else if(pa==2)
					{
						clrscr();
						printf("\n\t\tDay :-");
						scanf("%d",&dd);
						printf("\n\t\tWhich Month :-");
						scanf("%d",&mm);
						printf("\n\t\tWhich Year :-");
						scanf("%d",&yy);
						clrscr();
						header("<<< Employee >>>");
						center("Search By Day To Now");
						lin("-");
						printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
						for(i=0;i<40;i++)
						{
							printf("-");
						}
						for(i=0;i<em;i++)
						{
							if(y[i].dd >= dd && y[i].mm==mm && y[i].yy==yy)
							{
								printf("\n%5d %-10s %-10s %3d-%d-%d",
								y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
								++ct;
								fg=1;
							}
						}
						if(fg==1)
						{
							printf("\n\nCount Of Records : %d",ct);
							ct=0;
							getch();
						}
						else if(fg==0)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
						}

					}
					else if(pa==3)
					{
						clrscr();
						printf("\n\t\tDay :-");
						scanf("%d",&dd);
						printf("\n\t\tWhich Month :-");
						scanf("%d",&mm);
						printf("\n\t\tWhich Year :-");
						scanf("%d",&yy);
						clrscr();
						header("<<< Employee >>>");
						center("Search By Start Day To End Day");
						lin("-");
						printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
						for(i=0;i<40;i++)
						{
							printf("-");
						}
						for(i=0;i<em;i++)
						{
							if(y[i].dd <= dd && y[i].mm==mm && y[i].yy==yy)
							{
								printf("\n%5d %-10s %-10s %3d-%d-%d",
								y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
								++ct;
								fg=1;
							}
						}
						if(fg==1)
						{
							printf("\n\nCount Of Records : %d",ct);
							ct=0;
							getch();
						}
						else if(fg==0)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
						}
					}
				}
				else if(pa==2)
				{
					clrscr();
					header("<<< Employee >>>");
					center("Search By Month");
					lin("-");
					printf("\n\t\t1.Search By Month 	   For Press [1] :- ");
					printf("\n\t\t2.Start Month To End Month For Press [2] :- ");
					printf("\n\n\t\tEnter Your Choice  	   	         :-");
					scanf("%d",&pa);
					if(pa==1)
					{
						clrscr();
						printf("\n\t\tWhich Month :-");
						scanf("%d",&mm);
						printf("\n\t\tWhich Year :-");
						scanf("%d",&yy);
						clrscr();
						header("<<< Employee >>>");
						center("Search By Entered Month");
						lin("-");
						printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
						for(i=0;i<40;i++)
						{
							printf("-");
						}
						for(i=0;i<em;i++)
						{
							if(y[i].mm==mm && y[i].yy==yy)
							{
								printf("\n%5d %-10s %-10s %3d-%d-%d",
								y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
								++ct;
								fg=1;
							}
						}
						if(fg==1)
						{
							printf("\n\nCount Of Records : %d",ct);
							ct=0;
							getch();
						}
						else if(fg==0)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
						}
					}
					else if(pa==2)
					{
						clrscr();
						printf("\n\t\tStart Month :-");
						scanf("%d",&mm);
						printf("\n\t\tWhich Year :-");
						scanf("%d",&yy);
						printf("\n\t\tEnd Month :-");
						scanf("%d",&dd);
						clrscr();
						header("<<< Employee >>>");
						center("Search By Start Month To End Month");
						lin("-");
						printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
						for(i=0;i<40;i++)
						{
							printf("-");
						}
						for(i=0;i<em;i++)
						{
							if(y[i].dd >= mm && y[i].mm <= dd && y[i].yy==yy)
							{
								printf("\n%5d %-10s %-10s %3d-%d-%d",
								y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
								++ct;
								fg=1;
							}
						}
						if(fg==1)
						{
							printf("\n\nCount Of Records : %d",ct);
							ct=0;
							getch();
						}
						else if(fg==0)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
						}
					}
				}
				else if(pa==3)
				{
					clrscr();
					header("<<< Employee >>>");
					center("Search By Year");
					lin("-");
					printf("\n\t\t1.Search By Enter Year   For Press [1] :- ");
					printf("\n\t\t2.Start Year To End Year For Press [2] :- ");
					printf("\n\n\t\tEnter Your Choice  	   	       :-");
					scanf("%d",&pa);
					if(pa==1)
					{
						clrscr();
						printf("\n\t\tWhich Year :-");
						scanf("%d",&yy);
						clrscr();
						header("<<< Employee >>>");
						center("Search By Entered Year");
						lin("-");
						printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
						for(i=0;i<40;i++)
						{
							printf("-");
						}
						for(i=0;i<em;i++)
						{
							if(y[i].yy==yy)
							{
								printf("\n%5d %-10s %-10s %3d-%d-%d",
								y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
								++ct;
								fg=1;
							}
						}
						if(fg==1)
						{
							printf("\n\nCount Of Records : %d",ct);
							ct=0;
							getch();
						}
						else if(fg==0)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
						}
					}
					else if(pa==2)
					{
						clrscr();
						printf("\n\t\tStart Year :-");
						scanf("%d",&mm);
						printf("\n\t\tEnd Year :-");
						scanf("%d",&yy);
						clrscr();
						header("<<< Employee >>>");
						center("Search By Start Year To End Year");
						lin("-");
						printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
						for(i=0;i<40;i++)
						{
							printf("-");
						}
						for(i=0;i<em;i++)
						{
							if(y[i].yy >= mm && y[i].yy <= yy)
							{
								printf("\n%5d %-10s %-10s %3d-%d-%d",
								y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
								++ct;
								fg=1;
							}
						}
						if(fg==1)
						{
							printf("\n\nCount Of Records : %d",ct);
							ct=0;
							getch();
						}
						else if(fg==0)
						{
							clrscr();
							gotoxy(1,12);
							lin("-");
							center("Employee Record Not Exist");
							lin("-");
							getch();
						}
					}
				}
				else if(pa==4)
				{
					clrscr();
					header("<<< Employee >>>");
					center("Search By Custome Date");
					printf("\n\t\tFirst Date [DD-MM-YY] :-");
					scanf("%d %d %d",&dd,&mm,&yy);
					printf("\n\t\tEnd Date [DD-MM-YY] :-");
					scanf("%d %d %d",&a,&b,&d);
					clrscr();
					header("<<< Employee >>>");
					center("Search By Only Day");
					lin("-");
					printf("\n%5s %-10s %-10s %3s\n","Id","Name","City","JoinDate");
					for(i=0;i<40;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(y[i].dd>=dd && y[i].mm>=mm && y[i].yy>=yy || y[i].dd<=a && y[i].mm<=b && y[i].yy<=d)
						{
							printf("\n%5d %-10s %-10s %3d-%d-%d",
							y[i].id,y[i].name,y[i].city,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Employee Record Not Exist");
						lin("-");
						getch();
					}
				}
			}
		  }while(pa!=0);
		}
		else if(p==2)
		{
		  do
		  {
			clrscr();
			fg=0;
			header("<<< Department >>>");
			center("Search By");
			lin("-");
			printf("\n\t\t1.Search By Department Id   For Press [1] :-");
			printf("\n\t\t2.Search By Department Name For Press [2] :-");
			printf("\n\t\t3.Back To Main Menu         For Press [0] :- ");
			printf("\n\n\t\tEnter Choice 	      	                  :- ");
			scanf("%d",&pa);
			if(pa==1)
			{

				clrscr();
				printf("\n\n\t\tDepartment Id :- ");
				scanf("%d",&id);
				clrscr();
				header("<<< Department >>>");
				center("Search By Id");
				lin("-");
				printf("\n%5s %-10s\n","Id","Name");
				for(i=0;i<30;i++)
				{
					printf("-");
				}
				for(i=0;i<dp;i++)
				{
					if(x[i].did==id)
					{
						printf("\n%5d %-10s",x[i].did,x[i].dname);
						++ct;
						fg=1;
					}
				}
				if(fg==1)
				{
					printf("\n\nCount Of Records : %d",ct);
					ct=0;
					getch();
				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Department Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==2)
			{
				clrscr();
				header("<<< Depatment >>>");
				center("Search By Name");
				lin("-");
				printf("\n\t\t1.Serch  By Name 	     For Press [1] :- ");
				printf("\n\t\t2.Search By First Character  For Press [2] :- ");
				printf("\n\n\t\tEnter Your Choice 		           :- ");
				scanf("%d",&pa);
				if(pa==1)
				{
					clrscr();
					fflush(stdin);
					printf("\n\n\t\tDepartment Name :- ");
					gets(name);
					clrscr();
					header("<<< Department >>>");
					center("Search By Name");
					lin("-");
					printf("\n%5s %-10s\n","Id","Name");
					for(i=0;i<30;i++)
					{
						printf("-");
					}
					for(i=0;i<dp;i++)
					{
						if(strcmpi(x[i].dname,name)==0)
						{
							printf("\n%5d %-10s",x[i].did,x[i].dname);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Department Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==2)
				{
					clrscr();
					fflush(stdin);
					printf("\n\n\t\tFirst Character :- ");
					scanf("%c",&c);
					c1 = toupper(c);
					c2 = tolower(c);
					clrscr();
					header("<<< Department >>>");
					center("Serch By First Character Of Name");
					lin("-");
					printf("\n%5s %-10s\n","Id","Name");
					for(i=0;i<30;i++)
					{
						printf("-");
					}
					for(i=0;i<dp;i++)
					{
						if(x[i].dname[0]==c1 || x[i].dname[0]==c2)
						{
							printf("\n%5d %-10s",x[i].did,x[i].dname);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Department Record Not Exist");
						lin("-");
						getch();
					}
				}
			}
		  }while(pa!=0);
		}
		else if(p==3)
		{
		  do
		  {
			clrscr();
			fg=0;
			header("<<< Work Details >>>");
			center("Search By");
			lin("-");
			printf("\n\t\t1.Search By Department Id For Press [1] :-");
			printf("\n\t\t2.Search By Employee   Id For Press [2] :-");
			printf("\n\t\t3.Search By Salary	  For Press [2] :-");
			printf("\n\t\t4.Back To Main Menu       For Press [0] :- ");
			printf("\n\n\t\tEnter Choice 	      	                :- ");
			scanf("%d",&pa);
			if(pa==1)
			{
				clrscr();
				printf("\n\t\tDepartment Id :- ");
				scanf("%d",&id);
				clrscr();
				header("<<< Work Details >>>");
				center("Search By Department Id");
				lin("-");
				printf("\n%5s %-10s %4s %7s %3s\n","Id","Name","DeptId","Salary","JoinDate");
				for(i=0;i<50;i++)
				{
					printf("-");
				}
				for(i=0;i<w;i++)
				{
					if(z[i].did==id)
					{
						printf("\n%5d %-10s %5d %7ld %3d-%d-%d",z[i].id,y[i].name,z[i].did,z[i].salary,y[i].dd,y[i].mm,y[i].yy);
						++ct;
						fg=1;
					}
				}
				if(fg==1)
				{
					printf("\n\nCount Of Records : %d",ct);
					ct=0;
					getch();
				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Work Details Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==2)
			{
				clrscr();
				printf("\n\t\tEmployee Id :- ");
				scanf("%d",&id);
				clrscr();
				header("<<< Work Details >>>");
				center("Search By Employee Id");
				lin("-");
				printf("\n%5s %-10s %4s %7s %3s\n","Id","Name","DeptId","Salary","JoinDate");
				for(i=0;i<50;i++)
				{
					printf("-");
				}
				for(i=0;i<em;i++)
				{
					if(y[i].id==id)
					{
						printf("\n%5d %-10s %5d %7ld %3d-%d-%d",z[i].id,y[i].name,z[i].did,z[i].salary,y[i].dd,y[i].mm,y[i].yy);
						++ct;
						fg=1;
					}
				}
				if(fg==1)
				{
					printf("\n\nCount Of Records : %d",ct);
					ct=0;
					getch();
				}
				else if(fg==0)
				{
					clrscr();
					gotoxy(1,12);
					lin("-");
					center("Work Details Record Not Exist");
					lin("-");
					getch();
				}
			}
			else if(pa==3)
			{
				clrscr();
				header("<<< Work Details >>>");
				center("Search By Salary");
				lin("-");
				printf("\n\t\t1.Search By Enter   Salary             For Press [1] :-");
				printf("\n\t\t2.Search By Entered Salary Greater     For Press [2] :-");
				printf("\n\t\t3.Search By Entered Salary leser       For Press [3] :-");
				printf("\n\t\t4.Search By Start Salary To End Salary For Press [4] :-");
				printf("\n\n\t\tEnter Choice 	      	                             :- ");
				scanf("%d",&pa);
				if(pa==1)
				{
					clrscr();
					printf("\n\t\tSalary :- ");
					scanf("%ld",&sal);
					clrscr();
					header("<<< Work Details >>>");
					center("Search By Entered Salary");
					lin("-");
					printf("\n%5s %-10s %4s %7s %3s\n","Id","Name","DeptId","Salary","JoinDate");
					for(i=0;i<50;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(z[i].salary==sal)
						{
							printf("\n%5d %-10s %5d %7ld %3d-%d-%d",z[i].id,y[i].name,z[i].did,z[i].salary,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Work Details Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==2)
				{
					clrscr();
					printf("\n\t\tSalary :- ");
					scanf("%ld",&sal);
					clrscr();
					header("<<< Work Details >>>");
					center("Search By Entered Salary Greater");
					lin("-");
					printf("\n%5s %-10s %4s %7s %3s\n","Id","Name","DeptId","Salary","JoinDate");
					for(i=0;i<50;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(z[i].salary >= sal)
						{
							printf("\n%5d %-10s %5d %7ld %3d-%d-%d",z[i].id,y[i].name,z[i].did,z[i].salary,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
						{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Work Details Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==3)
				{
					clrscr();
					printf("\n\t\tSalary :- ");
					scanf("%ld",&sal);
					clrscr();
					header("<<< Work Details >>>");
					center("Search By Entered Salary Lesser");
					lin("-");
					printf("\n%5s %-10s %4s %7s %3s\n","Id","Name","DeptId","Salary","JoinDate");
					for(i=0;i<50;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(z[i].salary <= sal)
						{
							printf("\n%5d %-10s %5d %7ld %3d-%d-%d",z[i].id,y[i].name,z[i].did,z[i].salary,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Work Details Record Not Exist");
						lin("-");
						getch();
					}
				}
				else if(pa==4)
				{
					clrscr();
					printf("\n\t\tFirst Salary :- ");
					scanf("%ld",&sal);
					printf("\n\t\tEnd Salary :- ");
					scanf("%ld",&sl);
					clrscr();
					header("<<< Work Details >>>");
					center("Search By Start Salary To End Salary");
					lin("-");
					printf("\n%5s %-10s %4s %7s %3s\n","Id","Name","DeptId","Salary","JoinDate");
					for(i=0;i<50;i++)
					{
						printf("-");
					}
					for(i=0;i<em;i++)
					{
						if(z[i].salary >= sal && z[i].salary <= sl)
						{
							printf("\n%5d %-10s %5d %7ld %3d-%d-%d",z[i].id,y[i].name,z[i].did,z[i].salary,y[i].dd,y[i].mm,y[i].yy);
							++ct;
							fg=1;
						}
					}
					if(fg==1)
					{
						printf("\n\nCount Of Records : %d",ct);
						ct=0;
						getch();
					}
					else if(fg==0)
					{
						clrscr();
						gotoxy(1,12);
						lin("-");
						center("Work Details Record Not Exist");
						lin("-");
						getch();
					}
				}
			}
		  }while(pa!=0);
		}
	  }while(p!=0);
	}
	else if(ch > 6 || ch < 0)
	{
		clrscr();
		header("<<< Choices Are Only This Range [1 To 6] And Exit For [0] >>>");
		getch();
	}
	else if(ch==0)
	{
		clrscr();
		gotoxy(1,11);
		line();
		center("<<< Are You Sure Want To Exit >>>");
		center("Yes[0] or No[1]");
		gotoxy(1,14);
		line();
		scanf("%d",&chr);
	}
  }while(chr!=0);
    clrscr();
    gotoxy(1,11);
    line();
    center("<<< Thanks For Use >>>");
    line();
}
else
{
	clrscr();
	gotoxy(1,11);
	line();
	center("<<< Password Is The Wrong >>>");
	line();
}
  getch();
}

void line()
{
	int i;
	for(i=0;i<80;i++)
	{
		printf("%c",205);
	}
      //	printf("\n");
}
void center(char ch[])
{
	int i;
	for(i=0;i<40-strlen(ch)/2;i++)
	{
		printf(" ");
	}
	printf("%s\n",ch);
}
void header(char chr[])
{
	line();
	int i;
	for(i=0;i<40-strlen(chr)/2;i++)
	{
		printf(" ");
	}
	printf("%s\n",chr);
	line();
}
void left(char chr[],int ps)
{
	int i;
	for(i=0;i<80-ps;i++)
	{
		printf(" ");
	}
	printf("%s",chr);
}
void lin(char ch[])
{
	int i;
	for(i=0;i<80;i++)
	{
		printf("%s",ch);
	}
      //	printf("\n");
}