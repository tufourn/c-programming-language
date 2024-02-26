#!/bin/bash

# Check if correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <chapter_num> <exercise_num>"
    exit 1
fi

# Extract chapter and exercise numbers
chapter_num=$1
exercise_num=$2

# Set the source file and output executable name
source_file="ch${chapter_num}/${chapter_num}-${exercise_num}.c"
output_executable="build/${chapter_num}-${exercise_num}"

# Create build directory if not exists
mkdir -p build

# Compile the C file
gcc -Wall -o "$output_executable" "$source_file"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the executable
    "$output_executable"
else
    echo "Compilation failed."
fi
