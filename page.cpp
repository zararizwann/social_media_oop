
#include "content.h"
#include "user.h"
#include "post.h"
#include "page.h"
#include <iostream>
#include <cstring>
using namespace std;


	page::page(const char* id1, const char* name1, user* owner1):content(id1,name1) {
		owner = owner1;
		postcount = 0;
		likednum = 0;
		posts = nullptr;
	}

	user* page::getowner() {
		return owner;
	}
	post** page::getpost() {
		return posts;
	}
	int	page::getpostcount() {
		return postcount;
	}
	int 	page::getlikednum() {
		return likednum;
	}
	


	void 	page::displaypage() {
		cout << getname() << endl;
		for (int i = 0; i < postcount; i++) {
			posts[i]->displaypost();
		}
	}

		void 	page::addpost(post * p) {
			post** temp = new post * [postcount + 1];
			for (int i = 0; i < postcount; i++) {
				temp[i] = posts[i];
			}
			temp[postcount] = p;
			postcount++;
			delete[]  posts;
			posts = temp;
	}
		void 	page::addlike() {
			likednum++;
	}


		page::~page() {
			delete[] posts;
	}



