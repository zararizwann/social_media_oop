#ifndef CONTENT_H
#define CONTENT_H


class content {
private:
	char* id;
	char* name;
public:
	content(const char* id1, const char* name1);
	char* getid();
	char* getname();

	void setid(char* id1);
	void setname(char* name1);

	virtual ~content();
};





#endif