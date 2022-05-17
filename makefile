all: help  isolate wheretogo talk history myShell0 interact open lookaround
help : commands/help.c
	gcc -o commands/help commands/help.c
isolate : commands/isolate.c
	gcc -o commands/isolate commands/isolate.c
wheretogo : commands/wheretogo.c
	gcc -o commands/wheretogo commands/wheretogo.c
talk : commands/talk.c
	gcc -o commands/talk commands/talk.c
history : commands/history.c
	gcc -o commands/history commands/history.c
interact : commands/interact.c
	gcc -o commands/interact commands/interact.c
open : commands/open.c
	gcc -o commands/open commands/open.c
lookaround : commands/lookaround.c
	gcc -o commands/lookaround commands/lookaround.c
myShell0 : myShell0.c
	gcc -o myShell0 myShell0.c
	./myShell0



