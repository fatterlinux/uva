#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct card
{
  char m_rank;
  char m_suit;
  card(char rank, char suit):m_rank(rank), m_suit(suit){}
};

bool match_card(const card& a, const card& b)
{
  return ((a.m_rank == b.m_rank) || (a.m_suit == b.m_suit));
}
typedef stack<card> pile;
typedef vector<pile> piles;

void play(piles& ps, const pile& p);


int main()
{
  while(true)
  {
    bool end_flag(false);
    piles ps;
    int n = 52;
    while (n--)
    {
      string s;
      cin >> s;
      if (s == "#")
      {
        end_flag = true;
        break;
      }
    }
    if (end_flag) break;
  }
}
