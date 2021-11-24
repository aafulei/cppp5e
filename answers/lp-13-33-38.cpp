// 18/03/05 = Mon

// Exercise 13.33: Why is the parameter to the save and remove members of Message a Folder&? Why didn’t we define that parameter as Folder? Or const Folder&?

// Answer: Because they change the contents of the Folder.

// Exercise 13.34: Write the Message class as described in this section.

// Answer: See Message.h, Message.cpp, and the code below.

// Exercise 13.35: What would happen if Message used the synthesized versions of the copy-control members?

// Answer: The bookkeeping of Folders would go asynchronized, because it relies on the copy-control actions of the Messages to keep the Folders in order.

// Exercise 13.36: Design and implement the corresponding Folder class. That class should hold a set that points to the Messages in that Folder.

// Answer: See Folder.h, Folder.cpp, and the code below.

// Exercise 13.37: Add members to the Message class to insert or remove a given Folder* into folders. These members are analogous to Folder’s addMsg and remMsg operations.

// Answer: They are already there: Message::save() and Message::remove().

// Exercise 13.38: We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?

// Answer: The copy-and-swap technique works best for value-like copy involving allocation of dynamic memory, which is not the case in this setting. Moreover, the swap() function is special in this case, which does bookkeeping jobs for Folders. Using the copy-and-swap technique would only complicate the situation.

#include "include\Folder.h"
#include "include\Message.h"
#include "source\Folder.cpp"
#include "source\Message.cpp"
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void notify(const string & s)
{
	cout << string(50, '-') << endl;
	cout << s << endl;
}

int main()
{
	Folder inbox("[Inbox]");
	Folder unread("[Unread]");
	Folder spam("[Spam]");
	vector<Folder *> account = { &inbox, &unread, &spam };

	notify("Receiving three Season's Greetings");
	Message a("Season's Greetings!");
	a.save(inbox);		// equivalent to "inbox.addMsg(&a);"
	a.save(unread);		// equivalent to "unread.addMsg(&a);"
	Message b = a;
	Message c;
	c = c = b = b;		// test for self-assignment
	print(account);

	notify("Reading two of the Season's Greetings");
	a.remove(unread);	// equivalent to "unread.remMsg(&a);"
	b.remove(unread);	// equivalent to "unread.remMsg(&b);"
	print(account);

	notify("Removing all three Season's Greetings");
	a.remove(inbox);
	b.remove(inbox);
	c.remove(inbox);
	c.remove(unread);
	print(account);

	notify("Getting two Advertisements");	
	Message d("25% Discount like Never Before!");
	Message e("Once-in-a-lifetime Opportunity!");
	d.save(spam);
	e.save(spam);
	print(account);

	notify("Removing one Advertisement");
	swap(d, e);			// Now d is "Once-in-a-lifetime Opportunity!"
	d.remove(spam);		// d is removed
	print(account);

	notify("Moving one Advertisement from Spam to Inbox");
	e.remove(spam);
	e.save(inbox);
	print(account);

	return 0;
}