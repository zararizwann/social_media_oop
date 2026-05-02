
#include "post.h"
#include "memory.h"
#include <iostream>
#include <cstring>

using namespace std;



memory::memory(char* id1, char* description1, datee* shareddate1,content* postedby1, post* realp1, char* newdesc) :post(id1, description1, shareddate1,postedby1) {
	realpost = realp1;
	newdescription = new char[strlen(newdesc) + 1];
	strcpy_s(newdescription, strlen(newdesc) + 1, newdesc);
};

void memory::displaypost() {

	cout << getpostedby()->getname() << " shared a memory ";
	getshareddate()->displaydate();
	cout << endl;
	cout << newdescription << endl;
	realpost->displaypost();


	}
memory:: ~memory() {
	delete[] newdescription;
	}

