shell: \
			proj.o \
			cd.o \
			exec.o \
			execute.o \
			ls.o \
			pinfo.o \
			printPrompt.o \
			pwd.o \
			echo.o
		$(CC) -g -o shell $^
clean:
	@rm -f *.o shell

proj.o: shell.h proj.c
	$(CC) -g -c proj.c

cd.o: shell.h src/cd.c
	$(CC) -g -c src/cd.c

exec.o: shell.h src/exec.c
	$(CC) -g -c src/exec.c

execute.o: shell.h src/execute.c
	$(CC) -g -c src/execute.c

ls.o: shell.h src/ls.c
	$(CC) -g -c src/ls.c

pinfo.o: shell.h src/pinfo.c
	$(CC) -g -c src/pinfo.c

printPrompt.o: shell.h src/printPrompt.c
	$(CC) -g -c src/printPrompt.c

pwd.o: shell.h src/pwd.c
	$(CC) -g -c src/pwd.c

echo.o: shell.h src/cd.c
	$(CC) -g -c src/echo.c
