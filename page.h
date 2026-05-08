#ifndef PAGE_h
#define PAGE_h
#include "content.h"
class user;
class post;
class page : public content {
private:
	user* owner;
	post** posts;
	int postcount;
	int likednum;

public:
	page(const char* id1, const char* name1, user* owner1);

	user* getowner();
	post** getpost();
	int getpostcount();
	int getlikednum();

	void displaypage();

	void addpost(post* p);
	void addlike();


	~page();


};
#endif 
