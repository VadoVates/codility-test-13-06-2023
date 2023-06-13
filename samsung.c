#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOWER_CASES 26
#define CHAR_A_POSITION 97


struct Results {
    int *B;
    int L;
};

struct Results solution(char *S[], int N)
{
    int M = strlen(S[0]);
    

    int string1, string2, position, index;
    int (*char_array) [LOWER_CASES] = calloc (LOWER_CASES * M, sizeof (int));
    int i, j;

    struct Results result = {calloc(3, sizeof(int)), M};
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            index = ((int) S[i][j]) - CHAR_A_POSITION;
            ++char_array [index][j];
            if (char_array [index][j] > 1) {
                position = j;
                string2 = i;
                for (int k=0; k<i; k++) {
                    if (S[i][j] == S[k][j])
                    string1 = k;
                }
                
                result.B[0] = string1;
                result.B[1] = string2;
                result.B[2] = position;
                result.L = 3;
                free (char_array);
                return result;
            }
        }
    }

    free (char_array);
    free (result.B);
    result.L = 0;
    return result;
}


int main(void)
{
    char* S0[] = {"abbaq", "kakuw", "pipie", "cddur"};

    struct Results result0 = solution(S0, 4);

    if (result0.L != 0) {
        for (int i = 0; i < 3; ++i) {
            printf("%d ", result0.B[i]);
        }
        printf("\nresult0.L: %d", result0.L);
    }

    printf ("\n");
    return 0;
}