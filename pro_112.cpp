#include<iostream>
#include<string>
using namespace std;
int student_num=0,teacher_num=0;
	class LMS
	{
		private:
			
			string student_data[100][5];
			string student_course[100][5];
			string teacher_data[100][3];
			string teacher_course[100][3];
    	public:
			
			void set_student_data(string n,int s,int t)
			{
				if(t==-1)
				{
					student_num++;
				}
				else
				{
					student_data[student_num][t]=n;
				}
			}
			void set_student_data1(string n,int s,int t)
			{
					student_data[s][t]=n;
			}
			void set_teacher_data(string n,int s,int t)
			{
				if(t==-1)
				{
					teacher_num++;
				}
				else
				{
					teacher_data[teacher_num][t]=n;
				}
			}
			void set_teacher_data1(string n,int s,int t)
			{
				teacher_data[s][t]=n;
			}
			void set_student_course(string n, int s, int t)
			{
				student_course[s][t]=n;
			}
			void set_teacher_course(string n, int s, int t)
			{
				teacher_course[s][t]=n;
			}
			string get_student_data(int s,int t)
			{
				return student_data[s][t];
			}
			string get_teacher_data(int s,int t)
			{
				return teacher_data[s][t];
			}
			string get_student_course( int s, int t)
			{
				return student_course[s][t];
			}
			string get_teacher_course( int s, int t)
			{
				return teacher_course[s][t];
			}
			int get_student_num()
			{
				return student_num;
			}
			int get_teacher_num()
			{
				return teacher_num;
			}
	};
class admin :public LMS
{
	private:
		int choice,choice1,a1,x2,choice3,choice4,a4,x3,choice7;
		string data,reg,title;
	public:
	void admin_fun(LMS &lms1)
	{
		x2=lms1.get_student_num();
		x3=lms1.get_teacher_num();
	cout<<"-----------------------------------------"<<endl;	
	cout<<"Press: "<<endl;
	cout<<"1-to Add, remove or update student detail"<<endl;
	cout<<"2-to Check record of all student"<<endl;
	cout<<"3-to Enroll/unenroll student from a course"<<endl;
	cout<<"4-to Add remove or update teacher detail"<<endl;
	cout<<"5-to Check record of all teachers"<<endl;
	cout<<"6-to Check courses alloted to all students"<<endl;
	cout<<"7-to Allocate course to a teacher"<<endl;
	cout<<"8-to Check courses alloted to all teacher"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cin>>choice;
	if(choice==1)
	{   cout<<"----------------------------"<<endl;
	    cout<<"To:"<<endl;
		cout<<"Add detail of student(s) press 1"<<endl;
		cout<<"Remove detail of student press 2"<<endl;
		cout<<"Update detail of student(s) press 3"<<endl;
		cin>>choice1;
		cout<<"----------------------------"<<endl;
		if(choice1==1)
		{
			cout<<"How many students data you want to upload?"<<endl;
			cin>>a1;
			for(int i=0;i<a1;i++)
			{
				cout<<"Enter data for student# "<<i+1<<endl;
				cout<<"Enter Name: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,0);
				cout<<"Enter Regno: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,1);
				cout<<"Enter Faculty: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,2);
				cout<<"Enter contact: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,3);
				lms1.set_student_data(data,i,-1);
			}
		}
		if(choice1==2)
		{
			cout<<"Enter regno of student to delete his data: "<<endl;
			cin>>reg;
			for(int i=0;i<x2;i++)
			{
				if(lms1.get_student_data(i,1)==reg)
				{
					for(int j=0;j<4;j++)
					{
						lms1.set_student_data1("Data of this student was deleted",i,j);
					}
				}
			}
			cout<<"Data Deleted Sucessfully"<<endl;
		}
		if(choice1==3)
		{
			cout<<"Enter regno to updata data of a student: "<<endl;
			cin>>reg;
			for(int i=0;i<x2;i++)
			{
				if(lms1.get_student_data(i,1)==reg)
				{
					cout<<"Write correct detail"<<endl;
					for(int j=0;j<3;j++)
					{
						cout<<lms1.get_student_data(i,j)<<endl;
						cin>>data;
						lms1.set_student_data1(data,i,j);
					}
				}
			}
		}
		
	}
	if(choice==2)
	{
			cout<<"_____________________________"<<endl;
			cout<<"|Details of all students are: |"<<endl;
			cout<<"_____________________________"<<endl;
			for(int i=0;i<x2;i++)
			{
				cout<<"______________________________"<<endl;
				cout<<"|Details of all student# "<<i+1<<" are:| "<<endl;
				cout<<"______________________________"<<endl;
				for(int j=0;j<5;j++)
				{
					cout<<lms1.get_student_data(i,j)<<endl;
				}
			}
	}
	if(choice==3)
	{   cout<<"----------------------------"<<endl;
		cout<<"To enroll a student press 1"<<endl;  
		cout<<"To uneroll a student press 2"<<endl;
	    cout<<"----------------------------"<<endl;
	
		cin>>choice3;
		if(choice3==1)
		{
			cout<<"Enter regno of student: "<<endl;
			cin>>reg;
			for(int i=0;i<x2;i++)
			{
				if(reg==lms1.get_student_data(i,1))
				{
					for(int j=0;j<5;j++)
					{
						cout<<"Enter course title"<<endl;
						cin>>title;
						lms1.set_student_course(title,i,j);
					}
				}
			}
		}
		if(choice3==2)
		{
			cout<<"Enter Regno of student: "<<endl;
			cin>>reg;
			string course;
			cout<<"Courses allocated to this student are: "<<endl;
			for(int i=0;i<x2;i++)
			{
				if(reg==lms1.get_student_data(i,1))
				{
					for(int j=0;j<5;j++)
					{
						cout<<lms1.get_student_course(i,j)<<endl;
					}
					cout<<"Enter the  course name that you want to unenroll: "<<endl;
					cin>>course;
					for(int j=0;j<5;j++)
					{
						if(course==lms1.get_student_course(i,j))
						{
							lms1.set_student_course("This course was  deleted",i,j);
						}
					}
				}
			}
			
		}
	}
	if(choice==4)
	{   cout<<"To: "<<endl;
		cout<<"Add detail of teacher(s) press 1"<<endl;
		cout<<"To Remove detail of teacher press 2"<<endl;
		cout<<"Update detail of teacher(s) press 3"<<endl;
		cin>>choice4;
		if(choice4==1)
		{
			cout<<"How many teacher(s) data do you want to upload?"<<endl;
			cin>>a4;
			for(int i=0;i<a4;i++)
			{
				cout<<"Enter the data for teacher: "<<i+1<<endl;
				cout<<"Enter the  Name: "<<endl;
				cin>>data;
				lms1.set_teacher_data(data,i,0);
				cout<<"Enter the Faculty: "<<endl;
				cin>>data;
				lms1.set_teacher_data(data,i,1);
				cout<<"Enter contact: "<<endl;
				cin>>data;
				lms1.set_teacher_data(data,i,2);
				lms1.set_teacher_data(data,i,-1);
			}
		}
		if(choice4==2)
		{
			cout<<"Enter name of teacher to delete his data: "<<endl;
			cin>>reg;
			for(int i=0;i<x3;i++)
			{
				if(lms1.get_teacher_data(i,0)==reg)
				{
					for(int j=0;j<4;j++)
					{
						lms1.set_teacher_data1("Data of this student was been deleted",i,j);
					}
				}
			}
		}
		if(choice4==3)
		{
			cout<<"Enter name to updata data of a teacher: "<<endl;
			cin>>reg;
			for(int i=0;i<x3;i++)
			{
				if(reg==lms1.get_teacher_data(i,0))
				{
					cout<<"Write correct detail"<<endl;
					for(int j=0;j<3;j++)
					{
						cout<<lms1.get_teacher_data(i,j)<<endl;
						cin>>data;
						lms1.set_teacher_data1(data,i,j);
					}
				}
			}
		}
	}
	if(choice==5)
	{
			cout<<"______________________________"<<endl;
			cout<<"|Details of all teachers are:| "<<endl;
			cout<<"______________________________"<<endl;
			for(int i=0;i<x3;i++)
			{
				cout<<"_________________________"<<endl;
				cout<<"|Details of teacher# "<<i+1<<" are:|"<<endl;
				cout<<"_________________________"<<endl;
				for(int j=0;j<3;j++)
				{
					cout<<lms1.get_teacher_data(i,j)<<endl;
				}
			}
	}
	if(choice ==6)
	{
		cout<<"_____________________________"<<endl;
		cout<<"|Details of all courses are: |"<<endl;
		cout<<"_____________________________"<<endl;
		for(int i=0;i<x2;i++)
		{
			cout<<"____________________________"<<endl;
			cout<<"|Courses of student# "<<i+1<<" are |"<<endl;
			cout<<"____________________________"<<endl;
			for(int j=0;j<5;j++)
			{
				cout<<lms1.get_student_course(i,j)<<endl;
			}
		}
	}
	if(choice==7)
	{   cout<<"----------------------------"<<endl;
		cout<<"To enroll a teacher press 1"<<endl;
		cout<<"To uneroll a teacher press 2"<<endl;
		cin>>choice7;
		cout<<"----------------------------"<<endl;
		if(choice7==1)
		{
			cout<<"Enter name of teacher: "<<endl;
			cin>>reg;
			for(int i=0;i<x3;i++)
			{
				if(reg==lms1.get_teacher_data(i,0))
				{
					for(int j=0;j<3;j++)
					{
						cout<<"Enter course title"<<endl;
						cin>>title;
						lms1.set_teacher_course(title,i,j);
					}
				}
			}
		}
		if(choice7==2)
		{
			cout<<"Enter name of teacher: "<<endl;
			cin>>reg;
			string course;
			cout<<"Courses allocated to this teacher are: "<<endl;
			for(int i=0;i<x3;i++)
			{
				if(reg==lms1.get_teacher_data(i,0))
				{
					for(int j=0;j<3;j++)
					{
						cout<<lms1.get_teacher_course(i,j)<<endl;
					}
					cout<<"Enter course name you want to unenroll: "<<endl;
					cin>>course;
					for(int j=0;j<3;j++)
					{
						if(course==lms1.get_teacher_course(i,j))
						{
							lms1.set_teacher_course("This course was  removed",i,j);
						}
					}
				}
			}
			
		}
	}
	if(choice==8)
	{
		cout<<"____________________________"<<endl;
		cout<<"|Details of all courses are: |"<<endl;
		cout<<"____________________________"<<endl;
		for(int i=0;i<x3;i++)
		{
			cout<<"____________________________"<<endl;
			cout<<"|Courses of teacher# "<<i+1<<" are|"<<endl;
			cout<<"____________________________"<<endl;
			for(int j=0;j<3;j++)
			{
				cout<<lms1.get_teacher_course(i,j)<<endl;
			}
		}
	}
	}
};
class teacher :public LMS,public admin
{
	private:
		int choice, x2,x3;
		string name,d,regno;
	public:
	void teacher_fun(LMS &lms1)
	{
	x2=lms1.get_teacher_num();
	x3=lms1.get_student_num();
	cout<<"Enter your name: "<<endl;
	cin>>name;
	for(int q=0;q<x2;q++)
	{
		if(lms1.get_teacher_data(q,0)==name)
		{   cout<<"-----------------------------------------"<<endl;
			cout<<"Press: "<<endl;
			cout<<"1 to check personal detail"<<endl;
			cout<<"2 to check allocated courses"<<endl;
			cout<<"3 to view enrolled students in each course"<<endl;
			cout<<"4 assign marks to students"<<endl;
			cin>>choice;
			cout<<"------------------------------------------"<<endl;
			if(choice==1)
			{
				for(int i=0;i<3;i++)
				{
					cout<<lms1.get_teacher_data(q,i)<<endl;
				}
			}
			if(choice==2)
			{
				for(int i=0;i<3;i++)
				{
					cout<<lms1.get_teacher_course(q,i)<<endl;
				}
			}
			if(choice==3)
			{
				for(int i=0;i<3;i++)
				{
					d=lms1.get_teacher_course(q,i);
					for(int j=0;j<5;j++)
					{
						for(int k=0;k<5;k++)
						{
							if(d==lms1.get_student_course(j,k))
							{
								cout<<lms1.get_student_data(j,0)<<"---"<<lms1.get_student_data(j,1)<<"---"<<lms1.get_student_course(j,k)<<endl;
							}
						}
					}
				}
			}
			if(choice==4)
			{
				cout<<"Enter regno of student to save his marks: "<<endl;
				cin>>regno;
				for(int i=0;i<x3;i++)
				{
					if(lms1.get_student_data(i,1)==regno)
					{
						string marks;
						cout<<"Enter marks: "<<endl;
						cin>>marks;
						lms1.set_student_data1(marks,i,4);
					}
				}
			}
		}
		choice=-1;
	}
	if(choice!=-1)
		{
			cout<<"Incorect name!"<<endl;
		}
	}
};
class student :public teacher,public LMS,public admin
{
	private:
		int x2,choice,choice2;
		string name,regno,course;
	public:
	void student_fun(LMS &lms1)
	{
	x2=lms1.get_student_num();
	cout<<"Enter your name: "<<endl;
	cin>>name;
	cout<<"Enter your regno: "<<endl;
	cin>>regno;
	for(int i=0;i<x2;i++)
	{
		if(name==lms1.get_student_data(i,0)&&regno==lms1.get_student_data(i,1))
		{   cout<<"-------------------------------"<<endl;
			cout<<"Press: "<<endl;
			cout<<"1 to Check personal details"<<endl;
			cout<<"2 to Enroll in available courses"<<endl;
			cout<<"3 to View obtained marks"<<endl;
			cout<<"4 to View list of teachers"<<endl;
			cin>>choice;
			cout<<"--------------------------------"<<endl;
			if(choice==1)
			{
				for(int j=0;j<x2;j++)
				{
					cout<<lms1.get_student_data(i,j)<<endl;
				}
			}
			if(choice==2)
			{
				cout<<"Press: "<<endl;
				cout<<"1 to enroll in courses"<<endl;
				cout<<"2 to replace a course"<<endl;
				cin>>choice2;
				if(choice2==1)
				{
					for(int j=0;j<5;j++)
					{
						cout<<"Enter course# "<<j+1<<endl;
						cin>>course;
						lms1.set_student_course(course,i,j);
					}
				}
				if(choice2==2)
				{
					cout<<"Your current corses are: "<<endl;
					for(int j=0;j<5;j++)
					{
						cout<<lms1.get_student_course(i,j)<<endl;
					}
					cout<<"Enter course you want to replace: "<<endl;
					cin>>course;
					for(int j=0;j<5;j++)
					{
						if(course==lms1.get_student_course(i,j))
						{
							cout<<"Enter new course title: "<<endl;
							cin>>course;
							lms1.set_student_course(course,i,j);
						}
					}
				}
			}
			if(choice==3)
			{
				cout<<"Obtained Marks by "<<lms1.get_student_data(i,0)<<" are: "<<lms1.get_student_data(i,4)<<endl;
			}
			if(choice==4)
			{
				for(int j=0;j<5;j++)
				{
					for(int k=0;k<3;k++)
					{
						for(int l=0;l<3;l++)
						{
							if(lms1.get_student_course(i,j)==lms1.get_teacher_course(k,l))
							{
								cout<<lms1.get_student_course(i,j)<<"---"<<lms1.get_teacher_data(k,0)<<endl;
							}
						}
					}
				}
			}
			x2=-1;
		}
	}
	if(x2!=-1)
	{
		cout<<"####Warning!Enter correct name and regno####"<<endl;
	}
	}
};
	
int main(){
	LMS lms1;
	char choice;
do
{
	int user;
	admin admin1;
	teacher teacher1;
	student student1;
	cout<<"Who are you?"<<endl; 
	cout<<"1 for admin"<<endl; 
	cout<<"2 for teacher"<<endl; 
	cout<<"3 for student"<<endl;
	cout<<"---Enter one---"<<endl;  
	cin>>user;
	if(user==1)
	{
		teacher1.admin_fun(lms1);
	}
	if(user==2)
	{
		student1.teacher_fun(lms1);
	}
	if(user==3)
	{
		student1.student_fun(lms1);
	}
	cout<<"Do you want to continue(y/n)?"<<endl;
	cin>>choice;
}while(choice!='n'&&choice!='N');

	return 0;
}
