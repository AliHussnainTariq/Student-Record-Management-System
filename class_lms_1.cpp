#include<iostream>
#include<string>
using namespace std;
int student_num=0,teacher_num=0;
	class lms
	{
		private:
			string student_data[10000][5];
			string student_course[10000][5];
			string teacher_data[10000][3];
			string teacher_course[10000][3];
		public:
			void set_student_data(string n,int x,int y)
			{
				if(y==-1)
				{
					student_num++;
				}
				else
				{
					student_data[student_num][y]=n;
				}
			}
			void set_student_data1(string n,int x,int y)
			{
					student_data[x][y]=n;
			}
			void set_teacher_data(string n,int x,int y)
			{
				if(y==-1)
				{
					teacher_num++;
				}
				else
				{
					teacher_data[teacher_num][y]=n;
				}
			}
			void set_teacher_data1(string n,int x,int y)
			{
					teacher_data[x][y]=n;
			}
			void set_student_course(string n, int x, int y)
			{
				student_course[x][y]=n;
			}
			void set_teacher_course(string n, int x, int y)
			{
				teacher_course[x][y]=n;
			}
			string get_student_data(int x,int y)
			{
				return student_data[x][y];
			}
			string get_teacher_data(int x,int y)
			{
				return teacher_data[x][y];
			}
			string get_student_course( int x, int y)
			{
				return student_course[x][y];
			}
			string get_teacher_course( int x, int y)
			{
				return teacher_course[x][y];
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
