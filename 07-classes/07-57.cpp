// 22/02/12 = Sat
// 18/02/11 = Sun

// Exercise 7.57: Write your own version of the Account class.

#include <iostream>
#include <string>

class Bank;

class Account {
  friend Bank;

public:
  Account(std::string owner, double amount = 0.0)
      : owner(owner), amount(amount) {}

  double get_amount() const { return amount; }
  static double get_rate() { return rate; }

  Account &accrue() {
    amount *= (1 + rate);
    return *this;
  }

private:
  const std::string owner;
  double amount;
  static double rate;
};

class Bank {
public:
  static void set_rate(double rate) { Account::rate = rate; }
};

double Account::rate = 0.05;

void test() {
  Account kaka("Kaka", 3000);
  std::cout << kaka.get_rate() << std::endl;
  std::cout << Account::get_rate() << std::endl;
  std::cout << kaka.get_amount() << std::endl;
  std::cout << kaka.accrue().get_amount() << std::endl;
  Bank::set_rate(0.025);
  std::cout << kaka.accrue().get_amount() << std::endl;
}

int main() {
  test();
  return 0;
}
