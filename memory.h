#ifndef MEMORY_H
#define MEMORY_H
#include "post.h"

class memory :public post {
private:
	post* realpost;
	char* newdescription;

public:
	memory(char* id1, char* description1, datee* shareddate1,content* postedby1, post* realp1,char* newdesc) :post(id1, description1, shareddate1,postedby1) {};

	void displaypost() override;
	~memory();
};


#endif