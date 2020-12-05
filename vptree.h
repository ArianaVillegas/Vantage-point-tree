#include "metricas.h"

struct node {
	int vp;
	metrics umbral;
	vector<int> idx;
	node* children[2];
};


class vptree {

	node* root;
	vector<record> data;
	metrics (*f)(record, record);

	node* create_vptree(vector<int> &idx){
		node* n = new node();
		n->idx = idx;
		if(idx.size() <= 1){
			n->vp = idx.size() ? idx[0] : 0;
			return n;
		}
		int item = rand()%(idx.size());
		n->vp = idx[item];
		idx.erase(idx.begin()+item);
		vector<int> left, right;
		vector<metrics> dist(idx.size());
		metrics umbral = 0;
		for(int i=0; i<idx.size(); i++){
			dist[i] = f(data[idx[i]], data[n->vp]);
			umbral += dist[i];
		}
		umbral /= idx.size();
		n->umbral = umbral;
		for(int i=0; i<idx.size(); i++){
			if(dist[i] <= umbral){
				left.push_back(idx[i]);
			} else {
				right.push_back(idx[i]);
			}
		}
		n->children[0] = create_vptree(left);
		n->children[1] = create_vptree(right);
		return n;
	}

	void knnsearch(node *node, record q, int k, metrics &umbral, 
		priority_queue<pair<metrics,int>> &ans){

		if(node == nullptr) return;

		metrics d = f(data[node->vp], q);

		if(d < umbral) {
			if(ans.size() == k) ans.pop();
			ans.push({d, node->vp});
			if(ans.size() == k) umbral = ans.top().first;
		}

		if(node->children[0] == nullptr && node->children[1] == nullptr)
			return;

		if(d - umbral <= node->umbral){
			knnsearch(node->children[0], q, k, umbral, ans);
		}
		if(d + umbral >= node->umbral){
			knnsearch(node->children[1], q, k, umbral, ans);
		}
	}


public:

	vptree(vector<record> data, metrics (*f)(record, record)){
		this->data = data;
		this->f = f;

		vector<int> idx;
		for(int i=0; i<data.size(); i++)
			idx.push_back(i);

		this->root = create_vptree(idx);
	}

	vector<record> knnsearch(record query, int k){
		vector<record> ans;
		priority_queue<pair<metrics,int>> pq;
		metrics rq = 1e32;
		knnsearch(root, query, k, rq, pq);
		while(!pq.empty()){
			auto it = pq.top();
			pq.pop();
			ans.push_back(data[it.second]);
		}
		reverse(begin(ans), end(ans));
		return ans;
	}

	~vptree(){};
	
};
