#include <bits/stdc++.h>
#define metrics long double 
using namespace std;

/*struct record {
	int posx;
};
*/
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

struct node {
	int vp;
	vector<int> idx;
	node* children[2];
	
};


class vptree {

	node* root;
	vector<record> data;
	//metrics (*f)(record, record);

	/*metrics f(record r1, record r2){
		return metrics(abs(r1.posx-r2.posx));
	}*/

	metrics f(record r1,record r2){
		metrics return_value =0;
		for(int i=0;i<100;i++){
			return_value+=pow(r2.dimensions[i]-r1.dimensions[i],2);
		}
		return sqrt(return_value);
	}

	node* create_vptree(vector<int> &idx){
		//cout<<"hola "<<endl;
		node* n = new node();
		n->idx = idx;
		if(idx.size() == 1){
			//cout<<"hola2 "<<endl;
			n->vp = idx[0];
			return n;
		}
		//cout<<"hola6"<<endl;
		n->vp = idx[rand()%(idx.size())];
		//cout<<"hola 7"<<endl;
		idx.erase(idx.begin()+n->vp);
		vector<int> left, right;
		vector<metrics> dist(idx.size());
		metrics umbral = 0;
		//cout<<"hola3 "<<endl;
		for(int i=0; i<idx.size(); i++){
			dist[i] = f(data[idx[i]], data[n->vp]);
			umbral += dist[i];
		}
		//cout<<"hola 5"<<endl;
		umbral /= idx.size();
		for(int i=0; i<idx.size(); i++){
			if(dist[i] < umbral){
				left.push_back(idx[i]);
			} else {
				right.push_back(idx[i]);
			}
		}
		//cout<<"left size:"<<left.size()<<endl;
		//cout<<"right size:"<<right.size()<<endl;
		n->children[0] = create_vptree(left);
		//cout<<"hola4"<<endl;
		n->children[1] = create_vptree(right);
		return n;
	}

public:

	vptree(vector<record> data){
		this->data = data;

		vector<int> idx;
		for(int i=0; i<data.size(); i++)
			idx.push_back(i);

		this->root = create_vptree(idx);
	}

	~vptree(){};
	
};
