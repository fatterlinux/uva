#include <iostream>
#include <string>
#include <queue>
#include <assert.h>

using namespace std;

typedef queue<int> team_elm;
const int max_elm_size = 999999;
const int max_team_size = 1000;
struct team_queue
{
  int elm[max_elm_size];
  team_elm team[max_team_size];
  queue<int> team_order;//dequeue使用
  void elm_team_idx_set(int idx, int e)
  {
    elm[e] = idx;
    return;
  }
  int elm_team_idx_get(int e)
  {
    return elm[e];
  }
  void enqueue(int e)
  {
    int idx = elm_team_idx_get(e);
    if (team[idx].empty())
    {
      team_order.push(idx);
    }
    team[idx].push(e);
    return;
  }
  int dequeue()
  {
    int idx = team_order.front();
    assert(!team[idx].empty());
    int e = team[idx].front();
    team[idx].pop();
    if (team[idx].empty())
    {
      team_order.pop();
    }
    return e;
  }
};

int main()
{
  int team_num;
  int case_idx = 0;
  while (cin >> team_num)
  {
    if (!team_num) break;
    team_queue Q;
    int team_idx  = 0;
    while (team_num--)
    {
      team_idx ++;
      int elm_num;
      cin >> elm_num;
      while (elm_num--)
      {
        int e;
        cin >> e;
        Q.elm_team_idx_set(team_idx, e);
      }
    }
    cout << "Scenario #" << case_idx << endl;
    case_idx++;
    string cmd;
    while (cin >> cmd)
    {
      if (cmd == "ENQUEUE")
      {
        int e;
        cin >> e;
        Q.enqueue(e);
      }
      else if (cmd == "DEQUEUE")
      {
        cout << Q.dequeue() << endl;
      }
      else if (cmd == "STOP")
      {
        break;
      }
      else
      {
        assert(0);
      }
    }
    cout << endl;
  }
}
