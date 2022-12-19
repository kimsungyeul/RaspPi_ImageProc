#!/bin/bash
a=0
while [ $a -le 95 ]
do
  if [ "$a" -lt "10" ]
  then
    wget https://github.com/Lee-Dong-Wook/Automatic-Redaing-Analog-Guage-System/raw/master/ClockTexting/trainImage/num/0$a.png
  else
    wget https://github.com/Lee-Dong-Wook/Automatic-Redaing-Analog-Guage-System/raw/master/ClockTexting/trainImage/num/$a.png
  fi
  a=`expr $a + 1`
done
