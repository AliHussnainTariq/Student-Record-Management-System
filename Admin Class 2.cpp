if(choice==5)
	{
			cout<<"__________"<<endl;
			cout<<"|Details of all teachers are:| "<<endl;
			cout<<"__________"<<endl;
			for(int i=0;i<x3;i++)
			{
				cout<<"_________"<<endl;
				cout<<"|Details of teacher# "<<i+1<<" are:|"<<endl;
				cout<<"_________"<<endl;
				for(int j=0;j<3;j++)
				{
					cout<<lms1.get_teacher_data(i,j)<<endl;
				}
			}
	}
	if(choice ==6)
	{
		cout<<"___________"<<endl;
		cout<<"|Details of all courses are: |"<<endl;
		cout<<"___________"<<endl;
		for(int i=0;i<x2;i++)
		{
			cout<<"__________"<<endl;
			cout<<"|Courses of student# "<<i+1<<" are |"<<endl;
			cout<<"__________"<<endl;
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
		system("CLS");
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
