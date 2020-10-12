#!/bin/bash -e

# ./01_judge.sh <file_name.c>

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

[ $(xxd -ps < ${1} | sed "s,\(..\),\1\n,g" | sed -ne "/^$(echo -n '[' | xxd -ps)/ p" | wc -l) -le 1 ] || \
  (>&2 echo "FAILED! Wiecej niz 1 znak '['"; false)
[ $(xxd -ps < ${1} | sed "s,\(..\),\1\n,g" | sed -ne "/^$(echo -n ']' | xxd -ps)/ p" | wc -l) -le 1 ] || \
  (>&2 echo "FAILED! Wiecej niz 1 znak ']'"; false)
if grep strlen < ${1}; then
  (>&2 echo "FAILED! strlen can not be used"; false)
fi

gcc -W -Wall -ansi -pedantic -Werror -Wextra ${1} -o ./${1}.exe

i=10
while [ ${i} -gt 0 ]; do
  generate_random ${i} 1000 20 > _.in
  j=100
  while [ ${j} -gt 0 ]; do
    echo -en "\rChecking ${i}/${j} ... "
    ./01_solution.sh < _.in > _.out
    ./${1}.exe < _.in > _.outchk 2>/dev/null
    diff _.out _.outchk || (>&2 echo "FAILED !"; false)
    j=$(( ${j} - 1 ))
  done
  i=$(( ${i} - 1 ))
done

rm -fr ./${1}.exe _.arg _.in _.out _.outchk

echo SUCCESS
