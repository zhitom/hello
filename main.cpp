
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <strstream>

using namespace std;

class SmSpCode;
void setObj(SmSpCode &obj,const char* spCode,const char* pCode,
                          const char* serviceCode,const char* feeRateIdUp,
                          const char* feeRateIdDn,const char* beginTime,
                          const char* endTime,const int dealFlag);


class SmSpCode
{
public:
		char serviceCode[10+1];
		char spCode[6+1];
		char pCode[3+1];
		char feeRateIdUp[4+1];
		char feeRateIdDn[4+1];
		char beginTime[14+1];
		char endTime[14+1];
		int dealFlag;
SmSpCode::SmSpCode()
{}
SmSpCode::~SmSpCode()
{}

SmSpCode::SmSpCode(const SmSpCode& right)
{
	*this=right;
}

void SmSpCode::operator=(const SmSpCode& right)
{
	setObj((*this),right.spCode,right.pCode,right.serviceCode,
	       right.feeRateIdUp,right.feeRateIdDn,right.beginTime,
               right.endTime,right.dealFlag);
}

friend int operator==(const SmSpCode &left,const SmSpCode& right)
{
        cout<<"operator == :"<<left.serviceCode<<" == "<<right.serviceCode<<" "
            /*<<left.beginTime<<" <= "<<right.beginTime<<" "
            <<left.endTime<<" >= "<<right.endTime*/<<endl;
        return (strcmp(left.serviceCode,right.serviceCode)==0/*&&
                strcmp(left.beginTime,right.beginTime)<=0&&
                strcmp(left.endTime,right.endTime)>=0*/);
}

friend int operator<(const SmSpCode &left,const SmSpCode& right)
{
/**
使用lower_bound时，对象的"<"比较运算，需要符合下面的规律：
1.若"=="运算符重载中进行的都是"<="运算，那么在"<"运算符重载中相应的字段应遵循
   "<"运算和 ">"相互间隔的比较运算。
2. "=="比较运算应单独进行
3.若"=="运算符重载中进行的是">"比较运算，那么在"<"运算符重载中相应的字段的
   比较运算应该在符合第1条的基础上再取反！
4.使用lower_bound只能支持(a,b]的半开半闭区间。 
*/
        cout<<"operator < :"<<left.serviceCode<<" < "<<right.serviceCode<<" "
            /*<<left.beginTime<<" > "<<right.beginTime<<" "
            <<left.endTime<<" > "<<right.endTime*/<<endl;
        if(strcmp(left.serviceCode,right.serviceCode)<0)
                return true;
        /*if(strcmp(left.serviceCode,right.serviceCode)==0)
        {
        	if(strcmp(left.beginTime,right.beginTime)>0)
	                return true;
	        if(strcmp(left.beginTime,right.beginTime)==0)
        	{
                        if(strcmp(left.endTime,right.endTime)>0)
	                       return true;
                }
                     
	} */       
        return false;
}

friend ostream& operator<<(ostream& os,const SmSpCode& po)
{
	os
        //<<po.spCode<<" , "
	//		<<po.pCode<<","
                        <<po.serviceCode<<","
	//		<<po.feeRateIdUp<<","
	//		<<po.feeRateIdDn<<","
			<<po.beginTime<<","
			<<po.endTime<<","
	//		<<po.dealFlag
        ;
	
	return os;
}

};

void setObj(SmSpCode &obj,const char* spCode,const char* pCode,
                          const char* serviceCode,const char* feeRateIdUp,
                          const char* feeRateIdDn,const char* beginTime,
                          const char* endTime,const int dealFlag)
{
strcpy(obj.spCode,spCode);obj.spCode[strlen(spCode)]='\0';
strcpy(obj.pCode,pCode);obj.pCode[strlen(pCode)]='\0';
strcpy(obj.serviceCode,serviceCode);obj.serviceCode[strlen(serviceCode)]='\0';
strcpy(obj.feeRateIdUp,feeRateIdUp);obj.feeRateIdUp[strlen(feeRateIdUp)]='\0';
strcpy(obj.feeRateIdDn,feeRateIdDn);obj.feeRateIdDn[strlen(feeRateIdDn)]='\0';
strcpy(obj.beginTime,beginTime);obj.beginTime[strlen(beginTime)]='\0';
strcpy(obj.endTime,endTime);obj.endTime[strlen(endTime)]='\0';
obj.dealFlag=dealFlag;
}

int main(int argc, char *argv[])
{
  SmSpCode obj;
  vector<SmSpCode> objVec;
  setObj(obj,"978022","871","164","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978022","871","1644","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978022","871","165","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978022","871","166","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978020","871","163","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","160","0100","0000",
             "20030101000000","20080101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","160","0100","0000",
             "20080101000000","20100101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","150","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","110","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","100","0100","0000",
             "20030101000000","20990101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","160","0100","0000",
             "20100101000000","20200101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","160","0100","0000",
             "20100101000000","30200101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","160","0100","0000",
             "20100101000000","10200101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","160","0100","0000",
             "20100101000000","90200101000000",0);
  objVec.push_back(obj);
  setObj(obj,"978070","871","160","0100","0000",
             "20100101000000","99200101000000",0);
  objVec.push_back(obj);
  
  ::partial_sort(objVec.begin(),objVec.end(),objVec.end());
  vector<SmSpCode>::iterator itr;
  cout<<"ObjVector{"<<endl;
  for(itr=objVec.begin();itr!=objVec.end();itr++)
  {
	cout<<(*itr)<<endl;
  }
  cout<<"}"<<endl;
  
  cout<<endl<<"starting find..."<<endl;
  setObj(obj,"","","160","","","20990101000000","20990101000000",0);
  itr=lower_bound(objVec.begin(),objVec.end(),obj);
  for(;itr!=objVec.end();itr++)
  {
	if(!(*itr==obj))break;
	cout<<(*itr)<<endl;
  }
  strstream strs;
  strs<<"abc"<<endl<<"obc"<<endl;
  cout<<strs.str();
  system("PAUSE");	
  return 0;
}



