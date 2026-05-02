#ifndef COMMENT_H
#define COMMENT_H
#include "content.h"

class comment {
private:
	content* postedby;
	char* text;

public:
	comment(content* postedby1, const char* text1);

	void displaycomment();
	char* gettext();
	content* getpostedby();

	~comment();
};

#endif 