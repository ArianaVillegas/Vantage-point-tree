#include "vptree.h"

using namespace std;

int main(){

	metrics dimensions[100];
	string type,file_source;
	vector<record> data;

    fstream file("data.txt");
    while(file>>file_source){
        file>>type;
        for(int i=0;i<100;i++){
            file>>dimensions[i];
        }
        record temp (dimensions,type,file_source);
        data.push_back(temp); 
    }

    vptree tree(data, &f);

    // TEST ------------------------------------------------------

    fstream test("input.txt");
	int rep = 0;
	int num = 0;
	double t = 0;
    while(test>>file_source){
    	test>>type;
    	for(int i=0;i<100;i++){
            test>>dimensions[i];
        }
        record temp (dimensions,type,file_source);
        clock_t start = clock();
        auto ans = tree.knnsearch(temp, 1);
        clock_t end = clock();
        t += double(end-start)/CLOCKS_PER_SEC;
        for(auto it:ans){
        	if(type == it.type) rep++;
        }
        num++;
    }
    cout << "Predicción correcta: " << rep*1.0/num*100 << '\n';
    cout << "Predicción incorrecta: " << (1-rep*1.0/num)*100 << '\n';
    cout << "Tiempo promedio (s): " << t/num << '\n';


	return 0;
}

