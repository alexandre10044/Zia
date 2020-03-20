#!/bin/sh

## Made to be used at the root of repo

# Makes dir
mkdir -p ./modules/$1

# Copy files and renames them
cp ./modules/moduleCreator/httpCheckRequest/httpCheckRequest.cmake ./modules/$1/$1.cmake
cp ./modules/moduleCreator/httpCheckRequest/httpCheckRequest.cpp ./modules/$1/$1.cpp
cp ./modules/moduleCreator/httpCheckRequest/httpCheckRequest.hpp ./modules/$1/$1.hpp

# Changes text
text='s/httpParseRequest/'$1'/'
#echo $text
sed -i $text ./modules/$1/$1.cmake
sed -i $text ./modules/$1/$1.cmake
sed -i $text ./modules/$1/$1.cpp
sed -i $text ./modules/$1/$1.cpp
sed -i $text ./modules/$1/$1.hpp
sed -i $text ./modules/$1/$1.hpp
