#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int student_num = 0, teacher_num = 0;

class LMS {
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

    void save_data_to_file(string filename) {
        ofstream file("data2023.txt");
        if (file.is_open()) {
            file << student_num << endl;
            for (int i = 0; i < student_num; i++) {
                for (int j = 0; j < 5; j++) {
                    file << student_data[i][j] << ",";
                }
                file << endl;
            }
            file << teacher_num << endl;
            for (int i = 0; i < teacher_num; i++) {
                for (int j = 0; j < 3; j++) {
                    file << teacher_data[i][j] << ",";
                }
                file << endl;
            }
            file.close();
            cout << "Data saved successfully to " << filename << endl;
        }
        else {
            cout << "Unable to open file " << filename << endl;
        }
    }

    void load_data_from_file(string filename) {
        ifstream file("data2023.txt");
        if (file.is_open()) {
            file >> student_num;
            for (int i = 0; i < student_num; i++) {
                for (int j = 0; j < 5; j++) {
                    getline(file, student_data[i][j], ',');
                }
                file.ignore();
            }
            file >> teacher_num;
            for (int i = 0; i < teacher_num; i++) {
                for (int j = 0; j < 3; j++) {
                    getline(file, teacher_data[i][j], ',');
                }
                file.ignore();
            }
            file.close();
            cout << "Data loaded successfully from " << "data2023" << endl;
        }
        else {
            cout << "Unable to open file " << filename << endl;
        }
    }
    void save_teacher_data_to_file(string filename) {
    ofstream file("teacher_data.txt");
    if (file.is_open()) {
        file << teacher_num << endl;
        for (int i = 0; i < teacher_num; i++) {
            for (int j = 0; j < 3; j++) {
                file << teacher_data[i][j] << ",";
            }
            file << endl;
        }
        file.close();
        cout << "Teacher data saved successfully to " << filename << endl;
    }
    else {
        cout << "Unable to open file " << filename << endl;
    }
}
void load_teacher_data_from_file(string filename) {
    ifstream file("teacher_data.txt");
    if (file.is_open()) {
        file >> teacher_num;
        for (int i = 0; i < teacher_num; i++) {
            for (int j = 0; j < 3; j++) {
                getline(file, teacher_data[i][j], ',');
            }
            file.ignore();
        }
        file.close();
        cout << "Teacher data loaded successfully from " << filename << endl;
    }
    else {
        cout << "Unable to open file " << filename << endl;
    }
}

};

class admin :public LMS {
private:
    int choice,choice1,a1,x2,choice3,choice4,a4,x3,choice7;
		string data,reg,title;
		char choice9;
public:
    void admin_fun(LMS& lms1) {
    	do{
		
       x2=lms1.get_student_num();
		x3=lms1.get_teacher_num();
	cout<<"-----------------------------------------"<<endl;	
	cout<<"Press: "<<endl;
	cout<<"1-to Add, remove or update student detail"<<endl;
	cout<<"-----------------------------------------"<<endl;	
	cout<<"2-to Check record of all student"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"3-to Enroll/unenroll student from a course"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"4-to Add remove or update teacher detail"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"5-to Check record of all teachers"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"6-to Check courses alloted to all students"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"7-to Allocate course to a teacher"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"8-to Check courses alloted to all teacher"<<endl;
	cout<<"-----------------------------------------"<<endl<<endl;
	cout<<"-----------------------------------------"<<endl;
	cin>>choice;
	cout<<"-----------------------------------------"<<endl;
	system("CLS");
	if(choice==1)
	{   cout<<"----------------------------"<<endl;
	    cout<<"To:"<<endl;
	    cout<<"-----------------------------------------"<<endl<<endl;
		cout<<"Add detail of student(s) press 1"<<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<"Remove detail of student press 2"<<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<"Update detail of student(s) press 3"<<endl;
		cout<<"-----------------------------------------"<<endl<<endl;
		cout<<"-----------------------------------------"<<endl;
		cin>>choice1;
		cout<<"-----------------------------------------"<<endl<<endl;
		cout<<"----------------------------"<<endl;
		system("CLS");
		if(choice1==1)
		{
			cout<<"-----------------------------------------"<<endl;
			cout<<"How many students data you want to upload?"<<endl;
			cout<<"-----------------------------------------"<<endl<<endl;
			cout<<"-----------------------------------------"<<endl;
			cin>>a1;
			cout<<"-----------------------------------------"<<endl<<endl;
			for(int i=0;i<a1;i++)
			{
				cout<<"-----------------------------------------"<<endl;
				cout<<"Enter data for student# "<<i+1<<endl;
				cout<<"-----------------------------------------"<<endl<<endl;
				cout<<"-----------------------------------------"<<endl;
				cout<<"Enter Name: "<<endl;
				cout<<"-----------------------------------------"<<endl;
				cin>>data;
				cout<<"-----------------------------------------"<<endl;
				lms1.set_student_data(data,i,0);
				cout<<"Enter Regno: "<<endl;
				cout<<"-----------------------------------------"<<endl;
				cin>>data;
				cout<<"-----------------------------------------"<<endl;
				lms1.set_student_data(data,i,1);
				cout<<"-----------------------------------------"<<endl;
				cout<<"Enter Faculty: "<<endl;
				cout<<"-----------------------------------------"<<endl;
				cin>>data;
				cout<<"-----------------------------------------"<<endl;
				lms1.set_student_data(data,i,2);
				cout<<"-----------------------------------------"<<endl;
				cout<<"Enter contact: "<<endl;
				cout<<"-----------------------------------------"<<endl;
				cin>>data;
				cout<<"-----------------------------------------"<<endl<<endl;
				lms1.set_student_data(data,i,3);
				lms1.set_student_data(data,i,-1);
			}
		}
		if(choice1==2)
		{
			cout<<"-----------------------------------------"<<endl;
			cout<<"Enter regno of student to delete his data: "<<endl;
			cout<<"-----------------------------------------"<<endl;
			cin>>reg;
			for(int i=0;i<x2;i++)
			{
				if(lms1.get_student_data(i,1)==reg)
				{
					for(int j=0;j<4;j++)
					{
						cout<<"-----------------------------------------"<<endl;
						lms1.set_student_data1("Data of this student was deleted",i,j);
						cout<<"-----------------------------------------"<<endl<<endl;
					}
				}
			}
			cout<<"-----------------------------------------"<<endl;
			cout<<"Data Deleted Sucessfully"<<endl;
			cout<<"-----------------------------------------"<<endl<<endl;
		}
		if(choice1==3)
		{
			cout<<"-----------------------------------------"<<endl;
			cout<<"Enter regno to update data of a student: "<<endl;
			cout<<"-----------------------------------------"<<endl;
			cin>>reg;
			for(int i=0;i<x2;i++)
			{
				if(lms1.get_student_data(i,1)==reg)
				{
					cout<<"-----------------------------------------"<<endl;
					cout<<"Write correct detail"<<endl;
					cout<<"-----------------------------------------"<<endl<<endl;
					for(int j=0;j<3;j++)
					{
						cout<<lms1.get_student_data(i,j)<<endl;
						cout<<"-----------------------------------------"<<endl;
						cin>>data;
						cout<<"-----------------------------------------"<<endl<<endl;
						lms1.set_student_data1(data,i,j);
					}
				}
			}
		}
		
	}
	if(choice==2)
	{
		cout<<"-----------------------------------------"<<endl;
			cout<<"Details of all students are: "<<endl;
			cout<<"-----------------------------------------"<<endl<<endl;
			for(int i=0;i<x2;i++)
			{
				cout<<"-----------------------------------------"<<endl;
				cout<<"Details of all student# "<<i+1<<" are: "<<endl;
				cout<<"-----------------------------------------"<<endl<<endl;
				for(int j=0;j<5;j++)
				{
					cout<<lms1.get_student_data(i,j)<<endl;
				}
			}
	}
	if(choice==3)
	{   cout<<"-----------------------------------------"<<endl;
		cout<<"To enroll a student press 1"<<endl; 
		cout<<"-----------------------------------------"<<endl; 
		cout<<"To uneroll a student press 2"<<endl;
		cout<<"-----------------------------------------"<<endl<<endl;
		cout<<"-----------------------------------------"<<endl;
	    cin>>choice3;
	    cout<<"-----------------------------------------"<<endl<<endl;
		system("CLS");
		if(choice3==1)
		{
			cout<<"-----------------------------------------"<<endl;
			cout<<"Enter regno of student: "<<endl;
			cout<<"-----------------------------------------"<<endl<<endl;
			cout<<"-----------------------------------------"<<endl;
			cin>>reg;
			cout<<"-----------------------------------------"<<endl<<endl;
			for(int i=0;i<x2;i++)
			{
				if(reg==lms1.get_student_data(i,1))
				{
					for(int j=0;j<5;j++)
					{
						cout<<"-----------------------------------------"<<endl;
						cout<<"Enter course title"<<endl;
						cout<<"-----------------------------------------"<<endl<<endl;
						cout<<"-----------------------------------------"<<endl;
						cin>>title;
						cout<<"-----------------------------------------"<<endl;
						lms1.set_student_course(title,i,j);
					}
				}
			}
		}
		if(choice3==2)
		{
			cout<<"-----------------------------------------"<<endl;
			cout<<"Enter Regno of student: "<<endl;
			cout<<"-----------------------------------------"<<endl<<endl;
			cout<<"-----------------------------------------"<<endl;
			cin>>reg;
			cout<<"-----------------------------------------"<<endl<<endl;
			string course;
			cout<<"-----------------------------------------"<<endl;
			cout<<"Courses allocated to this student are: "<<endl;
			cout<<"-----------------------------------------"<<endl<<endl;
			for(int i=0;i<x2;i++)
			{
				if(reg==lms1.get_student_data(i,1))
				{
					for(int j=0;j<5;j++)
					{
						cout<<lms1.get_student_course(i,j)<<endl;
					}
					cout<<"---------------------------------------------------"<<endl;
					cout<<"Enter the  course name that you want to unenroll: "<<endl;
					cout<<"---------------------------------------------------"<<endl<<endl;
					cout<<"---------------------------------------------------"<<endl;
					cin>>course;
					cout<<"---------------------------------------------------"<<endl<<endl;
					for(int j=0;j<5;j++)
					{
						if(course==lms1.get_student_course(i,j))
						{
							cout<<"-------------------------------------------"<<endl;
							lms1.set_student_course("This course was  deleted",i,j);
							cout<<"-------------------------------------------"<<endl<<endl;
						}
					}
				}
			}
			
		}
	}
	if(choice==4)
	{
		cout<<"-------------------------------------------"<<endl;   
		cout<<"Press: ";
		cout<<"-------------------------------------------"<<endl;
		cout<<"1. To add detail of teacher(s)"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"2. To remove detail of teacher"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"3. To Update detail of teacher(s)"<<endl;
		cout<<"-------------------------------------------"<<endl<<endl;
		cout<<"-------------------------------------------"<<endl;
		cin>>choice4;
		cout<<"-------------------------------------------"<<endl<<endl;
	    system("CLS");
		if(choice4==1)
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"How many teacher(s) data do you want to upload?"<<endl;
			cout<<"-----------------------------------------------"<<endl<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cin>>a4;
			cout<<"-----------------------------------------------"<<endl<<endl;
			for(int i=0;i<a4;i++)
			{
				cout<<"-----------------------------------------------"<<endl;	
				cout<<"Enter the data for teacher: "<<i+1<<endl;
				cout<<"-----------------------------------------------"<<endl<<endl;
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Enter the name without space : "<<endl;
				cout<<"-----------------------------------------------"<<endl;
				cin>>data;
				cout<<"-----------------------------------------------"<<endl<<endl;
				lms1.set_teacher_data(data,i,0);
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Enter the Faculty: "<<endl;
				cout<<"-----------------------------------------------"<<endl;
				cin>>data;
				cout<<"-----------------------------------------------"<<endl<<endl;
				lms1.set_teacher_data(data,i,1);
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Enter contact: "<<endl;
				cout<<"-----------------------------------------------"<<endl;
				cin>>data;
				cout<<"-----------------------------------------------"<<endl<<endl;
				lms1.set_teacher_data(data,i,2);
				lms1.set_teacher_data(data,i,-1);
			}
		}
		if(choice4==2)
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Enter name of teacher to delete his data: "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cin>>reg;cout<<"-----------------------------------------------"<<endl<<endl;
			for(int i=0;i<x3;i++)
			{
				if(lms1.get_teacher_data(i,0)==reg)
				{
					for(int j=0;j<4;j++)
					{
						cout<<"-----------------------------------------------"<<endl;
						lms1.set_teacher_data1("Data of this student was been deleted",i,j);
						cout<<"-----------------------------------------------"<<endl<<endl;
					}
				}
			}
		}
		if(choice4==3)
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Enter name to updata data of a teacher: "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cin>>reg;
			cout<<"-----------------------------------------------"<<endl<<endl;
			for(int i=0;i<x3;i++)
			{
				if(reg==lms1.get_teacher_data(i,0))
				{
					cout<<"-----------------------------------------------"<<endl;
					cout<<"Write correct detail"<<endl;
					cout<<"-----------------------------------------------"<<endl;
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
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Details of all teachers are: "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			for(int i=0;i<x3;i++)
			{
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Details of teacher# "<<i+1<<" are:"<<endl;
				cout<<"-----------------------------------------------"<<endl;
				for(int j=0;j<3;j++)
				{
					cout<<lms1.get_teacher_data(i,j)<<endl;
				}
			}
	}
	if(choice ==6)
	{
		cout<<"-----------------------------------------------"<<endl;
		cout<<"Details of all courses are: "<<endl;
		cout<<"-----------------------------------------------"<<endl;
		for(int i=0;i<x2;i++)
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Courses of student# "<<i+1<<" are "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			for(int j=0;j<5;j++)
			{
				cout<<lms1.get_student_course(i,j)<<endl;
			}
		}
	}
	if(choice==7)
	{
		cout<<"-----------------------------------------------"<<endl;
		cout<<"To enroll a teacher press 1"<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"To uneroll a teacher press 2"<<endl;
		cout<<"-----------------------------------------------"<<endl<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cin>>choice7;
		cout<<"-----------------------------------------------"<<endl<<endl;
		system("CLS");
		if(choice7==1)
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Enter name of teacher: "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cin>>reg;
			cout<<"-----------------------------------------------"<<endl<<endl;
			for(int i=0;i<x3;i++)
			{
				if(reg==lms1.get_teacher_data(i,0))
				{
					for(int j=0;j<3;j++)
					{
						cout<<"-----------------------------------------------"<<endl;
						cout<<"Enter course title"<<endl;
						cout<<"-----------------------------------------------"<<endl;
						cin>>title;
						cout<<"-----------------------------------------------"<<endl<<endl;
						lms1.set_teacher_course(title,i,j);
					}
				}
			}
		}
		if(choice7==2)
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Enter name of teacher: "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cin>>reg;
			cout<<"-----------------------------------------------"<<endl<<endl;
			string course;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Courses allocated to this teacher are: "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			for(int i=0;i<x3;i++)
			{
				if(reg==lms1.get_teacher_data(i,0))
				{
					for(int j=0;j<3;j++)
					{
						cout<<lms1.get_teacher_course(i,j)<<endl;
					}
					cout<<"-----------------------------------------------"<<endl;
					cout<<"Enter course name you want to unenroll: "<<endl;
					cout<<"-----------------------------------------------"<<endl;
					cin>>course;
					cout<<"-----------------------------------------------"<<endl<<endl;
					for(int j=0;j<3;j++)
					{
						if(course==lms1.get_teacher_course(i,j))
						{
							cout<<"-----------------------------------------------"<<endl;
							lms1.set_teacher_course("This course was  removed",i,j);
							cout<<"-----------------------------------------------"<<endl;
						}
					}
				}
			}
			
		}
	}
	if(choice==8)
	{
		cout<<"-----------------------------------------------"<<endl;
		cout<<"Details of all courses are: "<<endl;
		cout<<"-----------------------------------------------"<<endl;
		for(int i=0;i<x3;i++)
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Courses of teacher# "<<i+1<<" are "<<endl;
			for(int j=0;j<3;j++)
			{
				cout<<lms1.get_teacher_course(i,j)<<endl;
			}
		}
	}
        lms1.save_data_to_file("data2023.txt");
        cout<<"-----------------------------------------------"<<endl;
                    cout << "Do you want exit the admin section (y/n)? ";
                    cout<<"-----------------------------------------------"<<endl;
            cin >> choice9;
            cout<<"-----------------------------------------------"<<endl<<endl;
        } while (choice9 != 'y' && choice9 != 'Y');
    }
   
};

class teacher :public LMS, public admin {
private:
    int choice, x2, x3;
    string name, d, regno;
    char choice9;
public:
    void teacher_fun(LMS& lms1) {
        // Load teacher data from file
        lms1.load_teacher_data_from_file("teacher_data.txt");
        do {
            x2 = lms1.get_teacher_num();
            x3 = lms1.get_student_num();
            cout<<"-----------------------------------------------"<<endl;
            cout << "Enter your name: " << endl;
            cout<<"-----------------------------------------------"<<endl;
            cin >> name;
            cout<<"-----------------------------------------------"<<endl<<endl;
            for (int q = 0; q < x2; q++) {
                if (lms1.get_teacher_data(q, 0) == name) {
                    cout << "-----------------------------------------" << endl;
                    cout << "Press: " << endl;
                    cout<<"-----------------------------------------------"<<endl;
                    cout << "1 to check personal detail" << endl;
                    cout<<"-----------------------------------------------"<<endl;
                    cout << "2 to check allocated courses" << endl;
                    cout<<"-----------------------------------------------"<<endl;
                    cout << "3 to view enrolled students in each course" << endl;
                    cout<<"-----------------------------------------------"<<endl;
                    cout << "4 assign marks to students" << endl;
                    cout<<"-----------------------------------------------"<<endl<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                    cin >> choice;
                    cout<<"-----------------------------------------------"<<endl<<endl;
                    system("CLS");
                    if (choice == 1) {
                        for (int i = 0; i < 3; i++) {
                            cout << lms1.get_teacher_data(q, i) << endl;
                        }
                    }
                    if (choice == 2) {
                        for (int i = 0; i < 3; i++) {
                            cout << lms1.get_teacher_course(q, i) << endl;
                        }
                    }
                    if (choice == 3) {
                        for (int i = 0; i < 3; i++) {
                            d = lms1.get_teacher_course(q, i);
                            for (int j = 0; j < 5; j++) {
                                for (int k = 0; k < 5; k++) {
                                    if (d == lms1.get_student_course(j, k)) {
                                        cout << lms1.get_student_data(j, 0) << "---" << lms1.get_student_data(j, 1) << "---" << lms1.get_student_course(j, k) << endl;
                                    }
                                }
                            }
                        }
                    }
                    if (choice == 4) {
                    	cout<<"-----------------------------------------------"<<endl;
                        cout << "Enter regno of student to save his marks: " << endl;
                        cout<<"-----------------------------------------------"<<endl;
                        cin >> regno;
                        cout<<"-----------------------------------------------"<<endl<<endl;
                        for (int i = 0; i < x3; i++) {
                            if (lms1.get_student_data(i, 1) == regno) {
                                string marks;
                                cout<<"-----------------------------------------------"<<endl;
                                cout << "Enter marks: " << endl;
                                cout<<"-----------------------------------------------"<<endl;
                                cin >> marks;
                                cout<<"-----------------------------------------------"<<endl<<endl;
                                lms1.set_student_data1(marks, i, 4);
                            }
                        }
                    }
                }
                choice = -1;
            }
            if (choice != -1) {
            	cout<<"-----------------------------------------------"<<endl;
                cout << "Incorect name!" << endl;
                cout<<"-----------------------------------------------"<<endl<<endl;
            }
            cout<<"-----------------------------------------------"<<endl;
            cout << "Do you want exit the teacher section (y/n)? " << endl;
            cout<<"-----------------------------------------------"<<endl;
            cin >> choice9;
            cout<<"-----------------------------------------------"<<endl<<endl;
        } while (choice9 != 'y' && choice9 != 'Y');

        // Save teacher data to file
        lms1.save_teacher_data_to_file("teacher_data2023.txt");
    }
};


class student :public teacher, public LMS, public admin {
private:
   int x2,choice,choice2;
	 char choice9;
	string name,regno,course;
public:
	void student_fun(LMS& lms1) {
   do {
	
	
       	x2=lms1.get_student_num();
       	cout<<"-----------------------------------------------"<<endl;
	cout<<"Enter your name: "<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cin>>name;
	cout<<"-----------------------------------------------"<<endl<<endl;
	cout<<"Enter your regno: "<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cin>>regno;
	cout<<"-----------------------------------------------"<<endl<<endl;
	for(int i=0;i<x2;i++)
	{
		if(name==lms1.get_student_data(i,0)&&regno==lms1.get_student_data(i,1))
		{
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Press: "<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"1 to Check personal details"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"2 to Enroll in available courses"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"3 to View obtained marks"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"4 to View list of teachers"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cin>>choice;
			cout<<"-----------------------------------------------"<<endl<<endl;
			system("CLS");
			if(choice==1)
			{
				for(int j=0;j<x2;j++)
				{
					cout<<lms1.get_student_data(i,j)<<endl;
				}
			}
			if(choice==2)
			{
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Press: "<<endl;
				cout<<"-----------------------------------------------"<<endl;
				cout<<"1 to enroll in courses"<<endl;
				cout<<"-----------------------------------------------"<<endl;
				cout<<"2 to replace a course"<<endl;
				cout<<"-----------------------------------------------"<<endl;
				cin>>choice2;
				cout<<"-----------------------------------------------"<<endl<<endl;
				if(choice2==1)
				{
					for(int j=0;j<5;j++)
					{
						cout<<"-----------------------------------------------"<<endl;
						cout<<"Enter course# "<<j+1<<endl;
						cout<<"-----------------------------------------------"<<endl;
						cin>>course;
						cout<<"-----------------------------------------------"<<endl<<endl;
						lms1.set_student_course(course,i,j);
					}
				}
				if(choice2==2)
				{
					cout<<"-----------------------------------------------"<<endl;
					cout<<"Your current courses are: "<<endl;
					cout<<"-----------------------------------------------"<<endl;
					for(int j=0;j<5;j++)
					{
						cout<<lms1.get_student_course(i,j)<<endl;
					}
					cout<<"-----------------------------------------------"<<endl;
					cout<<"Enter course you want to replace: "<<endl;
					cout<<"-----------------------------------------------"<<endl;
					cin>>course;
					cout<<"-----------------------------------------------"<<endl<<endl;
					for(int j=0;j<5;j++)
					{
						if(course==lms1.get_student_course(i,j))
						{
							cout<<"-----------------------------------------------"<<endl;
							cout<<"Enter new course title: "<<endl;
							cout<<"-----------------------------------------------"<<endl;
							cin>>course;
							cout<<"-----------------------------------------------"<<endl<<endl;
							lms1.set_student_course(course,i,j);
						}
					}
				}
			}
			if(choice==3)
			{
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Obtained Marks by "<<lms1.get_student_data(i,0)<<" are: "<<lms1.get_student_data(i,4)<<endl;
				cout<<"-----------------------------------------------"<<endl;
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
		cout<<"-----------------------------------------------"<<endl;
		cout<<"####Warning!Enter correct name and regno####"<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}
	
   cout<<"-----------------------------------------------"<<endl;
            cout << "Do you want exit the student section (y/n)? "<<endl;
            cout<<"-----------------------------------------------"<<endl;
            cin >> choice9;
            cout<<"-----------------------------------------------"<<endl<<endl;
        } while (choice9 != 'y' && choice9 != 'Y');}
};

int main() {
    LMS lms1;
    lms1.load_data_from_file("data2023.txt");

    char choice;
    do {
        int user;
        admin admin1;
        teacher teacher1;
        student student1;
        cout<<"-----------------------------------------------"<<endl;
        cout << "Who are you?" << endl;
        cout<<"-----------------------------------------------"<<endl;
        cout << "1 for admin" << endl;
        cout<<"-----------------------------------------------"<<endl;
        cout << "2 for teacher" << endl;
        cout<<"-----------------------------------------------"<<endl;
        cout << "3 for student" << endl;
        cout<<"-----------------------------------------------"<<endl<<endl;
        cout << "---Enter one---" << endl;
        cout<<"-----------------------------------------------"<<endl;
        cin >> user;
        cout<<"-----------------------------------------------"<<endl<<endl;
        system("CLS");
        if (user == 1) {
            admin1.admin_fun(lms1);
        }
        if (user == 2) {
            teacher1.teacher_fun(lms1);
        }
        if (user == 3) {
            student1.student_fun(lms1);
        }
        cout<<"-----------------------------------------------"<<endl;
        cout << "Do you want to continue(y/n)?" << endl;
        cout<<"-----------------------------------------------"<<endl;
        cin >> choice;
        cout<<"-----------------------------------------------"<<endl<<endl;
    } while (choice != 'n' && choice != 'N');

    lms1.save_data_to_file("data2023.txt");
    return 0;
}

