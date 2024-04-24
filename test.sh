# Path to the invalid/ directory
directory="/nfs/homes/hsolet/42_Project/so_long/maps/valid"

# Output file path
output_file="/nfs/homes/hsolet/42_Project/so_long/output.txt"

# Loop through each file in the directory
for file in "$directory"/*
do
    # Run valmacro on each file and append the output to the output file
    #valgrind --leak-check=full --log-fd=1 --show-leak-kinds=all --track-fds=yes
	./so_long "$file" >> "$output_file"

    # Append a space to the output file
    echo " " >> "$output_file"
done
