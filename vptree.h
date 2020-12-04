#include <bits/stdc++.h>

using namespace std;

struct record {
	int posx;
};

struct node {
	int vp;
	vector<int> idx;
	node* children[2];
};


class vptree {

	node* root;
	vector<record> data;
	//double (*f)(record, record);

	double f(record r1, record r2){
		return double(abs(r1.posx-r2.posx));
	}

	node* create_vptree(vector<int> &idx){
		node* n = new node();
		n->idx = idx;
		if(idx.size() == 1){
			n->vp = 0;
			return n;
		}
		n->vp = idx[rand()%(idx.size())];
		idx.erase(idx.begin()+n->vp);
		vector<int> left, right;
		vector<double> dist(idx.size());
		double umbral = 0;
		for(int i=0; i<idx.size(); i++){
			dist[i] = f(data[idx[i]], data[n->vp]);
			umbral += dist[i];
		}
		umbral /= idx.size();
		for(int i=0; i<idx.size(); i++){
			if(dist[i] < umbral){
				left.push_back(idx[i]);
			} else {
				right.push_back(idx[i]);
			}
		}
		n->children[0] = create_vptree(left);
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
