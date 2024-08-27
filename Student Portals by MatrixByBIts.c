#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MatrixByBits 100

void AddStudent();
void StudentDetails();
void StudentSearch();
void DeleteStudentData();
//git 
struct Student {


    char student_first_name[50];
    char student_last_name[50];
    int student_roll_no ;
    char student_address[50];
    char course [50];
    float course_grade;


}data;



int main()
{
    printf("\t\t\t\t\tNorth South University\n");
    printf("\t\t\t\t\t    Student Portal\n");

    int i=1 ;

    char Given_name [50];
    char Given_password [50];
    char admin_name [50] = "Admin";
    char admin_password [50] = "12345";

    printf("ID : ");
    scanf("%s",&Given_name);
    printf("Password : ");
    scanf("%s",&Given_password);
    printf("\n");
    printf("\n");

    if(strcmp (admin_name,Given_name)==0 && strcmp (admin_password, Given_password)==0)
    {
        printf("Login Successful");
        printf("\n");
        getch();
        system ("cls");

        int option ;
        while (option !=5)
        {
            printf("\t\t\t\t\tNorth South University\n");
            printf("\t\t\t\t\t    Student Portal\n");
            printf("1.Student Details.\n");
            printf("2.Add Students.\n");
            printf("3.Student Search.\n");
            printf("4.Delete Student Data.\n");
            printf("5.Exit The Menu.\n");
            printf("\n\n");
            printf("Enter your chosen option : ");
            scanf("%d", &option);


            switch (option)
            {
            case 1 :
                system ("cls");
                StudentDetails();
                printf("\n");
                printf("Press any key to go back\n");
                getch();
                system ("cls");
                break;
            case 2:
                system ("cls");
                AddStudent();
                system ("cls");
                break ;
            case 3:
                system ("cls");
                StudentSearch();
                printf("\n");
                printf("Press any key to go back\n");
                getch();
                system ("cls");
                break;
            case 4:
                system ("cls");
                DeleteStudentData();
                printf("\n");
                printf("Press any key to go back\n");
                getch();
                system ("cls");
                break;
            case 5:
                system ("cls");
                printf("\t\t\t\t\tThank you for using our program :)\n");
                exit(0);
                break;
            default :
                system ("cls");
                getch();
                printf("\n\t\t\t\t\tEnter a valid number.");
                getch();
                system ("cls");
                break;
            }
        }
            getch();

        }

    else
    {
        printf("Forgot your password, I see :)\n");
        printf("Try Again.");
    }



}

void StudentDetails()
{
    FILE *fp;
//    struct student data ;
    fp=fopen("StudentData.txt", "r");


    printf("          Student Details             \n");
    printf("======================================\n\n\n");
    if(fp==NULL)
    {
        printf("There is no file in such name\n");
        exit(0);
    }
    else
    {
        while (fread(&data, sizeof(struct Student), 1 , fp))
        {
            printf("\n\n");
            printf("Student Name    : %s %s", data.student_first_name , data.student_last_name);
            printf("\n");
            printf("Student Address : %s",  data.student_address);
            printf("\n");
            printf("Student Roll no : %d", data.student_roll_no);
            printf("\n");
            printf("Course          : %s", data.course);
            printf("\n");
            printf("Course Grade    : %f", data.course_grade);
            printf("\n");

        }
        fclose(fp);
        getch();

    }
}

void AddStudent()
{
    FILE *fp;
    char wish ;
    int n , i ;

    do{
        system ("cls");

        printf("          Add A New Student In Your Database.          \n");
        printf("=======================================================\n");

        fp= fopen ("StudentData.txt", "a");
        printf("Enter the first name :");
        scanf("%s", &data.student_first_name);
        printf("\n");
        printf("Enter the last name : ");
        scanf("%s", &data.student_last_name);
        printf("\n");
        printf("Enter Student's Roll : ");
        scanf("%d", &data.student_roll_no);
        printf("Enter Student's Address : ");
        scanf("%s", &data.student_address);
        printf("\n");
        printf("Enter Course : ");
        scanf("%s", &data.course);
        printf("\n");
        printf("Enter Student's Course Grade : ");
        scanf("%f", &data.course_grade);
        printf("\n");

    if(fp==NULL)
    {
        printf("There is no file in such name.\n\n\n");
    }
    else
    {
        printf("Record is stored successfully in the file.\n\n\n");
    }

    fwrite(&data , sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("Would you like to add another student data?");
    printf("Type Y for Yes or N for NO : ");
    scanf("%s", &wish);

    }while (wish == 'y' || wish=='Y');
}


void StudentSearch()
{
    FILE *fp;
    int s_roll ;
    int flag=0;

    fp=fopen("StudentData.txt", "r");
    printf("          Search Student Data          \n");
    printf("=======================================\n");

    printf("Enter the roll of the student you want to see data : ");
    scanf("%d", &s_roll);

    while(fread(&data, sizeof(struct Student), 1, fp)>0)
    {
        if(data.student_roll_no == s_roll)
        {
            flag=1 ;

         printf("\n\n");
            printf("Student Name    : %s %s", data.student_first_name , data.student_last_name);
            printf("\n");
            printf("Student Address : %s",  data.student_address);
            printf("\n");
            printf("Student Roll no : %d", data.student_roll_no);
            printf("\n");
            printf("Course          : %s", data.course);
            printf("\n");
            printf("Course Grade    : %f", data.course_grade);
            printf("\n");
        }

    }

    if(flag==0)
    {
        printf("Student Data is not found\n");
    }
    fclose(fp);
    getch;
}

void DeleteStudentData()
{
    FILE *fp , *fp_1 ;

    int givenroll , flag=0 ;


    printf("          Delete Student Details          ");
    printf("==========================================\n");

    fp=fopen("StudentData.txt", "r");
    fp_1=fopen("temporary.txt", "w");
    printf("Enter the roll no : ");
    scanf("%d", &givenroll);
    if(fp==NULL)
    {
        printf("There is no file in such name.\n\n\n");
        exit(0);
    }
    while (fread(&data, sizeof(struct Student), 1 , fp))
    {
        if(data.student_roll_no == givenroll)
            flag=1;
        else
            fwrite(&data , sizeof(struct Student), 1, fp_1);
    }
    fclose (fp);
    fclose (fp_1);

    if(flag==0)
    {
        printf("There is no file about this student.");
    }
    else if(flag==1)
    {
        remove("StudentData.txt");
        rename ("temporary.txt", "StudentData.txt");

        printf("Student Data deleted successfully");

    }


    getch();
}




