#include "post.h"
#include "content.h"
#include <iostream>
#include <cstring>
using namespace std;



	post::post(char* id1, char* description1, datee* shareddate1,content* postedby1) {
		id = new char[strlen(id1) + 1];
		strcpy_s(id, strlen(id1) + 1, id1);
		description = new char[strlen(description1) + 1];
		strcpy_s(description, strlen(description1) + 1, description1);
		shareddate = shareddate1;
		likescount = 0;
		likedby = new content * [10];
		c1 = new comment * [10];
		commentcount = 0;
		postedby = postedby1;
	}
	char* post::getid() {
		return id;
	}
	char* post::getdescription() {
		return description;
	}
	int post::getlikednum() {
		return likescount;
	}
	int post::getcommentnum() {
		return commentcount;
	}
	content** post::getlikedby() {
		return likedby;
	}
	datee* post::getshareddate() {
		return shareddate;
	}
	content* post::getpostedby() {
		return postedby;
	}
	comment** post::getcomment() {
		return c1;
	}
	void post::displaylikedby() {
		for (int i = 0; i < likescount; i++) {
			cout << likedby[i]->getname();
		}
	}
		void post::setid(char* id1) {
			id = new char[strlen(id1) + 1];
			strcpy_s(id, strlen(id1) + 1, id1);
	}
		void post::setdescription(char* description1) {
			description = new char[strlen(description1) + 1];
			strcpy_s(description, strlen(description1) + 1, description1);

	}
		void post::displaypost() {
			cout << postedby->getname() << " shared " << description << endl;
			for (int i = 0; i < commentcount; i++) {
				cout << c1[i]->getpostedby()->getname() << " wrote : " << c1[i]->gettext() << endl;
			}
			shareddate->displaydate();
			cout << postedby->getname() << " shared " << description << endl;
			for (int i = 0; i < commentcount; i++) {
				cout << c1[i]->getpostedby()->getname() << " wrote : " << c1[i]->gettext() << endl;
			}
			shareddate->displaydate();

	 }
	 void post::setshareddate(datee& d1) {
		 shareddate = &d1;
	 }
	void post::addlike(content* c) {
		if (likescount < 10){
			likedby[likescount] = c;
			likescount++;
		}
	}
	void post::addcomment(comment* c) {
		if (commentcount < 10) {
			c1[commentcount] = c;
			commentcount++;
		}
	
	}


	post:: ~post() {
		delete[] id;
		delete[] description;
		for (int i = 0;i < commentcount ; i++) {
			delete c1[i];
		}
		delete[] c1;
		c1 = nullptr;
			delete[] likedby;
	}