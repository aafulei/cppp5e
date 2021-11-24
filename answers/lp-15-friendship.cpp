// 18/03/17 = Sat

// Say if I'm your father's friend. You publicly inherit a nice sport car from your dad. I employ you. Then I may ask you to lend that car to me. In fact, I may even demand you hand in your father's private diary. Why? Because I'm your father's close friend, closer to your dad than you are.

struct B
{
public:
	void book() {}
protected:
	void car() {}
private:
	void diary() {}
friend class F;
};

struct D : public B {};

struct F
{
	void employ(D d)
	{
		d.car();
		d.diary();
	}
};

int main()
{
	return 0;
}