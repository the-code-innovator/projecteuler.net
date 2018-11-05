#!/bin/bash
CURRENT=`pwd`
echo "================= CLEAN SCRIPT ==================="
tempsDirectory="temps/"
if [ -d $CURRENT/$tempsDirectory ]; then
	echo "REMOVING $CURRENT/$tempsDirectory"
	rm -r $CURRENT/$tempsDirectory
else
	echo "$CURRENT/$tempsDirectory does not exist !"
fi
executeDiretory="execute/"
if [ -d $CURRENT/$executeDiretory ]; then
	echo "REMOVING $CURRENT/$executeDiretory"
	rm -r $CURRENT/$executeDiretory
else
	echo "$CURRENT/$executeDiretory does not exist !"
fi
outputDiretory="output/"
if [ -d $CURRENT/$outputDiretory ]; then
	echo "REMOVING $CURRENT/$outputDiretory"
	rm -r $CURRENT/$outputDiretory
else
	echo "$CURRENT/$outputDiretory does not exist !"
fi