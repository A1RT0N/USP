TEST_IN = $(wildcard casos-teste/*.in)

.PHONY: run

run: prim-diff.hs $(TEST_IN)
	rm test.out

%.in: prim-diff.hs %.out
	runghc prim-diff.hs < $@ > test.out
	diff test.out $*.out