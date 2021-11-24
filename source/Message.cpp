// 18/03/05 = Mon
// 18/03/08 = Thu: move from lp-13-33-38.cpp
// 18/03/11 = Sun: add m.folders.clear() to move operations

#include "..\include\Folder.h"
#include "..\include\Message.h"
#include <utility>				// for std::swap

using namespace std;

Message::
Message(const Message & m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders();
}

Message::
Message(Message && m) noexcept : contents(std::move(m.contents))
{
#ifdef DEBUG_MOVE
	clog << "Call: move constructor" << endl;
#endif
	// order of statements matters
	m.remove_from_Folders();
	folders = std::move(m.folders);
	m.folders.clear();				// ensure that destroying m is harmless
	add_to_Folders();
}

Message & Message::operator=(const Message & m)
{
	// protect against self-assignment by putting removal before addition
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders();
	return *this;
}

Message & Message::operator=(Message && m) noexcept
{
#ifdef DEBUG_MOVE
	clog << "Call: move-assignment operator" << endl;
#endif
	if (this != &m) {
		m.remove_from_Folders();
		remove_from_Folders();
		contents = std::move(m.contents);
		folders = std::move(m.folders);
		m.folders.clear();			// ensure that destroying m is harmless
		add_to_Folders();
	}
#ifdef DEBUG_SELF_ASSIGN
	else {
		clog << "Note: guarded against self-(move-)assignment" << endl;
	}
#endif
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder & f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder & f)
{
	folders.erase(&f);
	f.remMsg(this);
}

std::string Message::read() const
{
	return contents;
}

void Message::add_to_Folders()
{
	for (auto f : folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void swap(Message & lhs, Message & rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}