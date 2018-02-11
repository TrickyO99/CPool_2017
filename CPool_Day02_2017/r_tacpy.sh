#!/bin/bash
sed -n 0~2p | cut -d ':' -f 1 | rev | sort -r | head -n $MY_LINE2| tail -n $(($MY_LINE2-$MY_LINE1+1)) | tr "\n" "," | sed -e 's/,/, /gi' | sort | tr "\n" "!" | sed 's/, !/./' | sort
