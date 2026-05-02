#include <iostream>
#include <cstring>
#include "content.h"
using namespace std;

content::content(const char* id1, const char* name1) {
	id = new char[strlen(id1)+1];
	strcpy_s(id, strlen(id1) + 1, id1);
	name = new char[strlen(name1) + 1];
	strcpy_s(name, strlen(name1) + 1, name1);
}
char* content::getid() {
	return id;
}
char* content::getname() {
	return name;
}

void content::setid(char* id1) {
	delete[] id;
	id = new char[strlen(id1) + 1];
	strcpy_s(id, strlen(id1) + 1, id1);

}
void content::setname(char* name1) {
	delete[] name;
	name = new char[strlen(name1) + 1];
	strcpy_s(name, strlen(name1) + 1, name1);
}

 content :: ~content() {
	delete[] name;
	delete[] id;
}

