#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

char words[1010][25];
int words_len;
char work_words[1010][25];
void pre_handl(char a[][25], char b[][25], int len);
void run(char a[][25], char b[][25], int len);
int main()
{
  //char in_word[25];
  
  while (scanf("%s", words[words_len]) != EOF)
  {
    if (words[words_len][0] == '#')
    {
      words_len--;
      break;
    }
    
    words_len++;
    
  }
  pre_handl(words, work_words, words_len);
  run(words, work_words, words_len);
  return 0;
}
void sort_and_insensive(char* src, char* dst)
{
  int len = strlen(src);
  strcpy(dst, src);
  for(int i = 0; i < len;  i++)
  {
    if (isupper(dst[i]))
    dst[i] = tolower(dst[i]);
  }
  sort(dst, dst+len);
}
void pre_handl(char a[][25], char b[][25], int len)
{
  for (int i = 0; i < len; i++)
  {
    sort_and_insensive(a[i], b[i]);
  }
  
  return;
}

void run(char a[][25] , char b[][25], int len)
{
  vector<string> v;
  for (int i = 0; i <len; i++)
  {
    string s = a[i];
    if (strlen(b[i]) == 1)
    {
      v.push_back(s);
      continue;
    }
    bool found = false;
    for (int j = 0; j < len; j++)
    {
      if (i == j)
      {
        continue;
      }
      if (0 == strcmp(b[i], b[j]))
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      v.push_back(s);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << endl;
  }
  return;
  
}
