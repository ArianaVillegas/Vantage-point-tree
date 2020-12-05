#include <bits/stdc++.h>

#define metrics long double 

using namespace std;

struct record{ 
	metrics dimensions[100];
	string type;
	string file_source;
	record(metrics data[100],string type_,string file_source_){
		for(int i=0;i<100;i++){
			dimensions[i]=data[i];
		}
		type=type_;
		file_source=file_source_;
	}
};

metrics f(record r1,record r2){
	metrics return_value =0;
	for(int i=0;i<100;i++){
		return_value+=pow(r2.dimensions[i]-r1.dimensions[i],2);
	}
	return sqrt(return_value);
}