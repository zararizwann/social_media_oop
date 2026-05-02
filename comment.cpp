#include <iostream>
#include <cstring>
#include "content.h"
#include "comment.h"
using namespace std;


comment::comment(content* postedby1, const char* text1) {
	postedby = postedby1;
	text = new char[strlen(text1) + 1];
	strcpy_s(text, strlen(text) + 1, text1);


}

void comment::displaycomment() {
	cout << postedby->getname() << " wrote " << text << endl;
}
char* comment::gettext() {
	return text;
}
content* comment::getpostedby() {
	return postedby ;
}

comment::~comment(){
		delete[] text;
};

