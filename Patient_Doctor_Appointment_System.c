/* SEMESTER PROJECT
___________________________________________________________________
This is my semester project that is Hospital Doctor Patient Appointment manegment system.
___________________________________________________________________
Written by M Taha Khadim (2020mc70@student.uet.edu.pk) on 23-DEC-2021
IDE: Visual Studio Code 1.60.0
C Compiler: GCC{Rev.5,Builtby MSYS2 Project}*/
//--------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>                                                           //libraries that are being used in this program
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"colors.h"
struct patient                                                              //structure for patients data storage
{
    char name[30];
    char number[15];
    char time_app[25];
}p[400];
int patient_no=0;                                                                       //global variables/arrays
int appointment[20]={5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
char t[30];
FILE *fp;
char doctor[20] = "Doctor_Data.txt";
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
// DECLARATIONS OF FUNCTIONS USED ------------------------------------------------------------------------------------------------------------------
int  doctor_or_patient();                                                               //functions declaration
void print_text_file(char *);                                                          // All functions used 
void  patient_menu();
void doctor_start();
void doctor_menu(int);
void data_storing(int,struct patient *p);
char *time_ap();
void manegment();
void manegment_log();
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
// MAIN --------------------------------------------------------------------------------------------------------------------------------------------
int main()                                                                               //     /\  /\   /\  |  /\  /
{                                                                                       //     /  \/  \ /--\ | /  \/
    int selection=0;
    char user_name[100];
    selection=doctor_or_patient();
    if(selection==0)
    {
        exit(1);
    }
    if(selection==1)
    {
     patient_menu();
    }
    else if(selection==2)
    {
        doctor_start();
    }
    else if(selection==3)
    {
        manegment();
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
// END OF MAIN -------------------------------------------------------------------------------------------------------------------------------------
int doctor_or_patient()                                                                 //Just a simple selector
{
    int select_doc_pat=0,i=0;
    while(i==0)
    {  system("cls");
        system("color e");
       printf("\n\n\n**************************************************************Hospital's Appointment manegment system******************************************************************\n\n\n");
        printf("\t\t1. You are a Patient\n\t\t  2. You are a doctor\n\t\t    3.Manegment System\n\t\t\t0.Exit\n\t\t\t   Select an option >>  ");
        scanf("%d",&select_doc_pat);
        if(select_doc_pat>=0&&select_doc_pat<=3)
        {
             i++;
        }
    }
    return select_doc_pat;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
// PATIENT WORK ------------------------------------------------------------------------------------------------------------------------------------
void  patient_menu()                                                                        //patient menu 
{  char ddf[20]="Doctor_Data.txt";
    system("cls");
    system("color b");
printf("****************************************************************Patient's Menu********************************************************************\n");
    printf("Doctor Avalable at the Hospital are :\n");
        print_text_file(ddf);

    int doc_no=-1;
    while(doc_no<0||doc_no>20)
    {
        printf("\n\t\t\t\tPress 0 to goto Main Menu\n\t\t\t\t\t======>Select any >> ");
        scanf("%d",&doc_no);
        if((doc_no<0||doc_no>=20))
        {printf("Invalid Choice !");}
    }
    system("cls");
    system("color e");
    printf("****************************************************************Appointment Menu********************************************************************\n");
    if(doc_no>0&&doc_no<=20)
    {
        if(appointment[doc_no-1]!=0)
        {
            printf("\n\n********************************** Appointments Avalable **********************************");
            printf("\n\nPlease enter Your name >> ");
            fgets(p[patient_no].name,sizeof(p[patient_no].name),stdin);
            fgets(p[patient_no].name,sizeof(p[patient_no].name),stdin);                                                          //name
            while(strlen(p[patient_no].number)!=12)
            {
                printf("\nPlease enter Your mobile number(03001234567) >> ");
                fgets(p[patient_no].number,sizeof(p[patient_no].number),stdin);                                                   //number
                if(strlen(p[patient_no].number)!=12)
                {printf("Invalid number!Try Again >> %d\n",(strlen(p[patient_no].number)));}
            }
                    appointment[doc_no-1]-=1;
            printf("\n\n********************************** Appointment placed and serial no is %d\n\n",5-appointment[doc_no-1]);
            strcpy(p[patient_no].time_app,time_ap());                                                                             //time
            data_storing(doc_no,&p[patient_no]);
            
        }else
            {
                printf("\n\n\t\tSorry! For selected Doctor, Today's Appointments are Full.\n");
            }
        if((5-appointment[doc_no-1])!=0)
        {
            // data_storing(doc_no,&p[patient_no]);

            patient_no++;
        }
        system("pause");
        main();
    }
    else
    {
        main();
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------
}
void print_text_file(char *x)
{
    fp =  fopen(x,"r");                                                                     //doctor data text file reading
    char c;
    if(fp!=NULL)
    {
            while (1)
        {
            c=fgetc(fp);
            printf("%c",c);
            // c=fgetc(fp);
            if(c==EOF){break;}
        }
    }else   {
                printf("No Appointments.\n\n");
            }
    fclose(fp);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
// DOCTOR START ------------------------------------------------------------------------------------------------------------------------------------

void doctor_start()
{
    int count_pass=0,count_name=0;
    int x=-100,drsr;
    char user_name[20],password[20];
    char id[20][30]={"Amjad","Samina","Maria","Amir","Mahmood","Adeel","Amrita","Usman","Gulfraz","Khawaja","Shumaila","Hanif","Saleem","Naveed","Irfan","Nadeem","Abbas","Kalim","Mehmood_Shah","Omer"};
    char pass[20][30]={"12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345","12345"};
    system("cls");
    system("color 3");
        printf("****************************************************************Doctor's Menu********************************************************************\n");
        printf("\n\n\tPlease log-in to your Doctor's ID");
        loop_name:printf("\n\t\tEnter User name >> ");
        scanf("%s",user_name);
            for(int i=0; i<20 ; i++)
            {
                 if(strcmp(user_name,id[i])==0)
                    {
                        x=i;
                        loop_pass:printf("\t\t\t%s! Please enter your password >> ",user_name);
                        scanf("%s",password);
                        if(strcmp(password,pass[x])==0)
                            {
                                drsr=x+1;                                                               //Password Checker
                                system("cls");
                                system("color e");
                                doctor_menu(drsr);
                                count_pass++;
                            }if(count_pass<1){printf("Invalid! Try Again");goto loop_pass;}
                    count_name++; 
                    }
                }
                if(count_name<1){printf("Invalid! Try Again");goto loop_name;
            } 
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void doctor_menu(int x)
{
    int d=0;
    while(d==0||d>2||d<0)
    {
        printf("****************************************************************Doctor's Menu********************************************************************\n");
        printf("\n\n\t\t1.Main menu\n\t\t2.See Appointments\n\t\t\t");
        scanf("%d",&d);
        if(d==1)
        {
            main();
        }
        else if (d==2)                                                                              //Doctor_File printer
        {
            system("color e");
            switch (x)
            {
            case 1:
                print_text_file("doc1.txt");
                break;
            case 2:
                print_text_file("doc2.txt");
                break;
            case 3:
                print_text_file("doc3.txt");
                break;
            case 4:
                print_text_file("doc4.txt");
                break;
            case 5:
                print_text_file("doc5.txt");
                break;
            case 6:
                print_text_file("doc6.txt");
                break;
            case 7:
                print_text_file("doc7.txt");
                break;
            case 8:
                print_text_file("doc8.txt");
                break;
            case 9:
                print_text_file("doc9.txt");
                break;
            case 10:
                print_text_file("doc10.txt");
                break;
            case 11:
                print_text_file("doc11.txt");
                break;
            case 12:
                print_text_file("doc12.txt");
                break;
            case 13:
                print_text_file("doc13.txt");
                break;
            case 14:
                print_text_file("doc14.txt");
                break;
            case 15:
                print_text_file("doc15.txt");
                break;
            case 16:
                print_text_file("doc16.txt");
                break;
            case 17:
                print_text_file("doc17.txt");
                break;
            case 18:
                print_text_file("doc18.txt");
                break;
            case 19:
                print_text_file("doc19.txt");
                break;
            case 20:
                print_text_file("doc20.txt");
                break;
            default:
                break;
            }
        system("pause");                                                                //System pause
        }
    main();
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------

void data_storing(int doctor_no,struct patient *p)
{
    FILE *ff;
    switch (doctor_no)                                                                //storing patients data in each doctor's text file sepratly
    {
    case 1:
        ff=fopen("doc1.txt","a+");
        
        break;
    case 2:
        ff=fopen("doc2.txt","a+");
        
        break;
    case 3:
        ff=fopen("doc3.txt","a+");
        
        break;
    case 4:
        ff=fopen("doc4.txt","a+");
        
        break;
    case 5:
        ff=fopen("doc5.txt","a+");
        
        break;
    case 6:
        ff=fopen("doc6.txt","a+");
        
        break;
    case 7:
       ff=fopen("doc7.txt","a+");
        
        break;
    case 8:
        ff=fopen("doc8.txt","a+");
        
        break;
    case 9:
        ff=fopen("doc9.txt","a+");
        
        break;
    case 10:
        ff=fopen("doc10.txt","a+");
        
        break;
    case 11:
        ff=fopen("doc11.txt","a+");
        
        break;
    case 12:
        ff=fopen("doc12.txt","a+");
        
        break;
    case 13:
        ff=fopen("doc13.txt","a+");
        
        break;
    case 14:
        ff=fopen("doc14.txt","a+");
        
        break;
    case 15:
        ff=fopen("doc15.txt","a+");
        
        break;
    case 16:
        ff=fopen("doc16.txt","a+");
        
        break;
    case 17:
        ff=fopen("doc17.txt","a+");
        
        break;
    case 18:
        ff=fopen("doc18.txt","a+");
        
        break;
    case 19:
        ff=fopen("doc19.txt","a+");
        
        break;
    case 20:
        ff=fopen("doc20.txt","a+");
        
        break;
    default:
        break;
    }
    printf("\n%s\n",p->name);                                                                           //file writing
        if((5-appointment[doctor_no-1])==1)
            {
                fprintf(ff,"\n******************************Today's appointments list******************************\n");
            }
        fprintf(ff,"\n\nPatient's Name: %s",(p->name));
        fprintf(ff,"Patient's Mobile no: %s",(p->number));
        fprintf(ff,"Booking time : %s",(p->time_app));
        fprintf(ff,"\nPatient's serial no: %d",5-appointment[doctor_no-1]);
        fprintf(ff,"\n");
    fclose(ff);
    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//-Manegment----------------------------------------------------------------------------------------------------------------------------------------
void manegment()
{ 
    int var=0;
    char id[20];
    char pass[10];
    char temp[20];
    FILE *fp;
    fp=fopen("Manegment_ids.txt","r");
    system("cls");
    printf("\n\n\n************************************************************** Manegment Menu ******************************************************************\n\n\n");
    Justgo:printf("\t\tEnter your manegment id >> ");
    scanf("%s",id);
    while(strcmp(id,temp)!=0)
    {
    fscanf(fp,"%s",temp);
    }
    fscanf(fp,"%s",temp);
    do{
    printf("\n\t\t\tEnter Password >> ");
    scanf("%s",pass);
    if(strcmp(pass,temp)==0)
    {
        var=0;
            manegment_log();
    }
    else
    {
        printf("Wrong password! ");
        var++;
    }}while(var>0);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
char *time_ap()                                                                             //will return time and date at the point called
{
    char * time_str;
    time_t mytime = time(NULL);
    time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';
    return time_str;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------

void manegment_log()
{
    int x=0;
    Wrongselect:system("cls");
    printf("\n\n\n************************************************************** Manegment Menu ******************************************************************\n\n\n");
    printf("\n\t\t0.Main menu\n\n\t\t1. Show every doctor's appointments\n\n\t\t  2.Clear All stored data from doctors' files\n\n\t\t\tSelect an option >>  ");
    scanf("%d",&x);
    if(x>3)
    {
        goto Wrongselect;
    }
    if(x==0)                                //Return to main menu
    {
        main();
    }
    if(x==1)
    {                                                                                   //Showing whole data of doctors
        printf("\nThis is the data of every doctor's Appointment.\n");
        cyan();                                                                     //color changer defined in the colors.h
        printf("1.Dr.Muhammad Amjad Bhatti\n");
        reset();                                                                    //reset defined in the colors.h
        print_text_file("doc1.txt");
        cyan();
        printf("2.Dr.Saima Saeed\n");        
        reset();
        print_text_file("doc2.txt");
        cyan();
        printf("3.Dr.Maria Mehmood\n");
        reset();
        print_text_file("doc3.txt");
        cyan();
        printf("4.Dr.Amir Riaz Bhutta\n");
        reset();
        print_text_file("doc4.txt");
        cyan();
        printf("5.Dr.Mehmood-Ul-Haq Farooqi\n");
        reset();
        print_text_file("doc5.txt");
        cyan();
        printf("6.Dr.Adeel Khalil\n");
        reset();
        print_text_file("doc6.txt");
        cyan();
        printf("7.Dr.Amrita Rizwan\n");
        reset();
        print_text_file("doc7.txt");
        cyan();
        printf("8.Dr.Usman Iqbal\n");
        reset();
        print_text_file("doc8.txt");
        cyan();
        printf("9.Dr.Raja GulFraz Akbar\n");
        reset();
        print_text_file("doc9.txt");
        cyan();
        printf("10.Dr.Khwaja Amjad Hassan\n");
        reset();
        print_text_file("doc10.txt");
        cyan();
        printf("11.Dr.Shumaila Asghar\n");
        reset();
        print_text_file("doc11.txt");
        cyan();
        printf("12.Dr.Hanif Jan\n");
        reset();
        print_text_file("doc12.txt");
        cyan();
        printf("13.Dr.Saleem Sheikh\n");
        reset();
        print_text_file("doc13.txt");
        cyan();
        printf("14.Dr.Naveed Baloch\n");
        reset();
        print_text_file("doc14.txt");
        cyan();
        printf("15.Dr.Irfan Ahmad\n");
        reset();
        print_text_file("doc15.txt");
        cyan();
        printf("16.Dr.Nadeem Akhtar\n");
        reset();
        print_text_file("doc16.txt");
        cyan();
        printf("17.Dr.Muhammad Abbas\n");
        reset();
        print_text_file("doc17.txt");
        cyan();
        printf("18.Dr.Muhammad Kalim\n");
        reset();
        print_text_file("doc18.txt");
        cyan();
        printf("19.Dr.Mehmood Shah\n");
        reset();
        print_text_file("doc19.txt");
        cyan();
        printf("20.Dr.Omer Afzal\n");
        reset();
        print_text_file("doc20.txt");
        system("pause");
        manegment_log();
    }
    if(x==2)                                                                        //removing files of every doctors
    {   remove("doc1.txt");
        remove("doc2.txt");
        remove("doc3.txt");
        remove("doc4.txt");
        remove("doc5.txt");
        remove("doc6.txt");
        remove("doc7.txt");
        remove("doc8.txt");
        remove("doc9.txt");
        remove("doc10.txt");
        remove("doc11.txt");
        remove("doc12.txt");
        remove("doc13.txt");
        remove("doc14.txt");
        remove("doc15.txt");
        remove("doc16.txt");
        remove("doc17.txt");
        remove("doc18.txt");
        remove("doc19.txt");
        remove("doc20.txt");
        system("pause");
        manegment_log();
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
// END OF PROGRAM ----------------------------------------------------------------------------------------------------------------------------------