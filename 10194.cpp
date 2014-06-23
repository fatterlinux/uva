#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;
struct team_info{
    std::string name;
    int goals_scored, goals_against;
    int points;
    int games_played;
    int wins;
    int ties;
    int losses;
    int goal_difference;
    team_info()
    {
        name = "";
        goals_scored = goals_against = points = games_played = wins = ties = losses = goal_difference = 0;
    }
};

bool cmp1(const team_info& a, const team_info& b)
{
    string c(a.name), d(b.name);
    for (int i = 0; i < a.name.size(); i++)
    {
        c[i] = tolower(c[i]);
    }
    for (int i = 0; i < b.name.size(); i++)
    {
        d[i] = tolower(d[i]);
    }
    return c < d;
}
bool cmp2(const team_info& a, const team_info& b)
{
    return a.losses < b.losses;
}
bool cmp3(const team_info& a, const team_info& b)
{
    return a.goals_scored > b.goals_scored;
}
bool cmp4(const team_info& a, const team_info& b)
{
    return a.goal_difference > b.goal_difference;
}
bool cmp5(const team_info& a, const team_info& b)
{
    return a.wins > b.wins;
}
bool cmp6(const team_info& a, const team_info& b)
{
    return a.points > b.points;
}
const int max_teams = 30;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int test;
    std::cin >> test;
    std::string ssss;
    getline(std::cin, ssss);
    while (test--)
    {
        team_info t[max_teams];
        //memset(t, 0, sizeof(t));
        std::string s;
        std::getline(std::cin, s);
        std::cout << s << std::endl;
        int num;
        std::cin >> num;
        getline(std::cin, ssss);
        for(int i = 0; i < num; i++)
        {
            getline(std::cin, s);
            t[i].name = s;
        }
        int records;
        std::cin >> records;
        getline(std::cin, ssss);
        for (int k = 0; k < records; k++)
        {
            std::string ss;
            getline(std::cin, ss);
            int pos1(ss.find('#')), pos2(ss.rfind('#'));

            std::string t1(ss.substr(0, pos1)), t2(ss.substr(pos2+1));
            stringstream sin(ss.substr(pos1+1));
            int t1_score, t2_score;
             sin >> t1_score;
             char c;
             sin >> c;
             sin >> t2_score;
              for (int i = 0; i < num; i++)
            {
                if (t[i].name == t1)
                {
                    t[i].goals_scored += t1_score;
                    t[i].goal_difference += t1_score - t2_score;
                    t[i].goals_against += t2_score;
                    if (t1_score - t2_score > 0)
                    {
                        t[i].wins += 1;
                        t[i].points += 3;
                    }
                    else if (t1_score - t2_score == 0)
                    {
                        t[i].ties += 1;
                        t[i].points += 1;
                    }
                    else
                    {
                        t[i].losses += 1;
                    }
                    t[i].games_played++;
                }
                else if (t[i].name == t2)
                {
                    t[i].goals_scored += t2_score;
                    t[i].goal_difference += t2_score - t1_score;
                    t[i].goals_against += t1_score;
                    if (t2_score - t1_score > 0)
                    {
                        t[i].wins++;
                        t[i].points += 3;
                    }
                    else if (t2_score - t1_score == 0)
                    {
                        t[i].ties ++;
                        t[i].points ++;
                    }
                    else
                    {
                        t[i].losses ++;
                    }
                    t[i].games_played++;
                }
            }
        }
        std::sort(t, t+num, cmp1);
        std::stable_sort(t, t+num, cmp2);
        std::stable_sort(t, t+num, cmp3);
        std::stable_sort(t, t+num, cmp4);
        std::stable_sort(t, t+num, cmp5);
        std::stable_sort(t, t+num, cmp6);
        for (int i = 0; i <num; i++)
        {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                    i+1, t[i].name.c_str(), t[i].points, t[i].games_played, t[i].wins, t[i].ties, t[i].losses, t[i].goal_difference, 
                    t[i].goals_scored, t[i].goals_against);
        }
        if (test)
        {
            cout << endl;
        }
    }

    return 0;
}
