#define  patientNumber 500
#include <ctime>
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/*created Patient class to store all patient info in string */
class Patient
{
public:
	char ID[20];
	char Name[30];
	char Medicine[30];
	char Test[30];
	char Age[10];
	char Sex[10];
	char PresentDate[20];
	char NextDate[20];
};

/* Patient Manager is the main Class of this Project.
 This class meantain searching, adding,
updateing,storing in file and viewing to our customer  */

class PatientManager:public Patient
{
private:
	Patient PatientNo[patientNumber];
	int count;
public:
	int totalPatient,NotFoundID,NotFoundName;
	char idMenu[20],NameMenu[20];
	char tempID[10],tempName[20];
	PatientManager();
	void Save();
	void UpdatePatient(char UpdateDate[20]);
	void Add(Patient P1)
	{
		PatientNo[count] = P1;
		totalPatient=count+1;
		count++;
		Save();
		patientDetails();
	}



	void ShowAllPatient()
	{
		printf("Total Patent %d\n",count);
		for(int i=0;i<count;i++)
		{
			cout<<"\n Patient ID  :"<<PatientNo[i].ID<<endl;
			cout<<"   Name        :"<<PatientNo[i].Name<<endl;
			cout<<"   Age         :"<<PatientNo[i].Age<<endl;
			cout<<"   Sex         :"<<PatientNo[i].Sex<<endl;
			cout<<"   Medicine    :"<<PatientNo[i].Medicine<<endl;
			cout<<"   Test        :"<<PatientNo[i].Test<<endl;
			cout<<"   Attend  Date:"<<PatientNo[i].PresentDate<<endl;
			cout<<"   Next  Date  :"<<PatientNo[i].NextDate<<"\n\n";
		}
	}
	void patientDetails();

	void ShowByID();
	void ShowByName();

};
 /*made patientDetails function to view patient info in a file.
  from there doctor can get a copy of his patients */

void PatientManager:: patientDetails()
{
		FILE *f;
		f = fopen("Patient Details.txt","w");

		fprintf(f,"**********************Total Patient %d *********************\n\n",count);

		for(int i=0;i<count;i++)
		{
			fprintf(f,"*********************** Patient no %d ************************\n\n",i+1);
			fprintf(f,"                 Patient ID  :%s\n",PatientNo[i].ID);
			fprintf(f,"                 Name        :%s\n",PatientNo[i].Name);
			fprintf(f,"                 Age         :%s\n",PatientNo[i].Age);
			fprintf(f,"                 Sex         :%s\n",PatientNo[i].Sex);
			fprintf(f,"                 Medicine    :%s\n",PatientNo[i].Medicine);
			fprintf(f,"                 Test        :%s\n",PatientNo[i].Test);
			fprintf(f,"                 Attend  Date:%s\n",PatientNo[i].PresentDate);
			fprintf(f,"                 Next  Date  :%s\n\n\n",PatientNo[i].NextDate);
		}
}


PatientManager::PatientManager()
{
	totalPatient = 0;
	FILE *p =fopen("Patient.txt","r");
	char ch,temp[20];
	int x=0,y=0;
	count = 0;

	if(p)
	{
		while(fscanf(p,"%c",&ch)!=EOF)
		{
			if(ch=='#'||ch=='\n')
			{
				temp[y]=0;

				switch(x)
				{
				case 0:
					strcpy(PatientNo[count].ID,temp);
					break;
				case 1:
					strcpy(PatientNo[count].Name,temp);
					break;
				case 2:
					strcpy(PatientNo[count].Medicine,temp);
					break;
				case 3:
					strcpy(PatientNo[count].Test,temp);
					break;
				case 4:
					strcpy(PatientNo[count].Age,temp);
					break;
				case 5:
					strcpy(PatientNo[count].Sex,temp);
					break;
				case 6:
					strcpy(PatientNo[count].PresentDate,temp);
					break;
				case 7:
					strcpy(PatientNo[count].NextDate,temp);
					break;
				}
				x++;
				y=0;
				if(ch=='\n')
				{
					x=0;
    				count++;
				}
			}
			else
			{
				temp[y]=ch;
				y++;
			}
		}

		totalPatient=count;
		fclose(p);
	}
	else
	{
		FILE *p1 =fopen("Patient.txt","w");
		fclose(p1);
	}
}

void PatientManager::Save()
{
	FILE *p =fopen("Patient.txt","w");

	for(int i=0;i<count;i++)
	{
		fprintf(p,"%s#%s#%s#%s#%s#%s#%s#%s\n",PatientNo[i].ID,PatientNo[i].Name,PatientNo[i].Medicine,PatientNo[i].Test,
			PatientNo[i].Age,PatientNo[i].Sex,PatientNo[i].PresentDate,PatientNo[i].NextDate);
	}
	fclose(p);
}



/*  UpdatePatient function use to update patient info*/

void PatientManager::UpdatePatient(char UpdateDate[20])
{
	char want[10];
wrongUpdate:
    NotFoundID=0;
	cout<<" Give Id:";
	gets(tempID);
	for(int i=0;i<count;i++)
	{
		if(strcmp(PatientNo[i].ID,tempID)==0)
		{
			strcpy(PatientNo[i].PresentDate,UpdateDate);

			cout<<"\nID            :"<<PatientNo[i].ID<<endl;
			cout<<"Name          :"<<PatientNo[i].Name<<endl;
			cout<<"Do you want to update your  age?\nType Yes or No:";
			gets(want);
			if(strcmp(want,"Yes")==0 || strcmp(want,"yes")==0 || strcmp(want,"Y")==0 || strcmp(want,"y")==0)
			{
				cout<<"Type   Age    :"; gets(PatientNo[i].Age);
			}
			else
				cout<<"Previous   Age:"<<PatientNo[i].Age<<endl;

			cout<<"Sex           :"<<PatientNo[i].Sex<<endl;
			cout<<"Do you want to update your Medicine?\nType Yes or No:";
			gets(want);

			if(strcmp(want,"Yes")==0 || strcmp(want,"yes")==0 || strcmp(want,"Y")==0 || strcmp(want,"y")==0)
			{
				cout<<"Type Medicine :"; gets(PatientNo[i].Medicine);
			}
			else
			{
				cout<<"Previous Medicine Continued:"<<PatientNo[i].Medicine<<endl;
			}

			cout<<"Do you want to update your Test?\nType Yes or No:";
			gets(want);

			if(strcmp(want,"Yes")==0 || strcmp(want,"yes")==0 || strcmp(want,"Y")==0 || strcmp(want,"y")==0)
			{
				cout<<"Type  Test    :"; gets(PatientNo[i].Test);
			}
			else
			{
				cout<<"Test        :"<<PatientNo[i].Test<<endl;
			}

			cout<<"Attend  Date  :"<<PatientNo[i].PresentDate<<endl;
			cout<<"Type Next Date:"; gets(PatientNo[i].NextDate);

			cout<<"Update Complete. Thanks "<<PatientNo[i].Name<<".\n\n";
			NotFoundID=1;
			break;
		}
	}
	if(NotFoundID==0)
	{
		cout<<"Do not found!!!!\n";
wrongIdMenu2:
		cout<<"Press 1 for go to main menu and 2 for search again\n";
		cout<<"Press your choice:";
		gets(idMenu);
		switch (idMenu[0])
		{
		case '1':
			break;
		case '2':
			goto wrongUpdate;
			break;
		default:
			cout<<"Wrong keyword.Try again :)\n";
			goto wrongIdMenu2;
		}
	}

	Save();
	patientDetails();

}

/*made ShowByName function function to search a patient by his name.
If one patient forget his/her id. He/She can found his/her id by searching his name.
If doctor want to findout a patient info he/she can also use it*/

void PatientManager::ShowByName()
{
	NotFoundName=0;
	cout<<"Give Name:";
	gets(tempName);
	for(int i=0;i<count;i++)
	{
		if(strcmp(PatientNo[i].Name,tempName)==0)
		{
			cout<<"\nID          :"<<PatientNo[i].ID<<endl;
			cout<<"Name        :"<<PatientNo[i].Name<<endl;
			cout<<"Age         :"<<PatientNo[i].Age<<endl;
			cout<<"Sex         :"<<PatientNo[i].Sex<<endl;
			cout<<"Medicine    :"<<PatientNo[i].Medicine<<endl;
			cout<<"Test        :"<<PatientNo[i].Test<<endl;
			cout<<"Attend  Date:"<<PatientNo[i].PresentDate<<endl;
			cout<<"Next  Date  :"<<PatientNo[i].NextDate<<"\n\n";
			NotFoundName=1;
		}
	}
	if(NotFoundName==0)
	{
		cout<<"Do not found!!!!\n";
wrongNameMenu:
		cout<<"Press 1 for go to main menu and 2 for search again\n";
		cout<<"Press your choice:";

		gets(NameMenu);
		switch (NameMenu[0])
		{
		case '1':
			break;
		case '2':
			ShowByName();
			break;
		default:
			cout<<"Wrong keyword.Try again :)\n";
			goto wrongNameMenu;
		}
	}
}

/*we make ShowByID function to search a patient by his ID.
If doctor want to findout a patient info he/she can use it for the searching*/

void PatientManager::ShowByID()
{
	NotFoundID=0;
	cout<<"Give Id:";
	gets(tempID);
	for(int i=0;i<count;i++)
	{
		if(strcmp(PatientNo[i].ID,tempID)==0)
		{
			cout<<"\nID          :"<<PatientNo[i].ID<<endl;
			cout<<"Name        :"<<PatientNo[i].Name<<endl;
			cout<<"Age         :"<<PatientNo[i].Age<<endl;
			cout<<"Sex         :"<<PatientNo[i].Sex<<endl;
			cout<<"Medicine    :"<<PatientNo[i].Medicine<<endl;
			cout<<"Test        :"<<PatientNo[i].Test<<endl;
			cout<<"Attend  Date:"<<PatientNo[i].PresentDate<<endl;
			cout<<"Next  Date  :"<<PatientNo[i].NextDate<<"\n\n";
			NotFoundID=1;
			break;
		}
	}
	if(NotFoundID==0)
	{
		cout<<"Do not found!!!!\n";
wrongIdMenu1:
		cout<<"Press 1 for go to main menu and 2 for search again\n";
		cout<<"Press your choice:";
		gets(idMenu);
		switch (idMenu[0])
		{
		case '1':
			break;
		case '2':
			ShowByID();
			break;
		default:
			cout<<"Wrong keyword.Try again :)\n";
			goto wrongIdMenu1;
		}
	}
}


int main()
{

	PatientManager PManager;

	PatientManager *pm=&PManager;


	time_t now = time(0);

	tm *ltm = localtime(&now);

	int year=1900 + ltm->tm_year ;

	char todayDate[10];

	_strdate(todayDate);

	int exit=0;
	char menu[20],search[20];




	while(1)
	{
		cout<<"._________. .___________. .___________. ._________. ._________.   \n";
		cout<<"|         | |           | |           | |         | |         |   \n";
		cout<<"| Press 1 | |  Press 2  | |  Press 3  | | Press 4 | | Press 5 |   \n";
		cout<<"|   for   | |    for    | |for showing| |  for    | |  for    |   \n";
		cout<<"|   Add   | | Searching | |  all info | | update  | |  exit   |   \n";
		cout<<"|_________| |___________| |___________| |_________| |_________|   \n\n";
		printf("%cPress your choice: ",2);
		gets(menu);
		switch(menu[0])
		{
		case '1':  // For adding
			Patient newpatient;
			sprintf(newpatient.ID,"%d-%d",year,PManager.totalPatient+1);
			cout<<"Your    id     is  :"<<newpatient.ID<<endl;
			cout<<"Type  your  Name   :";  gets(newpatient.Name);
			cout<<"Type  your   Age   :";  gets(newpatient.Age);
			cout<<"Type  your   Sex   :";  gets(newpatient.Sex);
			cout<<"Type your Medicine :";  gets(newpatient.Medicine);
			cout<<"Type  your   Test  :";  gets(newpatient.Test);
			sprintf(newpatient.PresentDate,"%s",todayDate);
			cout<<"Present date   is  :"<<newpatient.PresentDate<<endl;
			cout<<"Type your next Date:";  gets(newpatient.NextDate);
			cout<<"Your data has added. Thanks\n";
			PManager.Add(newpatient);
			break;

		case '2':  // For searching
			cout<<".___________. .___________.  \n";
			cout<<"|           | |           |  \n";
			cout<<"|  Press 1  | |  Press 2  |  \n";
			cout<<"|for search | |for search |  \n";
			cout<<"|  by  ID   | | by Name   |  \n";
			cout<<"|___________| |___________|  \n\n";
			printf("%cPress your choice: ",2);
			gets(search);
			if(search[0]=='1')
				pm->ShowByID();
			else if(search[0]=='2')
				pm->ShowByName();
			else
				cout<<"Wrong keyword.Try again :)\n\n";
			break;
		case '3':   // For showing all info
			PManager.ShowAllPatient();
			break;

		case '4':  // For updating patient info
			PManager.UpdatePatient(todayDate);
			PManager.Save();
			pm->patientDetails();
			break;

		case '5': // For shuting down
			exit = 1;
			break;
		default:
			cout<<"Wrong keyword.Try again :)\n\n";
		}
		if(exit==1)
		{
			cout<<" Byee.....:)\n";
			break;
		}

	}
	PManager.Save();
	pm->patientDetails();

return 0;
}
