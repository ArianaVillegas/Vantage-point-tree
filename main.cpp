#include "vptree.h"

int main(){

	srand(time(NULL));

	vector<record> data = {
					{12},
					{20},
					{30},
					{82},
					{5}
					};

	vptree vt(data);

    return 0;
}


