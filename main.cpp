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

    fstream test("input.txt");
    while(test>>file_source){
    	test>>type;
    	for(int i=0;i<100;i++){
            test>>dimensions[i];
        }
        record temp (dimensions,type,file_source);
        auto ans = tree.knnsearch(temp, 5);
        cout << "Tipo del query: " << type << '\n';
        cout << "Tipo de respuestas\n";
        for(auto it:ans){
        	cout << it.type << '\n';
        }
        cout << "\n\n\n";
    }


	return 0;
}

