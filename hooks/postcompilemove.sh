#!/bin/bash
CURRENT=`pwd`
executeDirectory="execute"
tempsDirectory="temps"
echo "============ POST COMPILE MOVE SCRIPT ============"
asmDirectory="asm/"
echo "CHECKING FOR $CURRENT/$tempsDirectory/$asmDirectory: "
if [ ! -d "$CURRENT/$tempsDirectory/$asmDirectory" ]; then
	echo "CREATING FOLDER: $CURRENT/$tempsDirectory/$asmDirectory"
	mkdir $CURRENT/$tempsDirectory/$asmDirectory
elif [ -d "$CURRENT/$tempsDirectory/$asmDirectory" ]; then
	echo "$CURRENT/$asmDirectory exists !"
fi
echo "MOVING $CURRENT/$executeDirectory/*.s to $CURRENT/$tempsDirectory/$asmDirectory"
mv $CURRENT/$executeDirectory/*.s $CURRENT/$tempsDirectory/$asmDirectory
echo "--------------------------------------------------"
includeDirectory="inc/"
echo "CHECKING FOR $CURRENT/$tempsDirectory/$includeDirectory: "
if [ ! -d "$CURRENT/$tempsDirectory/$includeDirectory" ]; then
	echo "CREATING FOLDER: $CURRENT/$tempsDirectory/$includeDirectory"
	mkdir $CURRENT/$tempsDirectory/$includeDirectory
elif [ -d "$CURRENT/$tempsDirectory/$includeDirectory" ]; then
	echo "$CURRENT/$tempsDirectory/$includeDirectory exists !"
fi
echo "MOVING $CURRENT/$executeDirectory/*.i to $CURRENT/$tempsDirectory/$includeDirectory"
mv $CURRENT/$executeDirectory/*.i $CURRENT/$tempsDirectory/$includeDirectory
echo "--------------------------------------------------"
binCDirectory="bin/"
echo "CHECKING FOR $CURRENT/$tempsDirectory/$binCDirectory: "
if [ ! -d "$CURRENT/$tempsDirectory/$binCDirectory" ]; then
	echo "CREATING FOLDER: $CURRENT/$tempsDirectory/$binCDirectory"
	mkdir $CURRENT/$tempsDirectory/$binCDirectory
elif [ -d "$CURRENT/$tempsDirectory/$binCDirectory" ]; then
	echo "$CURRENT/$tempsDirectory/$binCDirectory exists !"
fi
echo "MOVING $CURRENT/$executeDirectory/*.bc to $CURRENT/$tempsDirectory/$binCDirectory"
mv $CURRENT/$executeDirectory/*.bc $CURRENT/$tempsDirectory/$binCDirectory
echo "--------------------------------------------------"
objDirectory="obj/"
echo "CHECKING FOR $CURRENT/$tempsDirectory/$objDirectory: "
if [ ! -d "$CURRENT/$tempsDirectory/$objDirectory" ]; then
	echo "CREATING FOLDER: $CURRENT/$tempsDirectory/$objDirectory"
	mkdir $CURRENT/$tempsDirectory/$objDirectory
elif [ -d "$CURRENT/$tempsDirectory/$objDirectory" ]; then
	echo "$CURRENT/$tempsDirectory/$objDirectory exists !"
fi
echo "MOVING $CURRENT/$executeDirectory/*.o to $CURRENT/$tempsDirectory/$objDirectory"
mv $CURRENT/$executeDirectory/*.o $CURRENT/$tempsDirectory/$objDirectory
echo "--------------------------------------------------"
irDirectory="ir/"
echo "CHECKING FOR $CURRENT/$tempsDirectory/$irDirectory: "
if [ ! -d "$CURRENT/$tempsDirectory/$irDirectory" ]; then
	echo "CREATING FOLDER: $CURRENT/$tempsDirectory/$irDirectory"
	mkdir $CURRENT/$tempsDirectory/$irDirectory
elif [ -d "$CURRENT/$tempsDirectory/$irDirectory" ]; then
	echo "$CURRENT/$tempsDirectory/$irDirectory exists !"
fi
echo "MOVING $CURRENT/*.ll to $CURRENT/$tempsDirectory/$irDirectory"
mv $CURRENT/*.ll $CURRENT/$tempsDirectory/$irDirectory
