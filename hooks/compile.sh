#!/bin/bash
# verbose_flag($_VERBOSE_FLAG) is $2
_VERBOSE_FLAG=$2
CURRENT=`pwd`
echo "================= COMPILE SCRIPT ================="
executeDirectory="execute"
tempsDirectory="temps"
sourceDirectory="source"
sourceCount=`expr 0`
for i in `ls $CURRENT/$sourceDirectory/*.c`; do
	sourceCount=`expr $sourceCount + 1`
done
sourceFill=$(echo "l($sourceCount)/l(10)" | bc -l | cut -d '.' -f 1 | ( read log;logval=`expr $log + 0`;logval=`expr $logval + 1`;echo $logval;))
for ((c=1;c<=$1;c++)); do
	I=`printf %0$sourceFill\\d $c`
	echo "--------------------------------------------------"
	echo "COMPILING $I: "
	echo "--------------------------------------------------"
	clang -emit-llvm -S $CURRENT/$sourceDirectory/$I.c
	if [ $_VERBOSE_FLAG -eq 1 ]; then
		clang --save-temps=obj -v -Wall $CURRENT/$sourceDirectory/$I.c -o $CURRENT/$executeDirectory/$I
	elif [ $_VERBOSE_FLAG -eq 0 ]; then
		clang --save-temps=obj -Wall $CURRENT/$sourceDirectory/$I.c -o $CURRENT/$executeDirectory/$I
	fi
done
