// 21/12/22 = Wed
// 18/01/27 = Sat
// 17/10/22 = Sun

// Exercise 3.17: Read a sequence of words from cin and store the values in a
// vector. After you've read all the words, process the vector and change each
// word to uppercase. Print the transformed elements, eight words to a line.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-17-uppercase.cpp && \
./a.out <../data/summer.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-17-uppercase.cpp && ^
a <..\data\summer.txt

=== Input ===
(summer.txt)
Shall I compare thee to a summer's day?
Thou art more lovely and more temperate.
Rough winds do shake the darling buds of May,
And summer's lease hath all too short a date.
Sometime too hot the eye of heaven shines,
And often is his gold complexion dimmed;
And every fair from fair sometime declines,
By chance, or nature's changing course, untrimmed;
But thy eternal summer shall not fade,
Nor lose possession of that fair thou ow'st,
Nor shall death brag thou wand'rest in his shade,
When in eternal lines to Time thou grow'st.
So long as men can breathe, or eyes can see,
So long lives this, and this gives life to thee.

=== Output ===
(summer.txt)
SHALL I COMPARE THEE TO A SUMMER'S DAY?
THOU ART MORE LOVELY AND MORE TEMPERATE. ROUGH
WINDS DO SHAKE THE DARLING BUDS OF MAY,
AND SUMMER'S LEASE HATH ALL TOO SHORT A
DATE. SOMETIME TOO HOT THE EYE OF HEAVEN
SHINES, AND OFTEN IS HIS GOLD COMPLEXION DIMMED;
AND EVERY FAIR FROM FAIR SOMETIME DECLINES, BY
CHANCE, OR NATURE'S CHANGING COURSE, UNTRIMMED; BUT THY
ETERNAL SUMMER SHALL NOT FADE, NOR LOSE POSSESSION
OF THAT FAIR THOU OW'ST, NOR SHALL DEATH
BRAG THOU WAND'REST IN HIS SHADE, WHEN IN
ETERNAL LINES TO TIME THOU GROW'ST. SO LONG
AS MEN CAN BREATHE, OR EYES CAN SEE,
SO LONG LIVES THIS, AND THIS GIVES LIFE
TO THEE.
*/

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vec;
  for (std::string s; std::cin >> s; /* empty */) {
    vec.push_back(s);
  }
  for (std::string &s : vec) {
    for (char &c : s) {
      c = std::toupper(static_cast<unsigned char>(c));
    }
  }
  for (decltype(vec.size()) i = 0; i != vec.size(); ++i) {
    std::cout << vec[i] << " ";
    if (i % 8 == 7) {
      std::cout << std::endl;
    }
  }
  return 0;
}
