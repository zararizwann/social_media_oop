#ifndef ACTIVITY_H
#define ACTIVITY_H
#include "post.h"
#include "datee.h"

class activity :public post {
private:
	int type;
	char* value;

public:
	activity(char* id1, char* description1, datee* shareddate1, content* postedby1, int type1, const char* value1) :post(id1, description1, shareddate1, postedby1) {};

	void displaypost() override;

	~activity();
};




#endif