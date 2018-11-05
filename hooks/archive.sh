#!/bin/bash
DATE=`git show -s --format=%ct HEAD`
REPOSITORY=`pwd`
cd ..
PARENT=`pwd`
cd $REPOSITORY
find $REPOSITORY -name ".DS_Store" -delete
git archive --verbose --format=zip --output $PARENT/projectruler.net-$DATE.zip HEAD