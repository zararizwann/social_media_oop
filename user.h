#ifndef USER_H
#define USER_H
#include "content.h"

class pages;
class post;
class datee;


class user : public content {
private:
	user** friendlist;
	pages** likedpages;
	post** posts;
	int friendcount, likedpagescount, postcount;

public:
	user(const char* id1, const  char* name1) :content(id1, name1) {};
	void addfriend(user* u);
	void addposts(post* p);
	void addlikedpages(pages* p);
	user** getfriendlist();
	pages** getlikedpages();
	post** getposts();
	int getpostcount();
	int getlikedpagescount();
	int getfriendcount();


	void displayfriendlist();
	void viewfriendpost(datee* d);
	void viewlikedpagespost(datee* d);
	void displayprofile();
	~user();

};
#endif