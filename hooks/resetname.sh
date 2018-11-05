#!/bin/bash
CURRENT=`pwd`
echo "=============== RESET NAME SCRIPT ================"
pdfDirectory="pdf"
for i in `ls $CURRENT/$pdfDirectory`; do
	echo $i | cut -d '.' -f 1 | (
		read fileName;
		numberName=`expr $fileName + 0`;
		mv $CURRENT/$pdfDirectory/$fileName.pdf $CURRENT/$pdfDirectory/$numberName.pdf;
	);
done
echo "RESET NAMES OF FILES IN: $CURRENT/$pdfDirectory"
echo "--------------------------------------------------"
sourceDirectory="source"
for i in `ls $CURRENT/$sourceDirectory`; do
	echo $i | cut -d '.' -f 1 | (
		read fileName;
		numberName=`expr $fileName + 0`;
		mv $CURRENT/$sourceDirectory/$fileName.c $CURRENT/$sourceDirectory/$numberName.c;
	);
done
echo "RESET NAMES OF FILES IN: $CURRENT/$sourceDirectory"
echo "--------------------------------------------------"
inputDirectory="test/input"
for i in `ls $CURRENT/$inputDirectory`; do
	echo $i | cut -d '.' -f 1 | (
		read fileName;
		numberName=`expr $fileName + 0`;
		mv $CURRENT/$inputDirectory/$fileName.txt $CURRENT/$inputDirectory/$numberName.txt;
	);
done
echo "RESET NAMES OF FILES IN: $CURRENT/$inputDirectory"
echo "--------------------------------------------------"
outputDirectory="test/output"
for i in `ls $CURRENT/$outputDirectory`; do
	echo $i | cut -d '.' -f 1 | (
		read fileName;
		numberName=`expr $fileName + 0`;
		mv $CURRENT/$outputDirectory/$fileName.txt $CURRENT/$outputDirectory/$numberName.txt;
	);
done
echo "RESET NAMES OF FILES IN: $CURRENT/$outputDirectory"