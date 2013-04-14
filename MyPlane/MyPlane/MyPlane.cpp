// MyPlane.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;
#define PCOUT 100			//定义航班数量
#define PGCOUT 1000			//定义乘客数量
int ipCount;				//定义航班个数

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

}MyPlane[PCOUT];
//定义乘客的结构体
struct passenger{
	char name[30];			//乘客姓名		
	char pid[30];			//证件号
	int count;				//订票数量		
	char id;			    //航班情况
	char ddid[30];				//订单编号

}Passenger[PGCOUT];

//函数声明
void plInput();				//		定义录入航班情况
void plOutput();			//		定义输出航班情况
void outPut();				//		定义输出目录函数


//主函数
int main(){

	int in;
	outPut();
	cout<<"请选择："<<endl;
	cin >>in;
	while(in!=-1){
		switch(in){
			case 1:
				plInput();
				break; 
			case 2:
				plOutput();
				break;
		}
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
	cout<<"请输入票价: "<<endl;
	cin>>MyPlane[i].ticket;//读取机票数
	cout<<"请输入折扣: "<<endl;
	cin>>MyPlane[i].discount;//读取机票数
	}
}


//定义航班输出函数
void plOutput(){
	cout <<"请输入查询航班编号"<<endl;
	char inplid[30];
	cin>>inplid;
	cout<<endl;
	cout<<"航班编号   "<<"起飞站   "<<"  终点站 "<<" 起飞时间  "<<"  降落时间  "
		<<"  票价  "<<"  折扣  "<<" 是否满仓 "<<endl;
	for (int i=0;i<ipCount;i++){	
		if (!strcmp(MyPlane[i].id,inplid)){
			cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"   "
			<<MyPlane[i].sTime<<"     "<<MyPlane[i].eTime<<"     "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].isFull<<endl;
		}
	}
}

//定义输出函数
void outPut(){
cout<<"                       ★---您好，欢迎进入飞机航班管理系统！---★ "<<endl;
cout<<"================================================================================";
cout<<"     -------- ☆        1.输入航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        2.浏览航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        3.修改航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        4.查找航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        5.删除航班信息            ☆-------- "<<endl;
cout<<"     -------- ☆        6.订票信息                ☆-------- "<<endl;
cout<<"     -------- ☆        7.退票信息                ☆-------- "<<endl;
cout<<"     -------- ☆        0.退出                    ☆-------- "<<endl;
cout<<"================================================================================ "<<endl;
}


