all:
	bison -d form.y
	flex form.l
	gcc -o form_generator form.tab.c lex.yy.c -lfl

run: all
	./form_generator < example.form > output.html
	./form_generator < example2.form > output2.html

clean:
	rm -f form_generator lex.yy.c form.tab.c form.tab.h output.html
	rm -f form_generator lex.yy.c form.tab.c form.tab.h output2.html
