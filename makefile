.PHONY: clean
main:seqlist.c
	gcc $^ -o $@
clean:
	rm main
