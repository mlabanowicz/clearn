
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static int compare(int a, int b)
{
  return a < b;
}

static void swap(int array [], int idA, int idB)
{
  int tmp = array[idA];

  array[idA] = array[idB];

  array[idB] = tmp;
}

static int update2root(int array [], int id)
{
  int parent;

  while ((parent = id >> 1) && compare(array[id], array[parent]))
  {
    swap(array, id, parent);

    id = parent;
  }

  return id;
}

static int update2leaf(int array [], int id)
{
  int child;

  while ((child = id << 1) <= *array)
  {
    child += (child + 1 <= *array) && compare(array[child + 1], array[child]);

    if (compare(array[child], array[id]))
    {
      swap(array, id, child);

      id = child;

      continue;
    }

    break;
  }

  return id;
}

static int add(int array [], int value)
{
  array[++(*array)] = value;

  return update2root(array, *array);
}

static void del(int array [], int id)
{
  if (id != (*array)--)
  {
    swap(array, id, *array + 1);

    update2root(array, update2leaf(array, id));
  }
}

static void dump(int const array [], FILE * f)
{
  int i = 0;

  fprintf(f, "%d:", *array);

  while (i < *array) fprintf(f, " %d", array[++i]);

  putc('\n', f);
}

static void check_integrity(int const array [])
{
  int count = array[0];

  int id;

  for (id = 1; id <= count; id++)
  {
    int child = (id << 1);

    int j = 2;

    while (j--)
    {
      if (child <= count)
      {
        if (array[id] > array[child])
        {
          fprintf(stderr, "ID:%d has greater value than CHILD:%d\n", id, child);

          dump(array, stderr);

          exit(EXIT_FAILURE);
        }
      }

      ++child;
    }
  }
}

int main(void)
{
  int result = EXIT_SUCCESS;

  int   avail = 1;
  int * array = (int *)calloc(sizeof(*array), avail);

  char cmd [32];

  if (!array)
  {
    fprintf(stderr, "Failed to allocate memory for %d elements !\n", avail);

    return EXIT_FAILURE;
  }

  while (scanf("%s", cmd) == 1)
  {

    if (!strcmp("dump", cmd))
    {
      dump(array, stdout);
    }
    else if (!strcmp("add", cmd))
    {
      int v;

      if (scanf("%d", &v) == 1)
      {
        if (*array + 1 == avail)
        {
          int   s = avail ? (avail * 2) : 32;
          int * p = (int *)realloc(array, s * sizeof(*array));

          if (!p)
          {
            fprintf(stderr, "Failed to allocate memory for %d elements !\n", s);

            result = EXIT_FAILURE;

            break;
          }

          array = p;
          avail = s;
        }

        add(array, v);
      }
      else
      {
        fprintf(stderr, "Failed to parse integer value !\n");

        result = EXIT_FAILURE;

        break;
      }
    }
    else if (!strcmp("get", cmd))
    {
      if (*array)
      {
        printf("%d\n", array[1]);
      }
      else
      {
        puts("-");
      }
    }
    else if (!strcmp("del", cmd))
    {
      int id;

      if (scanf("%d", &id) == 1)
      {
        del(array, id);
      }
      else
      {
        fprintf(stderr, "Failed to parse integer value !\n");

        result = EXIT_FAILURE;

        break;
      }
    }
    else
    {
      fprintf(stderr, "Unknown command : '%s' !\n", cmd);

      result = EXIT_FAILURE;

      break;
    }

    check_integrity(array);
  }

  free(array);

  return result;
}

#ifdef __cplusplus
}
#endif
