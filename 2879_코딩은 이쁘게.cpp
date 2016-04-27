#include <stdio.h>
int best[1000];
int cur[1000];
int n;
void f(int index)
{
    int state = best[index] > cur[index] ? 1 : 0; // 증가해야하는가?
    if (state)
        cur[index] ++;
    else
        cur[index] --;
 
    for (int i = index+1; i < n; i++)
    {
        if (state)
        {
            if (best[i] > cur[i])
                cur[i]++;
            else
                return;
        }
        else
        {
            if (best[i] < cur[i])
                cur[i] --;
            else
                return;
        }
    }
}
int main()
{
    int i,count = 0;
    scanf("%d", &n);
 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &best[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &cur[i]);
    }
 
    for (i = 0; i < n; i++)
    {
        while (best[i] != cur[i])
        {
            f(i);
            count++;
        }
    }
 
    printf("%d", count);
    return 0;
}