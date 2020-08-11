#!/bin/sh -e

rm -fr judge
mkdir judge
pushd judge

gcc ${1} -W -Wall -ansi -pedantic -Werror -Wextra ${2} ../05_lesson08.c -o a.exe

check()
{
  cat > input.txt
  ../04_test_org.sh < input.txt > good.out
  ./a.exe < input.txt > tocheck.out
  diff good.out tocheck.out
}

check < ../03_data_1_a.in
check < ../03_data_1_b.in
check < ../03_data_1_c.in
check < ../06_data.in

i=3
while [ ${i} -le 1000 ]; do
  echo -en "\rtest: ${i} ... "
  echo ${i} | awk -f ../04_test_gen.awk | check
  i=$((i+1))
done
echo ok

# cleaning
popd
rm -fr judge
