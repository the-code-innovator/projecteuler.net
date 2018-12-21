#!/bin/bash
CURRENT=`pwd`
echo "================ SET NAME SCRIPT ================="
pdfDirectory="pdf"
pdfCount=`expr 0`
for i in `ls $CURRENT/$pdfDirectory/*.pdf`; do
	pdfCount=`expr $pdfCount + 1`
done
pdfFill=$(echo "l($pdfCount)/l(10)" | bc -l | cut -d '.' -f 1 | ( read log;logval=`expr $log + 0`;logval=`expr $logval + 1`;echo $logval;))
for ((i=1;i<=$pdfCount;i++)); do
	pdfName=`printf %0$pdfFill\\d $i`
	mv $CURRENT/$pdfDirectory/$i.pdf $CURRENT/$pdfDirectory/$pdfName.pdf
done
echo "SET NAMES FOR FILES IN: $CURRENT/$pdfDirectory"
echo "--------------------------------------------------"
sourceDirectory="source"
sourceCount=`expr 0`
for i in `ls $CURRENT/$sourceDirectory/*.c`; do
	sourceCount=`expr $sourceCount + 1`
done
sourceFill=$(echo "l($sourceCount)/l(10)" | bc -l | cut -d '.' -f 1 | ( read log;logval=`expr $log + 0`;logval=`expr $logval + 1`;echo $logval;))
for ((i=1;i<=$sourceCount;i++)); do
	sourceName=`printf %0$sourceFill\\d $i`
	mv $CURRENT/$sourceDirectory/$i.c $CURRENT/$sourceDirectory/$sourceName.c
done
echo "SET NAMES FOR FILES IN: $CURRENT/$sourceDirectory"
echo "--------------------------------------------------"
inputDirectory="test/input"
inputCount=`expr 0`
for i in `ls $CURRENT/$inputDirectory/*.txt`; do
	inputCount=`expr $inputCount + 1`
done
inputFill=$(echo "l($inputCount)/l(10)" | bc -l | cut -d '.' -f 1 | ( read log;logval=`expr $log + 0`;logval=`expr $logval + 1`;echo $logval;))
for ((i=1;i<=$inputCount;i++)); do
	inputName=`printf %0$inputFill\\d $i`
	mv $CURRENT/$inputDirectory/$i.txt $CURRENT/$inputDirectory/$inputName.txt
done
echo "SET NAMES FOR FILES IN: $CURRENT/$inputDirectory"
echo "--------------------------------------------------"
outputDirectory="test/output"
outputCount=`expr 0`
for i in `ls $CURRENT/$outputDirectory/*.txt`; do
	outputCount=`expr $outputCount + 1`
done
outputFill=$(echo "l($outputCount)/l(10)" | bc -l | cut -d '.' -f 1 | ( read log;logval=`expr $log + 0`;logval=`expr $logval + 1`;echo $logval;))
for ((i=1;i<=$outputCount;i++)); do
	outputName=`printf %0$outputFill\\d $i`
	mv $CURRENT/$outputDirectory/$i.txt $CURRENT/$outputDirectory/$outputName.txt
done
echo "SET NAMES FOR FILES IN: $CURRENT/$outputDirectory"
