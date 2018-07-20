 #include<stdio.h>
int main(void)
{
    int x,y;
    x=2;
    y=3;
    while((x>1)&&(y<4))
    {
      x--;
      y++;
    }
    while((y>0)&&(x<=4))
    {
      printf("(%d,%d)",x,y);
      y--;
      x++;
    }
    printf("\n");
}
