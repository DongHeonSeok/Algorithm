#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int len;
int jdata[100001];
int dp[100001][5][5];
int MIN(int a, int b)
{
   if (a<b)
      return a;
   else
      return b;
}

int algo(int x, int p)
{
   if (x == p) return 1;
   if (x == 0)return 2;
   if (x == 1 || x == 3) {
      if (p == 2 || p == 4) {
         return 3;
      }
      return 4;
   }
   if (x == 2 || x == 4) {
      if (p == 1 || p == 3) {
         return 3;
      }
      return 4;
   }
}

void init()
{
   for (int lop = 0; lop < 100000; lop++)
   {
      for (int i = 0; i < 5; i++)
      {
         for (int j = 0; j < 5; j++)
         {
            dp[lop][i][j] = 123456789;
         }
      }
   }
}
int main()
{
   while (1)
   {
      scanf("%d", &jdata[len++]);
      if (jdata[len-1] == 0) {
         len--;
         break;
      }
   }

   init();
   
   dp[0][0][jdata[0]] = 2;
   dp[0][jdata[0]][0] = 2;

   for (int lop = 1; lop < len; lop ++)
   {
      int n = jdata[lop];
      for (int i = 0; i < 5; i++)
      {
         for (int j = 0; j < 5; j++)
         {
            if (n != i)
            {
               dp[lop][n][i] = MIN(dp[lop][n][i], dp[lop - 1][i][j] + algo(j, n));
            }

            if (n != j)
            {
               dp[lop][j][n] = MIN(dp[lop][j][n], dp[lop - 1][i][j] + algo(i, n));
            }
         }
      }
   }



   int ans = 123456789;
   for (int i = 0; i<5; i++)
   {
      for (int j = 0; j<5; j++)
      {
         ans = MIN(ans, dp[len-1][i][j]);
      }
   }
   printf("%d", ans);

   return 0;
}