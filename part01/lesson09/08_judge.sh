#!/bin/bash -e

# ./08_judge.sh <file_name.c>

generate_random()
# <seed> <words_max> <word_len_max>
{
  echo "${@}" | gawk '
  function randRange(a, b)
  {
    return a + int(rand() * (b - a + 1));
  }
  function randChar(chars)
  {
    return substr(chars, randRange(1, length(chars)), 1);
  }
  function randString(len, chars)
  {
    r = "";
    while (len--)
    {
      r = r randChar(chars);
    }
    return r;
  }
  BEGIN {
    chars = "abcdefghij";
  }
  {
    srand($1 + systime() * 0);
    words = randRange(1, $2);
    while (words--)
    {
      printf("%s\n", randString(randRange(1, $3), chars));
    }
  }'
}

gcc -W -Wall -ansi -pedantic -Werror -Wextra ${1} -o ./${1}.exe

i=10
while [ ${i} -gt 0 ]; do
  generate_random ${i} 1000 100 > _.in
  j=100
  while [ ${j} -gt 0 ]; do
    echo -en "\rChecking ${i}/${j} ... "
    generate_random ${j} 1 20 > _.arg
    ./01_test_org.sh  $(cat _.arg) < _.in > _.out
    ./${1}.exe $(cat _.arg) < _.in > _.outchk 2>/dev/null
    diff _.out _.outchk || (>&2 echo "FAILED !"; false)
    j=$(( ${j} - 1 ))
  done
  i=$(( ${i} - 1 ))
done

rm -fr ./${1}.exe _.arg _.in _.out _.outchk

echo SUCCESS
