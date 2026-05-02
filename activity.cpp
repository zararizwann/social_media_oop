#include "post.h"
#include "datee.h"
#include "content.h"
#include "activity.h"
#include <iostream>
#include <cstring>
using namespace std;




	activity::activity(char* id1, char* description1, datee* shareddate1, content* postedby1,int type1, const char* value1) :post(id1, description1, shareddate1,  postedby1) {
		 type = type1;
		value = new char[strlen(value1) + 1];
		strcpy_s(value, strlen(value1) + 1, value1);
	}

	void activity:: displaypost()  {
		if (type == 1) {
			cout << getpostedby()->getname() << " is " << " feeling " << value << endl;
		}
		else if (type == 2) {
			cout << getpostedby()->getname() << " is " << " thinking about " << value << endl;
		}
		else if (type == 3) {
			cout << getpostedby()->getname() << " is " << " making " << value << endl;
		}
		else if (type == 4) {
			cout << getpostedby()->getname() << " is " << " celebrating " << value << endl;
		}
	cout << getdescription() << endl;
		for (int i = 0; i < getcommentnum(); i++) {
			cout << getcomment()[i]->getpostedby()->getname() << " wrote : " << getcomment()[i]->gettext() << endl;
		}
		getshareddate()->displaydate();
	}

	activity:: ~activity() {
		delete[] value;
	}
