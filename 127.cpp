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
void play_res(const piles& ps);

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
      card c(s[0], s[1]);
      pile p;
      p.push(c);
      play(ps, p);
    }
    if (end_flag) break;
    play_res(ps);
  }
  return 0;
}

void play(piles& ps, const pile& p)
{
  ps.push_back(p);
  
  for (int i = ps.size() - 1; i < ps.size(); i++)
  {
    int j;
    for (j = i; j > 0; j--)
    {
      if (j >= 3)
      {
        match_card(ps[j-3].top(), ps[i].top());
        j -= 2;
        continue;
      }
      if (!match_card(ps[j-1].top(), ps[i].top()))
      {
        break;
      }
    }
    if (j != i)//可以移动
    {
      card c = ps[i].top();
      ps[i].pop();
      if (ps[i].empty())
      {
        ps.erase(ps.begin()+i);
      }
      ps[j].push(c);
      i = j;
    }
  }
  return;
}
void play_res(const piles& ps)
{
  cout << ps.size() << ((ps.size() > 1) ? " piles " : " pile ") << " remaining: ";
  for (int i = 0; i < ps.size(); i++)
  {
    cout << ps[i].size() << " ";
  }
  cout << endl;
  return;
}
