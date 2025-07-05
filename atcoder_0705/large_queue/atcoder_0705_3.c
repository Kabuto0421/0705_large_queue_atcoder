#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct
{
    long long value;
    long long count;
} LargeQueue;

int main(void)
{
    int Q;
    if (scanf("%d", &Q) != 1)
        return 1;

    LargeQueue queue[200005];

    long long *query_type = malloc(sizeof(long long) * Q);
    long long *c_or_k = malloc(sizeof(long long) * Q);
    long long *add_number_x = malloc(sizeof(long long) * Q);
    long long *k = malloc(sizeof(long long) * Q);

    for (int i = 0; i < Q; i++)
    {
        if (scanf("%lld", &query_type[i]) != 1)
            return 1;
        if (query_type[i] == 1)
        {
            if (scanf("%lld", &c_or_k[i]) != 1)
                return 1;
            if (scanf("%lld", &add_number_x[i]) != 1)
                return 1;
        }
        else
        {
            if (scanf("%lld", &c_or_k[i]) != 1)
                return 1;
        }
    }

    int rear = 0;
    int head = 0;

    for (int i = 0; i < Q; i++)
    {
        if (query_type[i] == 1)
        {
            queue[rear].count = c_or_k[i];
            queue[rear].value = add_number_x[i];
            rear++;
        }
        else
        {
            long long k = c_or_k[i];
            long long sum = 0;
            while (k > 0)
            {

                long long remove_cnt;
                if (k < queue[head].count) // headのcountよりも削除する個数kが小さいなら
                {
                    remove_cnt = k; // headからk個消す.
                }
                else
                {
                    remove_cnt = queue[head].count; // kの方がheadのcountよりも大きいなら, head.countの数だけheadから消す
                }
                sum += queue[head].value * remove_cnt;
                queue[head].count -= remove_cnt;
                k -= remove_cnt;
                if (queue[head].count == 0)
                    head++;
            }
            printf("%lld\n", sum);
        }
    }
    free(query_type);
    free(c_or_k);
    free(add_number_x);
    free(k);
    return 0;
}