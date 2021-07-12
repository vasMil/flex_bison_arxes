all: myParser.exe

lex.yy.c: scanner.l
	lex scanner.l

parser.tab.c: parser.y
	bison -d parser.y -W -Wcounterexamples
	
myParser.exe: lex.yy.c parser.tab.c
	gcc -o myParser.exe parser.tab.c lex.yy.c -lfl

delete:
	rm -f myParser.exe parser.tab.c parser.tab.h lex.yy.c

clean: delete
	clear