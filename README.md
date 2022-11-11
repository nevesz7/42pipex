# 42pipex
Repository for my code of the 42 school project Pipex

make compiles the mandatory part that should be run with:
./pipex infile "cmd1" "cmd2" outfile

make bonus compiles bonus part that runs with 2 or more commands

Mandatory part was made using pipe function to send command1 to command2 input

Bonus part was made using 2 temporary files that are used in alternance as input and output except on first and last command, when infile is used as input and outfile is used as output. Both temporary files are deleted in the end of the proccess through the unlink C function. Fun fact: pipe function wasnt used at all.

To compare the output of my pipex project with the original bash run:
< infile "cmd1"| "cmd2" | ... | "cmdx" > outfile
Use "echo $?" to check and compare the exit code of the programs, too!

infile and outfile are arbitrary names and can be switched to any name desired (be careful with outfile, it will be cleaned as soon as you run the ./pipex with proper parameters)
Whenever infile does not exist, command 1 are skipped and program starts by running command 2 with empty string as input.