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
