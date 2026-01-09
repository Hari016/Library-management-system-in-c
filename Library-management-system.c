#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int student_info();
int add_book();
int Delete_Book();
int issue_book();
int return_book();
void white(){
	printf("\033[0;37m");
}
void cyan(){
	printf("\033[0;36m");
}
void yellow(){
	printf("\033[0;33m");
}
void red(){
	printf("\033[0;31m");
}
void blue(){
	printf("\033[0;34m");
}
void purple(){
	printf("\033[0;35m");
}
void reset(){
	printf("\033[0m");
}
void menu()
{
	int num;
	while(1)
	{
	yellow();
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t  *     =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=    *");
    printf("\n\t\t\t  *     =                 WELCOME                   =    *");
    printf("\n\t\t\t  *     *                   TO                      *    *");
    printf("\n\t\t\t  *     =                 LIBRARY                   =    *");
    printf("\n\t\t\t  *     *               MANAGEMENT                  *	 *");
    printf("\n\t\t\t  *     =                 SYSTEM                    =    *");
    printf("\n\t\t\t  *     =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=    *");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	red();
	printf("\n\n++++Main Modules++++");
	white();
	printf("\n--------------------------------------------\n");
	blue();
	printf("\n1.Student info");
	printf("\n2.Book info");	
	printf("\n3.Issue Book");
	printf("\n4.Return Book");
	printf("\n5.Exit");
	yellow();
	printf("\n\tEnter any number:");
	reset();
	scanf("%d",&num);
	switch(num)
	{
		case 1:
			white();
			printf("\nStudent info");
			printf("\n-------------------------------\n");
			reset();
			student_info();
			break;
		case 2:
			white();
			printf("\nBook info");
			printf("\n-------------------------------\n");
			reset();
			add_book();
			break;
		case 3:
			white();
			printf("\nIssue Book");
			printf("\n-------------------------------\n");
			reset();
			issue_book();
			break;
		case 4:
			white();
			printf("\nReturn Book");
			printf("\n-------------------------------\n");
			reset();
			return_book();
			break;
		case 5:
			exit(0);
		default:
			red();
			printf("\n\t Invlaid number..........!");
			reset();
		}
	}
}
int main()
     //...............................................password section.........................................................................
{
	int i;
	char username[25];
	char password[20];
	top:
		i=0;
		yellow();
		printf("\nEnter your username: ");
		gets(username);
		yellow();
		printf("\nEnter your password: ");
		do
		{
			password[i]=getch();
			if(password[i]!='\r')
			{
				printf("*");
			}
			i++;
		}
		while(password[i-1]!='\r');
		password[i-1]='\0';
		if(strcmp(username,"hari")==0)
		{
			system("cls");
		}
		else
		{
			system("cls");
			white();
			printf("\n\tYour username is incorrect plz Re-Enter.......!");
			reset();
			goto top;
		}
		{
			if(strcmp(password,"hari@123")==0)
			{
				printf("\n login sucessful......!");
				system("cls");
				menu();
			}
		else
		{
			white();
			printf("\n\t Your password is Wrong  please try again......!\n");
			reset();
			goto top;
		}
	}
	return 0;
}
struct date 
{
	int mm,yy,dd;
};
struct student 
{
	char name[20];
	int id;
	struct date dob;
	char gender[10];
	char number[15];
	char gmail[25];
	char address[20];
	char program[20];
	char guardain_name[20];
};
//...............................................................Student info................................................
struct student s;
void student_info_add()
{
	FILE *fp_std;
	fp_std=fopen("student.txt","a+");
	if(fp_std == NULL)
	{
		printf("\n\t Cannot open file");
	}
	else
	{
		blue();
		printf("\nStudent Name:");
		scanf("%s",s.name);
		printf("\nStudent ID:");
		scanf("%d",&s.id);
		printf("\nDate of birth:");
		printf("\nYear:");
		scanf("%d",&s.dob.yy);
		printf("\nMonth:");
		scanf("%d",&s.dob.mm);
		printf("\nDay:");
		scanf("%d",&s.dob.dd);
		printf("\nGender:");
		scanf("%s",s.gender);
		printf("\nContact Number:");
		scanf("%s",s.number);
		printf("\nGmail:");
		scanf("%s",s.gmail);
		printf("\nAddress:");
		scanf("%s",s.address);
		printf("\nProgram:");
		scanf("%s",s.program);
		printf("\nGuardain Name:");
		scanf("%s",s.guardain_name);
		fprintf(fp_std,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s ",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
		yellow();
		printf("\n\t +++++++ student_info Saved +++++++\n");
		reset();
	}
	fclose(fp_std);
}
void student_info_edit()
{
	struct student upd,s1;
	FILE *fp_old;
	FILE *fp_new;
	fp_old = fopen("student.txt","r");
	fp_new = fopen("new_student.txt","a");
	if(fp_old == NULL || fp_new == NULL)
	{
		printf("\n\t\t Cannot Open File .. ........!");
	}
	else
	{
		int flag=0;
		int num;
		blue();
		printf("\nEnter student Id:");
		reset();
		scanf("%d",&s1.id);
		while(fscanf(fp_old,"%s\n %d\n %d-%d-%d\n %s\n %s\n %s\n %s\n %s\n %s\n",s.name,&s.id,&s.dob.yy,&s.dob.mm,&s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name)!=EOF)
		{
			if(s1.id == s.id)
			{
				flag=1;
				red();
				printf("\nWhat do you want to edit................???");
				blue();
	   			printf("\n1.Student Name");
				printf("\n2.Student ID");
				printf("\n3.Date of birth");
				printf("\n4.Gender");
				printf("\n5.Contact Number");
				printf("\n6.Gmail");
				printf("\n7.Address");
				printf("\n8.Program");
				printf("\n9.Guardain Name");
				yellow();
				printf("\nEnter Any Number 1 to 9: ");
				reset();
				scanf("%d",&num);
				if(num==1)
				{
					blue();
					printf("\nEnter New Student Name:");
					scanf("%s",upd.name);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",upd.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
				}
				if(num==2)
				{
					blue();
					printf("\nEnter New Student ID:");
					scanf("%d",&upd.id);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,upd.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
				}
				if(num==3)
				{
					blue();
					printf("\nEnter New Date of Birth");
					printf("\nYear:");
					scanf("%d",&upd.dob.yy);
					printf("\nMonth:");
					scanf("%d",&upd.dob.mm);
					printf("\nDay:");
					scanf("%d",&upd.dob.dd);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,s.id,upd.dob.yy,upd.dob.mm,upd.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
				}
				if(num==4)
				{
					blue();
					printf("\nEnter New Gender:");
					scanf("%s",upd.gender);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,upd.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
				}
				if(num==5)
				{
					blue();
					printf("\nEnter New Contact Number:");
					scanf("%s",upd.number);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,upd.number,s.gmail,s.address,s.program,s.guardain_name);
				}
				if(num==6)
				{
					blue();
					printf("\nEnter New Gmail:");
					scanf("%s",upd.gmail);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,upd.gmail,s.address,s.program,s.guardain_name);
				}
				if(num==7)
				{
					blue();
					printf("\nEnter New Address:");
					scanf("%s",upd.address);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,upd.address,s.program,s.guardain_name);
				}
				if(num==8)
				{
					blue();
					printf("\nEnter New Program:");
					scanf("%s",upd.program);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,upd.program,s.guardain_name);
				}		
				if(num==9)
				{
					blue();
					printf("\nEnter New Guardain Name:");
					scanf("%s",upd.guardain_name);
					fprintf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,upd.guardain_name);
					reset();
				}	
				yellow();	
				printf("\n\t+++++++++Student Info Edit Data Saved++++++++\n");
				reset();				
			}
			else
			{
				fprintf(fp_new,"%s\n %d\n %d-%d-%d\n %s\n %s\n %s\n %s\n %s\n %s\n",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
			}
		}
		if(flag==0)
		{
			white();
			printf("\n\t Record Not  Found..........!\n");
			reset();
		}
	}
	fclose(fp_old);
	fclose(fp_new);
	remove("student.txt");
	rename("new_student.txt","student.txt");
}
void student_info_search()//................................student_info_search...........................................................
{
	FILE *fp_search;
	fp_search = fopen("student.txt","r");
	if(fp_search == NULL)
	{
		printf("\n Cannot Open File.....!");
	}
	else
	{
		int flag=0;
		yellow();
		printf("| %10s | %5s | %10s | %8s | %10s | %25s | %13s | %7s | %10s |\n","Name","Id","Dob","Gender","Number","Gmail","Address","Program","guardain Name");
		reset();
		while(fscanf(fp_search,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s ",s.name,&s.id,&s.dob.yy,&s.dob.mm,&s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name)!=EOF)
		{
			flag=1;
			red();
			printf("| %10s | %5d | %4d-%2d-%2d |%9s | %10s | %25s | %13s | %7s | %13s |\n",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
			reset();
		}
		if(flag==0)
		{
			white();
			printf("\n\t Record not found..........!\n");
			reset();
		}
	}
	fclose(fp_search);
}
void del_data()
{
	struct student s2;
	FILE *fp_old,*fp_new;
	fp_old = fopen("student.txt","r");
	fp_new = fopen("del_student.txt","a");
	if(fp_old == NULL || fp_new == NULL)
	{
		printf("\n\t Cannot Open File...............!");
	}
	else
	{
		int flag = 0;
		int num;
		blue();
		printf("\nEnter Student Id:");
		reset();
		scanf("%d",&s2.id);
		while(fscanf(fp_old,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s ",s.name,&s.id,&s.dob.yy,&s.dob.mm,&s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name)!=EOF)
		{
			if(s2.id != s.id)
			{
				fprintf(fp_new,"%s\n %d\n %d-%d-%d\n %s\n %s\n %s\n %s\n %s\n %s\n",s.name,s.id,s.dob.yy,s.dob.mm,s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name);
			}
			else
			{
				flag = 1;
			}
		
		}
		yellow();
		printf("\n\t+++++++++Student Data Deleted+++++++++++\n");
		reset();
		if(flag == 0)
		{
			white();
			printf("\n\t Record not found..........!\n");
			reset();
		}
	}
	fclose(fp_old);
	fclose(fp_new);
	remove("student.txt");
	rename("del_student.txt","student.txt");
}
int student_info()//.............................................student module.....................................................................
{
	int num;
	while(1)
	{
		red();
		printf("\n------------------Sub Module------------------\n");
		blue();
		printf("\n1.Add");
		printf("\n2.Edit");
		printf("\n3.Search");
		printf("\n4.Delete");
		printf("\n5.Return Back");
		yellow();
		printf("\n\n\tEnter any Number:");
		reset();			
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				system("cls");
				student_info_add();
				break;
			case 2:
				system("cls");
				student_info_edit();
				break;
			case 3:
				system("cls");
				student_info_search();
				break;
			case 4:
				system("cls");
				del_data();
				break;
			case 5:
				break;
			default:
				printf("\n\n Invilid number .........!");	
			}
		if(num==11)
		{
			system("cls");
			break;

		}
	}
}

// ......................................................................... Book detail...........................................................................!

struct time 
{
	int mm,yy,dd;
};
struct book 
{
	int id;
	struct time a;
	char name[20];
	char author_name[20];
	char publication[25];
	int price;
	int available_book;
};
struct book b;
void book_add()
{
	FILE *fp_book;
	fp_book = fopen("book.txt","a+");
	if(fp_book == NULL)
	{
		printf("\n\t\t Cannot open File.....!");
	}
	else
	{
		blue();
		printf("\nBook ID:");
		scanf("%d",&b.id);
		printf("\nBook Name:");
		scanf("%s",b.name);
		printf("\nAuthor Name:");
		scanf("%s",b.author_name);
		printf("\nPublication:");
		scanf("%s",b.publication);
		printf("\nPublished Year");
		printf("\nYear:");
		scanf("%d",&b.a.yy);
		printf("\nMonth:");
		scanf("%d",&b.a.mm);
		printf("\nDay:");
		scanf("%d",&b.a.dd);
		printf("\nPrice of Book:");
		scanf("%d",&b.price);
		printf("\nNo.of Book Available:");
		scanf("%d",&b.available_book);
		fprintf(fp_book,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
		yellow();
		printf("\n\t +++++++ book_details Saved +++++++\n");
		reset();
	}
	fclose(fp_book);
}
void book_info_edit()//........................edit book section..........................................................................................
{
	struct book update,b1;
	FILE *fp_old;
	FILE *fp_new;
	fp_old = fopen("book.txt","r");
	fp_new = fopen("new_book.txt","a");
	if(fp_old == NULL || fp_new == NULL)
	{
		printf("\n\t File Cannot Open........!");
	}
	else
	{
		int flag=0;
		int num;
		blue();
		printf("\nEnter Book ID:");
		reset();
		scanf("%d",&b1.id);
		while(fscanf(fp_old,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",&b.id,b.name,b.author_name,b.publication,&b.a.yy,&b.a.mm,&b.a.dd,&b.price,&b.available_book) != EOF)
		{
			if(b1.id == b.id)
			{
				flag=1;
				red();
				printf("\nWhat do you want to edit.......?");
				blue();
				printf("\n1.Book ID");
				printf("\n2.Book Name");
				printf("\n3.Author Name");
				printf("\n4.Publication");
				printf("\n5.Published Year");
				printf("\n6.Price of Book");
				printf("\n7.No.of Book Available");
				yellow();	
				printf("\n\t\tEnter any number 1 to 7:");
				reset();
				scanf("%d",&num);
				if(num==1)
				{
					blue();
					printf("\nEnter New Book ID:");
					scanf("%d",&update.id);
					fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",update.id,b.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
				}
				if(num==2)
				{
					blue();
					printf("\nEnter New Book Name:");
					scanf("%s",update.name);
					fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,update.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
				}
				if(num==3)
				{
					blue();
					printf("\nEnter New Author Nmae:");
					scanf("%s",update.author_name);
					fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,update.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
				}
				if(num==4)
				{
					blue();
					printf("\nEnter New Publication:");
					scanf("%s",update.publication);
					fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,update.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
				}
				if(num==5)
				{
					blue();
					printf("\nEnter New Published Year");
					printf("\nYear:");
					scanf("%d",&update.a.yy);
					printf("\nMonth:");
					scanf("%d",&update.a.mm);
					printf("\nDay:");
					scanf("%d",&update.a.dd);
					fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,b.publication,update.a.yy,update.a.mm,update.a.dd,b.price,b.available_book);
				}
				if(num==6)
				{
					blue();
					printf("\nEnter New Price of Book:");
					scanf("%d",&update.price);
					fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,update.price,b.available_book);
				}
				if(num==7)
				{
					blue();
					printf("\nEnter New Number of Book Available:");
					scanf("%d",&update.available_book);
					fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,update.available_book);
					reset();
				}
				yellow();
				printf("\n\t++++++++Book Edit data is Saved++++++++++++\n");
				reset();
			}
			else
			{
				fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
			}
		}
		if(flag==0)
		{
			white();
			printf("\n\t Record Not Found.........!\n");
			reset();
		}
	}
	fclose(fp_old);
	fclose(fp_new);
	remove("book.txt");
	rename("new_book.txt","book.txt");
}
void book_info_search()//.....................................................book_info_search.................................................
{
	FILE *fp_read;
	fp_read = fopen("book.txt","r");
	if(fp_read == NULL)
	{
		printf("\n\t Cannot Open File........!");
	}
	else
	{
		int flag=0;
		printf("| %10s | %5s | %10s | %8s | %10s | %25s | %10s | %7s | %10s |\n","Name","Id","published year","author_name","publication","price","available_book");
		while(fscanf(fp_read,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book) !=EOF )
		{
			flag=1;
			red();
			printf("| %10s | %5s | %10s | %8s | %10s | %25s | %10s | %7s | %10s |\n",b.name,b.id,b.publication,b.author_name,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
			blue();
			printf("\n\t\t\t Book ID  : %d",b.name);
			printf("\n\t\t\t Book Name : %s",b.id);
			printf("\n\t\t\t Author Name : %s",b.publication);
			printf("\n\t\t\t Publication : %s",b.author_name);
			printf("\n\t\t\t Published Year : %d-%d-%d",b.a.yy,b.a.mm,b.a.dd);
			printf("\n\t\t\t Price of Book : %d",b.price);
			printf("\n\t\t\t No.of Book Available : %d",b.available_book);
			red();
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			reset();
		}
		if(flag==0)
		{
			white();
			printf("\n\t Record not found........!\n");
			reset();
		}
	}
	fclose(fp_read);
}
void del_book_data()//........................................................del_book_data............................................................
{
	struct book b2;
	FILE *fp_old,*fp_new;
	fp_old = fopen("book.txt","r");
	fp_new = fopen("del_book.txt","a");
	if(fp_old==NULL || fp_new == NULL)
	{
		printf("\n\t file Cannot open........!");
	}
	else
	{
		int flag = 0;
		int num;
		blue();
		printf("\nEnter Book Id:");
		reset();
		scanf("%d",&b2.id);
		while(fscanf(fp_old,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",&b.id,b.name,b.author_name,b.publication,&b.a.yy,&b.a.mm,&b.a.dd,&b.price,&b.available_book) !=EOF )
		{
			if(b2.id != b.id)
			{
				fprintf(fp_new,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",b.id,b.name,b.author_name,b.publication,b.a.yy,b.a.mm,b.a.dd,b.price,b.available_book);
			}
			else
			{
				flag = 1;
			}
		}
		yellow();
		printf("\n\t+++++++++Book Details is deleted+++++++++++\n");
		reset();
		if(flag == 0)
		{
			white();
			printf("\n\t Record not found..........!\n");
			reset();
		}
	}
	fclose(fp_old);
	fclose(fp_new);
	remove("book.txt");
	rename("del_book.txt","book.txt");
}
int add_book()//...............................................................book module ........................................................................
{
	int num;
	while(1)
	{
		red();
		printf("\n------------------------Sub Module-----------------------\n");
		blue();
		printf("\n1.Add Book");
		printf("\n2.Edit Book");
		printf("\n3.Search Book");
		printf("\n4.Delete Book");
		printf("\n5.Return back");
		yellow();
		printf("\n\n Enter any Number:");
		reset();
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				system("cls");
				book_add();
				break;
			case 2:
				system("cls");
				book_info_edit();
				break;
			case 3:
				system("cls");
				book_info_search();
				break;
			case 4:
				system("cls");
				del_book_data();
				break;
			case 5:
				break;
			default:
				printf("\nInvilid number.....!");
		}
		if(num==11)
		{
			system("cls");
			break;
		}	   
	}
}
// .................................................................issue  book detail.........................................................................................!!
struct duration{
	int yy,mm,dd;
};
struct issue
{
	int book_id;
	char book_name[20];
	int student_id;
	char student_name[20];
	char program[10];
	struct duration i,r;	
};
struct issue c;
void add_issue_book_detail()
{
	int day,month,year,n;
	FILE *fp_issue,*fp_old,*fp_new;
	fp_issue = fopen("issue.txt","a+");
	fp_old = fopen("book.txt","r");
	fp_new = fopen("student.txt","r");
	if(fp_issue == NULL || fp_new == NULL || fp_old == NULL)
	{
		printf("\n\t file Cannot open...........!");
	}
	else
	{
		blue();	
		printf("\nEnter book Id:");
		scanf("%d",&c.book_id);
		printf("\nEnter book name:");
		scanf("%s",c.book_name);
		while(fscanf(fp_old,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",&b.id,b.name,b.author_name,b.publication,&b.a.yy,&b.a.mm,&b.a.dd,&b.price,&b.available_book) != EOF)
		{
			if(c.book_id == b.id && strcmp(c.book_name, b.name)==0)
			{
				blue();
				printf("\nEnter student name:");
				scanf("%s",c.student_name);
				printf("\nEnter Student Id:");
				scanf("%d",&c.student_id);
				printf("\nEnter Program:");
				scanf("%s",c.program);
				while(fscanf(fp_new,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s ",s.name,&s.id,&s.dob.yy,&s.dob.mm,&s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name)!=EOF)
				{
					if(strcmp(c.student_name,s.name)==0 && c.student_id == s.id && strcmp(c.program,s.program)==0)
					{
						blue();
						printf("\nIssue date");
						printf("\nYear:");
						scanf("%d",&c.i.yy);
						printf("\nMonth:");
						scanf("%d",&c.i.mm);
						printf("\nDay:");
						scanf("%d",&c.i.dd);
						printf("\nEnter duration time of book return in days : ");
						reset();
						scanf("%d",&n);
						day = c.i.dd + n;
						if(day >= 30)
						{
						   month = day/30;
						   day = day % 30;
						   month = month + c.i.mm;
						   if(month>=12)
						   {
						    	year = month / 12;
						   		month = month % 12;
						   		year = year + c.i.yy;
						   }
						   else
						   {
						   		year = c.i.yy;
						   }
						}
						else
						{
						   month =c.i.mm;
						   year = c.i.yy;
						}
						c.r.dd = day;
						c.r.mm = month;
						c.r.yy = year;
						fprintf(fp_issue,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,c.book_name,c.student_id,c.student_name,c.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
						yellow();
						printf("\n\t Issue Book Details is Saved.........!\n");
						reset();						
					}
				}
			}		
		}
	}
	fclose(fp_issue);
	fclose(fp_old);
	fclose(fp_new);
}
	
void edit_issue_book_detail()//............................................edit_issue_book_detail.........................................................................
{
	struct issue up,c1;
	FILE *fp_old;
	FILE *fp_new;
	fp_old = fopen("issue.txt","r");
	fp_new = fopen("new_issue.txt","a");
	if(fp_old == NULL || fp_new == NULL)
	{
		printf("\n\t file Cannot open.............!");
	}
	else
	{
		int flag=0;
		int num;
		blue();
		printf("\nEnter Student Id:");
		reset();
		scanf("%d",&c1.student_id);
		while(fscanf(fp_old,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",&c.book_id,c.book_name,&c.student_id,c.student_name,c.program,&c.i.yy,&c.i.mm,&c.i.dd,&c.r.yy,&c.r.mm,&c.r.dd)!=EOF)
		{
			if(c1.student_id == c.student_id)
			{
				flag=1;
				red();
				printf("\nWhat Do You want To Edit.............???");
				blue();
				printf("\n1.Book Id");
				printf("\n2.Book Name:");
				printf("\n3.Student Id");
				printf("\n4.Student Name");
				printf("\n5.Program");
				printf("\n6.Issue Date");
				yellow();
				printf("\n\tEnter any Number 1 to 6 : ");
				reset();
				scanf("%d",&num);
				if(num==1)
				{
					blue();
					printf("\nEnter New Book Id:");
					scanf("%d",&up.book_id);
					fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",up.book_id,c.book_name,c.student_id,c.student_name,c.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
				}
				if(num==2)
				{
					blue();
					printf("\nEnter Book Name:");
					scanf("%d",&up.student_id);
					fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,up.book_name,c.student_id,c.student_name,c.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
				}
				if(num==3)
				{
					blue();
					printf("\nEnter New Student Id:");
					scanf("%s",up.student_name);
					fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,c.book_name,up.student_id,c.student_name,c.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
				}
				if(num==5)
				{
					blue();
					printf("\nEnter New Student Id:");
					scanf("%s",up.student_name);
					fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,c.book_name,c.student_id,up.student_name,c.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
				}
				if(num==6)
				{
					blue();
					printf("\nEnter New Program:");
					scanf("%s",up.program);
					fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,c.book_name,c.student_id,c.student_name,up.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
				}
				if(num==6)
				{
					blue();
					printf("\nEnter New Issue date");
					printf("\nYear:");
					scanf("%d",&c.i.yy);
					printf("\nMonth:");
					scanf("%d",&c.i.mm);
					printf("\nDay:");
					scanf("%d",&c.i.dd);
					fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,c.book_name,c.student_id,c.student_name,c.program,up.i.yy,up.i.mm,up.i.dd,c.r.yy,c.r.mm,c.r.dd);
					reset();
				}
				yellow();
				printf("\n\t+++++++Edit Issue Book Details is Saved+++++\n");
				reset();
			}
			else
			{
				fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,c.book_name,c.student_id,c.student_name,c.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
			}
		}
		if(flag==0)	
		{
			white();
			printf("\n\t Record Not Found...............!\n");
			reset();
		}
	}
	fclose(fp_old);
	fclose(fp_new);
	remove("issue.txt");
	rename("new_issue.txt","issue.txt");
}
void search_issue_book_detail()//.....................................................search_issue_book_detail........................................
{
	FILE *fp_display;
	fp_display = fopen("issue.txt","r");
	if(fp_display == NULL)
	{
		printf("\n\t file Cannot Open ...........!");
	}
	else
	{
		int flag=0;
		while(fscanf(fp_display,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",&c.book_id,c.book_name,&c.student_id,c.student_name,c.program,&c.i.yy,&c.i.mm,&c.i.dd,&c.r.yy,&c.r.mm,&c.r.dd)!=EOF)
		{
			flag=1;
			red();
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
			blue();
			printf("\n\t\t\t Book Id : %d",c.book_id);
			printf("\n\t\t\t Book Name : %s",c.book_name);
			printf("\n\t\t\t Student Id : %d",c.student_id);
			printf("\n\t\t\t Student Name : %s",c.student_name);
			printf("\n\t\t\t Program : %s",c.program);
			printf("\n\t\t\t Issue Date : %d-%d-%d",c.i.yy,c.i.mm,c.i.dd);
			printf("\n\t\t\t Return Date : %d-%d-%d",c.r.yy,c.r.mm,c.r.dd);
			red();
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			reset();
		}
		if(flag==0)
		{
			white();
			printf("\n\t Record Not Found..........!\n");
			reset();
		}
	}
	fclose(fp_display);
}
void delete_issue_book_detail()
{
	struct issue c2;
	FILE *fp_old,*fp_new;
	fp_old = fopen("issue.txt","r");
	fp_new = fopen("del_issue.txt","a");
	if(fp_old==NULL || fp_new == NULL)
	{
		printf("\n\t file Cannot open..........!");
	}
	else
	{
		int flag = 0;
		int num;
		blue();
		printf("\nEnter Student Id:");
		reset();
		scanf("%d",&c2.student_id);
		while(fscanf(fp_old,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",&c.book_id,c.book_name,&c.student_id,c.student_name,c.program,&c.i.yy,&c.i.mm,&c.i.dd,&c.r.yy,&c.r.mm,&c.r.dd)!=EOF)
		{
			if(c2.student_id != c.student_id)
			{
				fprintf(fp_new,"\n%d \n%s \n%d \n%s \n%s \n%d-%d-%d \n%d-%d-%d",c.book_id,c.book_name,c.student_id,c.student_name,c.program,c.i.yy,c.i.mm,c.i.dd,c.r.yy,c.r.mm,c.r.dd);
			}
			else
			{
				flag = 1;
			}
		
		}
		yellow();
		printf("\n\t+++++++++Issue Book Details is deleted+++++++++++\n");
		reset();
		if(flag == 0)
		{
			white();
			printf("\n\n\t Record not found..........!");
			reset();
		}
	}
	fclose(fp_old);
	fclose(fp_new);
	remove("issue.txt");
	rename("del_issue.txt","issue.txt");
}
int issue_book()//.............................................issue_book.........................................................................
{
	int num;
	while(1)
	{
		red();
		printf("\n--------------------Sub Modules--------------------\n");
		blue();
		printf("\n1.Add");
		printf("\n2.Edit");
		printf("\n3.Search");
		printf("\n4.Delete");
		printf("\n5.Return Back");
		yellow();
		printf("\n\nEnter any Number: ");
		reset();
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				system("cls");
				add_issue_book_detail();
				break;
			case 2:
				system("cls");
				edit_issue_book_detail();
				break;
			case 3:
				system("cls");
				search_issue_book_detail();
				break;
			case 4:
				system("cls");
				delete_issue_book_detail();
				break;
			case 5:
				break;
			default:
				printf("\nInvalid Number......... !");
		}
		if(num==11)
		{
			system("cls");
			break;
		}
	}
}

// .........................................................Return book dteails........................................................................!!!
struct time_period
{
	int yy,mm,dd;
};
struct rtn
{
	int book_id;
	char book_name[20];
	int student_id;
	char student_name[20];
	char program[10];
	struct time_period t;	
};
struct rtn a;
void return_book_details()
{
	int return_date;
	FILE *fp_return,*fp1,*fp2;
	fp_return = fopen("return.txt","a+");
	fp1 = fopen("book.txt","r");
	fp2 = fopen("student.txt","r");
	if(fp_return == NULL || fp1 == NULL || fp2 == NULL )
	{
		printf("\n\t Cannot not open file..........!");
	}
	else
	{
		blue();	
		printf("\nEnter book Id:");
		scanf("%d",&a.book_id);
		printf("\nEnter book name:");
		scanf("%s",a.book_name);
		reset();
		while(fscanf(fp1,"\n%d \n%s \n%s \n%s \n%d-%d-%d \n%d \n%d",&b.id,b.name,b.author_name,b.publication,&b.a.yy,&b.a.mm,&b.a.dd,&b.price,&b.available_book) != EOF)
		{
			if(a.book_id == b.id && strcmp(a.book_name,b.name)==0)
			{
				blue();
				printf("\nEnter student name:");
				scanf("%s",a.student_name);
				printf("\nEnter Student Id:");
				scanf("%d",&a.student_id);
				printf("\nEnter Program:");
				scanf("%s",a.program);
				reset();
				while(fscanf(fp2,"\n%s \n%d \n%d-%d-%d \n%s \n%s \n%s \n%s \n%s \n%s ",s.name,&s.id,&s.dob.yy,&s.dob.mm,&s.dob.dd,s.gender,s.number,s.gmail,s.address,s.program,s.guardain_name)!=EOF)
				{
					if(strcmp(a.student_name,s.name)==0 && a.student_id == s.id && strcmp(a.program,s.program)==0)
					{
						printf("\nEnter return date");
						printf("\nYear:");
						scanf("%d",&a.t.yy);
						printf("\nMonth:");
						scanf("%d",&a.t.mm);
						printf("\nday:");
						scanf("%d",&a.t.dd);	
						fprintf(fp_return,"\n%d \n%s \n%s \n%d \n%s \n%d-%d-%d",a.book_id,a.book_name,a.student_name,a.student_id,a.program,a.t.yy,a.t.mm,a.t.dd);
						yellow();
						printf("\n\tReturn book details saved................!");
						reset();
					}
				}
			}
		}
	}
	fclose(fp_return);
	fclose(fp1);
	fclose(fp2);
}
void search_return_book()//............................................search_return_book.......................................................................
{
	FILE *fp1;
	fp1 = fopen("return.txt","r");
	if(fp1 == NULL)
	{
		printf("\n\t file Cannot Open ...........!");
	}
	else
	{
		int flag=0;
		while(fscanf(fp1,"\n%d \n%s \n%s \n%d \n%s \n%d-%d-%d",&a.book_id,a.book_name,a.student_name,&a.student_id,a.program,&a.t.yy,&a.t.mm,&a.t.dd)!=EOF)
		{
			flag=1;
			red();
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
			blue();
			printf("\n\t\t\t Book Id : %d",a.book_id);
			printf("\n\t\t\t Book Name : %s",a.book_name);
			printf("\n\t\t\t Student Name : %s",a.student_name);
			printf("\n\t\t\t Student Id : %d",a.student_id);
			printf("\n\t\t\t Program : %s",a.program);
			printf("\n\t\t\t Return Date : %d-%d-%d",a.t.yy,a.t.mm,a.t.dd);
			red();
			printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			reset();
		}
		if(flag==0)
		{
			white();
			printf("\n\t Record Not Found..........!\n");
			reset();
		}
	}
	fclose(fp1);
}
int return_book()//......................................................return_book.................................................................
{
	int num;
	while(1)
	{
		red();
		printf("\n--------------------Sub Modules--------------------\n");
		blue();
		printf("\n1.Add ");
		printf("\n2.Search");
		printf("\n3.fine");
		printf("\n4.return book");
		yellow();
		printf("\n\nEnter any Number: ");
		reset();
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				system("cls");
				return_book_details();
				break;
			case 2:
				system("cls");
				search_return_book();
				break;
			case 3:
				system("cls");
				break;
			case 4:
				break;
			default:
				printf("\nInvalid Number......... !");
		}
		if(num==11)
		{
			system("cls");
			break;
		}
	}
}
