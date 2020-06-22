CMARK=cmark-gfm --extension tasklist
CH-1=ch-1*
CH-2=ch-2*

all: README.html README-CH-1.html README-CH-2.html

README.html: README.md
	${CMARK} README.md > README.html

README-CH-1.html: ${CH-1}/README.md
	${CMARK} ${CH-1}/README.md > README-CH-1.html

README-CH-2.html: ${CH-2}/README.md
	${CMARK} ${CH-2}/README.md > README-CH-2.html

clean:
	rm -f README.html README-CH-1.html README-CH-2.html
