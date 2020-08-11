#!/usr/bin/awk -f

# usage: echo 0 | awk -f 04_test_gen.awk

function randRange(a, b)
{
  return a + int(rand() * (b - a + 1));
}

function randChar(chars)
{
  return substr(chars, randRange(1, length(chars)), 1);
}

function randString(len)
{
  chars = "abcdefghijklmnopqrstuvwxyz" \
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
          "0123456789" \
          "_[]{};'<>?,./" \
          "!@#$%^&*()_+-=\""; \
  r = "";
  while (len--)
  {
    r = r randChar(chars);
  }
  return r;
}

{
  srand(strtonum($1) + systime() * 1);
  m = i = randRange(3,10);
  while (i)
  {
    name = randString(randRange(1,20));
    val  = randRange(1,0x7fffffff);
    if (chn[name] || chv[val]) {
      # already present, try to generate new one
      continue;
    }
    chn[name] = 1;
    chv[val]  = 1;
    printf("%s %d\n", name, val);
    --i;
  }
}
