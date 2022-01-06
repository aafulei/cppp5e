// 18/03/05 = Mon

// for Message class in lp-13-33-38.cpp

#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>
#include <vector>

class Folder;

class Message
{
	std::string contents;
	std::set<Folder *> folders;
public:
	explicit Message(const std::string & c = "") : contents (c) {}
	Message(const Message &);
	Message(Message &&) noexcept;
	Message & operator=(const Message &);
	Message & operator=(Message &&) noexcept;
	~Message();
	void save(Folder &);
	void remove(Folder &);
	std::string read() const;
private:
	void add_to_Folders();
	void remove_from_Folders();
friend
	class Folder;
friend
	void swap(Message &, Message &);
friend
	void print(const std::vector<Folder *> &);
};

#endif