CH-1=ch-1-a-tutorial-introduction
CH-2=ch-2-types-operators-expressions

all: README.html README-CH-1.html README-CH-2.html

README.html: README.md
	cmark README.md > README.html

README-CH-1.html: ${CH-1}/README.md
	cmark ${CH-1}/README.md > README-CH-1.html

README-CH-2.html: ${CH-2}/README.md
	cmark ${CH-2}/README.md > README-CH-2.html

clean:
	rm -f README.html README-CH-1.html README-CH-2.html
