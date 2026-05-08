
#include "user.h"
#include "post.h"
#include "page.h"
#include "datee.h"
#include "app.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

	app::app() {
		userlist = nullptr;
		pagelist = nullptr;
		totalusers = 0;
		totalpages = 0;
		totalposts = 0;
		d = nullptr;
		currentuser = nullptr;
		postlist = nullptr;
		memorycount = 0;
		load()
	}
	void app::setcurrentuser() {
		cout << "Enter your id " << endl;
		char id[10];
		cin >> id;
		bool found = false;
		for (int i = 0; i < totalusers;i++) {
			if(strcmp(userlist[i]->getid(),id)==0) {
				currentuser = userlist[i];
				found = true;
				cout << userlist[i]->getname() << " has been set as the current user " << endl;
				break;
			}
		}
		if (found == false) {
			cout << "user not found " << endl;
		}
	}
	void app::viewhome() {
		cout << currentuser->getname() << "'s Home Page " << endl;
		currentuser->viewfriendpost(d);
		currentuser->viewlikedpagespost(d);

	}
	void app::likeapost() {
		char id[10];
		bool found = false;
		cout << "Enter post id that you want to like" << endl;
		cin >> id;
		for (int i = 0;i < totalposts;i++) {
			if (strcmp(postlist[i]->getid(), id) == 0) {
				found = true;
				postlist[i]->addlike(currentuser);
				break;
			}
		}
		if (found == false) {
			cout << "Post Unavailable" << endl;
		}
	}
	void app::displaylikedby() {
		char id[10];
		bool found = false;
		cout << "Enter post ID to see who liked it: " << endl;
		cin >> id;
		for (int i = 0; i < totalposts;i++) {
			if (strcmp(postlist[i]->getid(), id) == 0) {
				found = true;
				postlist[i]->displaylikedby();
				break;
			}
		}
			if (found == false) {
				cout << "Post Unavaiable" << endl;
			}

	}
	void app::addcomment() {
		char id[10];
		bool found = false;
		cout << "Enter post ID of the post you want to comment on " << endl;
		cin >> id;
		char text[100];
		cout << "Enter comment that u want to add " << endl;
		cin.ignore();
		cin.getline(text, 100); 
		comment* c= new comment(currentuser, text);
		for (int i = 0; i < totalposts;i++) {
			if (strcmp(postlist[i]->getid(), id) == 0) {
				found = true;
				postlist[i]->addcomment(c);
				break;
			}

		}
		if (found == false) {
			cout << "Post Not found" << endl;
		}
	}
	void app::viewpost() {
		char id[10];
		bool found =false;
		cout << "Enter post ID " << endl;
		cin >> id;
		for (int i = 0; i < totalposts;i++) {
			if (strcmp(postlist[i]->getid(), id) == 0) {
				found = true;
				postlist[i]->displaypost();
				break;
			}
		}
		if (found == false) {
			cout << "Page not found " << endl;
		}
	}
	void app::sharememory() {
		char id[10];
		bool found = false;
		cout << "Enter post ID that you want to share " << endl;
		cin >> id;
		char text[100];
		cout << "Enter Your text " << endl;
		cin.ignore();
		cin.getline(text, 100);
		for (int i = 0; i < totalposts; i++) {
			if (strcmp(postlist[i]->getid(), id) == 0) {
				char memid[20];
				sprintf(memid, "mem%d", memorycount);
				memorycount++;
				memory* m = new memory(memid, text, d, currentuser, postlist[i], text);
				currentuser->addposts(m);
				found = true;
				break;
			}
		}
		if (found == false) {
			cout << "Post not found" << endl;
		}
	}
	void app::viewprofile() {
		cout << currentuser->getname() << " Time Line " << endl;
		currentuser->displayprofile();

	}
	void app::viewfriendlist() {
		cout << currentuser->getname() << "'s Friend List : " << endl;
		currentuser->displayfriendlist();
	}
	void app::viewpage() {
		char id[10];
		cout << "Enter Page ID " << endl;
			cin >> id;
		bool found = false;
		for (int i = 0; i < totalpages; i++) {
			if (strcmp(pagelist[i]->getid(), id) == 0) {
				found = true;
				cout << pagelist[i]->getname() << endl;
				pagelist[i]->displaypage();
				break;
			}
		}
			if (found == false) {
				cout << "Page not found " << endl;
			}
	}
	void app::setdate() {
		if (d != nullptr) {
			delete d;
		}
		int day, month, year;
		cout << "enter day " << endl;
		cin >> day;
		cout << "enter month" << endl;
		cin >> month;
		cout << "enter year" << endl;
		cin >> year;
		d = new datee(day, month, year);
	}
	void app::run() {
		int choice;
		while (true) {
			cout << "Enter " << endl;
			cout << "1. Set Date" << endl;
			cout << "2. Set Current User" << endl;
			cout << "3. View Home" << endl;
			cout << "4. Like a Post" << endl;
			cout << "5. View Liked List" << endl;
			cout << "6. Comment on Post" << endl;
			cout << "7. View Post" << endl;
			cout << "8. Share Memory" << endl;
			cout << "9. View Profile" << endl;
			cout << "10. View Friend List" << endl;
			cout << "11. View Page" << endl;
			cout << "0. Exit" << endl;
			cout << "Enter Your Choice " << endl;
			cin >> choice;
			if (choice == 0) {
				break;
			}
			else if (choice == 1) {
				setdate();
			}
			else if (choice == 2) {
				setcurrentuser();
			}
			else if (choice == 3) {
				viewhome();
			}
			else if (choice == 4) {
				likeapost();
			}
			else if (choice == 5) {
				displaylikedby();
			}
			else if (choice == 6) {
				addcomment();
			}
			else if (choice == 7) {
				viewpost();
			}
			else if (choice == 8) {
				sharememory();
			}
			else if (choice == 9) {
				viewprofile();
			}
			else if (choice == 10) {
				viewfriendlist();
			}
			else if (choice == 11) {
				viewpage();
			}
		}
	}

            void app::load() {
    
            ifstream pagesFile("Pages.txt");
            pagesFile >> totalpages;
            pagelist = new page * [totalpages];
            for (int i = 0; i < totalpages; i++) {
                char pid[20], pname[100];
                pagesFile >> pid;
                pagesFile.ignore();
                pagesFile.getline(pname, 100);
                pagelist[i] = new page(pid, pname, nullptr);
            }
            pagesFile.close();

           
            ifstream usersFile("Users.txt");
            usersFile >> totalusers;
            usersFile.ignore();
            userlist = new user * [totalusers];

        
            for (int i = 0; i < totalusers; i++) {
                char line[500];
                usersFile.getline(line, 500);
                char uid[20], uname[100];
                int pos = 0;
            
                int j = 0;
                while (line[pos] != '\t') uid[j++] = line[pos++];
                uid[j] = '\0'; pos++;
               
                j = 0;
                while (line[pos] != '\t') uname[j++] = line[pos++];
                uname[j] = '\0';
                userlist[i] = new user(uid, uname);
            }
            usersFile.close();

            ifstream usersFile2("Users.txt");
            usersFile2 >> totalusers;
            usersFile2.ignore();
            for (int i = 0; i < totalusers; i++) {
                char line[500];
                usersFile2.getline(line, 500);
              
                int pos = 0;
                while (line[pos] != '\t') pos++; pos++; // skip id
                while (line[pos] != '\t') pos++; pos++; // skip name
            
                char token[20];
                while (true) {
                    int j = 0;
                    while (line[pos] != '\t' && line[pos] != '\0') token[j++] = line[pos++];
                    token[j] = '\0';
                    if (line[pos] == '\t') pos++;
                    if (strcmp(token, "-1") == 0) break;
                 
                    for (int k = 0; k < totalusers; k++) {
                        if (strcmp(userlist[k]->getid(), token) == 0) {
                            userlist[i]->addfriend(userlist[k]);
                            break;
                        }
                    }
                }
                
                while (true) {
                    int j = 0;
                    while (line[pos] != '\t' && line[pos] != '\0') token[j++] = line[pos++];
                    token[j] = '\0';
                    if (line[pos] == '\t') pos++;
                    if (strcmp(token, "-1") == 0) break;
               
                    for (int k = 0; k < totalpages; k++) {
                        if (strcmp(pagelist[k]->getid(), token) == 0) {
                            userlist[i]->addlikedpages(pagelist[k]);
                            break;
                        }
                    }
                }
            }
            usersFile2.close();

          
            ifstream postsFile("Posts.txt");
            postsFile >> totalposts;
            postlist = new post * [totalposts];

            for (int i = 0; i < totalposts; i++) {
                int posttype;
                char postid[20];
                postsFile >> posttype >> postid;
                int day, month, year;
                postsFile >> day >> month >> year;
                postsFile.ignore();
                char desc[300];
                postsFile.getline(desc, 300);
                datee* dt = new datee(day, month, year);

                int acttype = 0;
                char actvalue[100] = "";
                if (posttype == 2) {
                    postsFile >> acttype;
                    postsFile.ignore();
                    postsFile.getline(actvalue, 100);
                }

               
                char posterid[20];
                postsFile >> posterid;

              
                content* poster = nullptr;
                for (int k = 0; k < totalusers; k++) {
                    if (strcmp(userlist[k]->getid(), posterid) == 0) {
                        poster = userlist[k];
                        break;
                    }
                }
                if (poster == nullptr) {
                    for (int k = 0; k < totalpages; k++) {
                        if (strcmp(pagelist[k]->getid(), posterid) == 0) {
                            poster = pagelist[k];
                            break;
                        }
                    }
                }

              
                if (posttype == 1) {
                    postlist[i] = new post(postid, desc, dt, poster);
                }
                else {
                    postlist[i] = new activity(postid, desc, dt, poster, acttype, actvalue);
                }

             
                for (int k = 0; k < totalusers; k++) {
                    if (strcmp(userlist[k]->getid(), posterid) == 0) {
                        userlist[k]->addposts(postlist[i]);
                        break;
                    }
                }
                for (int k = 0; k < totalpages; k++) {
                    if (strcmp(pagelist[k]->getid(), posterid) == 0) {
                        pagelist[k]->addpost(postlist[i]);
                        break;
                    }
                }

               
                char token[20];
                while (postsFile >> token) {
                    if (strcmp(token, "-1") == 0) break;
                    for (int k = 0; k < totalusers; k++) {
                        if (strcmp(userlist[k]->getid(), token) == 0) {
                            postlist[i]->addlike(userlist[k]);
                            break;
                        }
                    }
                    for (int k = 0; k < totalpages; k++) {
                        if (strcmp(pagelist[k]->getid(), token) == 0) {
                            postlist[i]->addlike(pagelist[k]);
                            break;
                        }
                    }
                }
            }
            postsFile.close();

           
            ifstream commentsFile("Comments.txt");
            int totalcomments;
            commentsFile >> totalcomments;
            for (int i = 0; i < totalcomments; i++) {
                char cid[20], postid[20], posterid[20];
                commentsFile >> cid >> postid >> posterid;
                commentsFile.ignore();
                char ctext[300];
                commentsFile.getline(ctext, 300);

            
                content* poster = nullptr;
                for (int k = 0; k < totalusers; k++) {
                    if (strcmp(userlist[k]->getid(), posterid) == 0) {
                        poster = userlist[k];
                        break;
                    }
                }
                if (poster == nullptr) {
                    for (int k = 0; k < totalpages; k++) {
                        if (strcmp(pagelist[k]->getid(), posterid) == 0) {
                            poster = pagelist[k];
                            break;
                        }
                    }
                }

              
                for (int k = 0; k < totalposts; k++) {
                    if (strcmp(postlist[k]->getid(), postid) == 0) {
                        comment* c = new comment(poster, ctext);
                        postlist[k]->addcomment(c);
                        break;
                    }


                }
            }
            commentsFile.close();
        }
       

           

	app::~app() {
		delete d;

		for (int i = 0; i < totalpages;i++) {
			delete pagelist[i];
		}
		delete[] pagelist;
		for (int i = 0; i < totalposts;i++) {
			delete postlist[i];
		}
		delete[] postlist;
		for (int i = 0; i < totalusers;i++) {
			delete userlist[i];
		}
		delete[] userlist;

	}


	