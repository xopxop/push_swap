typedef struct s_test_2
{
  int data;
  int data2;
} t_test_2;

typedef struct s_test
{
  t_test_2 test;
  t_test_2 *test_2;
} t_test;

#include <stdlib.h>

t_test *init()
{
  t_test *test;

  test = (t_test*)malloc(sizeof(t_test));
  test->test.data2 = 100;
  return test;
}

#include <stdio.h>

void change(t_test test)
{
  test.test.data2 = 50;
  // return test;
}

int main()
{
  t_test *test = init();

  change(*test);
  // test.test.data2 = 50;
  printf("%d\n", test->test.data2);
  return 0;
}