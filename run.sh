#!/bin/sh

rm -f elapsed
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./bubble < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./comb < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./quick < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./insertion < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./shell < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./selection < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./heap < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./counting < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./radix < /dev/null
/bin/time -a -o elapsed -f '%C\n\t\t%E' ./bitonic_merge < /dev/null
