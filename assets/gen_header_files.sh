#!/bin/bash

# Function to convert a PNG file to a C header file using bin2header

convert_to_header() {
    local png_file="$1"
    local header_name="${png_file%.png}.h"
    bin2header -n "${png_file%.png}" -o "$header_name" "$png_file"
}



# Check if bin2header is installed

if ! command -v bin2header &> /dev/null; then

    echo "bin2header utility not found. Please install it first."

    exit 1

fi



# Check if a folder path is provided as an argument

if [ $# -eq 0 ]; then

    echo "Usage: $0 <folder_path>"

    exit 1

fi



folder_path="$1"



# Check if the provided path is a directory

if [ ! -d "$folder_path" ]; then

    echo "Error: '$folder_path' is not a valid directory."

    exit 1

fi



# Loop through all PNG files in the folder and convert each one to a C header file

for png_file in "$folder_path"/*.png; do

    if [ -f "$png_file" ]; then

        convert_to_header "$png_file"

    fi

done



echo "Conversion complete. All PNG files in '$folder_path' have been converted to C header files."


