 #include<conio.h>
 #include<iostream.h>
 #include<string.h>
 #include<stdio.h>
 #include<fstream.h>
 #include<stdlib.h>
 #include<iomanip.h>

 void delay(double n)
 {
   for (double i=0;i<n;i++)
   {
   }
 }

 class account
 {
   private :
   int d,u,b,a,i,age;
   long double n,acc_no;
   float curr_amnt;
   long char dob[1000],name[2500],address[5000],gender[100],email_id[2500];

   public:
   void create(long double);
   void create2(long double);   // Used for modify
   void modify(long double,long char[10]);
   void deposit(long double,long char[10],float);
   void withdraw(long double,long char[10],float);
   void details(long double,long char[10]);
   void group_by();
   void group_by_age1(int);
   void group_by_age2(int);
   void group_by_age3(int,int);
   void group_by_gender(int);
   void group_by_amnt1(float);
   void group_by_amnt2(float);
   void group_by_amnt3(float,float);
   void all_details();
   void Delete(long double,long char[10]);
 } acc;

 void account :: create (long double w)
 {
   ifstream fin("BANK.dat",ios::in|ios::binary|ios::app);
   //To check if the account number is taken already or not
   while (fin.read((char*)&acc,sizeof(acc)))
   {
     if (w==acc_no)
     {
       b=1;
       cout<<"\n\t THIS ACCOUNT NUMBER HAS ALREADY BEEN TAKEN.";
       cout<<"\n\t PLEASE USE ANOTHER ACCOUNT NUMBER.";
       break;
     }
   }
   fin.close();
   if (b!=1)
   {
     ofstream fout("BANK.dat",ios::out|ios::binary|ios::app);
     //acc_no=w;
     //cout<<"\n\t"<<acc_no; //The program shouldn't ask to give the account number again
     //fout.put(acc_no);
     //cout<<"\n\tYOUR ACCOUNT NUMBER HAS NOT BEEN TAKEN.";
     cout<<"\n\t RE-ENTER YOUR ACCOUNT NUMBER : ";
     cin>>acc_no;
     if (w==acc_no)
     {
       cout<<"\n\t FULL NAME (14 characters) : ";
       gets(name);
       cout<<"\n\t EMAIL ADDRESS (13 characters) : ";
       gets(email_id);
       cout<<"\n\t CURRENT HOME ADDRESS (16 characters) : ";
       gets(address);
       cout<<"\n\t AGE : ";
       cin>>age;
       cout<<"\n\t GENDER (MALE/FEMALE) : ";
       gets(gender);
       cout<<"\n\t DATE OF BIRTH (dd/mm/yy) : ";
       cin>>dob;
       cout<<"\n\t ENTER THE AMOUNT IN YOUR ACCOUNT : ";
       cin>>curr_amnt;
       cout<<"\n\t YOUR ACCOUNT HAS BEEN CREATED .................";
       cout<<"\n\t PLEASE USE YOUR ACCOUNT NUMBER "<<acc_no<<" TO ACCESS YOUR ACCOUNT DETAILS.";
       fout.write((char*)&acc,sizeof(acc));
     }
     else
     {
       cout<<"\n\t THE ACCOUNT NUMBERS DO NOT MATCH ......... ";
       cout<<"\n\t PLEASE TRY AGAIN LATER ............. ";
     }
     fout.close();
   }
   //delay(10000000);
   getch();
 }

 void account :: create2 (long double w)
 {
   ifstream fin("Temp.dat",ios::in|ios::binary|ios::app);
   //To check if the account number is taken already or not
   while (fin.read((char*)&acc,sizeof(acc)))
   {
     if (w==acc_no)
     {
       b=1;
       cout<<"\n\t THIS ACCOUNT NUMBER HAS ALREADY BEEN TAKEN.";
       cout<<"\n\t PLEASE USE ANOTHER ACCOUNT NUMBER.";
       break;
     }
   }
   fin.close();
   if (b!=1)
   {
     ofstream fout("Temp.dat",ios::out|ios::binary|ios::app);
     //acc_no=w;
     //cout<<"\n\t"<<acc_no; //The program shouldn't ask to give the account number again
     //fout.put(acc_no);
     //cout<<"\n\tYOUR ACCOUNT NUMBER HAS NOT BEEN TAKEN.";
     cout<<"\n\t RE-ENTER YOUR NEW ACCOUNT NUMBER : ";
     cin>>acc_no;
     if (w==acc_no)
     {
       cout<<"\n\t NEW FULL NAME (14 characters) : ";
       gets(name);
       cout<<"\n\t NEW EMAIL ADDRESS (13 characters) : ";
       gets(email_id);
       cout<<"\n\t NEW CURRENT HOME ADDRESS (16 characters) : ";
       gets(address);
       cout<<"\n\t NEW AGE : ";
       cin>>age;
       cout<<"\n\t NEW GENDER (MALE/FEMALE) : ";
       gets(gender);
       cout<<"\n\t NEW DATE OF BIRTH (dd/mm/yyyy) : ";
       cin>>dob;
       cout<<"\n\t ENTER THE NEW AMOUNT IN YOUR ACCOUNT : ";
       cin>>curr_amnt;
       cout<<"\n\t YOUR ACCOUNT HAS BEEN SUCCESSFULLY MODIFIED.";
       cout<<"\n\t PLEASE USE YOUR NEW ACCOUNT NUMBER "<<acc_no<<" TO ACCESS YOUR ACCOUNT DETAILS.";
       fout.write((char*)&acc,sizeof(acc));
     }
     else
     {
       cout<<"\n\t THE ACCOUNT NUMBERS DO NOT MATCH ......... ";
       cout<<"\n\t PLEASE TRY AGAIN LATER ............. ";
     }
     fout.close();
   }
   //cout<<delay(10000000);
   getch();
 }

 void account :: modify (long double w,long char dob2[10])
 {
   int g=0,y=0,j=0;
   ifstream fin("BANK.dat",ios::in|ios::app|ios::binary);
   ofstream fout("Temp.dat",ios::out|ios::app|ios::binary);
   while (fin.read((char*)&acc,sizeof(acc)))
   {
     if (strcmpi(dob2,dob)==0)
     {
       y=3;
       if (w==acc_no)
       {
	 j=3;
	 break;
       }
     }
   }
   fin.close();
   ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin2.read((char*)&acc,sizeof(acc)))
   {
     if (w==acc_no)
     g=3;
   }
   fin2.close();
   ifstream fin3("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin3.read((char*)&acc,sizeof(acc)))
   {
     if (j==3)
     {
       if (w!=acc_no)
       {
	 fout.write((char*)&acc,sizeof(acc));
       }
     }
     if ((y!=3)||(j!=3))
     fout.write((char*)&acc,sizeof(acc));
   }
   fin3.close();
   fout.close();
   //cout<<"\n\t y = "<<y;
   //cout<<"\n\t j = "<<j;
   //cout<<"\n\t g = "<<g;
   if (g!=3)
   cout<<"\n\t INVALID ACCOUNT NUMBER ................ ";
   if (y!=3)
   cout<<"\n\t INVALID DATE OF BIRTH ................. ";
   if ((y==3)&&(j!=3)&&(g==3))
   cout<<"\n\t INVALID DATE OF BIRTH ................. ";
   if ((j==3)&&(y==3))
   {
     cout<<"\n\t ENTER YOUR NEW ACCOUNT NUMBER : ";
     cin>>w;
     create2(w);
   }
   remove("BANK.dat");
   rename("Temp.dat","BANK.dat");
   getch();
 }

 void account :: deposit (long double w,long char dob2[10],float dpst)
 {
   int g=0,y=0,j=0;
   ifstream fin("BANK.dat",ios::in|ios::app|ios::binary);
   ofstream fout("Temp.dat",ios::out|ios::app|ios::binary);
   while (fin.read((char*)&acc,sizeof(acc)))
   {
     if (strcmpi(dob2,dob)==0)
     {
       y=3;
       if (w==acc_no)
       {
	 j=3;
	 curr_amnt+=dpst;
	 fout.write((char*)&acc,sizeof(acc));
	 break;
       }
     }
   }
   fin.close();
   ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin2.read((char*)&acc,sizeof(acc)))
   {
     if (w==acc_no)
     g=3;
   }
   fin2.close();
   ifstream fin3("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin3.read((char*)&acc,sizeof(acc)))
   {
     if (j==3)
     {
       if (w!=acc_no)
       {
	 fout.write((char*)&acc,sizeof(acc));
       }
     }
     if ((y!=3)||(j!=3))
     fout.write((char*)&acc,sizeof(acc));
   }
   //cout<<"\n\t y = "<<y;
   //cout<<"\n\t j = "<<j;
   //cout<<"\n\t g = "<<g;
   if (g!=3)
   cout<<"\n\t INVALID ACCOUNT NUMBER ................";
   if (y!=3)
   cout<<"\n\t INVALID DATE OF BIRTH .................";
   if ((y==3)&&(j!=3)&&(g==3))
   cout<<"\n\t INVALID DATE OF BIRTH .................";
   if ((j==3)&&(y==3))
   cout<<"\n\t AMOUNT HAS BEEN SUCCESSFULLY DEPOSITED INTO YOUR ACCOUNT.";
   fin3.close();
   fout.close();
   remove("BANK.dat");
   rename("Temp.dat","BANK.dat");
   getch();
 }

 void account :: withdraw (long double w,long char dob2[10],float withdr)
 {
   int s=0,g=0,y=0,j=0;
   ifstream fin("BANK.dat",ios::in|ios::app|ios::binary);
   ofstream fout("Temp.dat",ios::out|ios::app|ios::binary);
   while (fin.read((char*)&acc,sizeof(acc)))
   {
     if (strcmpi(dob2,dob)==0)
     {
       y=3;
       if (w==acc_no)
       {
	 j=3;
	 if (curr_amnt>=withdr)
	 {
	   s=3;
	   curr_amnt-=withdr;
	   fout.write((char*)&acc,sizeof(acc));
	   break;
	 }
       }
     }
   }
   fin.close();
   ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin2.read((char*)&acc,sizeof(acc)))
   {
     if (w==acc_no)
     g=3;
   }
   fin2.close();
   ifstream fin3("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin3.read((char*)&acc,sizeof(acc)))
   {
     if (s==3)
     {
       if (w!=acc_no)
       {
	 fout.write((char*)&acc,sizeof(acc));
       }
     }
     if ((y!=3)||(j!=3)||(s!=3))
     fout.write((char*)&acc,sizeof(acc));
   }
   //cout<<"\n\t y = "<<y;
   //cout<<"\n\t j = "<<j;
   //cout<<"\n\t s = "<<s;
   //cout<<"\n\t g = "<<g;
   if (g!=3)
   cout<<"\n\t INVALID ACCOUNT NUMBER ................";
   if (y!=3)
   cout<<"\n\t INVALID DATE OF BIRTH .................";
   if ((y==3)&&(j!=3)&&(g==3))
   cout<<"\n\t INVALID DATE OF BIRTH .................";
   if ((y==3)&&(j==3)&&(s!=3))
   cout<<"\n\t YOU DO NOT HAVE ENOUGH AMOUNT IN YOUR ACCOUNT TO MAKE A WITHDRAWAL.";
   if ((j==3)&&(y==3)&&(s==3))
   cout<<"\n\t AMOUNT HAS BEEN SUCCESSFULLY WITHDRAWN FROM YOUR ACCOUNT.";
   fin3.close();
   fout.close();
   remove("BANK.dat");
   rename("Temp.dat","BANK.dat");
   getch();
 }

 void account :: details (long double w,long char dob2[10])
 {
   ifstream fin("BANK.dat",ios::in|ios::binary|ios::app);
   while (fin.read((char*)&acc,sizeof(acc)))
   {
     if (w==acc_no)
     {
       i=3;
       if (strcmpi(dob2,dob)==0)
       {
	 d=3;
	 cout<<"\n\n\t\t ACCOUNT NUMBER : "<<acc_no;
	 cout<<"\n\t\t NAME : "<<name;
	 cout<<"\n\t\t EMAIL ADDRESS : "<<email_id;
	 cout<<"\n\t\t CURRENT HOME ADDRESS : "<<address;
	 cout<<"\n\t\t AGE : "<<age;
	 cout<<"\n\t\t GENDER : "<<gender;
	 cout<<"\n\t\t DATE OF BIRTH : "<<dob;
	 cout<<"\n\t\t AMOUNT PRESENT IN YOUR ACCOUNT : "<<curr_amnt;
	 //delay(15000000);
	 break;
       }
       //break;      //Should there be a break here or not ?
     }
   }
   if (i!=3)
   {
     cout<<"\n\t INVALID ACCOUNT NUMBER ...........";
     //delay(15000000);
   }
   if ((d!=3)&&(i==3))
   {
     cout<<"\n\t INVALID DATE OF BIRTH ............";
     //delay(15000000);
   }
   fin.close();
   getch();
 }

 void account :: group_by()
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   cout<<"\n\n\t ENTER THE ADMIN PASSWORD : ";
   cin>>n;
   if (n==123456)
   {
     do
     {
       clrscr();
       cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
       cout<<"\n\n\t\t 1. GROUP BY AGE ";
       cout<<"\n\t\t 2. GROUP BY GENDER ";
       cout<<"\n\t\t 3. GROUP BY AMOUNT PRESENT IN ACCOUNT ";
       cout<<"\n\t\t 4. EXIT ";
       cout<<"\n\n\t\t ENTER YOUR CHOICE (1 - 4) : ";
       cin>>u;
       switch(u)
       {
	 case 1 : do
		  {
		    clrscr();
		    cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		    cout<<"\n\n\t\t CATEGORIZE AGE BY : ";
		    cout<<"\n\n\t\t 1. LESS THAN (<) (AGE) ";
		    cout<<"\n\t\t 2. GREATER THAN (<) (AGE) ";
		    cout<<"\n\t\t 3. CERTAIN RANGE (< >) (AGE) ";
		    cout<<"\n\t\t 4. EXIT ";
		    cout<<"\n\n\t\t ENTER YOUR CHOICE (1 - 4) : ";
		    cin>>a;
		    switch(a)
		    {
		      case 1 : cout<<"\n\n\t\t ENTER THE UPPER LIMIT OF AGE : ";
			       cin>>b;
			       group_by_age1(b);
			       break;
		      case 2 : cout<<"\n\n\t\t ENTER THE LOWER LIMIT OF AGE : ";
			       cin>>b;
			       group_by_age2(b);
			       break;
		      case 3 : cout<<"\n\n\t\t ENTER THE LOWER LIMIT OF AGE : ";
			       cin>>b;
			       cout<<"\n\t\t ENTER THE UPPER LIMIT OF AGE : ";
			       cin>>i;
			       group_by_age3(b,i);
			       break;
		      case 4 : break;
		      default : cout<<"\n\n\t\t INVALID CHOICE ............ ";
				cout<<"\n\t\t PLEASE TRY AGAIN LATER ......... ";
				delay(9000000);
				break;
		    }
		  } while (a!=4);
		  break;
	 case 2 : do
		  {
		    clrscr();
		    cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		    cout<<"\n\n\t\t CATEGORIZE GENDER BY : ";
		    cout<<"\n\n\t\t 1. MALE ";
		    cout<<"\n\t\t 2. FEMALE ";
		    cout<<"\n\t\t 3. EXIT ";
		    cout<<"\n\n\t\t ENTER YOUR CHOICE (1 - 3) : ";
		    cin>>a;
		    switch(a)
		    {
		      case 1 : group_by_gender(1);
			       break;
		      case 2 : group_by_gender(2);
			       break;
		      case 3 : break;
		      default : cout<<"\n\n\t\t INVALID CHOICE ............ ";
				cout<<"\n\t\t PLEASE TRY AGAIN LATER ......... ";
				delay(9000000);
				break;
		    }
		  } while (a!=3);
		  break;
	 case 3 : do
		  {
		    clrscr();
		    cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		    cout<<"\n\n\t\t CATEGORIZE AMOUNT BY : ";
		    cout<<"\n\n\t\t 1. LESS THAN (<) (AMOUNT) ";
		    cout<<"\n\t\t 2. GREATER THAN (<) (AMOUNT) ";
		    cout<<"\n\t\t 3. CERTAIN RANGE (< >) (AMOUNT) ";
		    cout<<"\n\t\t 4. EXIT ";
		    cout<<"\n\n\t\t ENTER YOUR CHOICE (1 - 4) : ";
		    cin>>a;
		    switch(a)
		    {
		      case 1 : cout<<"\n\n\t\t ENTER THE UPPER LIMIT OF AMOUNT : ";
			       cin>>b;
			       group_by_amnt1(b);
			       break;
		      case 2 : cout<<"\n\n\t\t ENTER THE LOWER LIMIT OF AMOUNT : ";
			       cin>>b;
			       group_by_amnt2(b);
			       break;
		      case 3 : cout<<"\n\n\t\t ENTER THE LOWER LIMIT OF AMOUNT : ";
			       cin>>b;
			       cout<<"\n\t\t ENTER THE UPPER LIMIT OF AMOUNT : ";
			       cin>>i;
			       group_by_amnt3(b,i);
			       break;
		      case 4 : break;
		      default : cout<<"\n\n\t\t INVALID CHOICE ............ ";
				cout<<"\n\t\t PLEASE TRY AGAIN LATER ......... ";
				delay(9000000);
				break;
		    }
		  } while (a!=4);
		  break;
	 case 4 : break;
	 default : cout<<"\n\n\t\t INVALID CHOICE ............ ";
		   cout<<"\n\t\t PLEASE TRY AGAIN LATER ......... ";
		   delay(9000000);
		   break;
       }
     } while (u!=4);
   }
   else
   cout<<"\n\n\t\t INCORRECT PASSWORD .................. ";
   getch();
 }

 void account :: group_by_age1(int w)
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
   while(fin1.read((char*)&acc,sizeof(acc)))
   {
     if (age<w)
     {
       i=3;
       break;
     }
   }
   //cout<<"\n\t i = "<<i;
   fin1.close();
   if (i==3)
   {
     cout<<"\n\n\t SHOWING DETAILS OF PEOPLE UNDER THE AGE OF "<<w<<" ............ ";
     ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
     cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
     cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
     cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
     while(fin2.read((char*)&acc,sizeof(acc)))
     {
       if (age<w)
       {
	 cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	 cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       }
     }
     fin2.close();
   }
   else
   cout<<"\n\n\t NO RECORD EXISTS HAVING AGE LESS THAN "<<w;
   getch();
 }

 void account :: group_by_age2(int w)
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
   while(fin1.read((char*)&acc,sizeof(acc)))
   {
     if (age>w)
     {
       i=3;
       break;
     }
   }
   //cout<<"\n\t i = "<<i;
   fin1.close();
   if (i==3)
   {
     cout<<"\n\n\t SHOWING DETAILS OF PEOPLE ABOVE THE AGE OF "<<w<<" ............ ";
     ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
     cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
     cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
     cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
     while(fin2.read((char*)&acc,sizeof(acc)))
     {
       if (age>w)
       {
	 cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	 cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       }
     }
     fin2.close();
   }
   else
   cout<<"\n\n\t NO RECORD EXISTS HAVING AGE MORE THAN "<<w;
   getch();
 }

 void account :: group_by_age3(int w1,int w2)
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
   while(fin1.read((char*)&acc,sizeof(acc)))
   {
     if ((age>w1)&&(age<w2))
     {
       i=3;
       break;
     }
   }
   //cout<<"\n\t i = "<<i;
   fin1.close();
   if (i==3)
   {
     cout<<"\n\n\t SHOWING DETAILS OF PEOPLE BETWEEN THE AGE OF "<<w1<<" AND "<<w2<<" ............ ";
     ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
     cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
     cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
     cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
     while(fin2.read((char*)&acc,sizeof(acc)))
     {
       if ((age>w1)&&(age<w2))
       {
	 cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	 cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       }
     }
     fin2.close();
   }
   else
   cout<<"\n\n\t NO RECORD EXISTS HAVING AGE BETWEEN "<<w1<<" AND "<<w2;
   getch();
 }

 void account :: group_by_gender(int w)
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   if (w==1)
   {
     ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
     while(fin1.read((char*)&acc,sizeof(acc)))
     {
       if (strcmpi(gender,"male")==0)
       {
	 i=3;
	 break;
       }
     }
     //cout<<"\n\t i = "<<i;
     fin1.close();
     if (i==3)
     {
       cout<<"\n\n\t SHOWING DETAILS OF PEOPLE WHOSE GENDER IS MALE ............ ";
       ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
       cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
       cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
       cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       while(fin2.read((char*)&acc,sizeof(acc)))
       {
	 if (strcmpi(gender,"male")==0)
	 {
	   cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	   cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
	 }
       }
       fin2.close();
     }
     else
     cout<<"\n\n\t NO RECORD EXISTS WHOSE GENDER IS MALE ";
   }
   else
   {
     ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
     while(fin1.read((char*)&acc,sizeof(acc)))
     {
       if (strcmpi(gender,"female")==0)
       {
	 i=3;
	 break;
       }
     }
     //cout<<"\n\t i = "<<i;
     fin1.close();
     if (i==3)
     {
       cout<<"\n\n\t SHOWING DETAILS OF PEOPLE WHOSE GENDER IS FEMALE ............ ";
       ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
       cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
       cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
       cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       while(fin2.read((char*)&acc,sizeof(acc)))
       {
	 if (strcmpi(gender,"female")==0)
	 {
	   cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	   cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
	 }
       }
       fin2.close();
     }
     else
     cout<<"\n\n\t NO RECORD EXISTS WHOSE GENDER IS FEMALE ";
   }
   getch();
 }

 void account :: group_by_amnt1(float w)
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
   while(fin1.read((char*)&acc,sizeof(acc)))
   {
     if (curr_amnt<w)
     {
       i=3;
       break;
     }
   }
   //cout<<"\n\t i = "<<i;
   fin1.close();
   if (i==3)
   {
     cout<<"\n\n\t SHOWING DETAILS OF PEOPLE HAVING AMOUNT LESS THAN "<<w<<" ............ ";
     ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
     cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
     cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
     cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
     while(fin2.read((char*)&acc,sizeof(acc)))
     {
       if (curr_amnt<w)
       {
	 cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	 cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       }
     }
     fin2.close();
   }
   else
   cout<<"\n\n\t NO RECORD EXISTS HAVING AMOUNT LESS THAN "<<w;
   getch();
 }

 void account :: group_by_amnt2(float w)
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
   while(fin1.read((char*)&acc,sizeof(acc)))
   {
     if (curr_amnt>w)
     {
       i=3;
       break;
     }
   }
   //cout<<"\n\t i = "<<i;
   fin1.close();
   if (i==3)
   {
     cout<<"\n\n\t SHOWING DETAILS OF PEOPLE HAVING AMOUNT MORE THAN "<<w<<" ............ ";
     ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
     cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
     cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
     cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
     while(fin2.read((char*)&acc,sizeof(acc)))
     {
       if (curr_amnt>w)
       {
	 cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	 cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       }
     }
     fin2.close();
   }
   else
   cout<<"\n\n\t NO RECORD EXISTS HAVING AMOUNT MORE THAN "<<w;
   getch();
 }

 void account :: group_by_amnt3(float w1,float w2)
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   ifstream fin1("BANK.dat",ios::in|ios::app|ios::binary);
   while(fin1.read((char*)&acc,sizeof(acc)))
   {
     if ((curr_amnt>w1)&&(curr_amnt<w2))
     {
       i=3;
       break;
     }
   }
   //cout<<"\n\t i = "<<i;
   fin1.close();
   if (i==3)
   {
     cout<<"\n\n\t SHOWING DETAILS OF PEOPLE HAVING AMOUNT BETWEEN "<<w1<<" AND "<<w2<<" ............ ";
     ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
     cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
     cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
     cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
     while(fin2.read((char*)&acc,sizeof(acc)))
     {
       if ((curr_amnt>w1)&&(curr_amnt<w2))
       {
	 cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	 cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       }
     }
     fin2.close();
   }
   else
   cout<<"\n\n\t NO RECORD EXISTS HAVING AMOUNT BETWEEN "<<w1<<" AND "<<w2;
   getch();
 }

 /*void account :: all_details()
 {
   clrscr();
   ifstream fin("BANK.dat",ios::in|ios::binary|ios::app);
   cout<<"\n\t/////////////////// BANK MANAGEMENT SYSTEM ///////////////////";
   cout<<"\n\n\tENTER THE PASSWORD : ";
   cin>>n;
   if (n==123456)
   {
     while(fin.read((char*)&acc,sizeof(acc)))
     {
       cout<<"\n\n\tACCOUNT NUMBER : "<<acc_no;
       cout<<"\n\tNAME : "<<name;
       cout<<"\n\tEMAIL ADDRESS : "<<email_id;
       cout<<"\n\tCURRENT HOME ADDRESS : "<<address;
       cout<<"\n\tAGE : "<<age;
       cout<<"\n\tGENDER : "<<gender;
       cout<<"\n\tDATE OF BIRTH : "<<dob;
       cout<<"\n\tCOMPANY : "<<company;
       cout<<"\n\tAMOUNT PRESENT IN YOUR ACCOUNT : "<<curr_amnt;
     }
   }
   else
   cout<<"\n\n\tINCORRECT PASSWORD.";
   //delay(15000000);
   fin.close();
   getch();
 }*/

 void account :: all_details()
 {
   clrscr();
   cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
   cout<<"\n\n\t ENTER THE ADMIN PASSWORD : ";
   cin>>n;
   if (n==123456)
   {
     clrscr();
     int p=4;
     cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
     ifstream fin("BANK.dat",ios::in|ios::binary);
     while (fin.read((char*)&acc,sizeof(acc)))
     {
       //cout<<"\n\t "<<acc_no;
       if (fin.tellg()==0)
       {
	 p=0;
	 //break;
	}              // To check if there are any records in the file
     }
     //cout<<"\n\t "<<fin.tellg();
     fin.close();
     //cout<<"\n\t p = "<<p;
     if (p!=0)
     {
       ifstream fin1("BANK.dat",ios::in|ios::binary|ios::app);
       cout<<"\n\n|----|--------------|-------------|---------------|---|------|---------|------|";
       cout<<"\n|A_NO|"<<setw(9)<<"NAME"<<setw(6)<<"|"<<setw(9)<<"EMAIL"<<setw(5)<<"|"<<setw(11)<<"ADDRESS"<<setw(8)<<"|AGE"<<"|GENDER|"<<setw(6)<<"DOB"<<setw(11)<<"|AMOUNT|";
       cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       while(fin1.read((char*)&acc,sizeof(acc)))
       {
	 cout<<"\n|"<<setw(4)<<acc_no<<"|"<<setw(14)<<name<<"|"<<setw(13)<<email_id<<"|"<<setw(15)<<address<<"|"<<setw(3)<<age<<"|"<<setw(6)<<gender<<"|"<<setw(9)<<dob<<"|"<<setw(6)<<curr_amnt<<"|";
	 cout<<"\n|----|--------------|-------------|---------------|---|------|---------|------|";
       }
       fin1.close();
     }
     else
     cout<<"\n\t NO RECORDS ARE PRESENT IN THE FILE. ";
   }
   else
   cout<<"\n\n\t INCORRECT PASSWORD.";
   //delay(15000000);
   getch();
 }

 void account :: Delete (long double w,long char dob2[10])
 {
   int g=0,y=0,j=0;
   ifstream fin("BANK.dat",ios::in|ios::app|ios::binary);
   ofstream fout("Temp.dat",ios::out|ios::app|ios::binary);
   while (fin.read((char*)&acc,sizeof(acc)))
   {
     if (strcmpi(dob2,dob)==0)
     {
       y=3;
       if (w==acc_no)
       {
	 j=3;
	 break;
       }
     }
   }
   fin.close();
   ifstream fin2("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin2.read((char*)&acc,sizeof(acc)))
   {
     if (w==acc_no)
     g=3;
   }
   fin2.close();
   ifstream fin3("BANK.dat",ios::in|ios::app|ios::binary);
   while (fin3.read((char*)&acc,sizeof(acc)))
   {
     if (j==3)
     {
       if (w!=acc_no)
       {
	 fout.write((char*)&acc,sizeof(acc));
       }
     }
     if ((y!=3)||(j!=3))
     fout.write((char*)&acc,sizeof(acc));
   }
   //cout<<"\n\t y = "<<y;
   //cout<<"\n\t j = "<<j;
   //cout<<"\n\t g = "<<g;
   if (g!=3)
   cout<<"\n\t INVALID ACCOUNT NUMBER ................ ";
   if (y!=3)
   cout<<"\n\t INVALID DATE OF BIRTH ................. ";
   if ((y==3)&&(j!=3)&&(g==3))
   cout<<"\n\t INVALID DATE OF BIRTH ................. ";
   if ((j==3)&&(y==3))
   cout<<"\n\t YOUR ACCOUNT HAS BEEN SUCCESSFULLY DELETED. ";
   fin3.close();
   fout.close();
   remove("BANK.dat");
   rename("Temp.dat","BANK.dat");
   getch();
 }

 void load()
 {
   clrscr();
   for (int i=1;i<=50;i++)
   {
     clrscr();
     cout<<"\n\n\n\n\n\n\n\t\t\t\t     Loading "<<"\n"<<'\n'<<'\t'<<'\t';
     for(int j=1;j<=i;j++)
     cout<<"²";
     cout<<"\n\n\t\t\t\t      "<<2*i<<" % ";
     if (i>1&&i<20)
     cout<<"\n\n\t\t\t    Creating Temporary files ";
     else if (i>20&&i<40)
     cout<<"\n\n\t\t\t     Accessing Main Memory ";
     else if(i>40&&i<48)
     cout<<"\n\n\t\t\t        Accessing Cache ";
     else
     cout<<"\n\n\t\t\t             Complete ";
     delay(100000);
   }
   delay(1000);
 }
 void load();

 void main()
 {
   int n;
   float dpst,withdr;
   long double w;
   long char dob[10];
   do
   {
     clrscr();
     cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
     cout<<"\n\n\t\t 1. CREATE A NEW ACCOUNT ";
     cout<<"\n\t\t 2. MODIFY YOUR ACCOUNT DETAILS ";
     cout<<"\n\t\t 3. DEPOSIT MONEY IN YOUR ACCOUNT ";
     cout<<"\n\t\t 4. WITHDRAW MONEY FROM YOUR ACCOUNT ";
     cout<<"\n\t\t 5. SHOW DETAILS OF YOUR ACCOUNT ";
     cout<<"\n\t\t 6. GROUP ACCOUNTS ";
     cout<<"\n\t\t 7. SHOW ALL ACCOUNT DETAILS ";
     cout<<"\n\t\t 8. DELETE AN ACCOUNT ";
     cout<<"\n\t\t 9. EXIT ";
     cout<<"\n\n\t\t ENTER YOUR CHOICE (1 - 9) : ";
     cin>>n;
     switch(n)
     {
       case 1 : load();
		clrscr();
		cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		cout<<"\n\n\t ENTER YOUR ACCOUNT NUMBER : ";
		cin>>w;
		acc.create(w);
		break;
       case 2 : load();
		clrscr();
		cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		cout<<"\n\n\t ENTER THE ACCOUNT NUMBER TO BE MODIFIED : ";
		cin>>w;
		cout<<"\n\t ENTER THE DOB FOR CONFIRMATION : ";
		cin>>dob;
		acc.modify(w,dob);
		break;
       case 3 : load();
		clrscr();
		cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		cout<<"\n\n\t ENTER YOUR ACCOUNT NUMBER : ";
		cin>>w;
		cout<<"\n\t ENTER YOUR DATE OF BIRTH FOR CONFIRMATION  : ";
		cin>>dob;
		cout<<"\n\n\t AMOUNT TO BE DEPOSITED : ";
		cin>>dpst;
		acc.deposit(w,dob,dpst);
		break;
       case 4 : load();
		clrscr();
		cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		cout<<"\n\n\t ENTER YOUR ACCOUNT NUMBER : ";
		cin>>w;
		cout<<"\n\t ENTER YOUR DATE OF BIRTH FOR CONFIRMATION  : ";
		cin>>dob;
		cout<<"\n\n\t AMOUNT TO BE WITHDRAWN : ";
		cin>>withdr;
		acc.withdraw(w,dob,withdr);
		break;
       case 5 : load();
		clrscr();
		cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		cout<<"\n\n\t ACCOUNT NUMBER : ";
		cin>>w;
		cout<<"\n\t ENTER YOUR DATE OF BIRTH FOR CONFIRMATION : ";
		cin>>dob;
		acc.details(w,dob);
		break;
       case 6 : load();
		acc.group_by();
		break;
       case 7 : load();
		acc.all_details();
		break;
       case 8 : load();
		clrscr();
		cout<<"\n\t /////////////////// BANK MANAGEMENT SYSTEM /////////////////// ";
		cout<<"\n\n\t ACCOUNT NUMBER : ";
		cin>>w;
		cout<<"\n\t ENTER YOUR DATE OF BIRTH FOR CONFIRMATION : ";
		cin>>dob;
		acc.Delete(w,dob);
		break;
       case 9 : exit(0);
		break;
       default : cout<<"\n\t\t INVALID CHOICE ........... ";
		 cout<<"\n\t\t PLEASE TRY AGAIN ......... ";
		 delay(9000000);
		 break;
     }
   } while (n!=9);
   getch();
 }











