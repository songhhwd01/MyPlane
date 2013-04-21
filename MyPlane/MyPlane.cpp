// MyPlane.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <sstream>  
#include<string>
#include <stdlib.h> 
#include<iostream>
//#include "afx.h"
using namespace std;
#define PCOUT 100			//定义航班数量
#define PGCOUT 1000			//定义乘客数量
int ipCount;				//定义航班个数
int perCount=0;				//定义当前订票人数




//定义飞机航班的结构体
struct plane{
	char id[30];			//	飞机航班号
	char sTime[30];			//  起飞时间
	char eTime[30];			//  降落时间
	char sStation[30];		//  起飞地点
	char eStation[30];		//	降落地点
	double ticket;			//  票价
	double discount;		//  折扣
	int counts;				//	可承载人数
	int kong;				//  空座数
	bool isFull;			//  是否满仓
	int tId[30];			//  订单号

}MyPlane[PCOUT],*Planes;
//定义乘客的结构体
struct passenger{
	char name[30];			//乘客姓名		
	char pid[30];			//证件号
	int count;				//订票数量		
	char id[30];		    //航班号
	char ddid[30];			//订单编号
	plane pl;

}Passenger[PGCOUT],*Passg;

//函数声明
void plInput();										//		定义录入航班情况
void plOutput();									//		定义输出航班情况
void outPut();										//		定义输出目录函数
void search();	
void searchPlbyId(char id[]);						//		通过航班号查找航班信息
void searchPlbySta(char start[],char end[]);		//		通过起始站查找航班信息
void resetPl(char pid[30]);							//		修改航班信息
void deletePl();									//删除航班信息
void bookTicket();									//		订票信息
void outputTicket();								//		输出订票信息
void returnTicket();								//退票信息
void resetTicket();									//修改信息

//主函数
int main(){
	int in;
	outPut();
	cout<<"请选择："<<endl;
	cin >>in;
		while(in!=-1){
			switch(in){
				case 0:								//退出函数
					exit(1);
					break;
				case 1:								//录入航班信息
					plInput();
					break; 
				case 2:								//输出航班信息
					plOutput();
					break;
				case 3:								//查找函数
					search();
					break;
				case 4:								//修改航班信息
					char pid[30];
					cout<<"请输入你要修改的航班号:"<<endl;
					cin>>pid;
					resetPl( pid);
					break;
				case 6:
					bookTicket();					//订票
					break;
				case 7:								//输出订票信息
					outputTicket();
					break;
				default:							//选择错误
					cout<<"输入错误请重新输入！！"<<endl;
					break;	
			}
		outPut();
		cout<<"请选择："<<endl;
		cin >>in;
		}

return 0;
}
//定义航班录入函数
void plInput(){
	cout<<"请输入录入航班个数："<<endl;
	cin>>ipCount;
	for(int i=0;i<ipCount;i++)
   {
	   cout<<endl<<"请输入第"<<i+1<<"个航班信息！！！！！！！！！！！"<<endl;
	cout<<"请输入航班号: "<<endl;
	cin>>MyPlane[i].id;     //读取航班号
	cout<<"请输入起始站: "<<endl;
	cin>>MyPlane[i].sStation;//读取起始站
	cout<<"请输入终点站: "<<endl;
	cin>>MyPlane[i].eStation;//读取终点站
	cout<<"请输入起飞时间: "<<endl;
	cin>>MyPlane[i].sTime;//读取时间
	cout<<"请输入降落时间: "<<endl;
	cin>>MyPlane[i].eTime;//读取时间
	cout<<"请输入总乘客人数: "<<endl;
	cin>>MyPlane[i].counts;//读取机票数
	MyPlane[i].kong=MyPlane[i].counts;
	cout<<"请输入票价: "<<endl;
	cin>>MyPlane[i].ticket;//读取机票数
	cout<<"请输入折扣: "<<endl;
	cin>>MyPlane[i].discount;//读取机票数
	cout<<endl;
	
	}
}

void outputTicket(){
	cout<<endl;
	cout<<"订单号 "<<"  航班号 "<<" 姓名  "<<"     证件号"<<"  订票数量"<<" 起飞站   "<<"  终点站 "
		<<endl;
	for (int i=0;i<perCount;i++){	
		cout<<Passenger[i].ddid<<"  "<<Passenger[i].id<<"   "<<Passenger[i].name<<"  "<<Passenger[i].pid<<"  "
			<<Passenger[i].count<<"   "<<Passenger[i].pl.sStation<<"  "<<Passenger[i].pl.eStation<<endl;

	}

}

//定义航班输出函数
void plOutput(){
	cout<<endl;
	cout<<"航班编号 "<<"起飞站   "<<"  终点站 "<<" 起飞时间  "<<"  降落时间  "
		<<"  票价  "<<"  折扣  "<<" 空座数 "<<endl;
	for (int i=0;i<ipCount;i++){	
		cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"     "
		<<MyPlane[i].sTime<<"       "<<MyPlane[i].eTime<<"       "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].kong<<endl;
	}
}
//查找韩版信息
void search(){
	int sel;
	cout<<"请选择查找方法："<<endl;
	cout<<"///////////////////////////////////////"<<endl;
	cout<<"1. 通过航班号查询。"<<endl<<
		"2. 通过起降站查找"<<endl;
	cout<<"///////////////////////////////////////"<<endl;	
	cin >>sel;	
			switch(sel){
				case 1:	
					char pid[30];
					cout<<"请输入航班号"<<endl;
					cin>>pid;				
					searchPlbyId(pid);
					break;
				case 2:		
					char mystart[30],myend[30];
					cout<<"请输入起飞地点"<<endl;
					cin>>mystart;
					cout<<"请输入降落地点"<<endl;
					cin>>myend;
					 searchPlbySta(mystart,myend);		//通过起始站查找航班信息
					break; 
					
				default:							//选择错误
					cout<<"输入错误请重新输入！！"<<endl;
					break;
				
			}
}


//定义通过航班号查找航班信息函数
void searchPlbyId(char id[]){
	cout<<endl;
	cout<<"航班编号   "<<"起飞站   "<<"  终点站 "<<" 起飞时间  "<<"  降落时间  "
		<<"  票价  "<<"  折扣  "<<" 空座数 "<<endl;
	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].id,id)==0){
			cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"   "
				<<MyPlane[i].sTime<<"     "<<MyPlane[i].eTime<<"     "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].kong<<endl;
		}
	}
}
//定义通过起始站查找航班信息
void searchPlbySta(char start[],char end[]){

	cout<<endl;
	cout<<"航班编号   "<<"起飞站   "<<"  终点站 "<<" 起飞时间  "<<"  降落时间  "
		<<"  票价  "<<"  折扣  "<<" 空座数 "<<endl;
	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].sStation,start)==0&&strcmp(MyPlane[i].eStation,end)==0){
			cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"   "
				<<MyPlane[i].sTime<<"     "<<MyPlane[i].eTime<<"     "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].kong<<endl;
		}
	}
}
//修改航班信息
void resetPl(char pid[30]){
	cout<<endl;
	
	bool fin=false;

	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].id,pid)==0){
			fin=true;
			cout<<"请输入起始站: "<<endl;
			cin>>MyPlane[i].sStation;//读取起始站
			cout<<"请输入终点站: "<<endl;
			cin>>MyPlane[i].eStation;//读取终点站
			cout<<"请输入起飞时间: "<<endl;
			cin>>MyPlane[i].sTime;//读取起飞时间
			cout<<"请输入降落时间: "<<endl;
			cin>>MyPlane[i].eTime;//读取降落时间
			cout<<"请输入总乘客人数: "<<endl;
			cin>>MyPlane[i].counts;//读取机票数
			MyPlane[i].kong=MyPlane[i].counts;
			cout<<"请输入票价: "<<endl;
			cin>>MyPlane[i].ticket;//读取票价
			cout<<"请输入折扣: "<<endl;
			cin>>MyPlane[i].discount;//读取折扣
			cout<<endl;

			cout<<"修改成功！！"<<endl;
			break;
		}
	}
	if (fin==false){
	cout<<"对不起，未找到！！"<<endl;
	}
}							


//定义输出函数
void outPut(){
cout<<"                       ★---您好，欢迎进入飞机航班管理系统！---★ "<<endl;
cout<<"================================================================================";
cout<<"     -------- ☆        1.输入航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        2.浏览航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        3.查找航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        4.修改航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        5.删除航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        6.订票                    ☆-------- "<<endl;
cout<<"     -------- ☆        7.输出订票信息            ☆-------- "<<endl;
cout<<"     -------- ☆        0.退出                    ☆-------- "<<endl;
cout<<"================================================================================ "<<endl;
}


//		订票信息
void bookTicket(){
	char pid[30];    //查询航班号
	bool fin=false;
	cout<<"欢迎进入航班订票系统"<<endl<<"请输入航班号："<<endl;
	cin>>pid;
	
	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].id,pid)==0){
			fin=true;			//已找到航班
			//Passenger[perCount++].id=pid;							//设置航班编号
			strcpy(Passenger[perCount].id,pid);
			//CString s;
			//char s[30];
			//s.Format("%d",perCount);

			//char last[]=perCount;
			strcpy(Passenger[perCount].ddid,strcat(pid,"--"));						//设置订单编号						
			Passenger[perCount].pl=MyPlane[i];
			cout<<"请输入姓名："<<endl;
			cin>>Passenger[perCount].name;						//输入姓名
			cout<<"请输入证件号："<<endl;							//输入证件号
			cin>>Passenger[perCount].pid;
			cout<<"请输入订票数量："<<endl;							//输入订票数量
			cin>>Passenger[perCount].count;
			MyPlane[i].kong-=Passenger[perCount].count;			//空票数减少
			perCount++;
			break;
		}
	}
	if (fin==false){
		cout<<"对不起你查找的航班未找到！！"<<endl;
	}
}							
