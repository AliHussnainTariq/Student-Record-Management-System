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
