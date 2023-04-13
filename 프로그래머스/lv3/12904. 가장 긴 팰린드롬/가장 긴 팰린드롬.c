#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* s) {
    int answer = 1;

    int len = strlen(s);
    int sublen = len;

    while (sublen > 1)
    {
        for (int i = 0; i < len - sublen + 1; i++)
        {
			int cmp = sublen / 2;
			int cnt = 0;
            int n = 0;

			for (int j = i; j < i + cmp; j++)
			{
				if (s[j] != s[i + sublen - 1 - n])
					break;
				cnt++;
                n++;
			}
            if (cnt == cmp)
            {
                printf("%d", sublen);
                return sublen;
            }
        }

        sublen--;
    }

    printf("%d", answer);
    return answer;
}