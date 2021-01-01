#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define COURSE_NUM 20   //课程数上限
#define STU_NUM 50		 //学生人数上限
#define EPSILON 1e-7	    //精度要求

using namespace std;

typedef struct Course{
    char name[30];	//课名
    double credit;	//用于课程表时，表示学分；用于学生选修课时，表示成绩。
}COURSE;
typedef struct Student{
    int id;			//学号
    int crs_num;	//实际选课数
    COURSE courses[COURSE_NUM]; //选课与所获学分表
    double credits;	//所选课程的累计学分
    double sum;		//学分积之和
    double GPA;	//平均学分绩点
}STUDENT;

//读入课表数据，存入course数组。函数可用于读入公共课程表和
//每名学生的选课信息。
int readCourseTable(COURSE courses[]);

//读入所有学生的数据信息，存入stus数组；函数返回学生人数。
int readStudentData(STUDENT stus[]); 
//读入课表数据，存入course数组。函数可用于读入公共课程表和
//每名学生的选课信息
int readCourseTable(COURSE courses[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		getchar();
		scanf("%s %lf", courses[i].name, &courses[i].credit);

	}
	return n;
}

//读入所有学生的数据信息，存入stus数组；函数返回学生人数。
int readStudentData(STUDENT stus[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &stus[i].id);
		stus[i].crs_num = readCourseTable(stus[i].courses);
	}

	return n;
}


//计算stus数组中所有学生的GPA, 需要根据选修课程名查询相应的学分，
//可进一步写一个查询函数
void calculateGPA(COURSE courseTable[], int n, STUDENT stus[], int m);
//排序函数，排序方式满足输出要求
void sortStu(STUDENT stus[], int m);

void calculateGPA(COURSE courseTable[], int n, STUDENT stus[], int m)
{
	int i, j, k;

	for(i = 0; i < m; ++i) {
		stus[i].credits = stus[i].sum = 0;

		for(j = 0; j < stus[i].crs_num; ++j) {
			for(k = 0; k < n; ++k) {
				if(0 == strcmp(stus[i].courses[j].name, courseTable[k].name)) {
					stus[i].credits += courseTable[k].credit;
					stus[i].sum += courseTable[k].credit * stus[i].courses[j].credit;
				}
			}
		}

		stus[i].GPA = stus[i].sum / stus[i].credits;
	}
}

int stu_cmp(const void *a, const void *b)
{
	if(((STUDENT *)a)->GPA - ((STUDENT *)b)->GPA >= -EPSILON && ((STUDENT *)a)->GPA - ((STUDENT *)b)->GPA <= EPSILON)
		return ((STUDENT  *)b)->id - ((STUDENT *)a)->id;

	return (((STUDENT *)b)->GPA - ((STUDENT *)a)->GPA > EPSILON ? 1 : -1);
}

void sortStu(STUDENT stus[], int m)
{
	qsort(stus, m ,sizeof(STUDENT), stu_cmp);
}

int main()
{
	STUDENT stus[STU_NUM] = {{0}};			//学生
	COURSE CourseTable[COURSE_NUM] = {{{0}}}; //公共课表

    //1. 读入公共课表信息，得到课程
	int n = readCourseTable(CourseTable);

    //2. 读入所有学生选修课数据
    int m = readStudentData(stus);

    //3. 计算GPA
    calculateGPA(CourseTable, n, stus, m);

    //4. 排序
    sortStu(stus, m);
    //5. 输出
	for (int i = 0; i < m; i++)
	{
        printf("%d %.2f\n", stus[i].id, stus[i].GPA);
    }

    return 0;
}
