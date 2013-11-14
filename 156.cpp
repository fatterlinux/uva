#include <stdio.h>
#include <ctype.h>
#include <algorithm>

char words[1010][25];
const words_len;
char work_words[1010][25];
void pre_handl(char** a, char** b);
void run(char** a, char** b);
int main()
{
  //char in_word[25];
  
  while (scanf("%s", words[words_len]) != EOF)
  {
    if (words[0] == '#')
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
    sort(dst, dst+len);
  }
}
void pre_handl(char** a, char** b, int len)
{
  for (int i = 0; i < len; i++)
  {
    sort_and_insensive(a[i], b[i]);
  }
  
  return;
}

void run(char** a , char** b, int len)
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
      if (0 == strcmp(b[i], b[j])))
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
  v.sort(v.begin(), v.end(), cmp_fun);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << endl;
  }
  return;
  
}
