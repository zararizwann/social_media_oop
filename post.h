

#ifndef POST_H
#define POST_H
#include "content.h"

class datee;
class comment;
class post {
private:
	char* id;
	content* postedby;
	char* description;
	int likescount;
	content** likedby;
	datee* shareddate;
	comment** c1;
	int commentcount;

public:
	post(char* id1, char* description1, datee* shareddate1, content* postedby1);
	char* getid();
	char* getdescription();
	int getlikednum();
	int getcommentnum();
	content** getlikedby();
	datee* getshareddate();
	comment** getcomment();
	void displaylikedby();
	void setid(char* id1);
	void setdescription(char* description1);
	virtual void displaypost();
	void setshareddate(datee& d1);
	void addlike(content* c);
	void addcomment(comment* c);
	content* getpostedby();


	virtual ~post();
};



#endif