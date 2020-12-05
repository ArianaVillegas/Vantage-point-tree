#include "vptree2.h"
metrics dimensions[100];
string type,file_source;
vector<record> data;
using namespace std;

int main(){
    fstream file("data.txt");
    while(file>>file_source){
        file>>type;
        for(int i=0;i<100;i++){
            file>>dimensions[i];
        }
        record temp (dimensions,type,file_source);
        data.push_back(temp);
        
    }
    vptree tree(data);

	
}


