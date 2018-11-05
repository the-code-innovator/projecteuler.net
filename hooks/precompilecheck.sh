#!/bin/bash
CURRENT=`pwd`
echo "============ PRE COMPILE CHECK SCRIPT ============"
tempsDirectory="temps"
echo "CHECKING FOR FOLDER $CURRENT/$tempsDirectory/: "
if [ ! -d $CURRENT/$tempsDirectory ]; then
	echo "CREATING FOLDER: $CURRENT/$tempsDirectory/"
	mkdir $CURRENT/$tempsDirectory
elif [ -d $CURRENT/$tempsDirectory ]; then
	echo "$CURRENT/$tempsDirectory/ exists !"
fi
echo "--------------------------------------------------"
executeDirectory="execute"
echo "CHECKING FOR FOLDER $CURRENT/$executeDirectory/: "
if [ ! -d $CURRENT/$executeDirectory ]; then
	echo "CREATING FOLDER: $CURRENT/$executeDirectory/"
	mkdir $CURRENT/$executeDirectory
elif [ -d $CURRENT/$executeDirectory ]; then
	echo "$CURRENT/$executeDirectory/ exists !"
fi