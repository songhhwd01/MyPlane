// MyPlane.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int ipCount=0;				//定义航班个数
int perCount=0;				//定义当前订票人数

//定义飞机航班的结构体
typedef struct plane{
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
	plane *next;

}*Planes,PL;

//定义乘客的结构体
typedef struct passenger{
	char name[30];			//乘客姓名		
	char pid[30];			//证件号
	int count;				//订票数量		
	char id[30];		    //航班号
	char ddid[30];			//订单编号
	struct plane pl;		//所乘飞机
	passenger *next;

}*Passg,PAG;
Passg FirPa;		//定义乘客链表
Planes FirPl;		//定义飞机航班链表
//函数声明
void outPut();										//		输出目录函数
void myOutputPl();									//		航班输出函数
Planes myInputPl();								    //		航班输入函数
void searchPl();
void searchPlbyId();
void searchPlbySta(char mystart[],char myend[]);
Passg bookTickets(Passg MyPa);								//		订票函数
void outPutTickets();

Passg MyPa;
//主函数
int main(){
	 MyPa=new PAG();

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
				FirPl=myInputPl();
					break; 
				case 2:								//输出航班信息
					myOutputPl();
					break;
				case 3:
					searchPl();						//查询航班信息
					break;
				
				case 6:								//定义订票函数
					
				MyPa=bookTickets( MyPa);
				break;
				case 7:
				  outPutTickets();					//显示订票信息
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
Planes myInputPl(){
	Planes P1,P2,header;
	cout<<"请输入录入航班个数："<<endl;
	cin>>ipCount;
	 int i=0;
	 P2=new plane(); 
	 header=NULL;  
	
	while(i<ipCount){    
		if (i==0){				//当第一次进来时
			 P1=new plane(); 
			 header=P1;
		}
	cout<<endl<<"请输入第"<<i+1<<"个航班信息！！！！！！！！！！！"<<endl;
	cout<<"请输入航班号: "<<endl;
	cin>>P1->id;     //读取航班号
	cout<<"请输入起始站: "<<endl;
	cin>>P1->sStation;//读取起始站
	cout<<"请输入终点站: "<<endl;
	cin>>P1->eStation;//读取终点站
	cout<<"请输入起飞时间: "<<endl;
	cin>>P1->sTime;//读取时间
	cout<<"请输入降落时间: "<<endl;
	cin>>P1->eTime;//读取时间
	cout<<"请输入总乘客人数: "<<endl;
	cin>>P1->counts;//读取机票数
	P1->kong=P1->counts;
	cout<<"请输入票价: "<<endl;
	cin>>P1->ticket;//读取票价
	cout<<"请输入折扣: "<<endl;
	cin>>P1->discount;//读取折扣
	cout<<endl;
	 P2=P1;  
    P1=new plane();  
     P2->next=P1;  
	i++;
	}
	return header;
}
//	订票函数
Passg bookTickets(Passg MyPa){
	Passg endP=MyPa;
	if (endP->next!=NULL){
		endP=endP->next;			//订票指针指向最后
	}

	Passg Pg=NULL;                   //声明一个内部乘客节点
	Planes Pl1=FirPl;                // 声明一个航班节点，用以查找航班
	char pid[30];					 //查询航班号
	bool fin=false;					 //定义初始化未找到航班
	cout<<"欢迎进入航班订票系统"<<endl<<"请输入航班号："<<endl;
	cin>>pid;						 //输入订票的航班号
	for (int i=0;i<ipCount;i++){	
		if (strcmp(Pl1->id,pid)==0){
			fin=true;				  //已找到航班
			//设置航班编号
			Pg=new PAG();
			strcpy(Pg->id,pid);	
					
			strcmp((char*)Pg->pl.sStation,Pl1->sStation);//设置起飞降落地点
			//cout<<" 测试："<<Pg->pl.sStation<<"  ：：："<<Pl1->sStation<<endl;
			strcmp(Pg->pl.eStation,Pl1->eStation);
			strcpy(Pg->ddid,strcat(pid,"--"));	//设置订单编号
			cout<<"请输入姓名："<<endl;
			cin>>Pg->name;						//输入姓名
			cout<<"请输入证件号："<<endl;		//输入证件号
			cin>>Pg->pid;
			cout<<"请输入订票数量："<<endl;		//输入订票数量
			cin>>Pg->count;
			Pl1->kong-=Pg->count;			    //空票数减少
			perCount++;   //订单数量增加
			break;
		}
		if (Pl1->next!=NULL)
		Pl1=Pl1->next;
		else break;
	}
	//Pg->next=NULL;
	endP->next=Pg;

	if (fin==false){
		cout<<"对不起你查找的航班未找到！！"<<endl;
	}
return MyPa;
}								




//定义航班输出函数
void myOutputPl(){
	Planes P1=FirPl;
	cout<<endl;
	cout<<"航班编号 "<<" 起飞站 "<<"  终点站 "<<" 起飞时间 "<<"  降落时间  "
		<<"  票价  "<<"  折扣 "<<" 空座数 "<<endl;
	int count=0;
	while (count<ipCount){
		cout<<P1->id<<"      "<<P1->sStation<<"    "<<P1->eStation<<"      "<<P1->sTime<<"      "
			<<P1->eTime<<"     "<<P1->ticket<<"       "<<P1->discount<<"       "<<P1->kong<<endl;
	P1=P1->next;
	count++;
	}

}
//定义查询航班信息
void searchPl(){
	int sel;
	cout<<"请选择查找方法："<<endl;
	cout<<"///////////////////////////////////////"<<endl;
	cout<<"1. 通过航班号查询。"<<endl<<
		  "2. 通过起降站查找"<<endl;
	cout<<"///////////////////////////////////////"<<endl;	
	cin >>sel;	
			switch(sel){
				case 1:				
					searchPlbyId();
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
//定义通过起降站查询函数
void searchPlbySta(char mystart[],char myend[]){
	Planes P1=FirPl;
	bool fin=false;
	int count=0;
	
	while (count<ipCount){
		if(strcmp(P1->sStation,mystart)==0&&strcmp(P1->eStation,myend)==0){
			fin=true;
		cout<<endl;
	    cout<<"航班编号   "<<"起飞站   "<<"  终点站 "<<" 起飞时间  "<<"  降落时间  "
		<<"  票价  "<<"  折扣  "<<" 空座数 "<<endl;

		cout<<P1->id<<"      "<<P1->sStation<<"    "<<P1->eStation<<"      "<<P1->sTime<<"      "
			<<P1->eTime<<"     "<<P1->ticket<<"       "<<P1->discount<<"       "<<P1->kong<<endl;
		break;
		}
		P1=P1->next;
	   count++;
	}
	if (fin==false){
	cout<<"对不起未找到你查找的航班。"<<endl;
	}

}
void searchPlbyId(){
	Planes P1=FirPl;
	bool fin=false;
	int count=0;
	char search[30];
	cout<<"请输入查询航班号："<<endl;
	cin>>search;
	while (count<ipCount){
		if(strcmp(P1->id,search)==0){
			fin=true;
		cout<<endl;
	    cout<<"航班编号   "<<"起飞站   "<<"  终点站 "<<" 起飞时间  "<<"  降落时间  "
		<<"  票价  "<<"  折扣  "<<" 空座数 "<<endl;

		cout<<P1->id<<"      "<<P1->sStation<<"    "<<P1->eStation<<"      "<<P1->sTime<<"      "
			<<P1->eTime<<"     "<<P1->ticket<<"       "<<P1->discount<<"       "<<P1->kong<<endl;
		break;
		}
		P1=P1->next;
	   count++;
	}
	if (fin==false){
	cout<<"对不起未找到你查找的航班。"<<endl;
	}

}
void outPutTickets(){
	Passg Pg=MyPa;
	cout<<"订单号 "<<"  航班号 "<<" 姓名  "<<"     证件号"<<
		"  订票数量"<<" 起飞站   "<<"  终点站 "<<endl;
	do{
		Pg=Pg->next;
		if (Pg!=NULL)
			cout<<Pg->ddid<<"  "<<Pg->id<<"  "<<Pg->name <<"   "<<Pg->pid<<"  "<<Pg->count<<Pg->pl.sStation<<"  "<<Pg->pl.eStation<<endl;
	}while(Pg->next!=NULL);
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

