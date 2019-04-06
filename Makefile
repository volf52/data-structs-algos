src = $(wildcard *c)
obj = $(src:.c=.o)
dep = $(obj:.o=.d)

main: $(obj)
	gcc -O4 -Wall -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) main mian.exe
