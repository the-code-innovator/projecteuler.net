#!/bin/bash
CURRENT=`pwd`
echo "================== TEST SCRIPT ==================="
outputDirectory="output/"
echo "CHECKING FOR $CURRENT/$outputDirectory: "
if [ ! -d $CURRENT/$outputDirectory ]; then
	echo "CREATING FOLDER: $CURRENT/$outputDirectory"
	mkdir $CURRENT/$outputDirectory
elif [ -d $CURRENT/$outputDirectory ]; then
	echo "$CURRENT/$outputDirectory exists !"
fi
echo "--------------------------------------------------"
COUNT=`expr 0`
echo -n "WA: "
sourceDirectory="source"
sourceCount=`expr 0`
for i in `ls $CURRENT/$sourceDirectory/*.c`; do
	sourceCount=`expr $sourceCount + 1`
done
sourceFill=$(echo "l($sourceCount)/l(10)" | bc -l | cut -d '.' -f 1 | ( read log;logval=`expr $log + 0`;logval=`expr $logval + 1`;echo $logval;))
for ((c=1;c<=$1;c++)); do
	I=`printf %0$sourceFill\\d $c`
	chmod u+x $CURRENT/execute/$I
	$CURRENT/execute/$I < $CURRENT/test/input/$I.txt > $CURRENT/output/$I.txt
	RESULT=`diff -sw $CURRENT/test/output/$I.txt $CURRENT/output/$I.txt`
	CONSTRUCT=`printf Files\ %s\ and\ %s\ are\ identical $CURRENT/test/output/$I.txt $CURRENT/output/$I.txt`
	if [ "$RESULT" != "$CONSTRUCT" ]; then
		echo -n "$c, "
		COUNT=`expr $COUNT + 1`
	fi
done
if [ $COUNT -eq 0 ]; then
	echo -e "\b\b : NIL"
else 
	echo -e "\b\b "
fi
echo "--------------------------------------------------"
echo -n "TEST RESULT: "
if [ $COUNT -ne 0 ]; then
	echo "$COUNT WA"
else
	echo "$1 AC"
fi