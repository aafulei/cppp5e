// 18/03/05 = Mon

// for Folder class in lp-13-33-38.cpp

#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include <string>
#include <vector>

class Message;

class Folder
{
	std::string name;
	std::set<Message *> messages;
public:
	Folder(const std::string & n) : name(n) {}
	void addMsg(Message *);
	void remMsg(Message *);
friend
	class Message;
friend
	void print(const std::vector<Folder *> &);
};

#endif