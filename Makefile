all:	chatterbot

chatterbot:	chatterbot.c
	gcc -o chatterbot chatterbot.c -lconfig `pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0`

clean:
	rm -i chatterbot
