#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

struct team_info{
    std::string name;
    int goals_scored, goals_against;
    int points;
    int games_played;
    int wins;
    int ties;
    int losses;
    int goal_difference;
};

bool cmp1(const team_info& a, const team_info& b)
{
    return a.name < b.name;
}

const int max_teams = 1000;
int main()
{
    team_info t[max_teams];
    int t;
    std::cin >> t;
    while (t--)
    {
        memset(t, 0, sizeof(t));
        std::string s;
        std::getline(cin, s);
        std::cout << s << std::endl;
        int num;
        std::cin >> num;
        for(int i = 0; i < num; i++)
        {
            std::cin >> s;
            t[i].name = s;
        }
        int records;
        std::cin >> records;
        for (int i = 0; i < records; i++)
        {
            string ss;
            getline(std::cin, ss);
            int i = 0;
            string t1;
            while (i < ss.size() && ss[i] != '#')
            {
                t1 += ss[i];
                i++;
            }
            i++;
            int t1_score;
            t1_score = ss[i] - '0';
            i++;
            i++;
            int t2_score = ss[i] - '0';
            i++;
            i++;
            string t2;
            while (i < ss.size())
            {
                t2 += ss[i++];
            }
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
    }
}
