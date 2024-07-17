TEST_IN = $(wildcard casos-teste/*.in)

.PHONY: run

run: sequence.hs $(TEST_IN)
	rm test.out

%.in: sequence.hs %.out
	runghc sequence.hs < $@ > test.out
	diff test.out $*.out