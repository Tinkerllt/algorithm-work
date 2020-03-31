#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
const int maxn = 0x3f3f3f3f;
struct Point
{
	int x,y;
	friend ostream & operator << (ostream & out,const Point& p);
	Point(int _x=0,int _y=0):x(_x),y(_y){}
	bool operator < (const Point& rhs)const{
		return x < rhs.x;
	}
};
ostream & operator << (ostream & out,const Point& p){
	out<<"("<<setw(2)<<p.x<<","<<setw(2)<<p.y<<")";
	return out;
}
bool cmp(const Point&a,const Point&b) //��x��������
{
	return a.x<b.x;
}
bool cmp2(const Point&a,const Point&b) //��y��������
{
	return a.y<b.y;
}

double Dis(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double min(double a,double b,double c)
{
	return min(min(a,b),c));  
}

double ClosestPoint(vector<Point> points,int m,int n)  //����ҿ�
{
	if(n-m<2) return maxn;
	if(n-m==2)
	{
		return Dis(points[m],points[n-1]);
	}
	if(n-m==3)
	{
		double a = Dis(points[m],points[n-1]);
		double b = Dis(points[m],points[n-2]);
		double c = Dis(points[n-1],points[n-2]);
		return min(a,b,c);
	}
	int mid = (m+n)/2;
	int mm = points[mid].x;

	double d1 = ClosestPoint(points,m,mid); // ���������̾���
	double d2 = ClosestPoint(points,mid,n);  // �ұ�������̾���
	double minn = min(d1,d2);
	vector<Point> left,right;
	for(int i=m;i<mid;++i)
	{
		if(points[i].x>mm-minn)
			left.push_back(points[i]);
	}
	for(int i=mid;i<n;++i)
	{
		if(points[i].x<=mm+minn)
			right.push_back(points[i]);
	}
	sort(right.begin(),right.end(),cmp2); //��y��������
	double mindist = 100000;
	for(int i=0;i<(int)left.size();i++)   //����������е������ұ���̾���
	{
		for(int j=0;j<(int)right.size();j++)
		{
			if(abs(left[i].y-right[j].y)<minn)
			{
				double d = Dis(left[i],right[j]);
				if(d<min) mindist = d;
			}
		}
	}
	return min(minn,mindist);
}
int main()
{
	//freopen("out.txt","w",stdout);
	vector<Point> points;
	srand(time(NULL));
	int n = 15;
	for(int i=0;i<n;i++)
	{
		Point point;
		point.x = rand()%71;
		point.y = rand()%61;
	//	cin>>point.x>>point.y;
		points.push_back(point);
	}
	sort(points.begin(),points.end(),cmp);
	for(int i=0;i<n;i++)
	{
		//cout << points[i].x <<" "<< points[i].y <<endl;
		cout<<points[i]<<endl;
	}
	cout << "���η���õĴ�Ϊ��"<< ClosestPoint(points,0,points.size()) << endl ;
	return 0;
}
