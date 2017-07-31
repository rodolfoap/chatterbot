# chatterbot
A proof of concept on using C, GTK, glade, a voice syntesizer (espeak), to have a speaking animated character on the linux graphical environment.

![Chatterbot](https://github.com/rodolfoap/chatterbot/blob/master/img/chatterbot.png)

- Requires installing:
	* espeak
	* gtk2-devel

- Just an idea for a linux group, a lot to optimize.
	- Threads handling can be improved
	- gtk types require proper casting
	- Image rotation is highly inefficient, but it's only for this concept proof.
	- The synthesizer doesn't sync lips movement. Easy to do using a proper voice synth lib. No time, tough.
	- Change images as you like.
	- Since it accepts STDIN, the text can be feed by a pipe.
	- Keeps silent, while STDIN != EOF
	- GNU.

RodolfoAP (http://ydor.org)
