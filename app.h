#ifndef	APP_h
#define APP_H
#include "user.h"
#include "post.h"
#include "page.h"
#include "datee.h"

class app {
	user** userlist;
	page** pagelist;
	post** postlist;
	int totalusers;
	int totalpages;
	int totalposts;
	int memorycount;
	user* currentuser;
	datee* d;

public:
	app();
	void setcurrentuser();
	void viewhome();
	void likeapost();
	void displaylikedby();
	void addcomment();
	void viewpost();
	void sharememory();
	void viewprofile();
	void viewfriendlist();
	void viewpage();
	void setdate();
	void run();
	void load();

	~app();



};

#endif