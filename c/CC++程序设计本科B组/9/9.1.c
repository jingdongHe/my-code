    #include <stdio.h>  
    #include <stdlib.h>  
    #include <time.h>  
      
    int number, n = 0;  
    int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  
      
    int test;  
      
    void swap(int *a, int *b)  
    {  
        int temp = *a;  
        *a = *b;  
        *b = temp;  
    }  
      
    int getNum(int s, int an)  
    {  
        int i, num = 0;  
        for (i = s; i <= an; i++)  
        {  
            num = list[i] + num * 10;  
        }  
        return num;  
    }  
      
    void perm(int k, int m, int x)  
    {  
        int i, j, a, b, c;  
          
        if (k > m)  
        {  
            for (i = 0; i < x; i++)  
            {  
                a = getNum(0, i);  
                test=((number-a)*list[8])%10;  
                for (j =i+(8-i)/2; j < 8; j++)  
                {  
                    if(list[j]==test)  
                    {  
                        b = getNum(i + 1, j);  
                        c = getNum(j + 1, 8);  
                        if (b % c == 0 && a + b / c == number)  
                        {  
                            n++;  
                        }  
                        break;  
                    }  
                }  
                  
            }  
              
        }  
        else  
        {  
            for (i = k; i <= m; i++)  
            {  
                swap(&list[k], &list[i]);  
                perm(k + 1, m, x);  
                swap(&list[k], &list[i]);  
            }  
        }  
    }  
      
    int main()   
    {  
        clock_t s1, s2;  
        int temp, x;  
        while(scanf("%d", &number) != EOF && number != 0)  
        {  
            x = 0;  
            temp = number;  
            s1 = clock();  
            n = 0;  
            while (temp != 0)   
            {  
                x++;  
                temp /= 10;  
            }  
            perm(0, 8, x);  
            printf("total:%d\n", n);  
            s2 = clock();  
            printf("%f ms\n", (double)(s2 - s1));  
        }  
    }  