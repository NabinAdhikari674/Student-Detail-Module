#include<stdio.h>
#include<conio.h>
#include<string.h>

void choice();
void entry();
void search();
void display();
void del();
void update();

FILE *fptr;
struct student
{
	char nme[20];
    int s,r,rg;	
}st;
main ()
{
	char id[20],pass[20];
	char p;
	int i=0,cho,pa;
	puts ("\n\t\t\t\t\t\tEnter your pass ID\n");
	gets (id);
	if (stricmp(id,"Nabin")!=NULL)
    {
    	puts("\n\t\t\t\t\t\tSorry !!!   Wrong ID\n\n\t\t\t\t\t\t  :( Try Again :(\n\n\n");
    	main ();
	
    }
    else 
    {
    	puts("\n\t\t\t\t\t\tEnter Your PASSWORD\n\t\t\t\t\t\t  (Case Sensitive)\n");
    while(i<10)
    {
    
    	pass[i]=getch();
    	pa=pass[i];
		if( pa==13)
    	{
    		break;
		}
		else 
		{
		printf("*");
	}
	i++;
	}
    	
	}
	pass[i]='\0';
pa=strcmp(pass,"nabinabc");

    	if (pa!=NULL)
    	{
		 puts("\n\t\t\t\t\t\tSorry !!!  Wrong Password\n\n\t\t\t\t\t\t  :( Try Again :(");
    	    main (); 
		}
	
		else 
		{ 
    	   choice();
		}
    	
    fclose(fptr);
	return 0;
}
void choice()
{
	int cho;
 puts("\n\t\t\t\t\t############# STUDENT DETAIL MODULE #############  ");
		    printf("\n\n\t\t\t\t\t\t\t CHOOSE A OPTION\n");
		    puts("\n\t\t\t1. Entry Of A New Student");
			puts("\n\t\t\t2. Search Details Of A Student");
			puts("\n\t\t\t3. Display All Details");
			puts("\n\t\t\t4. Delete A Record");
			puts("\n\t\t\t5. Update A Student Detail ");
			puts("\n\t\t\t6. EXIT ");
			puts("\n\n...............................................Enter Your Choice.....................................................");
		cho=getch();
		int c;
		c=cho;	
			switch(c)
			
		{
		    case 49: entry();
			        break;
			case 50: search();
			        break;
		    case 51: display();
		            break;
		    case 52: del();
		            break;
			case 53: update();
			        break;
		    case 54: main();
                    break;
    	}	
}
void entry()
{ 

	
	fptr=fopen("Project.txt","a");
	
	if (fptr==NULL)
	{
		puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  File is not Opened  !!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	
	
	puts ("\n\n\t\t\t\t\t***Enter The Details Of The Student***");
	puts("\n\n\tName :");
	gets(st.nme);
	puts("\n\tSection :");
	scanf("%d",&st.s);
	puts("\n\tRoll No.:");
	scanf("%d",&st.r);
	puts("\n\tRegistration NO. :");
	scanf("%d",&st.rg);
	
	fwrite(&st, sizeof(struct student), 1, fptr);
	
	fclose(fptr);
	puts("\n\n\t\t\t                         !!! SUCESS !!!");
	puts("\n\n\n\tPress : \n\n\t\tEnter TO Display All Records\n\n\t\tEsc TO Exit\n\n\t\tANY Other Key TO go TO MENU\n");
	int c;
	char cho;
	cho=getch();
		c=cho;	
   if (c==13)
   {
   	display();
   }
   else if (c==27)
   {
   	return;
   }
   else 
   {
   	choice();
   }
}
void search()
{   int srl,i=1,g=0;
    puts("\n\n\tEnter the Roll No. of the student you want to SEARCH :");
    scanf("%d",&srl);
	fptr=fopen("Project.txt","r");
  if (fptr==NULL)
  {
  	puts("                          !!!!!!!!  File NOT Found  !!!!!!!!");
  main();
  }
	while (fread (&st, sizeof(struct student), 1,fptr))
	{

	if (srl==st.r)
	{   puts("\n\n\t\t\t                         !!! Record Found !!!");
		puts("\n\n\t   Name  \t\t\t\tSection\t\t\tRoll NO.\t\t  Reg NO.\n\n");
		printf ("\n\t%d. %s \t \t\t\t %d \t\t\t %d\t\t\t %d\n",i++,st.nme,st.s,st.r,st.rg);
	}
	else if (srl!=st.r)
	{
		g++;
	}
		
	}
	fclose(fptr);
	if (g<i)
	{
	   puts("\n\n\n\t\t\t\t!!!!!!!!!!!!!!!!   RECORD NOT FOUND   !!!!!!!!!!!!!!!!!");
       puts("\n\n\n\tPress : \n\n\t\tEnter TO Display All Records\n\n\t\tEsc TO Enter the Record Of A New Student\n\n\t\tANY Other Key TO go TO MENU\n");
	int c;
	char cho;
	cho=getch();
		c=cho;	
   if (c==13)
   {
   	display();
   }
   else if (c==27)
   {
   entry();
   }
   else 
   {
   	choice();
   }
	   
	}
	
 fclose(fptr);
}
void display()
{ int i=1;
  fptr=fopen("Project.txt","r");
  if (fptr==NULL)
  {
  	puts("                          !!!!!!!!  File NOT Found  !!!!!!!!");
  main();
  }
  puts("\n\n\t   Name  \t\t\t\tSection\t\t\tRoll NO.\t\t  Reg NO.\n\n");
  
  { 
  	while (fread (&st, sizeof(struct student), 1,fptr))
  
      printf ("\n\t%d. %s \t \t\t\t %d \t\t\t %d\t\t\t %d\n",i++,st.nme,st.s,st.r,st.rg);
  
  }
  
  
   	puts("\n\n\n\tPress : \n\n\t\tEnter For MENU\n\n\t\tEsc TO Exit\n\n\t\tANY Other Key TO UPDATE Details");
   	fclose(fptr);
	int c;
	char cho;
	cho=getch();
		c=cho;	
   if (c==13)
   {
   	choice();
   }
   else if (c==27)
   {
   	return;
   } 
   else
   {
   	update();
   }


}
void del()
{ int i=1;
	int delr;
  puts("\n\n\n\tPress : \n\n\t\tEnter TO Continue\n\n\t\tEsc TO Exit\n\n\t\tANY Other Key TO Display All Records\n");
	int c;
	char cho;
	cho=getch();
		c=cho;	
   if (c==13)
   {
   
   	puts("\n\n/\t\t\t\t\tEnter The Roll NO. Of The Student TO DELETE His/Her Record :");
   	scanf("%d",&delr);
   	fptr=fopen("Project.txt","r");
  if (fptr==NULL)
  {
  	puts("                          !!!!!!!!  File NOT Found  !!!!!!!!");
  main();
  }
 
  

 while (fread (&st, sizeof(struct student), 1,fptr))
  {
  	
  	if (st.r!=delr)
  	{   puts("Deleting");
  		fwrite (&st, sizeof(struct student), 1,fptr);
	}
	
  }
  fclose(fptr);
  	puts("\n\n\n\tPress : \n\n\t\tEnter TO Display All Records\n\n\t\tEsc TO Exit\n\n\t\tANY Other Key TO go TO MENU\n");
	int c;
	char cho;
	cho=getch();
		c=cho;	
   if (c==13)
   {
   	display();
   }
   else if (c==27)
   {
   	return;
   }
   else 
   {
   	choice();
   }
  
    
   }
   else if (c==27)
   {
   	
   	return;
   }
   else 
   { 
   fptr=fopen("Project.txt","r");
  if (fptr==NULL)
  {
  	puts("                          !!!!!!!!  File NOT Found  !!!!!!!!");
  main();
  }
   
   puts("\n\n\t   Name  \t\t\t\tSection\t\t\tRoll NO.\t\t  Reg NO.\n\n");
  
  { 
  	while (fread (&st, sizeof(struct student), 1,fptr))
  
      printf ("\n\t%d. %s \t \t\t\t %d \t\t\t %d\t\t\t %d\n",i++,st.nme,st.s,st.r,st.rg);
  
  }
  fclose(fptr);
  puts("\n\n\n\tPress : \n\n\t\tEnter TO Continue To DELETE RECORDS\n\n\t\tEsc TO Exit\n");
	int c;
	char cho;
	cho=getch();
		c=cho;	
   if (c==13)
   {
   	puts("Continue");
   }
   else if (c==27)
   {
   	
   	return;
   }
  
   }
}
void update()
{
}

