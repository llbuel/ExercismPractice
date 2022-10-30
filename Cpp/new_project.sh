#!/bin/bash

read -p "Enter new project name: " project_name

file_ext_cpp=".cpp"
file_ext_h=".h"

echo ""
echo "Creating the following files:"

full_source_file="$PWD/${project_name}/${project_name}${file_ext_cpp}"
full_header_file="$PWD/${project_name}/${project_name}${file_ext_h}"

echo $full_source_file
echo $full_header_file

echo ""
echo "Copying template files."

mkdir -p $PWD/$project_name

cp $PWD/1_template/README.md $PWD/1_template/source.cpp $PWD/1_template/header.h $PWD/1_template/test.cpp $PWD/$project_name
cp -r $PWD/1_template/.vscode $PWD/$project_name

echo "Renaming files."

$(mv $PWD/$project_name/source.cpp $PWD/$project_name/$project_name$file_ext_cpp)
$(mv $PWD/$project_name/header.h $PWD/$project_name/$project_name$file_ext_h)

echo "Configuring new files."

include_fileHToTest='#include "'$project_name$file_ext_h'"'
namespaceStart='namespace '"$project_name"' {'
newClassCall='        '$project_name'::templateClass c(a.a, a.b);'
include_h_inCpp='#include "'$project_name$file_ext_h'"'
header_guard_ifndef='#ifndef '$(echo $project_name | tr '[:lower:]' '[:upper:]')'_H'
header_guard_define='#define '$(echo $project_name | tr '[:lower:]' '[:upper:]')'_H'

sed -i '1s/.*/'"$include_h_inCpp"'/' $PWD/$project_name/$project_name$file_ext_cpp
sed -i '3s/.*/'"$namespaceStart"'/' $PWD/$project_name/$project_name$file_ext_cpp

sed -i '1s/.*/'"$header_guard_ifndef"'/' $PWD/$project_name/$project_name$file_ext_h
sed -i '2s/.*/'"$header_guard_define"'/' $PWD/$project_name/$project_name$file_ext_h
sed -i '4s/.*/'"$namespaceStart"'/' $PWD/$project_name/$project_name$file_ext_h

sed -i '2s/.*/'"$include_fileHToTest"'/' $PWD/$project_name/test.cpp
sed -i '36s/.*/'"$newClassCall"'/' $PWD/$project_name/test.cpp
