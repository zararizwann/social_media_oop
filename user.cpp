
#include "content.h"
#include "user.h"
#include "post.h"
#include "page.h"
#include <iostream>
#include <cstring>
using namespace std;

user::user(const char* id1, const  char* name1) :content(id1, name1) {
		friendlist = nullptr;
		posts = nullptr;
		likedpages = nullptr;
		friendcount = 0;
		likedpagescount = 0;
		postcount = 0;
	}
	void user::addfriend(user* u) {
		user** tempfriendlist = new user * [friendcount + 1];
		for (int i = 0; i < friendcount;i++) {
			tempfriendlist[i] = friendlist[i];
		}
		tempfriendlist[friendcount] = u;
		friendcount++;
		delete[] friendlist;
		friendlist = tempfriendlist;
	}
	void user::addposts(post* p){
		post** temp = new post * [postcount + 1];
		for (int i = 0; i < postcount; i++) {
			temp[i] = posts[i];
		}
		temp[postcount] = p;
		postcount++;
		delete[]  posts;
		posts = temp;

	}
	void user::addlikedpages(page* p) {
		page** likedtemp = new page * [likedpagescount + 1];
		for (int i = 0; i < likedpagescount; i++) {
			likedtemp[i] = likedpages[i];
		}
		likedtemp[likedpagescount] = p;
		likedpagescount++;
		delete[]  likedpages;
		likedpages = likedtemp;
	}
	user** user::getfriendlist() {
		return friendlist;

	}
	page** user::getlikedpages() {
		return likedpages;
	}
	post** user::getposts() {
		return posts;
	}
	int user::getpostcount() {
		return postcount;
	}
	int user::getlikedpagescount() {
		return likedpagescount;

	}
	int user::getfriendcount() {
		return friendcount;

	}


	void user::displayfriendlist() {
		cout << getname() << "'s Friend-List : " << endl;
		for (int i = 0; i < friendcount; i++) {
			cout << friendlist[i]->getid() << " - " << friendlist[i]->getname() << endl;
		}
	}
	void user::viewfriendpost(datee* d) {
		for (int i = 0; i < friendcount; i++) {
			for (int j = 0; j < friendlist[i]->getpostcount();j++) {
				if (((d->getday()) - friendlist[i]->getposts()[j]->getshareddate()->getday()) <= 1) {
					friendlist[i]->getposts()[j]->displaypost();
					}
			}
			
		}
	}
		void user::viewlikedpagespost(datee * d) {
			for (int i = 0; i < likedpagescount; i++) {
				for (int j = 0; j < likedpages[i]->getpostcount();j++) {
					if (((d->getday()) - (likedpages[i]->getpost()[j]->getshareddate()->getday()) <= 1) {
						likedpages[i]->getposts()[j]->displaypost();

					}
				}
			}
		}

	
				void user::displayprofile() {
					cout << getname() << " 's Timeline " << endl;
					for (int i = 0; i < postcount; i++) {
							posts[i]->displaypost();
					}

				}
					user::~user() {
						delete[] likedpages;
						for (int i = 0; i < postcount; i++) {
							delete posts[i];
						}
						delete[] posts;
						delete[] friendlist;
					}

